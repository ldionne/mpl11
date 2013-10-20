/*!
 * @file
 * Defines `boost::mpl11::Metafunction`.
 */

#ifndef BOOST_MPL11_METAFUNCTION_HPP
#define BOOST_MPL11_METAFUNCTION_HPP

#include <boost/mpl11/fwd/metafunction.hpp>

#include <boost/mpl11/boolean.hpp>
#include <boost/mpl11/if.hpp>
#include <boost/mpl11/not.hpp>


namespace boost { namespace mpl11 {
    struct Metafunction : Boolean {
        template <typename Self, typename Then, typename Else>
        struct if_
            : mpl11::if_<typename Self::type, Then, Else>
        { };

        template <typename Self>
        struct not_
            : mpl11::not_<typename Self::type>
        { };
    };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_METAFUNCTION_HPP
