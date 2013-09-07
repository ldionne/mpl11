/*!
 * @file
 * Defines `boost::mpl11::concept::Categorizable`.
 */

#ifndef BOOST_MPL11_CONCEPT_CATEGORIZABLE_HPP
#define BOOST_MPL11_CONCEPT_CATEGORIZABLE_HPP

#include <boost/mpl11/bool.hpp>
#include <boost/mpl11/detail/is_base_of.hpp>
#include <boost/mpl11/intrinsic/and.hpp>
#include <boost/mpl11/intrinsic/category_of.hpp>


namespace boost { namespace mpl11 { namespace concept {
    template <typename T, typename ...Categories>
    class Categorizable {
        // `and_` expects at least two arguments,
        // hence the two trailing `true_`s.
        static_assert(intrinsic::and_<
            detail::is_base_of<
                Categories,
                typename intrinsic::category_of<T>::type
            >...,
            true_, true_
        >::value, "");
    };
}}} // end namespace boost::mpl11::concept

#endif // !BOOST_MPL11_CONCEPT_CATEGORIZABLE_HPP
