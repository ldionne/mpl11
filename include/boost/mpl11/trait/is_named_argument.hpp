/*!
 * @file
 * This file defines `boost::mpl11::trait::is_named_argument`.
 */

#ifndef BOOST_MPL11_TRAIT_IS_NAMED_ARGUMENT_HPP
#define BOOST_MPL11_TRAIT_IS_NAMED_ARGUMENT_HPP

#include <boost/mpl11/has_xxx.hpp>


namespace boost { namespace mpl11 { namespace trait {
    namespace is_named_argument_detail {
        BOOST_MPL11_HAS_NESTED_TYPE(has_is_named_argument,
                                    mpl11::is_named_argument)
    }

    template <typename T>
    struct is_named_argument
        : is_named_argument_detail::has_is_named_argument<T>::type
    { };
}}} // end namespace boost::mpl11::trait

#endif // !BOOST_MPL11_TRAIT_IS_NAMED_ARGUMENT_HPP
