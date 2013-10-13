/*!
 * @file
 * Forward declares `boost::mpl11::as_placeholder`.
 */

#ifndef BOOST_MPL11_FWD_AS_PLACEHOLDER_HPP
#define BOOST_MPL11_FWD_AS_PLACEHOLDER_HPP

namespace boost { namespace mpl11 {
    /*!
     * @ingroup functional
     *
     * Wraps an arbitrary type to make it into a @ref Placeholder.
     *
     * Specifically, `as_placeholder<T>` is a type publically derived from
     * `T` for which the `is_placeholder` metafunction returns `true_`.
     */
    template <typename T>
    struct as_placeholder;
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_AS_PLACEHOLDER_HPP
