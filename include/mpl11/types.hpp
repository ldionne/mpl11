/**
 * This file defines meta-types to interact with mpl11.
 * This header is mainly to ease interoperation with different libraries.
 */

#ifndef MPL11_TYPES_HPP
#define MPL11_TYPES_HPP

#include <cstddef>
#include <type_traits>


namespace mpl11 {

using std::integral_constant;

template <char c>
using char_ = integral_constant<char, c>;
template <unsigned char uc>
using uchar_ = integral_constant<unsigned char, uc>;
template <signed char sc>
using schar_ = integral_constant<signed char, sc>;

template <short s>
using short_ = integral_constant<short, s>;
template <unsigned short us>
using ushort_ = integral_constant<unsigned short, us>;

template <int i>
using int_ = integral_constant<int, i>;
template <unsigned int ui>
using uint_ = integral_constant<unsigned int, ui>;

template <long l>
using long_ = integral_constant<long, l>;
template <unsigned long ul>
using ulong_ = integral_constant<unsigned long, ul>;

template <long long ll>
using longlong_ = integral_constant<long long, ll>;
template <unsigned long long ull>
using ulonglong_ = integral_constant<unsigned long long, ull>;

template <std::size_t s>
using size_t_ = integral_constant<std::size_t, s>;

template <bool b>
using bool_ = integral_constant<bool, b>;
using true_ = bool_<true>;
using false_ = bool_<false>;

} // end namespace mpl11

#endif // !MPL11_TYPES_HPP
