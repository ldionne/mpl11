/*!
 * @file
 * This file defines `boost::mpl11::trait::dispatcher_of`.
 */

#ifndef BOOST_MPL11_TRAIT_DISPATCHER_OF_HPP
#define BOOST_MPL11_TRAIT_DISPATCHER_OF_HPP

#include <boost/mpl11/has_xxx.hpp>
#include <boost/mpl11/if.hpp>


namespace boost { namespace mpl11 { namespace trait {
    namespace dispatcher_of_detail {
        template <typename T>
        struct get_dispatcher {
            using type = typename T::mpl11::dispatcher;
        };

        BOOST_MPL11_HAS_NESTED_TYPE(has_dispatcher, mpl11::dispatcher)
    } // end namespace dispatcher_of_detail

    template <typename T>
    struct dispatcher_of
        : if_<dispatcher_of_detail::has_dispatcher<T>,
            eval<dispatcher_of_detail::get_dispatcher<T>>>
    { };
}}} // end namespace boost::mpl11::trait

#endif // !BOOST_MPL11_TRAIT_DISPATCHER_OF_HPP
