/*!
 * @file
 * Defines `boost::mpl11::Container`.
 */

#ifndef BOOST_MPL11_CONTAINER_CONTAINER_HPP
#define BOOST_MPL11_CONTAINER_CONTAINER_HPP

#include <boost/mpl11/fwd/container.hpp>

#include <boost/mpl11/detail/optional.hpp>
#include <boost/mpl11/iterable/iterable.hpp>


namespace boost { namespace mpl11 {
    // Type containing other types.
    struct Container : Iterable {
        //! @internal
        //! In a classical object system, classes would be objects and
        //! new_ would be a class-method. However, our goal here is to
        //! have decent compile-time performance and a very simple object
        //! system, so we make this as a normal method.
        template <typename C, typename Iterable>
        struct renew;

        template <typename C, typename First, typename Last>
        struct renew;

        template <typename C>
        struct clear;

        template <typename C, typename First, typename Last = detail::optional>
        struct erase;
    };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_CONTAINER_CONTAINER_HPP
