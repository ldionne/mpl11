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
- [Metafunctions](#metafunctions)
  + [Boxed types](#boxed-types)
  + [Laziness](#laziness)
  + [Lifted metafunctions](#lifted-metafunctions)
- [Datatypes and data constructors](#datatypes-and-data-constructors)
  + [Boxed data constructors](#boxed-data-constructors)
  + [Laziness in data constructors](#laziness-in-data-constructors)
  + [Conversions](#conversions)
- [Methods](#methods)
- [Typeclasses](#typeclasses)
- [Rewrite rules](#rewrite-rules)
- [Acknowledgements](#acknowledgements)
- [Rationales](#rationales)
- [Todo list](#todo-list)


## Installation
The MPL11 is a header only library. To use it in your own project, just add the
[include](include) directory to your compiler's header search path and you are
done.

The library has no dependencies - not even the standard library. However,
it requires a C++14-able compiler. The test suite passes under the following
compilers:
- clang version 3.4
- clang version 3.5.0
- GCC 4.9.0 20140302 (experimental)
- Apple LLVM version 5.1 (clang-503.0.38)

To compile the unit tests, you will also need [CMake][]. Once you have it, you
can go to the root of the project and do:

```shell
$ mkdir build
$ cd build
$ cmake ..
$ make tests    # Compiles the unit tests.
```

### Minified version
A minified version of the library is also provided. To use it, simply include
the `boost/mpl11.min.hpp` header, which contains the whole library. Note that
the minified header must not be used in conjunction with other headers from
the library.


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


## Metafunctions
Informally, a metafunction is a template representing a compile-time function
taking types as arguments and returning a type as a result. Readers coming
from the MPL should be careful here, since the formal definition differs
from that of the MPL.

Formally, let `f` be a C++ template with an arbitrary number of type
template parameters, and type template parameters only. Then, `f` is a
__metafunction__ if and only if there exists types `x1, ..., xn` such
that `f<x1, ..., xn>::type` is a valid type name. In this context,

- `x1, ..., xn` are the __arguments__ of `f`.
- Forming a specialization `f<x1, ..., xn>` is called __suspending__ `f`
  with `x1, ..., xn`.
- A specialization `f<x1, ..., xn>` is called a __thunk__ or a __suspension__.
- The nested `::type` of a thunk is called the __result__ of the thunk. If the
  thunk is of the form `f<x1, ..., xn>`, we can also say it is the __result__
  of `f` with `x1, ..., xn`.
- Fetching the result of a thunk is called __evaluating__ the thunk. If the
  thunk is of the form `f<x1, ..., xn>`, we can also say __invoking__ `f`
  with `x1, ..., xn` or __applying__ `f` to `x1, ..., xn`.
- The __arity__ of a metafunction is the number of arguments it can be
  invoked with. A metafunction with arity _n_ is said to be a __n-ary__
  metafunction.
- A metafunction that can be invoked with any number of arguments is said
  to be __variadic__. By definition, a variadic metafunction is n-ary for
  any non-negative integer n.

It is important to note the difference between this definition and the one
given by the Boost.MPL. With this definition, a metafunction can never be a
normal C++ type; it must always be a template. Hence, Boost.MPL nullary
metafunctions implemented as non-template classes are not considered as
metafunctions. Here are some examples:

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


### Boxed types
Informally, a boxed type is a type that has yet to be evaluated. Hence,
before knowing the actual "value" of a boxed type, one must evaluate it,
a process which is called unboxing.

Formally, for an arbitrary C++ type `T`, a __boxed `T`__ is an arbitrary C++
type `B` such that `B::type` is `T`. In this context, `B` is called a __box__
(of `T`) and fetching the nested `::type` inside of `B` is called __unboxing__
`T`.

```cpp
struct T;
struct B { using type = T; }; // a boxed T (equivalently, a box of T)

B::type; // unboxing T
```

Conversely, wrapping an arbitrary type `T` in a type `B` such that `B::type`
is `T` is called __boxing__ `T` (into `B` or with `B`). It is important to
note that `B` may depend on `T`, without which boxing would be of limited
interest.

```cpp
struct T;

template <typename t>
struct B { using type = t; };

B<T>; // boxing T into B
```

Note that types may be boxed an arbitrary number of times. This is probably
not useful, but the definition is general enough to allow it.

```cpp
B<B<T>>; // this is a "box of B<T>", aka a "box of (box of T)"
```

There exists a special boxed type named `undefined` (sometimes called
_bottom_) which has the characteristic of causing a compile-time error
when it is unboxed, even in SFINAE-able contexts. `undefined` can be
seen as an invalid value, or the result of a computation that failed.

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
both box the same type `T`. However, `B1` and `B2` are _not_ equivalent w.r.t.
the C++ type system because they are different types. Now, this is important
because it tells us that we can't use pattern matching to define a
metafunction taking a boxed type as an argument. Indeed, since the
representation of a boxed type is not unique, we can't know what form
will have our argument in advance, and therefore we can't pattern match.
Consider the following:

```cpp
// B should be a boxed type.
template <typename B>
struct f;

// This should handle boxed chars, but we don't know
// what a boxed char may look like!
template <>
struct f<????> {
    // ...
};
```

Now, we might be tempted to do the following:

```cpp
// box is the template that we defined earlier. It takes an
// arbitrary type and boxes it.
template <>
struct f<box<char>> {
    // ...
};
```

But then...

```cpp
template <typename T>
struct bad {
    using type = T;
};

// works, as expected
f<box<char>>::type;

// does not work, even though bad<char> is clearly a boxed char
f<bad<char>>::type;
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

> It is interesting to note that boxed types and thunks share a lot. In
> fact, a thunk is nothing but a boxed type that was formed by _suspending_
> a metafunction. Hence, whenever a boxed type is expected, a thunk may be
> used instead.


### Laziness
This section introduces the notion of laziness in the context of template
metaprograms and explains how it relates to the previous notions. This is
by no means a rigorous treatment of the broader subject of evaluation
strategies, and knowledge of those concepts is expected.

Informally, laziness is a property of a metafunction meaning that the
metafunction performs the least amount of work needed to give its result.
It requires the metafunction to only evaluate the expressions that are
actually needed in its body, and to evaluate them no more than once.

The second point is called memoization and it is handled behind the scenes by
the compiler. While the C++ standard does not require compilers to memoize
template instantiations, this is always the case in practice. Consider:

```cpp
template <typename x>
struct f {
  using type = x;
};

f<int>::type; // instantiate f<int>
f<int>::type; // f<int> is already instantiated, nothing is done.
```

The first point, however, must be handled manually when writing template
metaprograms.

> __TODO__
> Finish this section. Specifically, explain the following:
>
> - What is a lazy metafunction (mf classes follow from that)
> - The inverse of a lazy metafunction is a strict metafunction (broadly)
> - Lazy metafunctions must take boxed types, otherwise they would always
>   evaluate their arguments whether they are needed or not. This is
>   equivalent to call-by-name.
> - Strict metafunctions can take unboxed arguments, because they always
>   evaluate their arguments anyways. However, strict metafunctions can still
>   take boxed arguments and unbox them unconditionally; this is just a matter
>   of convention.
> - Metafunctions take boxed arguments by default in the MPL11.
> - Metafunctions are lazy by default (i.e. whenever possible) in the MPL11.
> - Strict metafunctions usually still take boxed arguments for consistency.
> - Some metafunctions don't follow the convention, and in this case this
>   behavior is documented.
> - Metafunctions that don't follow the convention do it because it's
>   necessary or because it's much easier to do such or such when breaking
>   the convention.
> - Why are lazy metafunctions useful?
>   This could use the `drop` metafunction of the old introduction.
>   Laziness often leads to increased expressiveness; for example it becomes
>   easy to define new control structures and infinite data structures.
> - Consider keeping the optional section on non-strictness.

<!--
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
 -->

At this point, it is probably helpful to clarify that returning from a lazy
metafunction is no different than returning from a strict metafunction. For
example, consider the following lazy metafunction implementing an `if`
statement:

```cpp
template <typename Condition, typename Then, typename Else>
struct if_ {
    using Branch = std::conditional<Condition::type::value, Then, Else>::type;
    using type = typename Branch::type;
};
```

Since `if_` is lazy, its arguments are all boxed types. Here, we unbox
`Branch` and return that instead of returning `Branch` itself. This way,
`if_<Condition, Then, Else>` is a thunk and we can pass it to other lazy
metafunctions as-is:

```cpp
// A lazy metafunction.
template <typename x>
struct f;

using result = f<   if_<Condition, Then, Else>  >::type;
```

 If we had defined `if_` as follows

```cpp
template <typename Condition, typename Then, typename Else>
struct if_ {
    using Branch = std::conditional<Condition::type::value, Then, Else>::type;
    using type = Branch; // Note that we don't unbox Branch here
};
```

then `if_` would return a thunk and we would need to do the following instead:

```cpp
using result = f<   if_<Condition, Then, Else>::type    >::type;
                                              ^^^^^^
```


### Lifted metafunctions
Informally, a lifted metafunction is a representation of a metafunction that
allows it to be manipulated as a first class citizen in template metaprograms.
Formally, an arbitrary C++ type `f` is a __lifted metafunction__ if and only
if `f::apply` is a metafunction. In general, lifted metafunctions inherit the
terminology of metafunctions, and the characteristics of a lifted metafunction
follow from that of its nested `apply` metafunction. For example, the arity of
a lifted metafunction `f` is that of `f::apply`.

> The definition of a lifted metafunction is almost the same as the definition
> of a metafunction class in the Boost.MPL. The only difference is the
> difference between metafunctions in both libraries.

Here are some examples of lifted metafunctions:

```cpp
// A unary lifted metafunction.
struct unary {
    template <typename x>
    struct apply { struct type; };
};

// A binary lifted metafunction.
struct binary {
    template <typename x, typename y>
    struct apply { struct type; };
};

// A variadic lifted metafunction.
struct variadic {
    template <typename ...>
    struct variadic { struct type; };
};

// A nullary lifted metafunction.
struct nullary {
    template <typename ...> struct apply;
};
template <> struct nullary::apply<> { struct type; };

// Not a lifted metafunction with the MPL11; its nested apply
// is not a metafunction!
struct MPL_nullary {
    struct apply { struct type; };
};

// Not a lifted metafunction; its nested apply never has a result!
struct no_result {
    template <typename ...>
    struct apply { };
};
```

Any metafunction can be lifted, and the MPL11 defines a template to do
just that.

```cpp
template <template <typename ...> class f>
struct lift {
    template <typename ...xs>
    struct apply
        : f<xs...>
    { };
};
```

> `lift` is essentially the same as `quote` in the Boost.MPL. The name
> `lift` was preferred because of its relation to a _lift_ in category
> theory. For completeness, `lift` is actually an equivalence of categories
> between the category where objects are C++ types and morphisms are
> templates to the category where objects are C++ types and morphisms
> are structs with a nested `apply` template.


## Datatypes and data constructors
At compile-time, a type becomes a value. A legitimate question would then be:
what is the type of that value? In the MPL11, datatypes play that role.
Closely related are data constructors, which are a way of creating values
of a given datatype. For example, let's create a simple compile-time list:

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
their datatype. One can then use the `datatype` metafunction to retrieve it:

```cpp
datatype<nil>::type; // == List
```

It is also possible to specialize `datatype` instead of providing a
nested `mpl_datatype` alias. So this definition of `cons` is equally
valid (and the other constructors could be defined analogously):

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
the control, but for simplicity we'll stick with the nested `mpl_datatype`
whenever possible. When unspecialized, `datatype<T>` simply returns
`T::mpl_datatype` if that expression is a valid type name, and `Foreign`
otherwise. Hence, `Foreign` is the default datatype of everything.

> Note that `datatype` is a strict metafunction and that it does not obey the
> convention of taking boxed arguments. Breaking the convention is necessary
> to allow user-defined specializations.


### Boxed data constructors
While it is not mandatory, it is often a good idea to box data constructors
since it makes them usable as-is in lazy metafunctions. Let's rewrite the
previous data constructors that way:

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
compile-time performance. Fortunately, we can use self-referential boxing
to make this better.

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
and we only instantiate one template when we unbox it. Indeed,
`cons<...>::type` is just `cons<...>`, which is already instantiated.

You might wonder why I have even bothered with the inferior solution using
`cons_impl` and friends in the first place, since the self-referential
solution is so obvious. This was to highlight the fact that boxed data
constructors do not _need_ to be self-referential; it is merely a convenient
implementation trick. This is a subtle difference between the MPL11 and the
[mpllibs][] library collection, which I wanted to point out.


### Laziness in data constructors
There is something rather important that we have left undefined when we
created the `list` and `cons` data constructors: what do their arguments
look like?

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

This is clearly less natural than the first solution. Still, for reasons
that will soon become clearer, the MPL11 `List` constructors use the second
solution, and so will we for the rest of this tutorial. To reduce the
syntactic noise, we will define aliases that will make our life easier:

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

We will say that a data constructor taking unboxed arguments is __strict__,
and that a data constructor taking boxed arguments is __lazy__. An interesting
observation is that some (but not all) constructors are also metafunctions.
Specifically, boxed constructors taking type template parameters are
metafunctions. Therefore, strict boxed constructors correspond to strict
metafunctions, and lazy boxed constructors correspond to lazy metafunctions!


### Conversions
The MPL11 provides a way to convert values from one datatype to the other. The
usefulness of this is clearest when implementing numeric datatypes, but we'll
stick with `List` because we already have it. Let's suppose we want to convert
values from a `List` to an `std::tuple` and vice-versa. First, we will need to
define a datatype of which `std::tuple` can be a data constructor.

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
datatype. Note that unlike the arguments to `list`, the arguments to
`std::tuple` must be unboxed; this will be important for what follows.
The next step is to implement the conversion itself. This is done by
specializing the `cast` lifted metafunction for the involved datatypes.

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
`list`. Third, the `cast` lifted metafunction is strict and it does not follow
the convention of taking boxed arguments, which makes it possible to pattern
match data constructors. Here is how we could now convert between the two
datatypes:

```cpp
using my_list = list_<int, char, float>;
using my_tuple = std::tuple<int, char, float>;

cast<List, StdTuple>::apply<my_list>::type; // == my_tuple
cast<StdTuple, List>::apply<my_tuple>::type; // == my_list
```

Also note that casting from a datatype `T` to itself is a noop, so you don't
have to worry about that trivial case. The library also defines a handy
`cast_to` lifted metafunction that reduces the syntactic noise of `cast`:

```cpp
cast_to<StdTuple>::apply<my_list>::type; // == my_tuple
cast_to<List>::apply<my_tuple>::type; // == my_list
```

`cast_to` simply deduces the datatype to cast from by using that of its
argument and then forwards to `cast`. `cast_to` is strict and does not
take boxed arguments.

> __TODO__: Give more details on the `Foreign` datatype.


## Methods
So far, we have created the `List` datatype and a couple of constructors to
create "values" of that type, but we still don't have a way to manipulate
those values in a useful way. Let's define a `head` metafunction that will
return the first element of a `List`. We will stick to the convention of
taking boxed arguments.

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

First, we need to add a level of indirection (`head_impl`) because `head`
receives boxed arguments and we need to pattern match the constructors.
Second, note that `head` is a strict metafunction because its argument
is always evaluated. Third, we inherit from `Head` in `head_impl` because
the `List` constructors are lazy and hence `Head` is boxed.

It is now possible to see why it was useful to make the `List` constructors
lazy. Consider the following situation:

```cpp
using refs = list<
    std::add_lvalue_reference<int>,
    std::add_lvalue_reference<void>
>;

head<refs>::type; // == int&
```

Since we can't form a reference to `void`, we will trigger a compile-time
error if we evaluate the `std::add_lvalue_reference<void>` thunk. However,
since we only ever use the value of the first element in the list, it would
be nice if we could only evaluate that element, right? Making `list` a lazy
constructor makes that possible. If, instead, we had decided to make `list`
strict, we would need to write:

```cpp
using refs = list<
    std::add_lvalue_reference<int>::type,
    std::add_lvalue_reference<void>::type
>;
```

which does not compile. The same reasoning is valid if the contents of the
list were the results of complicated computations. By making the constructor
lazy, we would only need to evaluate those computation whose result is
actually used. In the end, the reasons for writing lazy data constructors
are similar to the reasons for writing lazy metafunctions.

The `head` metafunction we have so far is useful, but consider the following
datatype and lazy boxed constructor:

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
the implementation of `Vector`, the only way we have right now is to use
partial specialization of `head_impl` on `Vector`'s constructor.
Unfortunately, that constructor is `vector<...>::type`, not `vector<...>`.
Since we can't partially specialize on a dependent type, we're out of luck.
To bypass this limitation, we will refine `head` so it uses the datatype of
its argument.

```cpp
template <typename Datatype>
struct head_impl;

template <typename List>
struct head
    : head_impl<typename datatype<typename List::type>::type>::
      template apply<typename List::type>
{ };
```

We now consider `head_impl` as a lifted metafunction parameterized over the
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

It is sometimes useful to exert a finer grained control over template
specializations than what we currently have. A common idiom is for the
primary template to provide an additional dummy parameter which can be
SFINAE'd upon in partial specializations:

```cpp
template <typename T, typename Enable = void>
struct trait;

template <typename T>
struct trait<T, std::enable_if_t<std::is_trivial<T>::value>> {
    // ...
};
```

This enables the specialization to depend on an arbitrary compile-time boolean
expression (in fact on the syntactic validity of an arbitrary expression).
Note that all partial specializations using the enabler must have mutually
exclusive conditions or the specialization will be ambiguous; this can be
tricky at times. A variant of this trick is to use a default type of `true_`
instead of `void` for the dummy template parameter. That makes it possible to
leave the `std::enable_if_t` part for most use cases:

```cpp
template <typename T, typename Enable = true_>
struct trait;

template <typename T>
struct trait<T, bool_<std::is_trivial<T>::value>> {
    // ...
};
```

> Note that we used `bool_<...>` instead of `std::is_trivial<T>::type` because
> the latter is `std::true_type`, which is not necessarily the same as `true_`.
>
> Also, we don't use a straight `bool` for the enabler because partial
> specializations cannot have dependent non-type template arguments.

Since this functionality can really be useful, it might be a good idea to
support it in the `head_impl` lifted metafunction. Fortunately, that only
requires changing the `head_impl` forward declaration to:

```cpp
template <typename Datatype, typename = true_>
struct head_impl;
```

> __TODO__: Provide a use case where this is useful.

In this section, we went through the process of designing a simple yet
powerful way of dispatching metafunctions. The subset of metafunctions
using this dispatching technique are called __methods__ in the MPL11.

> __TODO__: Tackle binary operators and mixed-datatype dispatch.


### Typeclasses
Typeclasses come from the observation that some methods are naturally related
to each other. For example, take the `head`, `tail` and `is_empty` methods.
When implementing any of these three methods, it is probable that the other
two should also be implemented. Hence, it would be logical to group them in
some way; that is the job of typeclasses. However, typeclasses are much more
than mere method bundles. They provide a clean way of specifying and extending
the interface of a datatype through a process called typeclass instantiation.

Let's make a typeclass out of the `head`, `tail` and `is_empty` methods.
Datatypes supporting all three methods look somewhat like `List`s; hence
we will call the typeclass `Iterable`. We start by grouping the `*_impl`
lifted metafunctions of the methods together under the `Iterable` banner.
In the following code snippets, the `tail` and `is_empty` methods will be
omitted when illustrating `head` suffices.

```cpp
struct Iterable {
    template <typename Datatype, typename = true_>
    struct head_impl;

    // ...
};

template <typename Iter>
struct head
    : Iterable::head_impl<typename datatype<typename Iter::type>::type>::
      template apply<typename Iter::type>
{ };

// ...
```

To implement the methods for `List`, we now have to write:

```cpp
template <>
struct Iterable::head_impl<List> {
    template <typename the_list>
    struct apply {
        // ...
    };
};
```

Soon enough, we notice that we can regroup the datatype parametrization on
`Iterable` instead of leaving it on each nested lifted metafunction.

```cpp
template <typename Datatype, typename = true_>
struct Iterable {
    struct head_impl;

    // ...
};

template <typename Iter>
struct head
    : Iterable<typename datatype<typename Iter::type>::type>::
      head_impl::template apply<typename Iter::type>
{ };

// ...
```

The next logical step is to prune the superfluous indirection through the
`*_impl` lifted metafunctions and to simply make them metafunctions.

```cpp
template <typename Datatype, typename = true_>
struct Iterable {
    template <typename Iter>
    struct head_impl;

    // ...
};

template <typename Iter>
struct head
    : Iterable<typename datatype<typename Iter::type>::type>::
      template head_impl<typename Iter::type>
{ };

// ...
```

Since it might be useful to query whether a datatype supports the operations
of `Iterable`, we would like to have a boolean metafunction that does just
that. Fortunately, we can use the `Iterable` for this task with a small
modification.

```cpp
template <typename Datatype, typename = true_>
struct Iterable : false_ {
    // ...
};
```

By default, `Iterable` is therefore also a boolean metafunction returning
`false`, meaning that arbitrary datatypes don't implement the `head`, `tail`
and `is_empty` metafunctions. In its current form, the `Iterable` template is
called a __typeclass__, and metafunctions like `head` following this
dispatching pattern through a typeclass are called __typeclass methods__.
In order to implement `head` and friends, one would now write

```cpp
template <>
struct Iterable<List> : true_ {
    template <typename the_list>
    struct head_impl {
        // ...
    };

    // ...
};

static_assert(Iterable<List>{}, "List is an Iterable!");
```

The three methods `Iterable` contains so far are very basic; for any given
datatype, it is not possible to provide a suitable default implementation.
However, there are other metafunctions that can be implemented in terms of
these three basic blocks. For example, consider the `last` metafunction that
returns the last element of an `Iterable`. A possible implementation would be:

```cpp
template <typename iter>
struct last
    : if_<is_empty<tail<iter>>,
        head<iter>,
        last<tail<iter>>
    >
{ };
```

While we could provide this metafunction as-is, some datatypes might be able
to provide a more efficient implementation. Therefore, we would like to make
it a method, but one that can be defaulted to the above.

> Note that method dispatching incurs some compile-time overhead; hence there
> is a tradeoff between using (typeclass) methods and regular metafunctions.
> The rule of thumb is that if a method is likely to never be specialized
> (i.e. the default implementation is almost always the best), then it should
> probably be a regular metafunction.

It turns out that providing a default implementation can be done easily using
typeclasses and a little convention. First, we make `last` a normal typeclass
method.

```cpp
template <typename Iter>
struct last
    : Iterable<typename datatype<typename Iter::type>::type>::
      template last_impl<typename Iter::type>
{ };
```

Then, we require specializations of `Iterable` to inherit some special type
as follows:

```cpp
template <>
struct Iterable<List> : instantiate<Iterable>::with<List> {
    // ...
};
```

Here, `instantiate<...>::with<...>` is `true_` by default. Hence, it only
takes care of making `Iterable` a true-valued boolean metafunction, which we
did by ourselves previously. However, `instantiate` may be specialized by
typeclass designers in such a way that the member template `with` also
contains default methods. In our case, we would provide a `last_impl`
metafunction corresponding to the default implementation of `last` shown
above. This way, if a datatype does not implement the `last` method, our
default implementation will be used.

```cpp
namespace boost { namespace mpl11 {
    template <>
    struct instantiate<Iterable> {
        template <typename Datatype>
        struct with : true_ {
            template <typename Iter>
            struct last_impl {
                // default implementation
            };
        };
    };
}}
```

This technique provides a lot more flexibility. One notable improvement is the
ability to add new methods to `Iterable` without breaking existing client code,
provided the new methods have a default implementation. Hence, in the MPL11,
all typeclass specializations are required to use this technique, regardless
of whether they actually need defaulted methods.

> You might wonder why we use `instantiate<Typeclass>::with<Datatypes...>`
> instead of just using `instantiate<Typeclass>`. This is because some
> typeclasses need to know the datatype(s) they operate on to provide
> meaningful defaults. Also, we don't use `instantiate<Typeclass, Datatypes...>`
> because that would make defaulted typeclass parameters hard to handle.

A typeclass specialization using the technique we just saw is called a
__typeclass instantiation__. When a typeclass instantiation exists for
a typeclass `T` and a datatype `D`, we say that `D` is an __instance__ of
`T`. Equivalently, we say that `D` __instantiates__ `T`, or sometimes that
`D` __is a__ `T`. The set of definitions that _must_ be provided for a
typeclass to be complete is called the __minimal complete definition__ of
the typeclass. The minimal complete definition is typically the set of methods
without a default implementation, but it must be documented for each typeclass.

> The term _typeclass instantiation_ is borrowed from Haskell and should not be
> mistaken with _template instantiation_ even though they share similarities,
> especially in the MPL11.

<!--  -->

> __TODO__
> - Tackle mixed-datatype typeclass-method dispatch


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
need to make every lifted metafunction an instance of the typeclass defining
`apply`. Since lifted metafunctions are very common, that would be very
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
from using `f::apply<>` to invoke a nullary lifted metafunction. We have to use
`apply<f>`, which will then use either `f::apply<>` or `f::apply`. This adds a
template instantiation and an overload resolution to each lifted metafunction
invocation, which significantly slows down compilation. Considering nullary
metafunctions are of limited use anyway (why would you want a function without
arguments in a purely functional setting?), this is not worth the trouble. Also,
note that MPL-style nullary non-template metafunctions fit in the definition of
a boxed type, so they're not completely forgotten.


## Todo list
- [ ] What should we do for default typeclass methods?
      1. We reuse the "official" method and we rebox the arguments.
        ```cpp
        template <typename x, typename y>
        using equal_impl = not_<not_equal<box<x>, box<y>>>;
        ```

      2. We create an "official" unboxed method and we use that.
        ```cpp
        template <typename x, typename y>
        using equal_impl = not_<not_equal_<x, y>>;
        ```
        where `not_equal_` is a non-boxed version of `not_equal`.

      3. We directly forward to the implementation of the method in the
         typeclass.
        ```cpp
        template <typename x, typename y>
        using equal_impl = not_<Comparable<Left, Right>::not_equal_impl<x, y>>;
        ```
- [ ] Implement cross-type typeclasses.
- [ ] Implement associative data structures.
- [ ] Implement a small DSL to implement inline lifted metafunctions (like
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
- [ ] Consider having a wrapper that allows treating template specializations
      as data. Something like sequence operations on template specializations
      and/or tree operations.
- [ ] Consider adding `while_` and `until` metafunctions.
- [ ] Consider ditching `Foreign` and making the default datatype the data
      constructor itself.
- [ ] Consider adding `Either`.
- [ ] Right now, we must include `boost/mpl11/core.hpp` to get the
      `instantiate<>` template in client code. Maybe typeclass headers
      should take care of it. Or maybe `boost/mpl11/core.hpp` should
      never have to be included by clients altogether?
- [ ] Add interoperability with the Boost.MPL, Boost.Fusion and components
      in the `std` namespace.
- [ ] Use `constexpr` to perform numeric computations on homogeneous sequences
      of integral constants.
- [ ] Consider providing data constructors taking unboxed types for convenience.
- [ ] Consider making `int_<>` a simple boxed `int` without a value.
- [ ] Write a rationale for why we don't have parameterized datatypes.
      Or is this possible/useful?
- [ ] Make bool.hpp lighter. In particular, it should probably not depend
      on integer.
- [ ] Design a StaticConstant concept?
- [ ] In the tutorial, when we specialize lifted metafunctions inside the
      `boost::mpl11` namespace, we don't make them boxed. This makes sense
      because they are lifted metafunctions, not boxed lifted metafunctions.
      What should we do? Should we
      1. Make the specializations boxed
      2. Do not take for granted that they are boxed when we use them in the
         library and box them redundantly, which is correct but suboptimal.
      3. Explicitly state that nothing may be specialized inside the
         `boost::mpl11` namespace unless specified otherwise. Then,
         specify what can be specialized on a per-component basis and
         then we apply (2) only to the components that might not be boxed.
- [ ] Consider having a public data constructor for `Foreign`, which would
      simply preserve type identity. Also; might consider changing the name
      of `Foreign`.
- [ ] Consider regrouping the typeclass instantiations of a datatype in the
      datatype itself. This was done in a previous version, but it might have
      some advantages.
- [ ] Consider providing automatic currying for metafunctions.
- [ ] By making some std algorithms constexpr and providing a couple of
      containers with constexpr iterators, would we have constexpr for free
      almost everywhere?
- [ ] Consider making `bool_` a lifted metafunction that behaves like `if_`.
- [ ] Provide a better syntax for casting. Consider `cast<Datatype(expr)>`.
- [ ] Seriously consider making datatypes lifted metafunctions.
- [ ] Consider prototype-based objects?


<!-- Links -->
[Boost.MPL]: http://www.boost.org/doc/libs/1_55_0b1/libs/mpl/doc/index.html
[call-by-value]: http://en.wikipedia.org/wiki/Call_by_value
[Cmake]: http://www.cmake.org
[doxygen-doc]: http://ldionne.github.io/mpl11
[haskell-denot-semantics]: http://en.wikibooks.org/wiki/Haskell/Denotational_semantics
[Haskell]: http://www.haskell.org
[lazy]: http://en.wikipedia.org/wiki/Lazy_evaluation
[mpllibs]: http://github.com/sabel83/mpllibs
[on-iteration]: http://www.informit.com/articles/article.aspx?p=1407357
[wiki-tmp]: http://en.wikipedia.org/wiki/Template_metaprogramming
