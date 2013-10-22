/*!
 * @file
 * Defines `boost::mpl11::detail::dependent_on`.
 */

#ifndef BOOST_MPL11_DETAIL_DEPENDENT_ON_HPP
#define BOOST_MPL11_DETAIL_DEPENDENT_ON_HPP

namespace boost { namespace mpl11 { namespace detail {
    template <typename DependentType>
    struct dependent_on {
        template <typename T>
        using type = T;

        template <typename T, T x>
        static constexpr T value() { return x; }
    };
}}} // end namespace boost::mpl11::detail

#endif // !BOOST_MPL11_DETAIL_DEPENDENT_ON_HPP
