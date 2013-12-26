/*!
 * @file
 * Defines `boost::mpl11::FiniteSequence`.
 */

#ifndef BOOST_MPL11_FINITE_SEQUENCE_HPP
#define BOOST_MPL11_FINITE_SEQUENCE_HPP

#include <boost/mpl11/v2/fwd/finite_sequence.hpp>

#include <boost/mpl11/detail/default_unpack.hpp>
#include <boost/mpl11/integral_c.hpp>
#include <boost/mpl11/v2/detail/raw_foldl.hpp>


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
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FINITE_SEQUENCE_HPP
