/*!
 * @file
 * This file defines `boost::mpl11::detail::index_based_iterator`.
 */

#ifndef BOOST_MPL11_DETAIL_INDEX_BASED_ITERATOR_HPP
#define BOOST_MPL11_DETAIL_INDEX_BASED_ITERATOR_HPP

#include <boost/mpl11/fwd/algorithm.hpp>
#include <boost/mpl11/at.hpp>
#include <boost/mpl11/size.hpp>
#include <boost/mpl11/fwd/intrinsic.hpp>
#include <boost/mpl11/size_t.hpp>


namespace boost { namespace mpl11 { namespace detail {
template <typename Sequence, typename size<Sequence>::value_type N>
struct index_based_iterator {
    struct implementation {
        template <typename Operation, typename ...Args>
        struct apply;

        template <typename ...Ignore>
        struct apply<intrinsic::deref, Ignore...>
            : at_c<N, Sequence>
        { };

        template <typename ...Ignore>
        struct apply<intrinsic::next, Ignore...> {
            static_assert(N + 1 <= size<Sequence>::value,
            "advancing an iterator beyond the end of its sequence");
            using type = index_based_iterator<Sequence, N + 1>;
        };

        template <typename ...Ignore>
        struct apply<intrinsic::prior, Ignore...> {
            static_assert(N - 1 >= 0,
            "rewinding an iterator prior to the beginning of its sequence");
            using type = index_based_iterator<Sequence, N - 1>;
        };

        template <typename Distance>
        struct apply<algorithm::advance, Distance> {
        private:
            static constexpr auto new_pos = Distance::value + N;
            static_assert(new_pos < size<Sequence>::value,
            "advancing an iterator beyond the end of its sequence");

        public:
            using type = index_based_iterator<Sequence, new_pos>;
        };

        template <decltype(N) OtherN>
        struct apply<algorithm::distance,
                     index_based_iterator<Sequence, OtherN>>
        {
            using type = size_t<N - OtherN>;
        };
    };

public:
    struct mpl11 {
        struct is_random_access_iterator;
        using dispatcher = implementation;
    };
};
}}} // end namespace boost::mpl11::detail

#endif // !BOOST_MPL11_DETAIL_INDEX_BASED_ITERATOR_HPP
