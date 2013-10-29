/*!
 * @file
 * Defines `boost::mpl11::detail::bool_cast`.
 */

#ifndef BOOST_MPL11_DETAIL_BOOL_CAST_HPP
#define BOOST_MPL11_DETAIL_BOOL_CAST_HPP

#include <boost/mpl11/fwd/bool.hpp>
#include <boost/mpl11/identity.hpp>
#include <boost/mpl11/not.hpp>


namespace boost { namespace mpl11 { namespace detail {
    namespace bool_cast_detail {
        template <typename Bool>
        struct convert;

        template <>
        struct convert<true_> {
            static constexpr bool value = true;
        };

        template <>
        struct convert<false_> {
            static constexpr bool value = false;
        };
    } // end namespace bool_cast_detail

    /*!
     * @ingroup details
     *
     * Returns the truth value of `Bool`.
     */
    template <typename Bool>
    struct bool_cast {
        static constexpr bool value = !bool_cast_detail::convert<
            typename not_<identity<Bool>>::type
        >::value;
    };
}}} // end namespace boost::mpl11::detail

#endif // !BOOST_MPL11_DETAIL_BOOL_CAST_HPP
