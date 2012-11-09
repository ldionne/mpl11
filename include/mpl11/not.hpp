/**
 * This file defines the not_ metafunction.
 */

#ifndef MPL11_NOT_HPP
#define MPL11_NOT_HPP

#include <mpl11/bool.hpp>


namespace mpl11 {

/**
 * Metafunction that negates the result of evaluating a metafunction given
 * as argument.
 */
template <typename T>
struct not_ : not_<typename T::type> { };

template <>
struct not_<true_> : false_ { };

template <>
struct not_<false_> : true_ { };

} // end namespace mpl11

#endif // !MPL11_NOT_HPP
