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
     * Returns whether `T` is a @ref Placeholder.
     */
    template <typename T>
    struct is_placeholder;

    template <typename T>
    using is_placeholder_t = typename is_placeholder<T>::type;
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_IS_PLACEHOLDER_HPP
