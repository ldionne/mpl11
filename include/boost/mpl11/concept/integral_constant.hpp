/*!
 * @file
 * Defines `boost::mpl11::concept::IntegralConstant`.
 */

#ifndef BOOST_MPL11_CONCEPT_INTEGRAL_CONSTANT_HPP
#define BOOST_MPL11_CONCEPT_INTEGRAL_CONSTANT_HPP

#include <boost/mpl11/categories.hpp>
#include <boost/mpl11/concept/categorizable.hpp>


namespace boost { namespace mpl11 { namespace concept {
    template <typename N>
    class IntegralConstant
        : Categorizable<N, category::integral_constant>
    {
        using ValueType = typename N::value_type;

        static constexpr ValueType value1 = N::value,
                                   value2 = N{};
    };
}}} // end namespace boost::mpl11::concept

#endif // !BOOST_MPL11_CONCEPT_INTEGRAL_CONSTANT_HPP
