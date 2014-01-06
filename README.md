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


## Rationales
This is a list of rationales for some design decisions I made. If you have a
good reason to think that something is wrong, _please_ open an issue so we can
discuss and improve the library.

### Why do we provide a *_t alias even for integral metafunctions?
This question amounts to asking whether it might be desirable to use
integral metafunctions eagerly. If the answer is yes, then we should
definitely provide *_t aliases like for normal metafunctions. It turns
out that the answer is yes, because some operations (like logical operations)
can be optimized when we operate on `integral_c`s directly, i.e. when we
operate on `is_empty<S>::%type` instead of `is_empty<S>`, for example.


### Why does `new_` take a sequence instead of variadic arguments?
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


### Why aren't `and_`, `or_` and `not_` methods?
These used to be methods, but I did not see any use case and it added some
complexity, so it was removed. If you have what you think is a valid use case,
feel free to open an issue so we can discuss.


### Do not return a `Maybe`-like type from `at_key`
If we returned a `Maybe` from `at_key`, we would always have to use at_key
like so:

    if_<at_key<Map, Key>::type,
        use the result,
        do some default action
    >

This has several drawbacks:

1. It's cumbersome
2. You have to use `at_key<Map, Key>::%type` to refer the result and then get
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



### Todo
- Find a way to have fast arithmetic operations on sequences of
  StaticConstants. I think vectorized sum is the most basic instance
  of count_if: count_if adds 1 or 0 depending on the Predicate

- Consider replacing `insert_*` by `insert_at`, `insert_range_at`, `erase_at`.

- Consider taking advantage of operation commutativity when folding. Must see
  if a gain is possible.

- Consider renaming the Couple concept.

- add more default implementations of container operations using `new_`?


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
