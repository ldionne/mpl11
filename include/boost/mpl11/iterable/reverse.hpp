/*!
 * @file
 * Defines `boost::mpl11::reverse`.
 */

#ifndef BOOST_MPL11_ITERABLE_REVERSE_HPP
#define BOOST_MPL11_ITERABLE_REVERSE_HPP

#include <boost/mpl11/fwd/iterable.hpp>

#include <boost/mpl11/detail/std_size_t.hpp>
#include <boost/mpl11/fwd/tag_of.hpp>
#include <boost/mpl11/iterable/iterable.hpp>
#include <boost/mpl11/sequence_traits.hpp>


namespace boost { namespace mpl11 {
    template <typename S>
    struct reverse { using type = reverse; };

    template <typename S>
    struct tag_of<reverse<S>> { using type = iterable_tag; };

    template <typename S>
    struct sequence_traits<reverse<S>> : sequence_traits<S> {
        static constexpr bool has_O1_unpack = false;
    };

    template <typename S>
    struct head_impl<reverse<S>> {
        using type = typename last<S>::type;
    };

    template <typename S>
    struct tail_impl<reverse<S>> {
        using type = reverse<typename init<S>::type>;
    };

    template <typename S>
    struct is_empty_impl<reverse<S>>
        : is_empty<S>
    { };

    template <typename S>
    struct length_impl<reverse<S>>
        : length<S>
    { };

    template <typename S>
    struct last_impl<reverse<S>> {
        using type = typename head<S>::type;
    };

    template <typename S>
    struct init_impl<reverse<S>> {
        using type = reverse<typename tail<S>::type>;
    };

    namespace reverse_detail {
        template <bool IsFinite>
        struct at_c_impl;

        template <>
        struct at_c_impl<true> {
            template <typename S, detail::std_size_t Index>
            using result = typename at_c<
                S, length<S>::value - Index - 1
            >::type;
        };

        //! @todo Don't call the default version explicitly.
        template <>
        struct at_c_impl<false> {
            template <typename S, detail::std_size_t Index>
            using result = typename Iterable<iterable_tag>::
                           template at_c_impl<reverse<S>, Index>::type;
        };
    } // end namespace reverse_detail

    template <typename S, detail::std_size_t Index>
    struct at_c_impl<reverse<S>, Index> {
        using type = typename reverse_detail::at_c_impl<
            sequence_traits<S>::is_finite &&
            sequence_traits<S>::has_O1_length
        >::template result<S, Index>;
    };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_ITERABLE_REVERSE_HPP
