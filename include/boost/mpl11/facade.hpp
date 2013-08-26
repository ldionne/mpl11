/*!
 * @file
 * Defines `boost::mpl11::facade`.
 */

#ifndef BOOST_MPL11_FACADE_HPP
#define BOOST_MPL11_FACADE_HPP

#include <boost/mpl11/apply_wrap.hpp>
#include <boost/mpl11/dispatch.hpp>


namespace boost { namespace mpl11 {
    namespace tag { struct facade; }

    template <typename Operation, typename ...Args>
    struct dispatch<Operation, tag::facade, Args...> {
        template <typename Operation, typename Self, typename ...Args>
        struct apply
            : apply_wrap<Self, Operation, Self, Args...>
        { };
    };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FACADE_HPP
