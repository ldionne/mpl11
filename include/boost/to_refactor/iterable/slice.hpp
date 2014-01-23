/*!
 * @file
 * Defines `boost::mpl11::slice`.
 */

#ifndef BOOST_MPL11_ITERABLE_SLICE_HPP
#define BOOST_MPL11_ITERABLE_SLICE_HPP

#include <boost/mpl11/fwd/iterable.hpp>

#include <boost/mpl11/if.hpp>
#include <boost/mpl11/iterable/drop.hpp>
#include <boost/mpl11/iterable/take.hpp>
#include <boost/mpl11/sequence_traits.hpp>


namespace boost { namespace mpl11 {
    template <typename Iter, typename Start_, typename Stop_>
    struct slice {
    private:
        static constexpr auto Start = Start_::type::value;
        static constexpr auto Stop = Stop_::type::value;

#if defined(BOOST_MPL11_ENABLE_ASSERTIONS)
        static_assert(Start >= 0,
        "Invalid usage of `slice`: The start index must be non-negative.");

        static_assert(Start <= Stop,
        "Invalid usage of `slice`: "
        "The start index must be less-than or equal to the stop index.");

        using Length = if_c<sequence_traits<typename Iter::type>::is_finite,
            length<Iter>,
            Stop_
        >;

        static_assert(Stop <= Length::value,
        "Invalid usage of `slice`: "
        "The stop index is out of the bounds of the iterable.");
#endif

    public:
        using type = typename take_c<Stop - Start, drop_c<Start, Iter>>::type;
    };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_ITERABLE_SLICE_HPP
