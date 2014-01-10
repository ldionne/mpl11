/*!
 * @file
 * Defines `boost::mpl11::take_while`.
 */

#ifndef BOOST_MPL11_ITERABLE_TAKE_WHILE_HPP
#define BOOST_MPL11_ITERABLE_TAKE_WHILE_HPP

#include <boost/mpl11/fwd/iterable.hpp>

#include <boost/mpl11/apply.hpp>
#include <boost/mpl11/empty_sequence.hpp>
#include <boost/mpl11/if.hpp>
#include <boost/mpl11/iterable/cons.hpp>
#include <boost/mpl11/not.hpp>
#include <boost/mpl11/or.hpp>


namespace boost { namespace mpl11 {
    template <typename Pred, typename Iter>
    struct take_while
        : if_c<is_empty<Iter>::type::value,
            Iter
        , else_if<apply<Pred, head<Iter>>,
            cons<head<Iter>, take_while<Pred, tail<Iter>>>,
            empty_sequence
        >>
    { };

    namespace rules {
        template <typename Pred, typename Iter>
        struct is_empty_impl<take_while<Pred, Iter>>
            : or_<is_empty<Iter>, not_<apply<Pred, head<Iter>>>>
        { };
    }
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_ITERABLE_TAKE_WHILE_HPP
