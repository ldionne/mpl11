/*!
 * @file
 * Defines `boost::mpl11::detail::lazy_init`.
 */

#ifndef BOOST_MPL11_DETAIL_LAZY_INIT_HPP
#define BOOST_MPL11_DETAIL_LAZY_INIT_HPP

namespace boost { namespace mpl11 { namespace detail {
    /*!
     * @ingroup details
     *
     * Returns a lazy iterable implementing the default behavior
     * of the `init` method.
     *
     *
     * @invariant
     * `S` is never empty.
     */
    template <typename S>
    struct lazy_init;
}}} // end namespace boost::mpl11::detail


#include <boost/mpl11/fwd/iterable.hpp>
#include <boost/mpl11/fwd/sequence_traits.hpp>
#include <boost/mpl11/fwd/tag_of.hpp>
#include <boost/mpl11/integral_c.hpp>


namespace boost { namespace mpl11 {
    namespace detail {
        template <typename S>
        struct lazy_init {
            using type = lazy_init;
        };
    } // end namespace detail

    template <typename S>
    struct tag_of<detail::lazy_init<S>> { using type = iterable_tag; };

    template <typename S>
    struct sequence_traits<detail::lazy_init<S>> : sequence_traits<S> {
        static constexpr bool has_O1_unpack = false;
    };

    template <typename S>
    struct head_impl<detail::lazy_init<S>> {
        using type = typename head<S>::type;
    };

    template <typename S>
    struct tail_impl<detail::lazy_init<S>> {
        using type = detail::lazy_init<typename tail<S>::type>;
    };

    template <typename S>
    struct is_empty_impl<detail::lazy_init<S>>
        : is_empty<typename tail<S>::type>
    { };

    template <typename S>
    struct length_impl<detail::lazy_init<S>>
        : size_t<length<S>::value - 1>
    { };

    template <typename S, detail::std_size_t Index>
    struct at_c_impl<detail::lazy_init<S>, Index> {
        using type = typename at_c<S, Index>::type;
    };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_DETAIL_LAZY_INIT_HPP
