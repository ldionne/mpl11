/*!
 * @file
 * Defines `boost::mpl11::algorithm::max`.
 */

#ifndef BOOST_MPL11_ALGORITHM_MAX_HPP
#define BOOST_MPL11_ALGORITHM_MAX_HPP

#include <boost/mpl11/dispatch.hpp>
#include <boost/mpl11/if.hpp>
#include <boost/mpl11/intrinsic/less.hpp>
#include <boost/mpl11/tags.hpp>


namespace boost { namespace mpl11 {
namespace algorithm {
    /*!
     * @ingroup algorithm
     *
     * Returns the largest of its arguments.
     *
     *
     * ### Semantics and default implementation
     *
     * When invoked with arguments `T1`, `T2`, ...`Tn`, equivalent to
     * `max<T1, max<T2, Tn...>::type>`.
     *
     * When invoked with arguments `T1` and `T2`, equivalent to
     * `if_<less<T1, T2>, T2, T1>`.
     *
     *
     * @warning
     * Differences from the original MPL:
     * - `max` uses standard tag dispatching.
     * - Several types can be compared at a time.
     */
    template <typename T1, typename T2, typename ...Tn>
    struct max
        : dispatch<tag::max, T1, T2, Tn...>
    { };
} // end namespace algorithm

template <typename T1, typename T2, typename ...Tn>
struct dispatch<detail::default_<tag::max>, T1, T2, Tn...>
    : algorithm::max<T1, typename algorithm::max<T2, Tn...>::type>
{ };

template <typename T1, typename T2>
struct dispatch<detail::default_<tag::max>, T1, T2>
    : if_<intrinsic::less<T1, T2>, T2, T1>
{ };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_ALGORITHM_MAX_HPP
