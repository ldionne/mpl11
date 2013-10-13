/*!
 * @file
 * Defines `boost::mpl11::push_back`.
 */

#ifndef BOOST_MPL11_ALGORITHM_PUSH_BACK_HPP
#define BOOST_MPL11_ALGORITHM_PUSH_BACK_HPP

#include <boost/mpl11/algorithm/push_back_fwd.hpp>
#include <boost/mpl11/dispatch.hpp>
#include <boost/mpl11/identity.hpp>
#include <boost/mpl11/view/joined.hpp>
#include <boost/mpl11/view/single_element.hpp>


namespace boost { namespace mpl11 {
    template <typename Sequence, typename Element>
    struct dispatch<tag::default_<tag::push_back>, Sequence, Element>
        : identity<
            view::joined<Sequence, view::single_element<Element>>
        >
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_ALGORITHM_PUSH_BACK_HPP
