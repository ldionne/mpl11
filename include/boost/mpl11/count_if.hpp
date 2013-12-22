/*!
 * @file
 * Defines `boost::mpl11::count_if`.
 */

#ifndef BOOST_MPL11_COUNT_IF_HPP
#define BOOST_MPL11_COUNT_IF_HPP

#include <boost/mpl11/fwd/count_if.hpp>

#include <boost/mpl11/apply.hpp>
#include <boost/mpl11/foldl.hpp>
#include <boost/mpl11/integral_c.hpp>


namespace boost { namespace mpl11 {
    namespace count_if_detail {
        template <typename Predicate>
        struct count_pred {
            template <typename N, typename Element,
                bool = mpl11::apply<Predicate, Element>::type::value
            >
            struct apply;

            template <typename N, typename Element>
            struct apply<N, Element, false> {
                using type = N;
            };

            template <typename N, typename Element>
            struct apply<N, Element, true> {
                using type = size_t<N::value + 1>;
            };
        };
    } // end namespace count_if_detail

    template <typename Sequence, typename Predicate>
    struct count_if
        : foldl<
            Sequence, size_t<0>, count_if_detail::count_pred<Predicate>
        >::type
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_COUNT_IF_HPP
