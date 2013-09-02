/*!
 * @file
 * Defines `boost::mpl11::integral_c`.
 */

#ifndef BOOST_MPL11_INTEGRAL_C_HPP
#define BOOST_MPL11_INTEGRAL_C_HPP

#include <boost/mpl11/categories.hpp>
#include <boost/mpl11/dispatch.hpp>
#include <boost/mpl11/identity.hpp>
#include <boost/mpl11/inherit.hpp>
#include <boost/mpl11/tags.hpp>


namespace boost { namespace mpl11 {
    template <typename I, I N>
    struct integral_c  : identity<integral_c<I, N>> {
        using value_type = I;
        static constexpr value_type value = N;
        constexpr operator value_type() const { return value; }
    };

    template <typename I, I N>
    struct dispatch<tag::category_of, integral_c<I, N>>
        : inherit<
            category::random_access_iterator,
            category::integral_constant
        >
    { };

    template <typename I, I N>
    struct dispatch<tag::deref, integral_c<I, N>>
        : identity<integral_c<I, N>>
    { };

    template <typename I, I N>
    struct dispatch<tag::next, integral_c<I, N>>
        : identity<integral_c<I, N + 1>>
    { };

    template <typename I, I N>
    struct dispatch<tag::prior, integral_c<I, N>>
        : identity<integral_c<I, N - 1>>
    { };

    template <bool B>
    using bool_ = integral_c<bool, B>;

    template <char C>
    using char_ = integral_c<char, C>;

    template <short N>
    using short_ = integral_c<short, N>;

    template <unsigned short N>
    using ushort = integral_c<unsigned short, N>;

    template <int N>
    using int_ = integral_c<int, N>;

    template <unsigned int N>
    using uint = integral_c<unsigned int, N>;

    template <long N>
    using long_ = integral_c<long, N>;

    template <unsigned long N>
    using ulong = integral_c<unsigned long, N>;
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_INTEGRAL_C_HPP
