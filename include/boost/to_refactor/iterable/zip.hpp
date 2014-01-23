/*!
 * @file
 * Defines `boost::mpl11::zip`.
 */

#ifndef BOOST_MPL11_ITERABLE_ZIP_HPP
#define BOOST_MPL11_ITERABLE_ZIP_HPP

#include <boost/mpl11/fwd/iterable.hpp>

#include <boost/mpl11/empty_sequence.hpp>
#include <boost/mpl11/if.hpp>
#include <boost/mpl11/iterable/cons.hpp>
#include <boost/mpl11/list.hpp>
#include <boost/mpl11/or.hpp>
#include <boost/mpl11/quote.hpp>


namespace boost { namespace mpl11 {
    template <>
    struct zip<>
        : empty_sequence
    { };

    template <typename Iter>
    struct zip<Iter>
        : fmap<quote<list>, Iter>
    { };

    template <typename ...Iters>
    struct zip
        : if_<or_<is_empty<Iters>...>,
            empty_sequence,
            cons<
                list<head<Iters>...>,
                zip<tail<Iters>...>
            >
        >
    { };

    namespace rules {
        template <typename ...Iters>
        struct length_impl<zip<Iters...>>
            // We make it strict because we might get some optimization.
            : min<typename length<Iters>::type...>::type
        { };

        //! @todo
        //! Knowing whether `at_c` is fast for the zipped iterables could
        //! allow us to use this implementation only if it's faster than
        //! iterating to the given index.
        template <typename ...Iters, typename Index>
        struct at_impl<zip<Iters...>, Index>
            : list<at<Iters, Index>...>
        { };
    } // end namespace rules

    // template <typename ...Sn>
    // struct sequence_traits<zip<Sn...>> {
    //     static constexpr bool has_O1_length = and_<
    //         bool_<sequence_traits<typename Sn::type>::has_O1_length>...
    //     >::value;

    //     static constexpr bool has_O1_unpack = false;

    //     static constexpr bool is_finite = or_<
    //         bool_<sequence_traits<typename Sn::type>::is_finite>...
    //     >::value;
    // };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_ITERABLE_ZIP_HPP
