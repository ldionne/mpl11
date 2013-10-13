/*!
 * @file
 * Forward declares `boost::mpl11::max`.
 */

#ifndef BOOST_MPL11_ALGORITHM_MAX_FWD_HPP
#define BOOST_MPL11_ALGORITHM_MAX_FWD_HPP

#include <boost/mpl11/dispatch.hpp>


namespace boost { namespace mpl11 {
    namespace tag { struct max; }

    /*!
     * @ingroup algorithms
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
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_ALGORITHM_MAX_FWD_HPP
