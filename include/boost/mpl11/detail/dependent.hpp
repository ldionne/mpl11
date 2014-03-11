/*!
 * @file
 * Defines `boost::mpl11::detail::dependent`.
 */

#ifndef BOOST_MPL11_DETAIL_DEPENDENT_HPP
#define BOOST_MPL11_DETAIL_DEPENDENT_HPP

namespace boost { namespace mpl11 { namespace detail {
    //! @ingroup details
    //! Turns a value or a type into a dependent entity.
    template <typename ...>
    struct dependent {
        template <typename T>
        using type = T;

        template <typename T>
        static constexpr T value(T x) { return x; }
    };
}}} // end namespace boost::mpl11::detail

#endif // !BOOST_MPL11_DETAIL_DEPENDENT_HPP
