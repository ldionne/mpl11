/*!
 * @file
 * This file defines `boost::mpl11::quote`.
 */

#ifndef BOOST_MPL11_FUNCTIONAL_QUOTE_HPP
#define BOOST_MPL11_FUNCTIONAL_QUOTE_HPP

#include <boost/mpl11/has_xxx.hpp>
#include <boost/mpl11/identity.hpp>
#include <boost/mpl11/if.hpp>


namespace boost { namespace mpl11 {
    namespace quote_detail { BOOST_MPL11_HAS_NESTED_TYPE(has_type, type) }

    template <template <typename ...> class M>
    struct quote {
        template <typename ...Args>
        struct apply
            : if_<quote_detail::has_type<M<Args...>>,
                M<Args...>,
                identity<M<Args...>>
            >::type
        { };
    };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FUNCTIONAL_QUOTE_HPP
