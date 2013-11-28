/*!
 * @file
 * Forward declares `boost::mpl11::is_placeholder`.
 */

#ifndef BOOST_MPL11_FWD_IS_PLACEHOLDER_HPP
#define BOOST_MPL11_FWD_IS_PLACEHOLDER_HPP

namespace boost { namespace mpl11 {
    /*!
     * @ingroup metafunctions
     *
     * Returns whether `T` is a `Placeholder`.
     *
     * The default implementation of this metafunction is equivalent to
     * `false_`.
     */
    template <typename T>
    struct is_placeholder;

#ifdef BOOST_MPL11_DOXYGEN_INVOKED
    /*!
     * @ingroup concepts
     *
     * `MetafunctionClass` that is implicitly considered as a local variable
     * in `LetExpression`s.
     *
     * A `Placeholder` is a `MetafunctionClass` whose name can't be bound
     * explicitly in a `LetExpression`. The value of a `Placeholder` `P`
     * inside a `LetExpression` is the result of invoking `P` with the
     * arguments passed to the `LetExpression` when it is invoked.
     *
     * The library predefines some `Placeholder`s that are of general
     * interest. By convention, their name always start with a single
     * underscore (`_`) to make them stand out.
     *
     * Using `Placeholder`s outside of `LetExpression`s is __strongly__
     * discouraged. Template specializations in which `Placeholder`s appear
     * may not be used freely inside `LetExpression`s, because they will be
     * evaluated recursively. Inside template code, this can lead to subtle
     * compile-time errors that will certainly generate heaps of unreadable
     * error messages. You have been warned.
     *
     * @note
     * Within this documentation, the terms `Placeholder` and "implicit
     * local variable" refer to the same concept unless explicitly stated
     * otherwise.
     *
     * @note
     * This concept only lives in the documentation. There exists no such
     * `struct` in the library.
     */
    struct Placeholder { };
#endif
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_IS_PLACEHOLDER_HPP
