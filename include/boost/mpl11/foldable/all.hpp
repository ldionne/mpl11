/*!
 * @file
 * Defines `boost::mpl11::all`.
 */

#ifndef BOOST_MPL11_FOLDABLE_ALL_HPP
#define BOOST_MPL11_FOLDABLE_ALL_HPP

#include <boost/mpl11/fwd/foldable.hpp>

#include <boost/mpl11/and.hpp>
#include <boost/mpl11/apply.hpp>
#include <boost/mpl11/integral_c.hpp>


namespace boost { namespace mpl11 {
    namespace all_detail {
        template <typename Predicate>
        struct all_pred {
            using type = all_pred;

            template <typename Elem, typename LazyState>
            using apply = and_<mpl11::apply<Predicate, Elem>, LazyState>;
        };
    }

    template <typename Predicate, typename Structure>
    struct all
        : foldr<all_detail::all_pred<Predicate>, true_, Structure>::type
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FOLDABLE_ALL_HPP
