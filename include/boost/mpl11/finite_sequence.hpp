/*!
 * @file
 * Defines `boost::mpl11::FiniteSequence`.
 */

#ifndef BOOST_MPL11_FINITE_SEQUENCE_HPP
#define BOOST_MPL11_FINITE_SEQUENCE_HPP

#include <boost/mpl11/fwd/finite_sequence.hpp>

#include <boost/mpl11/detail/default_unpack.hpp>
#include <boost/mpl11/detail/raw_foldl.hpp>
#include <boost/mpl11/integral_c.hpp>
#include <boost/mpl11/tag_of.hpp>


namespace boost { namespace mpl11 {
    namespace defaults {
        struct FiniteSequence {
        private:
            struct increment {
                template <typename Size, typename>
                using apply = size_t<Size::value + 1>;
            };

        public:
            template <typename S>
            using length_impl = typename detail::raw_foldl<
                increment, size_t<0>, S
            >::state;

            template <typename S, typename F>
            using unpack_impl = detail::default_unpack<S, F>;
        };
    } // end namespace defaults

    template <typename S>
    struct length
        : FiniteSequence<typename tag_of<S>::type>::template length_impl<S>
    { };

    template <typename S, typename F>
    struct unpack
        : FiniteSequence<typename tag_of<S>::type>::template unpack_impl<S, F>
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FINITE_SEQUENCE_HPP
