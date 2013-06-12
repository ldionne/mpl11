/*!
 * @file
 * This file defines the `boost::mpl11::vector` container.
 */

#ifndef BOOST_MPL11_VECTOR_HPP
#define BOOST_MPL11_VECTOR_HPP

#include <boost/mpl11/bool.hpp>
#include <boost/mpl11/intrinsic/at.hpp>
#include <boost/mpl11/intrinsic/back.hpp>
#include <boost/mpl11/intrinsic/begin.hpp>
#include <boost/mpl11/intrinsic/clear.hpp>
#include <boost/mpl11/intrinsic/deref.hpp>
#include <boost/mpl11/intrinsic/empty.hpp>
#include <boost/mpl11/intrinsic/end.hpp>
#include <boost/mpl11/intrinsic/front.hpp>
#include <boost/mpl11/intrinsic/next.hpp>
#include <boost/mpl11/intrinsic/pop_back.hpp>
#include <boost/mpl11/intrinsic/pop_front.hpp>
#include <boost/mpl11/intrinsic/prior.hpp>
#include <boost/mpl11/intrinsic/push_back.hpp>
#include <boost/mpl11/intrinsic/push_front.hpp>
#include <boost/mpl11/intrinsic/size.hpp>
#include <boost/mpl11/size_t.hpp>

#include <cstddef>


namespace boost { namespace mpl11 { inline namespace v2 {
template <typename ...Elements>
struct vector;

namespace vector_detail {
    template <typename ...Elements>
    struct make_vector {
        using type = vector<Elements...>;
    };

#if 0
    template <typename First, typename Last, typename = typename
        enable_if<and_<is_iterator<First>, is_iterator<Last>>>::type>
    struct make_vector<First, Last>
        : copy<First, Last, back_inserter<vector<>>>
    { };

    template <typename Sequence, typename = typename
        enable_if<is_sequence<Sequence>>::type>
    struct make_vector<Sequence>
        : vector<
            typename begin<Sequence>::type,
            typename end<Sequence>::type
        >
    { };
#endif

    template <typename Vector, std::size_t Position>
    struct vector_iterator {
        struct mpl11 { using tag = vector_iterator; };
    };
}

template <typename ...Elements>
struct vector : vector_detail::make_vector<Elements...> {
private:
    // using as_map = typename map_from<
    //     zip_view<range_c<0, sizeof...(Elements)>, vector>
    // >::type;
    friend extension::at_impl<vector>;

public:
    struct mpl11 { using tag = vector; };
};

namespace extension {
    template <typename Vector, std::size_t Position>
    struct next_impl<vector_detail::vector_iterator<Vector, Position>> {
        template <typename Iterator>
        struct apply {
            using type = vector_detail::vector_iterator<Vector, Position + 1>;
        };
    };

    template <typename Vector, std::size_t Position>
    struct prior_impl<vector_detail::vector_iterator<Vector, Position>> {
        template <typename Iterator>
        struct apply {
            using type = vector_detail::vector_iterator<Vector, Position - 1>;
        };
    };

    template <typename Vector, std::size_t Position>
    struct deref_impl<vector_detail::vector_iterator<Vector, Position>> {
        template <typename Iterator>
        struct apply : at_c<Vector, Position> { };
    };

    template <typename ...Elements>
    struct begin_impl<vector<Elements...>> {
        template <typename Vector>
        struct apply {
            using type = vector_detail::vector_iterator<Vector, 0>;
        };
    };

    template <typename ...Elements>
    struct end_impl<vector<Elements...>> {
        template <typename Vector>
        struct apply {
            using type = vector_detail::vector_iterator<
                Vector, size<Vector>::value
            >;
        };
    };

    template <typename ...Elements>
    struct size_impl<vector<Elements...>> {
        template <typename Vector>
        struct apply
            : size_t<sizeof...(Elements)>
        { };
    };

    template <typename ...Elements>
    struct empty_impl<vector<Elements...>> {
        template <typename Vector>
        struct apply
            : bool_<sizeof...(Elements) == 0>
        { };
    };

    template <typename ...Elements>
    struct front_impl<vector<Elements...>> {
        template <typename Vector>
        struct apply : at_c<Vector, 0> { };
    };

    template <typename ...Elements>
    struct back_impl<vector<Elements...>> {
        template <typename Vector>
        struct apply : at_c<Vector, sizeof...(Elements) - 1> { };
    };

    template <typename ...Elements>
    struct at_impl<vector<Elements...>> {
        template <typename Vector, typename Position>
        struct apply
            : at<typename Vector::as_map, Position>
        { };
    };

    template <typename ...Elements>
    struct clear_impl<vector<Elements...>> {
        template <typename Vector>
        struct apply {
            using type = vector<>;
        };
    };

    template <typename ...Elements>
    struct push_back_impl<vector<Elements...>> {
        template <typename Vector, typename Element>
        struct apply {
            using type = vector<Elements..., Element>;
        };
    };

    template <typename ...Elements>
    struct pop_back_impl<vector<Elements...>> {
        template <typename Vector, bool make_dependent = false>
        struct apply {
            static_assert(make_dependent, "implement me");
        };
    };

    template <typename ...Elements>
    struct push_front_impl<vector<Elements...>> {
        template <typename Vector, typename Element>
        struct apply {
            using type = vector<Element, Elements...>;
        };
    };

    template <typename ...Elements>
    struct pop_front_impl<vector<Elements...>> {
        template <typename Vector> struct apply;

        template <typename First, typename ...Rest>
        struct apply<vector<First, Rest...>> {
            using type = vector<Rest...>;
        };
    };
}
}}}

#endif // !BOOST_MPL11_VECTOR_HPP
