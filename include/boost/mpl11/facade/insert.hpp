/*!
 * @file
 * This file defines `boost::mpl11::insert` for facades.
 */

#ifndef BOOST_MPL11_FACADE_INSERT_HPP
#define BOOST_MPL11_FACADE_INSERT_HPP

#include <boost/mpl11/detail/none.hpp>
#include <boost/mpl11/facade/base.hpp>
#include <boost/mpl11/intrinsic/insert.hpp>


namespace boost { namespace mpl11 { inline namespace v2 { namespace extension {
    template <typename T, typename = typename if_facade_enabled<T, insert>::type>
    struct insert_impl<facade_tag<T>> {
        template <typename Sequence,
                  typename Position,
                  typename Element = detail::none>
        struct apply
            : Sequence::template insert<Position, Element>
        { };

        template <typename AssociativeSequence, typename Element>
        struct apply<AssociativeSequence, Element, detail::none>
            : AssociativeSequence::template insert<Element>
        { };
    };
}}}}

#endif // !BOOST_MPL11_FACADE_INSERT_HPP
