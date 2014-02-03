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
     * Holds a compile-time value of an integral type.
     *
     *
     * ### Valid expressions
     * In the following table, `N` is an `Integer`, and `n` is an object of
     * type `N`.
     *
     * | Expression                        | Type
     * | ----------                        | ----
     * | `N::value_type`                   | An integral type
     * | `N::value`                        | An integral constant expression
     * | `N::type`                         | `N`
     * | `constexpr N::value_type c = N{}` | n/a
     * | `constexpr N::value_type c = n()` | n/a
     *
     *
     * ### Instance of
     * `Comparable`, `Orderable`, `Enumerable`, `Monoid`, `Group`, and `Ring`.
     *
     * @todo
     * Write unit tests for the provided instances.
     *
     * @{
     */
    struct Integer;

    /*!
     * `Integer` holding the specified value.
     *
     *
     * @internal
     * We define this in the forward declaration header because it is
     * required almost everywhere. This saves us trouble with circular
     * dependencies.
     */
    template <typename T, T v>
    struct integral_c {
        using value_type = T;
        static constexpr value_type value = v;
        constexpr operator value_type() const { return value; }
        constexpr value_type operator()() const { return value; }
        using type = integral_c;
        using mpl_datatype = Integer;
    };

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

#endif // !BOOST_MPL11_FWD_INTEGER_HPP
