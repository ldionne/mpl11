/*!
 * @file
 * This file defines `boost::mpl11::placeholder`.
 */

#ifndef BOOST_MPL11_FUNCTIONAL_PLACEHOLDER_HPP
#define BOOST_MPL11_FUNCTIONAL_PLACEHOLDER_HPP

#include <boost/mpl11/apply.hpp>


namespace boost { namespace mpl11 {
namespace placeholder_detail {
    template <typename LambdaExpression>
    struct make_placeholder {
        struct type {
            template <typename Args, typename Kwargs>
            struct apply
                : mpl11::apply<LambdaExpression, Args, Kwargs>
            { };
        };
    };
} // end namespace placeholder_detail

// Note:
// We can't use `placeholder` to define the other basic placeholders,
// because the `LambdaExpression` used to defined them would require
// them, which is a circular dependency.
template <typename LambdaExpression>
using placeholder = typename placeholder_detail::make_placeholder<
    LambdaExpression
>::type;
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FUNCTIONAL_PLACEHOLDER_HPP
