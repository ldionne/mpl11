/*!
 * @file
 * Defines `boost::mpl11::repeat`.
 */

#ifndef BOOST_MPL11_REPEAT_HPP
#define BOOST_MPL11_REPEAT_HPP

#include <boost/mpl11/fwd/repeat.hpp>

#include <boost/mpl11/fwd/iterable.hpp>
#include <boost/mpl11/fwd/sequence_traits.hpp>
#include <boost/mpl11/iterable/cons.hpp>


namespace boost { namespace mpl11 {
    template <typename T>
    struct repeat
        : cons<T, repeat<T>>
    { };

    //! @todo
    //! This is a workaround. This may break if `cons` changes.
    template <typename T>
    struct sequence_traits<cons<T, repeat<T>>> {
        static constexpr bool has_O1_length = false;
        static constexpr bool has_O1_unpack = false;
        static constexpr bool is_finite = false;
    };

    namespace rules {
        template <typename T, typename Index>
        struct at_impl<repeat<T>, Index> : T { };

        template <typename T>
        struct last_impl<repeat<T>> : T { };

        template <typename T>
        struct init_impl<repeat<T>> : repeat<T> { };
    }
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_REPEAT_HPP
