/*!
 * @file
 * Defines `boost::mpl11::detail::box`.
 */

#ifndef BOOST_MPL11_DETAIL_BOX_HPP
#define BOOST_MPL11_DETAIL_BOX_HPP

namespace boost { namespace mpl11 { namespace detail {
    /*!
     * @ingroup details
     *
     * Wraps a type so it becomes usable in lazy metafunctions.
     */
    template <typename T>
    struct box {
        using type = T;
    };
}}} // end namespace boost::mpl11::detail

#endif // !BOOST_MPL11_DETAIL_BOX_HPP
