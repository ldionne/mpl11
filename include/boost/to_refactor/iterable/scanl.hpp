/*!
 * @file
 * Defines `boost::mpl11::scanl`.
 */

#ifndef BOOST_MPL11_ITERABLE_SCANL_HPP
#define BOOST_MPL11_ITERABLE_SCANL_HPP

#include <boost/mpl11/fwd/iterable.hpp>

#include <boost/mpl11/apply.hpp>
#include <boost/mpl11/if.hpp>
#include <boost/mpl11/integral_c.hpp>
#include <boost/mpl11/iterable/cons.hpp>
#include <boost/mpl11/list.hpp>


namespace boost { namespace mpl11 {
    template <typename F, typename State, typename Iter>
    struct scanl
        : if_<is_empty<Iter>,
            list<State>,
            cons<
                State,
                scanl<F, apply<F, State, head<Iter>>, tail<Iter>>
            >
        >
    { };

    namespace rules {
        template <typename F, typename State, typename Iter>
        struct length_impl<scanl<F, State, Iter>>
            : size_t<length<Iter>::value + 1>
        { };

        template <typename F, typename State, typename Iter>
        struct last_impl<scanl<F, State, Iter>> : foldl<F, State, Iter> { };
    }

    // template <typename F, typename State, typename S>
    // struct sequence_traits<scanl<F, State, S>>
    //     : sequence_traits<typename S::type>
    // {
    //     static constexpr bool has_O1_unpack = false;
    // };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_ITERABLE_SCANL_HPP
