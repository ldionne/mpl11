/*!
 * @file
 * Defines the @ref Iterable typeclass.
 */

#ifndef BOOST_MPL11_ITERABLE_HPP
#define BOOST_MPL11_ITERABLE_HPP

#include <boost/mpl11/fwd/iterable.hpp>

#include <boost/mpl11/core.hpp>


namespace boost { namespace mpl11 {
namespace detail {
    namespace impls {
        template <typename iter>
        struct head
            : Iterable<typename datatype<typename iter::type>::type>::
              template head_impl<iter>
        { };

        template <typename iter>
        struct tail
            : Iterable<typename datatype<typename iter::type>::type>::
              template tail_impl<iter>
        { };
    }

    namespace checked_ns {
        template <typename iter>
        struct head {
            static_assert(!is_empty<iter>::value,
            "Invalid usage of `head` on an empty iterable.");
            using type = typename rules::head<iter>::type;
        };

        template <typename iter>
        struct tail {
            static_assert(!is_empty<iter>::value,
            "Invalid usage of `tail` on an empty iterable.");
            using type = typename rules::tail<iter>::type;
        };
    }
} // end namespace detail

template <typename iter>
struct is_empty :
    Iterable<typename datatype<typename iter::type>::type>::
    template is_empty_impl<iter>
{ };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_ITERABLE_HPP
