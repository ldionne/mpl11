/*!
 * @file
 * Defines @ref BOOST_MPL11_DEFINE_COMPARISON_OPERATOR.
 */

#ifndef BOOST_MPL11_DETAIL_COMPARISON_OPERATOR_HPP
#define BOOST_MPL11_DETAIL_COMPARISON_OPERATOR_HPP

/*!
 * @ingroup details
 *
 * Macro expanding to the definition of a comparison operator.
 */
#define BOOST_MPL11_DEFINE_COMPARISON_OPERATOR(NAME, IMPL)                  \
namespace boost { namespace mpl11 {                                         \
    template <typename X, typename Y, typename ...Z>                        \
    struct NAME                                                             \
        : and_<                                                             \
            NAME<X, Y>,                                                     \
            NAME<Y, Z...>                                                   \
        >                                                                   \
    { };                                                                    \
                                                                            \
    template <typename X, typename Y>                                       \
    struct NAME<X, Y>                                                       \
        : class_of<X>::type::template IMPL<X, Y>                            \
    { };                                                                    \
}} /* end namespace boost::mpl11 */                                         \
/**/


#include <boost/mpl11/and.hpp>
#include <boost/mpl11/class_of.hpp>

#endif // !BOOST_MPL11_DETAIL_COMPARISON_OPERATOR_HPP
