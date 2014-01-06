/*!
 * @file
 * Defines `boost::mpl11::detail::complete`.
 */

#ifndef BOOST_MPL11_DETAIL_COMPLETE_HPP
#define BOOST_MPL11_DETAIL_COMPLETE_HPP

namespace boost { namespace mpl11 { namespace detail {
    /*!
     * @ingroup details
     *
     * Variadic template with a trivial definition.
     */
    template <typename ...>
    struct complete { };
}}} // end namespace boost::mpl11::detail

#endif // !BOOST_MPL11_DETAIL_COMPLETE_HPP
