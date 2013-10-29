/*!
 * @file
 * Defines `boost::mpl11::Iterable`.
 */

#ifndef BOOST_MPL11_ITERABLE_HPP
#define BOOST_MPL11_ITERABLE_HPP

#include <boost/mpl11/fwd/iterable.hpp>

#include <boost/mpl11/begin.hpp>
#include <boost/mpl11/distance.hpp>
#include <boost/mpl11/end.hpp>
#include <boost/mpl11/equal.hpp>


namespace boost { namespace mpl11 {
    struct Iterable {
        //! This operation must be provided by the user.
        template <typename I>
        struct begin_impl;

        //! This operation must be provided by the user.
        template <typename I>
        struct end_impl;

        //! Returns the distance between both ends of the iterable.
        template <typename I>
        struct size_impl
            : distance<
                typename begin<I>::type,
                typename end<I>::type
            >
        { };

        //! Returns whether `begin<I>::type` is equal to `end<I>::type`.
        template <typename I>
        struct is_empty_impl
            : equal<
                typename begin<I>::type,
                typename end<I>::type
            >
        { };
    };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_ITERABLE_HPP
