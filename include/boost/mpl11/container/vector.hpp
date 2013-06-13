/*!
 * @file
 * This file defines the `boost::mpl11::vector` container.
 */

#ifndef BOOST_MPL11_CONTAINER_VECTOR_HPP
#define BOOST_MPL11_CONTAINER_VECTOR_HPP

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
class vector;

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
}

template <typename ...Elements>
class vector : public vector_detail::make_vector<Elements...> {
    template <std::size_t Position>
    class iterator {
        struct implementation {
            template <template <typename ...> class Impl, typename ...Args>
            struct apply;

            template <typename Iterator>
            struct apply<next, Iterator> {
                using type = iterator<Position + 1>;
            };

            template <typename Iterator>
            struct apply<prior, Iterator> {
                using type = iterator<Position - 1>;
            };

            template <typename Iterator>
            struct apply<deref, Iterator>
                : at_c<vector, Position>
            { };
        };

    public:
        struct mpl11 { using dispatcher = implementation; };
    };

#if 0
    using as_map = typename map_from<
        zip_view<range_c<0, sizeof...(Elements)>, vector>
    >::type;
#endif

    struct implementation {
        template <template <typename ...> class Impl, typename ...Args>
        struct apply;

        template <typename Vector>
        struct apply<begin, Vector> {
            using type = iterator<0>;
        };

        template <typename Vector>
        struct apply<end, Vector> {
            using type = iterator<sizeof...(Elements)>;
        };

        template <typename Vector>
        struct apply<size, Vector>
            : size_t<sizeof...(Elements)>
        { };

        template <typename Vector>
        struct apply<empty, Vector>
            : bool_<sizeof...(Elements) == 0>
        { };

        template <typename Vector>
        struct apply<front, Vector>
            : at_c<Vector, 0>
        {
            static_assert(sizeof...(Elements) > 0,
                "can't use `front` on an empty vector");
        };

        template <typename Vector>
        struct apply<back, Vector>
            : at_c<Vector, sizeof...(Elements) - 1>
        {
            static_assert(sizeof...(Elements) > 0,
                "can't use `back` on an empty vector");
        };

    private:
        template <std::size_t counter, typename ...>
        struct at_impl;

        template <typename First, typename ...Rest>
        struct at_impl<0, First, Rest...> {
            using type = First;
        };

        template <std::size_t pos, typename First, typename ...Rest>
        struct at_impl<pos, First, Rest...>
            : at_impl<pos - 1, Rest...>
        { };

    public:
        template <typename Vector, typename Position>
        struct apply<at, Vector, Position>
            : at_impl<Position::type::value, Elements...>
        { };

        template <typename Vector>
        struct apply<clear, Vector> {
            using type = vector<>;
        };

        template <typename Vector, typename Element>
        struct apply<push_back, Vector, Element> {
            using type = vector<Elements..., Element>;
        };

        template <typename Vector, typename Element>
        struct apply<push_front, Vector, Element> {
            using type = vector<Element, Elements...>;
        };

        template <typename Head, typename ...Tail>
        struct apply<pop_front, vector<Head, Tail...>> {
            using type = vector<Tail...>;
        };

    private:
        template <typename From, typename To>
        struct pop_back_impl;

        template <template <typename ...> class Variadic,
                  typename Head, typename ...Tail,
                  template <typename ...> class Result,
                  typename ...Transferred>
        struct pop_back_impl<Variadic<Head, Tail...>, Result<Transferred...>>
            : pop_back_impl<Variadic<Tail...>, Result<Transferred..., Head>>
        { };

        template <template <typename ...> class Variadic, typename Back,
                  template <typename ...> class Result, typename ...Transferred>
        struct pop_back_impl<Variadic<Back>, Result<Transferred...>> {
            using type = Result<Transferred...>;
        };

    public:
        template <typename Vector>
        struct apply<pop_back, Vector> : pop_back_impl<Vector, vector<>> {
            static_assert(!empty<Vector>::value,
                "can't use `pop_back` on an empty vector");
        };
    };

public:
    struct mpl11 { using dispatcher = implementation; };
};
}}}

#endif // !BOOST_MPL11_CONTAINER_VECTOR_HPP
