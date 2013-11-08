/*!
 * @file
 * Defines `boost::mpl11::contains`.
 */

#ifndef BOOST_MPL11_CONTAINS_HPP
#define BOOST_MPL11_CONTAINS_HPP

#include <boost/mpl11/fwd/contains.hpp>

#include <boost/mpl11/any_of.hpp>
#include <boost/mpl11/equal.hpp>


namespace boost { namespace mpl11 {
    namespace contains_detail {
        template <typename Element>
        struct is_equal_to {
            template <typename Other>
            struct apply
                : equal<Element, Other>
            { };
        };
    } // end namespace contains_detail

    //! @todo Use lambda here once implemented.
    template <typename Sequence, typename Element>
    struct contains
        : any_of<Sequence, contains_detail::is_equal_to<Element>>
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_CONTAINS_HPP

