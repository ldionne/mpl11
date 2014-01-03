/*!
 * @file
 * Defines `boost::mpl11::repeat`.
 */

#ifndef BOOST_MPL11_REPEAT_HPP
#define BOOST_MPL11_REPEAT_HPP

#include <boost/mpl11/fwd/repeat.hpp>

#include <boost/mpl11/detail/check_usage.hpp>
#include <boost/mpl11/integral_c.hpp>
#include <boost/mpl11/sequence.hpp>
#include <boost/mpl11/take.hpp>


namespace boost { namespace mpl11 {
    template <typename T>
    struct tag_of<repeat<T>> { using type = sequence_tag; };

    /////////////////////////////////
    // Minimal complete definition
    /////////////////////////////////
    template <typename T> struct head<repeat<T>> { using type = T; };
    template <typename T> struct tail<repeat<T>> { using type = repeat<T>; };
    template <typename T> struct is_empty<repeat<T>> : false_ { };

    /////////////////////////////////
    // Optimizations
    /////////////////////////////////
    template <typename T> struct last<repeat<T>> { using type = T; };
    template <typename T> struct init<repeat<T>> { using type = repeat<T>; };

    template <typename T, detail::std_size_t Index>
    struct at_c<repeat<T>, Index>
        : private BOOST_MPL11_CHECK_USAGE(at_c<repeat<T>, Index>)
    {
        using type = T;
    };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_REPEAT_HPP
