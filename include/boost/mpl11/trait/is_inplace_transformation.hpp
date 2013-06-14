/*!
 * @file
 * This file defines `boost::mpl11::trait::is_inplace_transformation`.
 */

#ifndef BOOST_MPL11_TRAIT_IS_INPLACE_TRANSFORMATION_HPP
#define BOOST_MPL11_TRAIT_IS_INPLACE_TRANSFORMATION_HPP

#include <boost/mpl11/has_xxx.hpp>


namespace boost { namespace mpl11 { inline namespace v2 { namespace trait {
    namespace inplace_trans_detail {
        BOOST_MPL11_HAS_NESTED_TYPE(has_is_inplace_transformation,
                                    mpl11::is_inplace_transformation)
    }

    template <typename T>
    struct is_inplace_transformation
        : inplace_trans_detail::has_is_inplace_transformation<T>::type
    { };
}}}}

#endif // !BOOST_MPL11_TRAIT_IS_INPLACE_TRANSFORMATION_HPP
