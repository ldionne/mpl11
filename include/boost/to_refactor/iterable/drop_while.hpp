/*!
 * @file
 * Defines `boost::mpl11::drop_while`.
 */

#ifndef BOOST_MPL11_ITERABLE_DROP_WHILE_HPP
#define BOOST_MPL11_ITERABLE_DROP_WHILE_HPP

#include <boost/mpl11/fwd/iterable.hpp>

#include <boost/mpl11/apply.hpp>
#include <boost/mpl11/foldable/all.hpp>
#include <boost/mpl11/if.hpp>


namespace boost { namespace mpl11 {
    template <typename Pred, typename Iter>
    struct drop_while :
        if_<is_empty<Iter>,
            Iter,
        else_if<apply<Pred, head<Iter>>,
            drop_while<Pred, tail<Iter>>,
        else_<
            Iter
        >>>
    { };

    namespace rules {
        template <typename Pred, typename Iter>
        struct is_empty_impl<drop_while<Pred, Iter>> : all<Pred, Iter> { };
    }
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_ITERABLE_DROP_WHILE_HPP
