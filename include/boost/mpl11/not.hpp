/*!
 * @file
 * Defines `boost::mpl11::not_`.
 */

#ifndef BOOST_MPL11_NOT_HPP
#define BOOST_MPL11_NOT_HPP

#include <boost/mpl11/fwd/not.hpp>

#include <boost/mpl11/dispatch.hpp>
#include <boost/mpl11/identity.hpp>
#include <boost/mpl11/integral_c.hpp>


namespace boost { namespace mpl11 {
    //! @bug
    //! We don't have a category for metafunctions, but that is what
    //! not_ takes as argument. What should we do?
    template <typename F>
    struct dispatch<tag::not_, F>
        : identity<bool_<!F::type::value>>
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_NOT_HPP
