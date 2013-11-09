/*!
 * @file
 * Defines `boost::mpl11::count`.
 */

#ifndef BOOST_MPL11_COUNT_HPP
#define BOOST_MPL11_COUNT_HPP

#include <boost/mpl11/fwd/count.hpp>

#include <boost/mpl11/count_if.hpp>
#include <boost/mpl11/equal.hpp>


namespace boost { namespace mpl11 {
    namespace count_detail {
        template <typename Element>
        struct is_equal_to {
            template <typename Other>
            struct apply
                : equal<Element, Other>
            { };
        };
    } // end namespace count_detail

    //! @todo Use lambda here when it's ready.
    template <typename Sequence, typename Element>
    struct count
        : count_if<Sequence, count_detail::is_equal_to<Element>>
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_COUNT_HPP
