/*!
 * @file
 * Defines `boost::mpl11::slice`.
 */

#ifndef BOOST_MPL11_ITERABLE_SLICE_HPP
#define BOOST_MPL11_ITERABLE_SLICE_HPP

#include <boost/mpl11/fwd/iterable.hpp>

#include <boost/mpl11/detail/std_size_t.hpp>
#include <boost/mpl11/if.hpp>
#include <boost/mpl11/integral_c.hpp>
#include <boost/mpl11/iterable/drop.hpp>
#include <boost/mpl11/iterable/take.hpp>
#include <boost/mpl11/sequence_traits.hpp>


namespace boost { namespace mpl11 {
    template <typename Iter, typename Start, typename Stop>
    struct slice {
#if defined(BOOST_MPL11_ENABLE_ASSERTIONS)
        static_assert(Start::value >= 0,
        "Invalid usage of `slice`: The start index must be non-negative.");

        static_assert(Stop::value >= 0,
        "Invalid usage of `slice`: The stop index must be non-negative.");
#endif

        using type = typename slice_c<Iter, Start::value, Stop::value>::type;
    };

    template <typename It, detail::std_size_t Start, detail::std_size_t Stop>
    struct slice_c {
#if defined(BOOST_MPL11_ENABLE_ASSERTIONS)
    private:
        static_assert(Start <= Stop,
        "Invalid usage of `slice_c`: "
        "The start index must be less-than or equal to the stop index.");

        using Length = if_c<sequence_traits<It>::is_finite,
            length<It>,
            size_t<Stop>
        >;

        static_assert(Stop <= Length::value,
        "Invalid usage of `slice_c`: "
        "The stop index is out of the bounds of the iterable.");

    public:
#endif

        using type = typename take_c<
            Stop - Start,
            typename drop_c<Start, It>::type
        >::type;
    };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_ITERABLE_SLICE_HPP
