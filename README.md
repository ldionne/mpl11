# mpl11 - a C++11 remake of the Boost.MPL


## Disclaimer
This is not an official Boost library. It might be proposed as a replacement
for the MPL in the future, but there is no guarantee.

The code is unstable at the moment; do not use for production.


## Requirements
A conformant C++11 compiler (a conformant C++11 standard library
is _not_ required).


## Getting started
The __mpl11__ is a header only library. Just add the _include_ directory to
your compiler's search path and you are good to go.


## Reference documentation
Available [here](http://ldionne.github.io/mpl11).


## Compiling the tests and examples
To do this, you will also need to have CMake installed. If this is the case,
you can go to the root of the project and issue:

    $ mkdir build
    $ cd build
    $ cmake ..
    $ make unit     # Compiles the tests. All tests are compile-time only.
    $ make example  # Compiles the examples.
    $ make          # Compiles the tests and the examples.


## Open design questions
This is a list of design issues that I currently have. If you happen to be
reading this and if you have interesting insight about something on this
list (or something that should be on this list), __please__ open an issue so
we can discuss.


### How do we propagate optimizations?
Is it possible to have those two below automatically? Using adaptors maybe?

    template <typename Sequence, typename F>
    struct has_optimization<transform<Sequence, F>, optimization::O1_size>
        : has_optimization<Sequence, optimization::O1_size>
    { };

    template <typename Sequence, typename F>
    struct has_optimization<transform<Sequence, F>, optimization::O1_unpack>
        : has_optimization<Sequence, optimization::O1_unpack>
    { };

Pitfall: If we propagate the O1_unpack optimization, since unpack is not an
intrinsic, it is not specialized by the adaptor automatically. So the adaptor
should specialize unpack manually, which is not practical.


### Multiple-dispatch everlasting problem
Here is approximately what they do in the current MPL.
Let Operation be the operator that we're implementing. We have:

    template <typename OperationTag, typename Tag1, typename Tag2>
    struct dispatch<OperationTag, Tag1, Tag2> {
        template <typename T1, typename T2>
        struct apply
            : if_<less<Tag1, Tag2>,
                Operation<T1, typename cast<Tag2, Tag1>::template apply<T2>::type>,
                Operation<typename cast<Tag1, Tag2>::template apply<T1>::type, T2>
            >::type
        { };
    };

Or, in a more general way (but maybe completely retarded; we'll see):
We take for granted that all arguments are useful for dispatching, which should
be the case for operators but not necessarily for every multimethod.

    template <typename OperationTag, typename Tag1, typename ...TagN>
    struct dispatch<OperationTag, Tag1, TagN...> {
        template <typename T1, typename ...Tn>
        struct apply {
            using CommonTag = typename min<Tag1, TagN...>::type;
            using type = typename Operation<
                typename cast<Tag1, CommonTag>::template apply<T1>::type,
                typename cast<TagN, CommonTag>::template apply<Tn>::type...
            >::type;
        };
    };


### What concept should lazy sequences model?
Maybe they should model more than just Sequence? However, if we support more
than just sequence_adaptor, we must specialize more operations. For example,
for directional sequences, we should specialize front_impl to transform the
returned result.

What about equal_impl? It is not obvious what to do with this one. We should
specialize it too, but then we should also specialize not_equal_impl. What
implementation can we have for equal_impl and not_equal_impl?

One would first say: I fear it's going to be the same as the default of
DirectionalSequence. If so, then using an adaptor these operations is useless.

However, thinking a bit further brings us to: Can we _really_ implement
equal_impl and not_equal_impl at all? Is the adapted sequence a
DirectionalSequence or an AssociativeSequence?


### Discussion between me and myself: Logical metafunctions and the `Logical` concept
- We can't assume that _all_ Booleans have a nested ::value
  because then we could not have custom Boolean implementations.
  If we assume that they all have a nested ::value, then there's no
  need for customizeable and_, or_ and not_.

- We can ask for Booleans to provide a `conditional` or `if_` method
  to do `if_`'s job, but we still can't say `boolean_metafunction<...>::value`
  nor `boolean_metafunction<...>::type::value`, which is a bit of a pain.

- From the above point we can conclude that at least one of the following
  statements will have to be true:
    (1) All boolean metafunctions have a nested `::value` static constant
        representing the boolean result of the operation.
    (2) All boolean metafunctions return a type (let's say a model of the
        `Boolean` concept) that has a nested `::value` static constant
        representing its boolean value.

- Could we consider having `int_`, `bool_`, etc... be metafunctions that
  convert a type argument to something? So we would do, for example,
  `bool_<some_type>::type`.

- I don't think there's any interest in _not requiring_ `equal`, `not_equal`,
  and other comparison operators to have a nested ::value member. The same
  reasoning goes for `not_`. The only interest is having `or_` and `and_`
  return their argument instead of returning a straight `bool_` everytime.
  However, if we return the argument from `and_` and `or_`, we need a way
  of explicitly converting something that might be returned by `and_` or
  `or_` to a boolean value. Consider the following:

        or_<identity<false_>, identity<struct something>>

  Here, `struct something` is inherited by the `or_`. Therefore, we need
  to be able to consider a `struct something::type` like a boolean and to
  convert it to a boolean value somehow. I'm also not sure whether it is
  reasonable to expect the above `or_` to have a nested `::value` member.
  It seems that whether `or_` has a nesed `::value` member or not depends
  on the nature or `struct something`.


## Rationales
This is a list of rationales for some design decisions that I made. If you
have a good reason to think that I made a bad decision, __please__ open an
issue so we can discuss.


### `new_` takes a sequence instead of variadic arguments
The usefulness of the variadic `new_` for containers was first questioned
when I noticed that it was very easy to emulate it by doing

    apply<new_<Container>, vector<Args...>>

instead of

    apply<new_<Container>, Args...>

Also, if we kept the variadic `new_`, we sometimes had to do

    unpack<Sequence, new_<Container>>

However, the sequence based approach enables the following:

Inside of `new_`, if the container can take advantage of being created by a
variadic pack, it just `unpack`s the sequence and creates itself in O(1). If
the sequence has O(1) `unpack`, then the container is created in O(1).

If the sequence has O(n) `unpack` but the container has O(1) creation from
variadics, the container creation is O(n).

If the container has O(n) creation, then regardless of the `unpack` complexity
for the sequence, the creation is O(n).

The conclusion is that container creation is bounded by the complexity of
filling the container, not by the complexity of `unpack`ing the sequence.


### Allow a default argument in `class_of`, making specialization more painful
It allows us to give a default implementation for some intrinsics to types
that do not have a proper MPL class, without trying to centralize it under
a default type that would contain all those default implementations. Believe
me, I tried both and the default class for all stops to make sense very
quickly.


### Do not return a `Maybe`-like type from `at_key`
If we returned a `Maybe` from `at_key`, we would always have to use at_key
like so:

    if_<at_key<Map, Key>::type,
        use the result,
        do some default action
    >

This has several drawbacks:

1. It's cumbersome
2. You have to use `at_key<Map, Key>::type` to refer the result and then get
   it out the the `Maybe` in some way.
3. The default action will very surely be something that we should not perform
   at all if the key is found in the map. Achieving lazyness might be hard in
   this case.
4. The `at_key<Map, Key, LazyDefaultAction>` seems superior in every way.


## Potential features
This is a list of features that I'm considering. I basically dump my whole
brain here everytime I have an idea that is not obviously stupid.

### Printing MPL objects
Could we make it possible to print objects of the library? Would this even
be useful? For example, you have a bug and you would like to know what is
the type you're getting at some point. You do something like:

    std::cout << mpl11::show<mpl11::vector<int, float, char>>();

or

    mpl11::show<mpl11::vector<int, float, char>>(std::cout);


### Customizeable algorithms and intrinsics
Think about a convention or system to customize algorithms and intrinsics.
Something neat would be to have a way of passing a custom predicate when
using the equal intrinsic on sequences; that would make `equal` as powerful
as the `equal` algo from the original MPL.



### Todo (sorted by the difficulty of the implied design choices):
#### Minor
- Optimize the 1-sized range case in `args<>` by specializing
  `args<First, First + 1>`.

- Implement `drop` and `take` algorithms/lazy sequences.

- Consider renaming `any_of`, `all_of` and `none_of` to `any`, `all`
  and `none`.

- Consider replacing `insert_*` by `insert_at`, `insert_range_at`, `erase_at`.

- Try to reduce code duplication in unit tests using `vector<>`/`map<>`.

- Consider taking advantage of operation commutativity when folding. Must see
  if a gain is possible.

#### Mid
- add more default implementations of container operations using `new_`?

- Consider verifying some pre/post conditions in the operations themselves.

- consider putting the implementation of operations for concepts in the
  header of the operation instead of that of the concept.

- consider making new_ a metafunction. Why is it a metafunction class?
  One argument in favor of making it a metafunction class is to make it
  a more generally useful type constructor.

- implement a repeating sequence? it repeats the same type a certain
  number of time. or would we be better with a way of filling arbitrary
  sequences with a single type?

- Consider defining more defaults, even if they are sometimes in a circular
  dependency. Document those well.

- Rename class_of to typeclass or similar, and document the whole thing
  (concepts, minimal requirements, dispatching, etc...).

- Should we provide *_t aliases for boolean metafunctions?

- Investigate major slowdown in args_take after using join<> instead of
  vector_concat<>. Gotta keep things clean while being as fast as
  vector_concat.


#### Major
- implement multiple dispatch for operators

- consider ditching count_if. instead, maybe a combination of count with
  filter could be used? if count was optimized for filter, we could have
  the same effect?

- find a way to have fast arithmetic operations on sequences of IntegralConstants.
  I think vectorized sum is the most basic instance of count_if:
  count_if adds 1 or 0 depending on the Predicate

- Consider implementing many foldls in terms of a `detail::repeat_until`:
  If we know the Predicate won't be true before n repetitions, we can
  streamline those and then we start checking the Predicate.

- Each Concept could maybe have an adaptor. then, in the views, we could
  simply use the adapted sequence's adaptor. that would give us the maximal
  supported concept automatically. try to find pitfalls with this approach.
  can all concepts have adaptors? more importantly, do we need to maximize
  the concept supported by a view?

- consider having the optimizations part of the interface of a type.
  it would be interesting, if not necessary, to be able to propagate those
  optimizations automatically in some way for example in some adaptors.

- while_ could actually be a sequence that's generated by applying
  a metafunction to an initial state until the predicate is false.

- Should we allow for 0 and 1 arguments in `and_` and `or_`?

- Is it really useful to have Logicals in the end? What does it gives us
  to keep them/remove them?


#### Lambda-related
- how to _not_ evaluate a placeholder expression in a lambda but merely
  perform placeholder substitution?

- how to leave a placeholder expression as-is inside a lambda?
  The obvious solution is to have a `protect` lambda specialization
  but it's also a bit inelegant. Or is it?

- investigate lambda and if_ interactions:

        lambda<if_<_1, do_stuff<_1>, do_other_stuff<_1>>>

  when applying this, will both do_stuff and do_other_stuff be evaluated?
  I think so.. problem!

- How can we use _args in lambda with a metafunction that is not variadic?
  Consider:

      template <typename T1, typename T2>
      struct f;
      using F = lambda<f<_args>>;

  This fails because f requires 2 arguments, but the semantics would
  otherwise be well defined and the intent is clear. How can we do?
