/*!
 * @file
 * Defines the @ref Iterable typeclass.
 */

#ifndef BOOST_MPL11_ITERABLE_HPP
#define BOOST_MPL11_ITERABLE_HPP

#include <boost/mpl11/fwd/iterable.hpp>

#include <boost/mpl11/core.hpp>


namespace boost { namespace mpl11 {
    template <typename iter>
    struct head {
#if defined(BOOST_MPL11_ENABLE_ASSERTIONS)
        static_assert(!is_empty<iter>::value,
        "Invalid usage of `head` on an empty iterable.");
#endif
        using type = typename
            Iterable<typename datatype<typename iter::type>::type>::
            template head_impl<iter>
        ::type;
    };

    template <typename iter>
    struct tail {
#if defined(BOOST_MPL11_ENABLE_ASSERTIONS)
        static_assert(!is_empty<iter>::value,
        "Invalid usage of `tail` on an empty iterable.");
#endif
        using type = typename
            Iterable<typename datatype<typename iter::type>::type>::
            template tail_impl<iter>
        ::type;
    };

    template <typename iter>
    struct is_empty :
        Iterable<typename datatype<typename iter::type>::type>::
        template is_empty_impl<iter>
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_ITERABLE_HPP
