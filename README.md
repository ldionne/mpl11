# MPL11
> Enjoy template metaprogramming

## Disclaimers
This is not an official Boost library. It might be proposed as a successor
for the current Boost.MPL in the future, but there is no guarantee.

The library is unstable at the moment; do not use for production.

This was initially supposed to be a simple C++11 reimplementation of the
Boost.MPL. However, for reasons documented in the [rationales](#rationales),
the library was redesigned and the name does not fit so well anymore.


## Table of contents
- [Installation](#installation)
- [Introduction](#introduction)
    + [Traditional metafunctions](#traditional-metafunctions)
    + [Evaluation strategies](#evaluation-strategies)
- [The MPL11](#the-mpl11)
    + [Boxed types](#boxed-types)
    + [Metafunctions](#metafunctions)
    + [Non-strictness](#non-strictness)
    + [Metafunction classes](#metafunction-classes)
    + [Datatypes and data constructors](#datatypes-and-data-constructors)
        * [Conversions](#conversions)
    + [Methods](#methods)
    + [Typeclasses](#typeclasses)
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

To compile the unit tests, you will also need [CMake][]. Once you have it, you
can go to the root of the project and do:

```shell
$ mkdir build
$ cd build
$ cmake ..
$ make tests    # Compiles the unit tests.
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


### Evaluation strategies
Like we just saw, traditional metafunctions expect their arguments to be "fully
evaluated". For example, when invoking a metafunction with the result of another
metafunction, that metafunction has to be evaluated by the caller before its
result is passed to the callee. This is roughly equivalent to a
[call-by-value][] evaluation strategy.

```cpp
using List = list<int_<1>, int_<2>>;
using Two = head<tail<List>::type>::type;
//                         ^^^^^^
// tail is evaluated so we can pass the result to head

using Error = head<tail<List>>::type; // head expects a list<...>
```

If `head` expected a metafunction returning a `list` instead of a `list`
directly, the burden of evaluating the arguments could be switched from
`head`'s caller to `head` itself. For example, we could write:

```cpp
using List = list<int_<1>, int_<2>>;
using Two = head<tail<List>>::type;
//                        ^ no evaluation of tail

using Error = head<tail<List>::type>;
// error: tail<List>::type is list<int_<2>>, which is not a metafunction
```

This would be roughly equivalent to a [call-by-need][] evaluation strategy,
where the compiler is the one performing memoization of template instantiations
behind the scenes. Right now, the usefulness of this evaluation strategy might
not be clear. However, we can expose a common situation where it comes in handy
using just the tools we created in the previous section. Let's assume we want to
create a metafunction that will drop the first `N` elements of a list and return
what's left, or the empty list if `N` is greater than the number of elements in
the list.

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

As it turns out, `eval_if` is only an `if_` using a call-by-need evaluation
strategy. We can now write the `drop` metafunction like so:

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
return the empty list, which is fine. However, we will also invoke `tail` on
the empty list, which is an error because `tail` expects its argument to be
non-empty. Much like the first one, this problem can be fixed by providing
an equivalent metafunction with a call-by-need evaluation strategy:

```cpp
template <typename N, typename List>
struct eval_drop
    : drop<typename N::type, typename List::type>
{ };
```

We can now write our final `drop` metafunction:

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
metafunction to be used in a context where it should be conditionally invoked,
all metafunctions should have a call-by-need version. It does increase the
complexity of the library, but the alternative is to have the user write an
equivalent ad-hoc solution, which is a net loss. Also, a nice side-effect of
call-by-need is the reduction of syntactic noise, particularly in dependent
contexts where `typename` and `::type` become a real pain.


## The MPL11
This section explains the core concepts of the library. We start with a couple
of definitions; be careful because some definitions clash with those from the
MPL, and some terms were used to denote different things in the introduction.
It is essential to start with a clean slate here.


### Boxed types
The notion of boxed type is central to the MPL11. As you will see later, it
serves as a bridge between normal types and metafunctions. For an arbitrary C++
type `T`, a __boxed `T`__ is an arbitrary C++ type `B` such that `B::type` is
`T`. In this context, `B` is called a __box__ (of `T`) and fetching the nested
`::type` inside of `B` is called __unboxing__ `T`.

```cpp
struct T;
struct B { using type = T; }; // a boxed T (equivalently, a box of T)

B::type; // unboxing T
```

Conversely, wrapping an arbitrary type `T` in a type `B` such that `B::type` is
`T` is called __boxing__ `T` (into `B` or with `B`). It is important to note
that `B` may depend on `T`, without which boxing would be of limited interest.

```cpp
struct T;

template <typename t>
struct B { using type = t; };

B<T>; // boxing T into B
```

Note that types may be boxed an arbitrary number of times. This is probably not
useful, but the definition is general enough to allow it.

```cpp
B<B<T>>; // this is a "box of B<T>", aka a "box of (box of T)"
```

There exists a special `undefined` type which has the characteristic of causing
a compile-time error when it is instantiated. `undefined` can be seen as a box
containing no type at all. `undefined` is also called bottom.

Here are some examples to illustrate the previous definition:

```cpp
// This template takes an arbitrary type T and boxes it.
template <typename T>
struct box {
    using type = T;
};

// These are not boxed.
class x;
struct y { char foo; };
char;
box<char>::type;

// These are boxed types.
box<char>;                          // a boxed `char`
box<box<char>>;                     // a boxed `box<char>`
box<box<char>>::type;               // a boxed `char`
struct x { using type = char; };    // a boxed `char`
struct y { struct type; };          // a boxed `y::type`
struct z { using type = z; };       // self-referential? why not!
```

It is important to note that there are many different representations for a
boxed `T`. This makes equivalence between boxed types a bit tricky. Consider
the following:

```cpp
struct T;
struct B1 { using type = T; }; // a boxed T
struct B2 { using type = T; }; // a boxed T too
```

Certainly, `B1` and `B2` are equivalent w.r.t. to the type they box since they
both are boxes of `T`. However, `B1` and `B2` are _not_ equivalent w.r.t. the
C++ type system because they are different types. Now, this is important because
it tells us that we can't use pattern matching on boxes! Consider a fictive
situation where we want to define a metafunction whose argument is a boxed type
(the relevance of such metafunctions will become clear):

```cpp
template <typename B>
struct f;

// this handle boxed chars
template <>
struct f<box<char>> {
    using type = ...;
};

template <typename T>
struct bad {
    using type = T;
};

f<box<char>>::type; // works
f<bad<char>>::type; // oops!
```

Instead, we would have to do something more convoluted like:

```cpp
template <typename T>
struct f_impl;

template <>
struct f_impl<char> {
    using type = ...;
};

template <typename B>
struct f
    : f_impl<typename B::type>
{ };

f<box<char>>::type; // works
f<bad<char>>::type; // works too
```


### Metafunctions
Informally, a metafunction is a template representing a compile-time function
taking types as arguments and returning a type as a result. Readers coming from
the MPL should be careful here, since the formal definition differs from the
that of the MPL.

Formally, let `f` be a C++ template accepting an arbitrary number of type
template parameters, and only type template parameters. Then, `f` is a
__metafunction__ if and only if there exists types `x1, ..., xn` such that
`f<x1, ..., xn>::type` is a valid type name. In this context,

- `x1, ..., xn` are the __arguments__ of `f`.
- Forming a specialization `f<x1, ..., xn>` is called __suspending__ `f`
  with `x1, ..., xn`.
- A specialization `f<x1, ..., xn>` is called a __thunk__ or a __suspension__.
- The nested `::type` of a thunk is called the __result__ of the thunk. If the
  thunk is of the form `f<x1, ..., xn>`, we can also say it is the __result__
  of `f` with `x1, ..., xn`.
- Fetching the result of a thunk is called __evaluating__ the thunk. If the
  thunk is of the form `f<x1, ..., xn>`, we can also say __invoking__ `f` with
  `x1, ..., xn` or __applying__ `f` to `x1, ..., xn`.
- The __arity__ of a metafunction is the number of arguments it can be
  invoked with. A metafunction with arity _n_ is said to be a __n-ary__
  metafunction.
- A metafunction that can be invoked with any number of arguments is said
  to be __variadic__. By definition, a variadic metafunction is n-ary for
  any non-negative integer n.

There are two important things to note here. The first is that thunks are
really the same as boxed types, which is why boxed types can be seen as a
bridge between normal types and metafunctions. The second is the difference
between this definition and the one given by the Boost.MPL. With our definition,
a metafunction can never be a normal C++ type; it must always be a template.
Hence, Boost.MPL nullary metafunctions implemented as non-template classes
are not considered metafunctions with our definition. Here are some examples:

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

// Not a metafunction with the MPL11; it is not a template!
struct MPL_nullary { struct type; };

// Not a metafunction; it never has a result (a nested ::type)!
template <typename ...>
struct no_result { };
```

In the MPL11, the default evaluation strategy is call-by-need. This is not a
requirement of the definition but merely a design choice which often makes
metafunctions easier to compose. However, a direct consequence is that
metafunctions must take boxed arguments and unbox them in their body as needed.

As an aside, it is interesting to note that the equivalence between thunks and
boxed types plays a big role in making call-by-need metafunctions useful. This
equivalence means that whenever a boxed type is expected, a thunk may be passed
instead. Hence, call-by-need metafunctions can sometimes avoid evaluating
complex thunks, which is far more interesting than avoiding to unbox a type.

At this point, it is probably helpful to clarify that the way we return from
call-by-need metafunctions is no different from that of usual metafunctions.
For example, consider the following call-by-need metafunction that returns the
successor of an integer:

```cpp
// We do this:
template <typename N>
struct succ {
    using type = int_<N::type::value + 1>;
};

// Not this:
template <typename N>
struct bad_succ {
    using type = box<int_<N::type::value + 1>>;
};

// So we can do this:
using one = succ<box<int_<0>>>;
using three = succ<succ<one>>;      // note that one and three are boxed
```


### Non-strictness
Call-by-need is an evaluation strategy that is part of a larger family of
evaluation strategies called non-strict evaluation. The goal of this section
is to formalize this notion in the context of metafunctions. While it offers
an interesting formalization, it can safely be skipped by the casual reader.

Let's define what it means for a metafunction to be strict. A n-ary metafunction
`f` taking boxed arguments only is __strict in its `i`-th argument__ if and only
if evaluating `f<x1, ..., xi-1, undefined, xi+1, ..., xn>` is a compile-time
error for all sets of arguments `x1, ..., xn`. A metafunction is __strict__ if
it is strict in all its arguments. Conversely, a metafunction that is not strict
in its `i`-th argument is __non-strict in its `i`-th argument__, and a
metafunction that is not strict is __non-strict__. Note that all metafunctions
taking unboxed arguments are trivially strict; for all sets of arguments
`x1, ..., xn` and for all `i`, evaluating
`f<x1, ..., xi-1, undefined::type, xi+1, ..., xn>` is indeed a
compile-time error, since peeking into `undefined` is an error.

The intuition behind this definition is that if replacing the `i`-th argument by
`undefined` yields an error for all choices of `x1, ..., xn`, the metafunction
must necessarily try to evaluate that `i`-th argument. Hence, one can think of
strictness in an argument as the fact that the metafunction always evaluates
this argument. Conversely, a metafunction that is non strict in the `i`-th
argument is a metafunction that might or might not evaluate that argument; but
there must be at least one combination of arguments for which the `i`-th
argument is not evaluated.

Given a fixed set of arguments `x1, ..., xk` and a n-ary metafunction `f`, it
is also possible to consider the strictness of `f` with respect to an argument
`y` that is not in `x1, ..., xk`. The strictness of `f` in `y` is defined as the
strictness in `y` of the metafunction created by partially applying `f` to
`x1, ..., xk`. That way, strictness in an argument can be seen as depending on
the value of the other arguments. For example, consider the following `if_`
metafunction:

```cpp
template <typename Condition, typename Then, typename Else>
struct if_
    : std::conditional<Condition::type::value, Then, Else>::type
{ };
```

`if_` is strict in its first argument and non-strict in its second and third
arguments. Now, let `if_<x>` denote the (binary) metafunction created by
partially applying `if_` to `x`. Then, we can further say that `if_<true_>`
is strict in its first argument and non-strict in its second one. Similarly,
`if<false_>` is non-strict in its first argument and strict in its second one.
Clearly, analyzing the strictness properties of a metafunction can quickly
become overwhelming. For this reason, metafunctions with special or complicated
strictness characteristics should be documented clearly.

> Interested readers should consider reading [this][haskell-denot-semantics]
> for a detailed treatment of strict versus non-strict semantics. This is a
> much richer topic than what is exposed here, and can lead to worthwhile
> insights.


### Metafunction classes
Informally, a metafunction class is a representation of a metafunction that
allows it to be manipulated as a first class citizen in template metaprograms.
Hence, the formal definition of a metafunction class naturally follows from
that of a metafunction.

An arbitrary C++ type `f` is a __metafunction class__ if and only if `f::apply`
is a metafunction. In general, metafunction classes inherit the terminology of
metafunctions, and the characteristics of a metafunction class follow from that
of its nested `apply` metafunction. For example, the arity of a metafunction
class `f` is that of `f::apply`.

> The definition of metafunction classes exposed here is not the same as that
> of the Boost.MPL. The difference between both definitions is the difference
> between the definition of metafunctions in both libraries.


### Datatypes and data constructors
At compile-time, types become values. A legitimate question would then be: what
is the type of those values? In the MPL11, datatypes play that role. Closely
related are data constructors, a way to create a "value" of a given datatype.
For example, let's create a simple compile-time list:

```cpp
// A "tag" representing the datatype.
struct List;

// The list constructor. It represents a value of type List that
// contains the provided elements.
template <typename ...Elements>
struct list { using mpl_datatype = List; };

// The cons constructor. It represents a value of type List
// with the provided head and tail.
template <typename Head, typename Tail>
struct cons { using mpl_datatype = List; };

// The nil constructor. It represents an empty List.
struct nil { using mpl_datatype = List; };
```

Data constructors must provide a nested `::mpl_datatype` alias representing
their datatype. One can then use the `mpl11::datatype` metafunction to retrieve
that datatype:

```cpp
mpl11::datatype<nil>::type; // == List
```

It is also possible to specialize `mpl11::datatype` instead of providing a
nested `mpl_datatype` alias. So this definition of `cons` is equally valid
(and the other constructors could be defined analogously):

```cpp
template <typename Head, typename Tail>
struct cons; // no nested mpl_datatype

namespace boost { namespace mpl11 {
    template <typename Head, typename Tail>
    struct datatype<cons<Head, Tail>> {
        using type = List;
    };
}}
```

Being able to do this is paramount when adapting code over which we don't have
the control, but for simplicity we'll stick with the nested `mpl_datatype` for
most of this tutorial. When unspecialized, `mpl11::datatype<ctor>` simply
returns `ctor::mpl_datatype` if that expression is a valid type name, and
`mpl11::Foreign` otherwise. `mpl11::Foreign` is the default datatype of
everything; its purpose will become clearer later.

Note that `mpl11::datatype` really takes a data constructor as an argument,
not a boxed type. This is one of the rare metafunctions of the library that
have call-by-value semantics. While it is not mandatory, it is often a good
idea to box data constructors since it makes them usable as-is in call-by-need
metafunctions too. Let's rewrite the previous data constructors that way:

```cpp
template <typename ...Elements>
struct list_impl {
    using mpl_datatype = List;
};

template <typename Head, typename Tail>
struct cons_impl {
    using mpl_datatype = List;
};

struct nil_impl { using mpl_datatype = List; };


template <typename ...Elements>
struct list {
    using type = list_impl<Elements...>;
};

template <typename Head, typename Tail>
struct cons {
    using type = cons_impl<Head, Tail>;
};

struct nil {
    using type = nil_impl;
};
```

The downside is that we end up with twice the amount of code, half of which
is complete boilerplate. Also, this approach causes twice as many templates
to be instantiated each time we unbox a data constructor, which can hurt
compile-time performance. Fortunately, we can use self-referential boxed
types to make this right.

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

struct nil {
    using type = nil;
    using mpl_datatype = List;
};
```

That way, only one additional line of code is required per data constructor
and we only instantiate one template when we unbox it. Indeed, `cons<...>::type`
is just `cons<...>`, which is already instantiated.

You might wonder why I have even bothered with the inferior solution using
`cons_impl` and friends in the first place, since the self-referential
solution is so obvious. This was to highlight the fact that boxed data
constructors do not _need_ to be self-referential; it is merely a convenient
implementation trick. This is a subtle difference between the MPL11 and the
[mpllibs][] library collection, which I wanted to point out.

There is something rather important that we have left undefined when we created
the `list` and `cons` data constructors: what do their arguments look like?

```cpp
template <typename ...Elements>
struct list;

template <typename Head, typename Tail>
struct cons;
```

There are two possible answers here, and both are valid. In the end, this is
mainly a design choice. The first option is to require the arguments to be
normal (non-boxed) types. We could then use the constructors like so:

```cpp
using x = list<int, char, float>;
using y = cons<int, list<char, float>>;
using z = cons<int, cons<char, cons<float, nil>>>;
```

The second option is to require boxed arguments. We could then use the
constructors like so:

```cpp
using x = list<box<int>, box<char>, box<float>>;
using y = cons<box<int>, list<box<char>, box<float>>>;
using z = cons<box<int>, cons<box<char>, cons<box<float>, nil>>>;
```

> Note that we do not need to box the second arguments to `cons` ourselves,
> because we have already made `list`, `cons` and `nil` boxed.

This is clearly less natural than the first solution. Still, for reasons that
will soon become clearer, the MPL11 `List` constructors use the second solution,
and so will we for the rest of this tutorial. To reduce the syntactic noise, we
will define aliases that will make our life easier:

```cpp
template <typename ...Elements>
using list_ = list<box<Elements>...>;

template <typename Head, typename Tail>
using cons_ = cons<box<Head>, box<Tail>>;
```

> Note that we would not need to box the second argument of `cons_` because we
> expect it to be a `List`, and all `List` constructors are already boxed. So
> `box<Tail>` is really redundant, but we still do it here for the sake of
> clarity.

An important distinction must be made here. One could come to think of data
constructors as metafunctions, but they are not quite the same. While some
data constructors may happen to fulfill the definition of a metafunction (like
`cons` and `list`), data constructors have far fewer restrictions. Indeed, data
constructors are not _required_ to be boxed (or even templates), in which case
any similarity with metafunctions vanishes:

```cpp
struct Integer;

// A non-boxed data constructor. This is _clearly_ not a metafunction.
template <int i>
struct int_ {
    using mpl_datatype = Integer;
};
```

#### Conversions
The MPL11 provides a preferred way to convert values from one datatype to the
other. The usefulness of this is clearest when implementing numeric datatypes,
but we'll stick with `List` because we already have it. Let's suppose we want to
convert values from a `List` to an `std::tuple` and vice-versa. First, we will
need to define a datatype of which `std::tuple` can be a data constructor.

```cpp
struct StdTuple;

namespace boost { namespace mpl11 {
    template <typename ...T>
    struct datatype<std::tuple<T...>> {
        using type = StdTuple;
    };
}}
```

We can now consider `std::tuple` as a data constructor for the `StdTuple`
datatype. Note that unlike the arguments to `list`, the arguments to `std::tuple`
must be unboxed; this will be important for what follows. The next step is to
implement the conversion itself. This is done by specializing the `mpl11::cast`
metafunction class for the involved datatypes.

```cpp
namespace boost { namespace mpl11 {
    template <>
    struct cast</*from*/ List, /*to*/ StdTuple> {
        template <typename>
        struct apply;

        template <typename ...Elements>
        struct apply<list<Elements...>> {
            using type = std::tuple<typename Elements::type...>;
        };

        template <>
        struct apply<nil> {
            using type = std::tuple<>;
        };

        template <typename Head, typename Tail>
        struct apply<cons<Head, Tail>> {
            using type = /* omitted for simplicity */;
        };
    };

    template <>
    struct cast</*from*/ StdTuple, /*to*/ List> {
        template <typename>
        struct apply;

        template <typename ...Elements>
        struct apply<std::tuple<Elements...>> {
            using type = list_<Elements...>;
        };
    };
}}
```

There are a few things to note here. First, it is very important to provide a
conversion for all the data constructors of a datatype. If, for instance, we
had forgotten to provide `apply<nil>`, we could only convert from the `list`
and `cons` constructors. Second, we had to unbox the elements of the `list`
when passing them to `std::tuple` because `std::tuple` expects unboxed types.
Similarly, we had to box the elements of the `std::tuple` when passing them to
`list`. Third, the arguments to the `mpl11::cast` metafunction class are unboxed
data constructors, which makes it easier to perform pattern matching in the
nested `apply`. Here is how we could now convert between the two datatypes:

```cpp
using my_list = list_<int, char, float>;
using my_tuple = std::tuple<int, char, float>;

mpl11::cast<List, StdTuple>::apply<my_list>::type; // == my_tuple
mpl11::cast<StdTuple, List>::apply<my_tuple>::type; // == my_list
```

The library also defines a handy `mpl11::cast_to` metafunction class that
reduces the syntactic noise of `mpl11::cast`:

```cpp
mpl11::cast_to<StdTuple>::apply<my_list>::type; // == my_tuple
mpl11::cast_to<List>::apply<my_tuple>::type; // == my_list
```

`mpl11::cast_to` simply deduces the datatype to cast from by using that of its
argument and then forwards to `mpl11::cast`.

__TODO__
- give more details on the `Foreign` datatype


### Methods
So far, we have created the `List` datatype and a couple of constructors to
create "values" of that type, but we still don't have a way to manipulate those
values in a useful way. Let's redefine the `head` metafunction from the
introduction for the `List` datatype. Keep in mind that metafunctions are
call-by-need by default in the MPL11, so we will stick with this convention
for `head`.

```cpp
template <typename List>
struct head_impl;

template <typename Head, typename ...Tail>
struct head_impl<list<Head, Tail...>>
    : Head
{ };

template <typename Head, typename Tail>
struct head_impl<cons<Head, Tail>>
    : Head
{ };

// head_impl<nil> is not defined since that's an error.

template <typename List>
struct head
    : head_impl<typename List::type>
{ };
```

We need to add a level of indirection (`head_impl`) because `head` receives
boxed arguments and we need to perform pattern matching on the data constructors.
Also, note that while `head` is technically call-by-need, it is still strict
because it always evaluates its argument. `head` is therefore a call-by-need
metafunction that _happens_ to always need to evaluate its argument. Also, note
that we inherit from `Head` in `head_impl` because it is a boxed type; fetching
`head_impl::type` will unbox `Head::type`, which is what we want.

It is now possible to see why it was useful to take boxed types in the `List`
data constructors. Consider the following situation:

```cpp
using refs = list<
    std::add_lvalue_reference<int>,
    std::add_lvalue_reference<void>
>;

using int_ref = head<refs>::type;
```

Since we can't form a reference to `void`, we will trigger a compile-time error
if we evaluate the `std::add_lvalue_reference<void>` thunk. However, since we
only ever use the value of the first element in the list, it would be nice if
we could only evaluate that element, right? Taking boxed types (which are
really the same as thunks) in the `list` constructor is what makes it possible.
If, instead, we had decided to take unboxed types in `list`, we would need to
write:

```cpp
using refs = list<
    std::add_lvalue_reference<int>::type,
    std::add_lvalue_reference<void>::type
>;
```

which does not compile. The same reasoning is valid if the contents of the
list were the results of complicated computations. By taking thunks in the
constructor, we would only need to evaluate those computation whose result
is actually used. In the end, the reasons for writing data constructors that
take boxed types are similar to the reasons for writing call-by-need
metafunctions.

The `head` metafunction we have so far is useful, but consider the following
datatype and boxed data constructor taking boxed arguments.

```cpp
struct Vector;

template <typename ...Elements>
struct vector {
    struct type {
        using mpl_datatype = Vector;
    };
};

template <typename Head, typename ...Tail>
struct vector<Head, Tail...> {
    struct type {
        using head = Head;
        using mpl_datatype = Vector;
    };
};
```

Since `Vector` is really some kind of `List`, it is only reasonable to expect
that we can invoke `head` on a `Vector` just like we do on a `List`. But how
would we go about implementing `head` for `Vector`? Assuming we can't modify
the implementation of `Vector`, the only way we have right now is to use partial
specialization of `head_impl` on `Vector`'s constructor. Unfortunately, that
constructor is `vector<...>::type`, not `vector<...>`. Since we can't partially
specialize on a dependent type, we're out of luck. To bypass this limitation,
we will refine `head` so it uses the datatype of its argument.

```cpp
template <typename Datatype>
struct head_impl;

template <typename List>
struct head
    : head_impl<typename datatype<typename List::type>::type>::
      template apply<typename List::type>
{ };
```

We now consider `head_impl` as a metafunction class parameterized over the
datatype of its argument. Implementing `head` for `List` and `Vector` is now
a breeze.

```cpp
template <>
struct head_impl<List> {
    template <typename> struct apply;

    template <typename Head, typename ...Tail>
    struct apply<list<Head, Tail...>>
        : Head
    { };

    template <typename Head, typename Tail>
    struct apply<cons<Head, Tail>>
        : Head
    { };
};

template <>
struct head_impl<Vector> {
    template <typename v>
    struct apply
        : v::head
    { };
};
```

Metafunctions using this dispatching technique are called __methods__.


### Typeclasses
Typeclasses come from the observation that some methods are naturally related
to each other. For example, take the `head`, `tail` and `is_empty` methods.
When implementing any of these three methods, it is probable that the other
two should also be implemented. Hence, it would be logical to group them in
some way; that is the job of typeclasses.

__TODO__
- Talk about default implementations
- There's more but its not clear right now
- Note that we can probably reuse a lot of stuff from the section on methods;
  typeclasses are mostly (but not only) method bundles.


### Rewrite rules
__TODO__


## Acknowledgements
The development of this library drew inspiration from a couple of projects with
different levels of involvement in template metaprogramming. I would like to
thank the people involved in these projects for their work, without which this
library wouldn't be the same. The most notable sources of inspiration and
enlightenment were:

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

### Why are MPL-style non-template nullary metafunctions not allowed?
It introduces a special case in the definition of metafunction that prevents us
from using `f::apply<>` to invoke a nullary metafunction class. We have to use
`apply<f>`, which will then use either `f::apply<>` or `f::apply`. This adds a
template instantiation and an overload resolution to each metafunction class
invocation, which significantly slows down compilation. Considering nullary
metafunctions are of limited use anyway (why would you want a function without
arguments in a purely functional setting?), this is not worth the trouble. Also,
note that MPL-style nullary non-template metafunctions fit in the definition of
a boxed type, so they're not completely forgotten.


## Todo list
- [ ] Sync the library with the tutorial. For example, there are some places
      where the tutorial says that we're taking unboxed types (and it is better
      to do so) but we're still taking boxed types in the library.
- [ ] Implement fast arithmetic operations on sequences of `StaticConstant`s.
- [ ] Implement associative data structures.
- [ ] Implement a small DSL to implement inline metafunction classes (like
    Boost.MPL's lambda). Consider let expressions. Using the Boost.MPL lingo,
    such a DSL should:
    - Allow leaving placeholders as-is inside a lambda, if this is desirable.
    - Allow performing placeholder substitution in a lambda without actually
    evaluating the expression, if this is desirable.
    - Allow "variadic placeholders", i.e. placeholders expanding to several
    types. One pitfall of this is using such a placeholder with a
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
- [ ] Clarify the notion of weak head normal form if this applies to us.
- [ ] Consider having a wrapper that allows treating template specializations
      as data. Something like sequence operations on template specializations
      and/or tree operations.
- [ ] Consider adding `while_` and `until` metafunctions.


<!-- Links -->
[Boost.MPL]: http://www.boost.org/doc/libs/1_55_0b1/libs/mpl/doc/index.html
[call-by-need]: http://en.wikipedia.org/wiki/Call_by_need
[call-by-value]: http://en.wikipedia.org/wiki/Call_by_value
[Cmake]: http://www.cmake.org
[doxygen-doc]: http://ldionne.github.io/mpl11
[haskell-denot-semantics]: http://en.wikibooks.org/wiki/Haskell/Denotational_semantics
[Haskell]: http://www.haskell.org
[mpllibs]: http://github.com/sabel83/mpllibs
[on-iteration]: http://www.informit.com/articles/article.aspx?p=1407357
[wiki-tmp]: http://en.wikipedia.org/wiki/Template_metaprogramming
