/*!
 * @file
 * Defines `boost::mpl11::detail::move`.
 */

#ifndef BOOST_MPL11_DETAIL_MOVE_HPP
#define BOOST_MPL11_DETAIL_MOVE_HPP

#include <boost/mpl11/identity.hpp>


namespace boost { namespace mpl11 { namespace detail {
    template <
        template <typename ...> class Next,
        typename Iterator,
        unsigned long N
    >
    struct move
        : move<Next, typename Next<Iterator>::type, N - 1>
    { };

    template <template <typename ...> class Next, typename Iterator>
    struct move<Next, Iterator, 0>
        : identity<Iterator>
    { };
}}} // end namespace boost::mpl11::detail

#endif // !BOOST_MPL11_DETAIL_MOVE_HPP
