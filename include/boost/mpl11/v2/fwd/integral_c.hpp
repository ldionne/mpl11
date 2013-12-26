/*!
 * @file
 * Forward declares `boost::mpl11::integral_c` and associated aliases.
 */

#ifndef BOOST_MPL11_FWD_INTEGRAL_C_HPP
#define BOOST_MPL11_FWD_INTEGRAL_C_HPP

#include <boost/mpl11/detail/std_size_t.hpp>


namespace boost { namespace mpl11 {
    /*!
     * @ingroup datatypes
     * @{
     *
     * Wrapper over a static constant of the specified integral type.
     */
    template <typename T, T v>
    struct integral_c;

    //! Alias to `integral_c<bool, B>`; provided for convenience.
    template <bool B>
    using bool_ = integral_c<bool, B>;

    //! Alias to `bool_<true>`; provided for convenience.
    using true_ = bool_<true>;

    //! Alias to `bool_<false>`; provided for convenience.
    using false_ = bool_<false>;

    //! Alias to `integral_c<char, C>`; provided for convenience.
    template <char C>
    using char_ = integral_c<char, C>;

    //! Alias to `integral_c<short, N>`; provided for convenience.
    template <short N>
    using short_ = integral_c<short, N>;

    //! Alias to `integral_c<unsigned short, N>`; provided for convenience.
    template <unsigned short N>
    using ushort = integral_c<unsigned short, N>;

    //! Alias to `integral_c<int, N>`; provided for convenience.
    template <int N>
    using int_ = integral_c<int, N>;

    //! Alias to `integral_c<unsigned int, N>`; provided for convenience.
    template <unsigned int N>
    using uint = integral_c<unsigned int, N>;

    //! Alias to `integral_c<long, N>`; provided for convenience.
    template <long N>
    using long_ = integral_c<long, N>;

    //! Alias to `integral_c<unsigned long, N>`; provided for convenience.
    template <unsigned long N>
    using ulong = integral_c<unsigned long, N>;

    //! Alias to `integral_c<long long, N>`; provided for convenience.
    template <long long N>
    using llong = integral_c<long long, N>;

    //! Alias to `integral_c<unsigned long long, N>`; provided for convenience.
    template <unsigned long long N>
    using ullong = integral_c<unsigned long long, N>;

    //! Alias to `integral_c<std::size_t, N>`; provided for convenience.
    template <detail::std_size_t N>
    using size_t = integral_c<detail::std_size_t, N>;

    //! @}
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_INTEGRAL_C_HPP
