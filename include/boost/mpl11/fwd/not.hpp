/*!
 * @file
 * Forward declares `boost::mpl11::not_`.
 */

#ifndef BOOST_MPL11_FWD_NOT_HPP
#define BOOST_MPL11_FWD_NOT_HPP

#include <boost/mpl11/dispatch.hpp>


namespace boost { namespace mpl11 {
    namespace tag { struct not_; }

    /*!
     * @ingroup logical_operators
     *
     * Returns the result of _logical not_ (`!`) on the result of
     * its argument.
     *
     *
     * ### Semantics and default implementation
     *
     * Equivalent to `identity<bool_<!F::type::value>>`.
     */
    template <typename F>
    struct not_
        : dispatch<tag::not_, F>
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_NOT_HPP
