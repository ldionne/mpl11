/*!
 * @file
 * Defines @ref BOOST_MPL11_DEFINE_LEFT_ASSOCIATIVE_OPERATOR.
 */

#ifndef BOOST_MPL11_DETAIL_LEFT_ASSOCIATIVE_OPERATOR_HPP
#define BOOST_MPL11_DETAIL_LEFT_ASSOCIATIVE_OPERATOR_HPP

#include <boost/mpl11/class_of.hpp>


/*!
 * @ingroup details
 *
 * Macro expanding to the definition of a left associative operator.
 */
#define BOOST_MPL11_DEFINE_LEFT_ASSOCIATIVE_OPERATOR(NAME, IMPL)            \
namespace boost { namespace mpl11 {                                         \
    template <typename X, typename Y, typename ...Z>                        \
    struct NAME                                                             \
        : NAME<typename NAME<X, Y>::type, Z...>                             \
    { };                                                                    \
                                                                            \
    template <typename X, typename Y>                                       \
    struct NAME<X, Y>                                                       \
        : class_of<X>::type::template IMPL<X, Y>                            \
    { };                                                                    \
}} /* end namespace boost::mpl11 */                                         \
/**/

#endif // !BOOST_MPL11_DETAIL_LEFT_ASSOCIATIVE_OPERATOR_HPP
