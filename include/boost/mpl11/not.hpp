/*!
 * @file
 * Defines `boost::mpl11::not_`.
 */

#ifndef BOOST_MPL11_NOT_HPP
#define BOOST_MPL11_NOT_HPP

#include <boost/mpl11/bool.hpp>


namespace boost { namespace mpl11 {
    /*!
     * Returns the result of _logical not_ on its argument.
     *
     * Equivalent to `bool_<!F::type::value>`.
     *
     * @tparam F
     *         A nullary boolean metafunction whose result is to be negated.
     */
    template <typename F>
    struct not_
        : bool_<!F::type::value>
    { };
}}

#endif // !BOOST_MPL11_NOT_HPP
