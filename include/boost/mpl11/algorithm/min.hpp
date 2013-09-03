/*!
 * @file
 * Defines `boost::mpl11::algorithm::min`.
 */

#ifndef BOOST_MPL11_ALGORITHM_MIN_HPP
#define BOOST_MPL11_ALGORITHM_MIN_HPP

#include <boost/mpl11/dispatch.hpp>
#include <boost/mpl11/if.hpp>
#include <boost/mpl11/intrinsic/less.hpp>
#include <boost/mpl11/tags.hpp>


namespace boost { namespace mpl11 {
namespace algorithm {
    /*!
     * @ingroup algorithm
     *
     * Returns the smallest of its arguments.
     *
     *
     * ### Semantics and default implementation
     *
     * When invoked with arguments `T1`, `T2`, ...`Tn`, equivalent to
     * `min<T1, min<T2, Tn...>::type>`.
     *
     * When invoked with arguments `T1` and `T2`, equivalent to
     * `if_<less<T1, T2>, T1, T2>`.
     *
     *
     * @warning
     * Differences from the original MPL:
     * - `min` uses standard tag dispatching.
     * - Several types can be compared at a time.
     */
    template <typename T1, typename T2, typename ...Tn>
    struct min
        : dispatch<tag::min, T1, T2, Tn...>
    { };
} // end namespace algorithm

template <typename T1, typename T2, typename ...Tn>
struct dispatch<detail::default_<tag::min>, T1, T2, Tn...>
    : algorithm::min<T1, typename algorithm::min<T2, Tn...>::type>
{ };

template <typename T1, typename T2>
struct dispatch<detail::default_<tag::min>, T1, T2>
    : if_<intrinsic::less<T1, T2>, T1, T2>
{ };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_ALGORITHM_MIN_HPP
