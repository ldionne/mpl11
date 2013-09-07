/*!
 * @file
 * Defines `boost::mpl11::concept::BooleanIntegralConstant`.
 */

#ifndef BOOST_MPL11_CONCEPT_BOOLEAN_INTEGRAL_CONSTANT_HPP
#define BOOST_MPL11_CONCEPT_BOOLEAN_INTEGRAL_CONSTANT_HPP

#include <boost/mpl11/concept/integral_constant.hpp>
#include <boost/mpl11/detail/is_same.hpp>


namespace boost { namespace mpl11 { namespace concept {
    template <typename N>
    class BooleanIntegralConstant : IntegralConstant<N> {
        static_assert(detail::is_same<
            typename N::value_type, bool
        >::value, "");
    };
}}} // end namespace boost::mpl11::concept

#endif // !BOOST_MPL11_CONCEPT_BOOLEAN_INTEGRAL_CONSTANT_HPP
