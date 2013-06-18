/*!
 * @file
 * This file defines the `boost::mpl11::vector` container.
 */

#ifndef BOOST_MPL11_CONTAINER_VECTOR_HPP
#define BOOST_MPL11_CONTAINER_VECTOR_HPP

#include <boost/mpl11/bool.hpp>
#include <boost/mpl11/detail/default_implementation.hpp>
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
            template <typename Operation, typename ...Args>
            struct apply
                : detail::default_implementation<Operation, iterator, Args...>
            { };

            template <typename ...Ignore>
            struct apply<intrinsic::next, Ignore...> {
                using type = iterator<Position + 1>;
            };

            template <typename ...Ignore>
            struct apply<intrinsic::prior, Ignore...> {
                using type = iterator<Position - 1>;
            };

            template <typename ...Ignore>
            struct apply<intrinsic::deref, Ignore...>
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
        template <typename Operation, typename ...Args>
        struct apply
            : detail::default_implementation<Operation, vector, Args...>
        { };

        template <typename ...Ignore>
        struct apply<intrinsic::begin, Ignore...> {
            using type = iterator<0>;
        };

        template <typename ...Ignore>
        struct apply<intrinsic::end, Ignore...> {
            using type = iterator<sizeof...(Elements)>;
        };

        template <typename ...Ignore>
        struct apply<intrinsic::size, Ignore...>
            : size_t<sizeof...(Elements)>
        { };

        template <typename ...Ignore>
        struct apply<intrinsic::empty, Ignore...>
            : bool_<sizeof...(Elements) == 0>
        { };

        template <typename ...Ignore>
        struct apply<intrinsic::front, Ignore...>
            : at_c<vector, 0>
        {
            static_assert(!empty<vector>::value,
                "can't use `front` on an empty vector");
        };

        template <typename ...Ignore>
        struct apply<intrinsic::back, Ignore...>
            : at_c<vector, sizeof...(Elements) - 1>
        {
            static_assert(!empty<vector>::value,
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
        template <typename Position>
        struct apply<intrinsic::at, Position>
            : at_impl<Position::type::value, Elements...>
        {
            static_assert(Position::type::value < size<vector>::value,
                "trying to access a vector at an index that is out of bound");
        };

        template <typename ...Ignore>
        struct apply<intrinsic::clear, Ignore...> {
            using type = vector<>;
        };

        template <typename Element>
        struct apply<intrinsic::push_back, Element> {
            using type = vector<Elements..., Element>;
        };

        template <typename Element>
        struct apply<intrinsic::push_front, Element> {
            using type = vector<Element, Elements...>;
        };

    private:
        template <typename Vector>
        struct pop_front_impl;

        template <typename Head, typename ...Tail>
        struct pop_front_impl<vector<Head, Tail...>> {
            using type = vector<Tail...>;
        };

    public:
        template <typename ...Ignore>
        struct apply<intrinsic::pop_front, Ignore...>
            : pop_front_impl<vector>
        {
            static_assert(!empty<vector>::value,
                "can't use `pop_front` on an empty vector");
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
        template <typename ...Ignore>
        struct apply<intrinsic::pop_back, Ignore...>
            : pop_back_impl<vector, vector<>>
        {
            static_assert(!empty<vector>::value,
                "can't use `pop_back` on an empty vector");
        };
    };

public:
    struct mpl11 { using dispatcher = implementation; };
};
}}}

#endif // !BOOST_MPL11_CONTAINER_VECTOR_HPP
