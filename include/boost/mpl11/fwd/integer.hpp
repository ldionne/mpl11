/*!
 * @file
 * Forward declares the @ref Integer datatype.
 */

#ifndef BOOST_MPL11_FWD_INTEGER_HPP
#define BOOST_MPL11_FWD_INTEGER_HPP

#include <boost/mpl11/detail/std_size_t.hpp>


namespace boost { namespace mpl11 {
    /*!
     * @ingroup datatypes
     * @defgroup Integer Integer
     *
     * @ref StaticConstant of an integral type.
     *
     *
     * ### Instance of
     * `Comparable`, `Orderable`, `Enumerable`, `Monoid`, `Group`, `Ring` and
     * `IntegralDomain`.
     *
     * @todo
     * Write unit tests for the provided instances.
     *
     * @{
     */
    struct Integer;

    //! `Integer` holding the specified value.
    template <typename T, T v>
    struct integer_c {
        using value_type = T;
        static constexpr value_type value = v;
        constexpr operator value_type() const { return value; }
        constexpr value_type operator()() const { return value; }
        using type = integer_c;
        using mpl_datatype = Integer;
    };

    //! Alias to `integer_c<T, v>`; provided for backward compatibility.
    template <typename T, T v>
    using integral_c = integer_c<T, v>;

    //! Alias to `integer_c<char, C>`; provided for convenience.
    template <char C>
    using char_ = integer_c<char, C>;

    //! Alias to `integer_c<short, N>`; provided for convenience.
    template <short N>
    using short_ = integer_c<short, N>;

    //! Alias to `integer_c<unsigned short, N>`; provided for convenience.
    template <unsigned short N>
    using ushort = integer_c<unsigned short, N>;

    //! Alias to `integer_c<int, N>`; provided for convenience.
    template <int N>
    using int_ = integer_c<int, N>;

    //! Alias to `integer_c<unsigned int, N>`; provided for convenience.
    template <unsigned int N>
    using uint = integer_c<unsigned int, N>;

    //! Alias to `integer_c<long, N>`; provided for convenience.
    template <long N>
    using long_ = integer_c<long, N>;

    //! Alias to `integer_c<unsigned long, N>`; provided for convenience.
    template <unsigned long N>
    using ulong = integer_c<unsigned long, N>;

    //! Alias to `integer_c<long long, N>`; provided for convenience.
    template <long long N>
    using llong = integer_c<long long, N>;

    //! Alias to `integer_c<unsigned long long, N>`; provided for convenience.
    template <unsigned long long N>
    using ullong = integer_c<unsigned long long, N>;

    //! Alias to `integer_c<std::size_t, N>`; provided for convenience.
    template <detail::std_size_t N>
    using size_t = integer_c<detail::std_size_t, N>;
    //! @}
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_INTEGER_HPP