/*!
 * @file
 * Forward declares `boost::mpl11::integral_c` and associated aliases.
 */

#ifndef BOOST_MPL11_INTEGRAL_C_FWD_HPP
#define BOOST_MPL11_INTEGRAL_C_FWD_HPP

namespace boost { namespace mpl11 {
    //! Generic @ref IntegralConstant implementation.
    template <typename I, I N>
    struct integral_c;

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

#endif // !BOOST_MPL11_INTEGRAL_C_FWD_HPP
