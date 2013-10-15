/*!
 * @file
 * Defines `boost::mpl11::equal_to`.
 */

#ifndef BOOST_MPL11_EQUAL_TO_HPP
#define BOOST_MPL11_EQUAL_TO_HPP

#include <boost/mpl11/fwd/equal_to.hpp>

#include <boost/mpl11/and.hpp>
#include <boost/mpl11/at.hpp>
#include <boost/mpl11/begin.hpp>
#include <boost/mpl11/bool.hpp>
#include <boost/mpl11/category/associative_sequence.hpp>
#include <boost/mpl11/category/forward_sequence.hpp>
#include <boost/mpl11/category/integral_constant.hpp>
#include <boost/mpl11/category/none.hpp>
#include <boost/mpl11/category_of.hpp>
#include <boost/mpl11/deref.hpp>
#include <boost/mpl11/detail/is_same.hpp>
#include <boost/mpl11/dispatch.hpp>
#include <boost/mpl11/end.hpp>
#include <boost/mpl11/equal.hpp>
#include <boost/mpl11/has_key.hpp>
#include <boost/mpl11/identity.hpp>
#include <boost/mpl11/key_of.hpp>
#include <boost/mpl11/size.hpp>
#include <boost/mpl11/value_of.hpp>


namespace boost { namespace mpl11 {
template <typename T1, typename T2, typename ...Tn>
struct dispatch<tag::default_<tag::equal_to>, T1, T2, Tn...>
    : and_<
        equal_to<T1, T2>,
        equal_to<T2, Tn...>
    >
{ };

namespace equal_to_detail {
    template <typename T1, typename T2>
    struct integral_constant_equal
        : identity<
            bool_<T1::value == T2::value>
        >
    { };

    template <typename T1, typename T2>
    struct lazy_equal_to
        : equal_to<typename T1::type, typename T2::type>
    { };

    template <typename S1, typename S2>
    class associative_sequence_equal {
        template <typename First1,
                  bool = equal_to<First1, typename end<S1>::type>::type::value>
        struct apply;

        template <typename First1>
        struct apply<First1, true>
            : identity<true_>
        { };

        template <typename First1>
        struct apply<First1, false> {
            using Element = typename deref<First1>::type;
            using Key = typename key_of<S1, Element>::type;

            using type = typename and_<
                has_key<S2, Key>,
                lazy_equal_to<
                    value_of<S1, Element>,
                    at<S2, Key>
                >
            >::type;
        };

    public:
        using type = typename and_<
            equal_to<
                typename size<S1>::type,
                typename size<S2>::type
            >,
            apply<typename begin<S1>::type>
        >::type;
    };

    template <typename T1, typename T2>
    auto pick(category::none*, category::none*)
        -> detail::is_same<T1, T2>
    ;

    template <typename T1, typename T2>
    auto pick(category::integral_constant*, category::integral_constant*)
        -> integral_constant_equal<T1, T2>
    ;

    template <typename T1, typename T2>
    auto pick(category::forward_sequence*, category::forward_sequence*)
        -> algorithm::equal<T1, T2>
    ;

    template <typename T1, typename T2>
    auto pick(category::associative_sequence*, category::associative_sequence*)
        -> associative_sequence_equal<T1, T2>
    ;
} // end namespace equal_to_detail

template <typename T1, typename T2>
struct dispatch<tag::default_<tag::equal_to>, T1, T2>
    : decltype(equal_to_detail::pick<T1, T2>(
        (typename category_of<T1>::type*)nullptr,
        (typename category_of<T2>::type*)nullptr
    ))
{ };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_EQUAL_TO_HPP
