/*!
 * @file
 * Forward declares `boost::mpl11::algorithm::min`.
 */

#ifndef BOOST_MPL11_ALGORITHM_MIN_FWD_HPP
#define BOOST_MPL11_ALGORITHM_MIN_FWD_HPP

#include <boost/mpl11/dispatch.hpp>


namespace boost { namespace mpl11 {
namespace tag { struct min; }

namespace algorithm {
    /*!
     * @ingroup algorithms
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
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_ALGORITHM_MIN_FWD_HPP
