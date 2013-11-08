/*!
 * @file
 * Defines `boost::mpl11::find`.
 */

#ifndef BOOST_MPL11_FIND_HPP
#define BOOST_MPL11_FIND_HPP

#include <boost/mpl11/fwd/find.hpp>

#include <boost/mpl11/equal.hpp>
#include <boost/mpl11/find_if.hpp>


namespace boost { namespace mpl11 {
    namespace find_detail {
        template <typename Element>
        struct is_equal_to {
            template <typename Other>
            struct apply
                : equal<Element, Other>
            { };
        };
    } // end namespace find_detail

    //! @todo Use lambda here once implemented.
    template <typename Sequence, typename Element>
    struct find
        : find_if<Sequence, find_detail::is_equal_to<Element>>
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FIND_HPP
