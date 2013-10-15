/*!
 * @file
 * Defines `boost::mpl11::equal_to`.
 */

#ifndef BOOST_MPL11_EQUAL_TO_HPP
#define BOOST_MPL11_EQUAL_TO_HPP

#include <boost/mpl11/fwd/equal_to.hpp>

#include <boost/mpl11/and.hpp>
#include <boost/mpl11/apply_wrap.hpp>
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
struct dispatch<tag::equal_to, T1, T2, Tn...>
    : and_<
        equal_to<T1, T2>,
        equal_to<T2, Tn...>
    >
{ };

template <typename T1, typename T2>
struct dispatch<tag::equal_to, T1, T2>
    : apply_wrap<
        dispatch<
            tag::by_category<tag::equal_to>,
            typename category_of<T1>::type
        >,
        T1, T2
    >
{
    //! @bug This should be equal_to or something similar, but that would
    //!      cause an obvious infinite recursion problem.
    static_assert(detail::is_same<
                    typename category_of<T1>::type,
                    typename category_of<T2>::type
                  >::type::value,
    "Trying to compare two types with different categories.");
};

template <>
struct dispatch<tag::by_category<tag::equal_to>, category::none> {
    template <typename T1, typename T2>
    struct apply
        : detail::is_same<T1, T2>
    { };
};

template <>
struct dispatch<tag::by_category<tag::equal_to>, category::forward_sequence> {
    template <typename S1, typename S2>
    struct apply
        : equal<S1, S2> // use element-wise equality
    { };
};

namespace equal_to_detail {
    template <typename T1, typename T2>
    struct lazy_equal_to
        : equal_to<typename T1::type, typename T2::type>
    { };
} // end namespace equal_to_detail

template <>
struct dispatch<tag::by_category<tag::equal_to>,
                category::associative_sequence> {
    template <typename S1, typename S2>
    class apply {
        using Last1 = typename end<S1>::type;

        template <typename First1,
                  bool = equal_to<First1, Last1>::type::value>
        struct impl;

        template <typename First1>
        struct impl<First1, true>
            : identity<true_>
        { };

        template <typename First1>
        struct impl<First1, false> {
            using Element = typename deref<First1>::type;
            using Key = typename key_of<S1, Element>::type;

            using type = typename and_<
                has_key<S2, Key>,
                equal_to_detail::lazy_equal_to<
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
            impl<typename begin<S1>::type>
        >::type;
    };
};

template <>
struct dispatch<tag::by_category<tag::equal_to>, category::integral_constant> {
    template <typename I, typename J>
    struct apply
        : identity<
            bool_<I::value == J::value>
        >
    { };
};
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_EQUAL_TO_HPP
