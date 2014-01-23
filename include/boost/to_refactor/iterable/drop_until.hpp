/*!
 * @file
 * Defines `boost::mpl11::drop_until`.
 */

#ifndef BOOST_MPL11_ITERABLE_DROP_UNTIL_HPP
#define BOOST_MPL11_ITERABLE_DROP_UNTIL_HPP

#include <boost/mpl11/fwd/iterable.hpp>

#include <boost/mpl11/compose.hpp>
#include <boost/mpl11/foldable/none.hpp>
#include <boost/mpl11/iterable/drop_while.hpp>
#include <boost/mpl11/not.hpp>
#include <boost/mpl11/quote.hpp>


namespace boost { namespace mpl11 { namespace rules {
    template <typename Pred, typename Iter>
    struct is_empty_impl<drop_until<Pred, Iter>> : none<Pred, Iter> { };
}}}

#endif // !BOOST_MPL11_ITERABLE_DROP_UNTIL_HPP
