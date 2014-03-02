# MPL11
> Template metaprogramming for humans

## Disclaimers
This is not an official Boost library. It might be proposed as a replacement
for the current Boost.MPL in the future, but there is no guarantee.

The library is unstable at the moment; do not use for production.

This was initially supposed to be a simple C++11 reimplementation of the
Boost.MPL. However, for reasons documented in the [rationales](#rationales),
the library was redesigned and the name does not fit so well anymore.


## Table of contents
- [Installation](#installation)
- [Introduction](#introduction)
    + [Traditional metafunctions](#traditional-metafunctions)
    + [The burden of evaluation](#the-burden-of-evaluation)
- [The MPL11](#the-mpl11)
    + [Boxed types](#boxed-types)
    + [Metafunctions](#metafunctions)
    + [Metafunction classes](#metafunction-classes)
    + [Datatypes and data constructors](#datatypes-and-data-constructors)
    + [Typeclasses and methods](#typeclasses-and-methods)
    + [Rewrite rules](#rewrite-rules)
- [Acknowledgements](#acknowledgements)
- [Rationales](#rationales)
- [Todo list](#todo-list)


## Installation
The MPL11 is a header only library. To use it in your own project, just add the
[include](include) directory to your compiler's header search path and you are
done.

Note that a C++11 man-compiler is required. Currently, only Clang 3.5 and
GCC 4.9 can compile all the tests. However, a standard library is _not_
required at all.

To compile the unit tests and the examples, you will also need [CMake][]. Once
you have it, you can go to the root of the project and do:

```shell
$ mkdir build
$ cd build
$ cmake ..
$ make unit     # Compiles the unit tests.
$ make example  # Compiles the examples.
$ make          # Compiles the unit tests and the examples.
```


## Introduction
The MPL11 is a C++11 library providing composable, high-level primitives for
solving complex [template metaprogramming][wiki-tmp] problems. The library is
built around a few core concepts; the aim of this tutorial is to present them,
while the handful of tools provided by the library are left to the
[reference documentation][doxygen-doc].

This tutorial assumes a good understanding of template metaprogramming and
basic functional programming concepts. Also, a good understanding of the
[Boost.MPL][] library will be helpful. However, the MPL11 diverges from the
Boost.MPL in many ways, and one should be careful not to transfer knowledge
between both libraries without checking the documentation.


### Traditional metafunctions
A traditional metafunction is simply a class or a class template representing a
compile-time function whose arguments are types instead of runtime values.

```cpp
template <typename x>
struct f {
    using type = ...;
};
```

By convention, the result of a metafunction is obtained by reaching its nested
`::type` type. For example, invoking `f` would look like so:

```cpp
using result = f<int>::type;
```

We decide to use only types as metafunction arguments. We adopt this convention
because it allows treating metafunctions uniformly, which is necessary when
dealing with higher-order metafunctions. Also, we do not lose the ability
to process compile-time values with metafunctions, because we can provide
a wrapper that will allow those to be passed as types:

```cpp
template <int i>
struct int_ {
    static constexpr int value = i;
};

template <typename X>
struct increment {
    using type = int_<X::value + 1>;
};

using two = increment<int<1>>::type;
```

To explore what's possible, let's implement a couple basic metafunctions. First,
we decide to create compile-time counterparts to the boolean values `true` and
`false`. These  will be useful to define a compile-time counterpart to the
well-known `if` statement.

```cpp
template <bool b>
struct bool_ {
    static constexpr bool value = b;
};

using true_ = bool_<true>;
using false_ = bool_<false>;

template <typename Condition, typename Then, typename Else>
struct if_ {
    using type = Then;
};

template <typename Then, typename Else>
struct if_<false_, Then, Else> {
    using type = Else;
};
```

We can now use our compile-time `if` to create a lot of interesting
metafunctions. For example, let's implement the `min` metafunction,
which returns the smaller of its two arguments.

```cpp
template <typename X, typename Y>
struct min {
    using type = typename if_<bool_<(X::value < Y::value)>, X, Y>::type;
};
```

As a quick note, observe how we could have inherited from `if_` instead of
doing what we did above:

```cpp
template <typename X, typename Y>
struct min
    : if_<bool_<(X::value < Y::value)>, X, Y>
{ };
```

This is a technique called metafunction forwarding. When we inherit from `if_`,
all its publicly accessible members become accessible through the derived type
too, so that `min<...>::type` is actually `if<...>::type`. From now on, this
technique will be used when appropriate because it reduces syntactic overhead.

Let's now set aside numeric metafunctions for a while and concentrate on
compile-time sequences. Compile-time sequences are data structures storing
types instead of runtime values. Compile-time sequences relate to runtime
sequences just like metafunctions relate to normal functions. However, our
compile-time data structures will have to be purely functional, because
templates are a purely functional sub-language. Let's implement a basic
`list` as seen in most functional programming languages:

```cpp
template <typename ...>
struct list;


// Returns the first element of a list. Requires a non-empty list.
template <typename List>
struct head;

template <typename Head, typename ...Tail>
struct head<list<Head, Tail...>> {
    using type = Head;
};


// Returns all the list except the head. Requires a non-empty list.
template <typename List>
struct tail;

template <typename Head, typename ...Tail>
struct tail<list<Head, Tail...>> {
    using type = list<Tail...>;
};


// Returns whether a list is empty.
template <typename List>
struct is_empty {
    using type = false_;
};

template <>
struct is_empty<list<>> {
    using type = true_;
};
```

We can now use our `list` like so:

```cpp
using List  = list<int, char, float>;
using Int   = head<List>::type;
using Char  = head<tail<List>::type>::type;
using Float = head<tail<tail<List>::type>::type>::type;
using Error = head<list<>>::type; // head requires a non-empty list
```


### The burden of evaluation
Like we just saw, traditional metafunctions expect their arguments to be "fully
evaluated types". For example, when invoking a metafunction with the result of
another metafunction, that metafunction has to be evaluated by the caller before
its result is passed to the callee:

```cpp
using List = list<int_<1>, int_<2>>;
using Two = head<tail<List>::type>::type;
//                         ^^^^^^
// tail is evaluated so we can pass the result to head

using Error = head<tail<List>>::type; // head expects a list<...>
```

From now on, we will say of such metafunctions that the caller has the burden of
evaluating the arguments. If `head` expected a metafunction returning a `list`
instead of a `list` directly, the burden of evaluation would be switched from
`head`'s caller to `head` itself. For example, we could write:

```cpp
using List = list<int_<1>, int_<2>>;
using Two = head<tail<List>>::type;
//                        ^ no evaluation of tail

using Error = head<tail<List>::type>;
// error: tail<List>::type is list<int_<2>>, which is not a metafunction
```

In such case, we would say that the callee has the burden of evaluation. Right
now, the usefulness of this distinction is unclear. However, we can expose a
common situation where it comes into play using just the tools we created in
the previous section. Let's assume we want to create a metafunction that will
drop the first `N` elements of a list and return what's left, or the empty list
if `N` is greater than the number of elements in the list.

```cpp
template <typename N, typename List>
struct drop
    : if_<bool_<N::value == 0 || is_empty<List>::type::value>,

    /* then */
        List,

    /* else */
        typename drop<
            int_<N::value - 1>, typename tail<List>::type
        >::type
    >
{ };
```

This metafunction looks fine, but it isn't. The first problem is in the
recursive invocation of `drop`. Since we fetch its nested `::type`, it is
instantiated regardless of the `if_` branch taken and we end up with infinite
recursion. This problem may be fixed by introducing a metafunction similar to
`if_`, except it expects the branches to be nullary metafunctions and returns
the result of the metafunction corresponding to the branch taken. The
metafunction corresponding to the other branch is never evaluated. Here
is a possible implementation:

```cpp
template <typename Condition, typename Then, typename Else>
struct eval_if : Then { };

template <typename Then, typename Else>
struct eval_if<false_, Then, Else> : Else { };

// This is the identity metafunction: it returns its argument unchanged.
// We'll need this in a second.
template <typename X>
struct id {
    using type = X;
};
```

While `eval_if` is simple, it has two things that makes it different from most
traditional metafunctions. First, the burden of evaluating the `Then` and `Else`
arguments are switched from the caller to the callee. Second, `eval_if` does not
evaluate all its arguments all the time. In fact, it would be useless if it did.
Later, we will formalize what it means for a metafunction not to evaluate all of
its arguments all the time. For now, what must be clear is the fact that
switching the evaluation burden and evaluating only the necessary arguments are
two different things, but the later requires giving the evaluation burden to the
callee. We can now write our `drop` metafunction like so:

```cpp
template <typename N, typename List>
struct drop
    : eval_if<bool_<N::value == 0 || is_empty<List>::type::value>,

    /* then */
        id<List>,

    /* else */
        drop<int_<N::value - 1>, typename tail<List>::type>
    >
{ };
```

Since we do not fetch `drop`'s nested `::type` anymore, we do not end up with
infinite recursion. Also notice how we wrapped `List` with `id` in the "then"
branch; this is a bit annoying but it is necessary because `eval_if` expects a
metafunction in both branches.

The second problem is when we have an empty list. When that happens, we will
return the empty list, which is fine. But we will also invoke `tail` on the
empty list, which is an error because `tail` expects its argument to be
non-empty. Much like the first one, this problem can be fixed by providing
another version of the problematic metafunction, which is `drop` in this case:

```cpp
template <typename N, typename List>
struct eval_drop
    : drop<typename N::type, typename List::type>
{ };
```

Note how the burden of evaluation is given to `eval_drop`, yet `eval_drop`
evaluates its arguments whether they are needed or not. This again illustrates
how the evaluation burden and the "laziness" are two different but related
things. We can now write our final `drop` metafunction:


```cpp
template <typename N, typename List>
struct drop
    : eval_if<bool_<N::value == 0 || is_empty<List>::type::value>,

    /* then */
        id<List>,

    /* else */
        eval_drop<
            id<int_<N::value - 1>>,
            tail<List>
        >
    >
{ };
```

This implementation works as expected. Note that the original Boost.MPL does
provide an `eval_if` metafunction, but it does not provide an analogous for
most other metafunctions. Hence, ad-hoc solutions like the following are common:

```cpp
// Forward declaration needed for drop_tail.
template <typename N, typename List>
struct drop;

// Invokes drop with the tail of the list.
template <typename N, typename List>
struct drop_tail
    : drop<N, typename tail<List>::type>
{ };

template <typename N, typename List>
struct drop
    : eval_if<bool_<N::value == 0 || is_empty<List>::type::value>,

    /* then */
        id<List>,

    /* else */
        drop_tail<int_<N::value - 1>, List>
    >
{ };
```

There is a lesson to be learned here. Since it makes sense for an arbitrary
metafunction to be invoked with arguments that must be evaluated by the callee,
all metafunctions should provide a version that does just that, or the library
should provide a way to achieve the same result without providing two different
versions. It does increase the complexity of the library, but the alternative is
to have the user write an equivalent ad-hoc solution, which is a net loss.


## The MPL11
This section explains the core concepts of the library. Definitions will be
introduced as we go, but be careful because some definitions clash with
definitions from the MPL. It is essential to start with a clean slate here.


### Boxed types
An __unboxed type__ is an arbitrary C++ type.

A __boxed type__ `B` is an arbitrary C++ type such that `B::type` is an
unboxed type. `B::type` is called the __boxee__ of `B`. As a mnemonic, one
can consider the pointer-pointee relation. In that context, `B` would be the
pointer and `B::type` the pointee.

Let `B` be a boxed type and `U` an unboxed type. Then,

- Fetching the nested `::type` inside of `B` is __unboxing__ `B`. In the pointer
  analogy, that would be dereferencing `B`.
- Conversely, wrapping `U` in a type `C` such that `U` is the boxee of `C` is
  __boxing__ `U` into `C`. With the pointer analogy, boxing `U` into `C` would
  be letting `C = &U`.

There exists a special `undefined` boxed type which as the characteristic of
causing a compile-time error when it is unboxed. `undefined` is also called
bottom.

One important thing to note is that `non-boxed != unboxed`. A type is unboxed
if it was a boxee at some point, but nothing prevents a boxee to be boxed, much
like we can have a pointer to a pointer. Here are some examples:

```cpp
// This useful template takes an arbitrary unboxed type U
// and makes it a boxed type.
template <typename U>
struct boxed {
    using type = U;
};

// These are unboxed types.
struct w;
int;
boxed<char>;
boxed<char>::type;

// These are non-boxed types.
struct x { char foo; };
int;
boxed<char>::type;

// These are boxed types.
boxed<char>;
boxed<boxed<char>>::type;
struct y { struct type; };
struct z { using type = char; };
```


### Metafunctions
Informally, a metafunction is a template representing a compile-time function
taking types as arguments and returning a type as a result.

Formally, let `f` be a C++ template accepting an arbitrary number of type
template parameters, and only type template parameters. Then, `f` is a
__metafunction__ if and only if there exists types `x1, ..., xn` such that
`f<x1, ..., xn>::type` is a valid type name. In this context,

- `x1, ..., xn` are the __arguments__ of `f`.
- Forming a specialization `f<x1, ..., xn>` is __suspending__ `f` with
  `x1, ..., xn`.
- A specialization `f<x1, ..., xn>` is a __thunk__ or a __suspension__.
- The nested `::type` of a thunk is the __result__ of the thunk. If the
  thunk is of the form `f<x1, ..., xn>`, we can also say it is the __result__
  of `f` with `x1, ..., xn`.
- Fetching the result of a thunk is __evaluating__ the thunk. If the thunk is
  of the form `f<x1, ..., xn>`, we can also say __invoking__ `f` with
  `x1, ..., xn` or __applying__ `f` to `x1, ..., xn`.
- The __arity__ of a metafunction is the number of arguments it can be
  invoked with. A metafunction with arity _n_ is said to be a __n-ary__
  metafunction.
- A metafunction that can be invoked with any number of arguments is said
  to be __variadic__. By definition, a variadic metafunction is n-ary for
  any non-negative integer n.

There are two important things to note here. The first is that thunks are really
the same as boxed types. The second is the difference between this definition
and the one given by the Boost.MPL. With our definition, a metafunction can
never be a normal C++ type; it must always be a template. Hence, Boost.MPL
nullary metafunctions implemented as non-template classes are not considered
metafunctions with our definition. Here are some examples:

```cpp
// A unary metafunction.
template <typename x>
struct unary { struct type; };

// A binary metafunction.
template <typename x, typename y>
struct binary { struct type; };

// A variadic metafunction.
template <typename ...>
struct variadic { struct type; };

// A nullary metafunction. It can only be invoked with
// 0 arguments, and it is therefore 0-ary (nullary).
template <typename ...> struct nullary;
template <> struct nullary<> { struct type; };

// Not a metafunction; it is not a template!
struct old_nullary { struct type; };

// Not a metafunction; it never has a result (a nested ::type)!
template <typename ...>
struct no_result { };
```

We can now formally define the notion of non-strictness (loosely referred to as
"laziness" earlier) for a metafunction. Let `f` be a `n-ary` metafunction whose
arguments `x1, ..., xn` must all be boxed types. Then, `f` is __strict in `xi`__
if and only if invoking `f<x1, ..., xi-1, undefined, xi+1, ..., xn>` is a
compile-time error for all `x1, ..., xi-1, xi+1, ..., xn`. A metafunction that
is not strict in `xi` is __non-strict in `xi`__. It is possible that strictness
in an argument depends on the value of the other arguments. For example,
consider the following implementation of an `if` statement:

```cpp
template <typename Condition, typename Then, typename Else>
struct if_
    : std::conditional<Condition::type::value, Then, Else>::type
{ };
```

Here, `if_` is always strict in its first argument. However, `if_<True, ...>` is
non-strict in its second argument and `if_<False, ...>` is non-strict in its
first argument. When a metafunction has special or complicated strictness
characteristics, they should be documented explicitly.

The intuition behind the definition of strictness in an argument is that if
replacing an argument by `undefined` yields an error, the metafunction must
necessarily try to evaluate that argument. Hence, one can think of strictness
in an argument as the fact that the metafunction always evaluates this argument.

> It is interesting to note that the equivalence between thunks and boxed types
> plays a big role in making non-strict metafunctions useful. This equivalence
> means that whenever a boxed type is expected, a thunk may be passed instead.
> Hence, non-strict metafunctions can sometimes avoid evaluating complete
> thunks, which is far more interesting that avoiding the unboxing of a type.

<!-- This comment makes the above and the below blocks distinct. -->

> Interested readers should consider reading [this][haskell-denot-semantics]
> for a detailed treatment of strict versus non-strict semantics. This is a
> much richer topic than what is exposed here.


### Metafunction classes
Informally, a metafunction class is a representation of a metafunction that
allows it to be manipulated as a first class citizen in template metaprograms.

Formally, an arbitrary C++ type `f` is a __metafunction class__ if and only if
`f::apply` is a metafunction. In general, metafunction classes inherit the
terminology of metafunctions, and the characteristics of a metafunction class
follow from that of its nested `apply` metafunction. For example, the arity of
a metafunction class `f` is that of `f::apply`.

> The definition of metafunction classes exposed here is not the same as that
> of the Boost.MPL. The difference between both definitions is the difference
> between the definition of metafunctions in both libraries.


### Datatypes and data constructors
A data constructor is a way to create "values" of a given datatype.
For example, let's create a simple list with two different data constructors.

```cpp
// The datatype.
struct List;

// The list constructor. It represents a List with the provided elements.
template <typename ...Elements>
struct list { using mpl_datatype = List; };

// The cons constructor. It represents a List with the provided
// head and tail.
template <typename Head, typename Tail>
struct cons { using mpl_datatype = List; };
```

While it is not mandatory, it is often a good idea to box data constructors
since it makes them usable in non-strict metafunctions as-is. Let's rewrite
the above data constructors this way:

```cpp
template <typename ...Elements>
struct list {
    using type = list;
    using mpl_datatype = List;
};

template <typename Head, typename Tail>
struct cons {
    using type = cons;
    using mpl_datatype = List;
};
```

An important distinction must be made here. One could come to think of data
constructors as metafunctions, but they are not quite the same. While
metafunctions must be templates taking type template parameters only, data
constructors do not have such a restriction. In fact, data constructors do not
even have to be boxed, in which case any similarity with metafunctions vanishes:

```cpp
struct Integer;

// A non-boxed data constructor. This is _clearly_ not a metafunction.
template <int i>
struct int_ {
    using mpl_datatype = Integer;
};
```


### Typeclasses and methods
__TODO__


### Rewrite rules
__TODO__


## Acknowledgements
The development of this library drew inspiration from a couple of projects with
different levels of involvement in template metaprogramming. I would like to
thank the people involved in these projects for their work, without which this
library wouldn't be the same. The most notable sources of inspirations and
enlightment were:

- The [Haskell][] programming language
- The original [Boost.MPL][]
- The [mpllibs][] library


## Rationales
This section contains rationales for some design decisions of the library. In
its early development, the library was rewritten several times because
fundamental aspects of it needed to be changed. Hence, only the rationales
pertaining to the current design are kept here. If you have a question about
a design decision that is not explained here, please contact the creator of
the library (Louis Dionne).

### Why are iterators not used in the library?
The following points led to their removal:
- Lazy views were hard to implement because they required creating new
  iterators, which is a pain. Using a different abstraction for sequences
  made it much easier.
- Iterators being hard to implement and non-composable is a known problem,
  which is addressed e.g. by the Boost.Range library or in this
  [paper][on-iteration] by Andrei Alexandrescu.
- There is no performance gain to be achieved by using iterators. In fact, it
  often makes straightforward implementations more complicated, which can hide
  possible optimizations.
- Implementing infinite ranges using iterators is hacky at best.

### Why isn't `apply` a method?
There are two main reasons for this. First, if `apply` were a method, one would
need to make every metafunction class an instance of the typeclass defining
`apply`. Since metafunction classes are very common, that would be very
cumbersome. Second, making `apply` a method requires using the usual method
dispatching mechanism, which adds some overhead.

### Why aren't `and_`, `or_` and `not_` methods?
In some previous design of the library, these were methods. However, allowing
`and_` and `or_` to be non-strict required special casing these methods. Since
I could not find any use case, I decided to make them normal metafunctions.

### Why aren't `*_t` versions of metafunctions provided like in C++1y?
Switching the evaluation burden from the caller to the callee makes this useless
in most cases.


## Todo list
- [ ] Implement fast arithmetic operations on sequences of `StaticConstant`s.
- [ ] Implement associative data structures.
- [ ] Implement a small DSL to implement inline metafunction classes (like
    Boost.MPL's lambda). Consider let expressions. Using the Boost.MPL lingo,
    such a DSL should:
    - Allow leaving placeholders as-is inside a lambda, if this is desirable.
    - Allow performing placeholder substitution in a lambda without actually
    evaluating the expression, if this is desirable.
    - Allow "variadic placeholders", i.e. placeholders expanding to several
    types. One pitfal of this is using such a placeholder with a
    metafunction that is not variadic:

        ```cpp
        template <typename, typename>
        struct f;
        using F = lambda<f<_args>>; // error here, f is not unary
        using Result = F::apply<int, char>::type;
        ```
    This fails because `f` requires 2 arguments.
- [ ] Consider allowing types to be printed somehow. The idea is to have
    something like a `Show` typeclass that allows types to be pretty-printed
    for debugging purposes.
- [ ] Think about a convention or a system to customize some metafunction calls.
    Something neat would be to have a way of passing a custom predicate when
    comparing sequences; that would make `equal` as powerful as the `equal`
    algorithm from the Boost.MPL. Maybe we can achieve the same effect in
    another way.


<!-- Links -->
[Boost.MPL]: http://www.boost.org/doc/libs/1_55_0b1/libs/mpl/doc/index.html
[Cmake]: http://www.cmake.org
[doxygen-doc]: http://ldionne.github.io/mpl11
[haskell-denot-semantics]: http://en.wikibooks.org/wiki/Haskell/Denotational_semantics
[Haskell]: http://www.haskell.org
[mpllibs]: https://github.com/sabel83/mpllibs
[on-iteration]: http://www.informit.com/articles/article.aspx?p=1407357
[wiki-tmp]: http://en.wikipedia.org/wiki/Template_metaprogramming
