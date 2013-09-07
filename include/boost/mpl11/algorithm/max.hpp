/*!
 * @file
 * Defines `boost::mpl11::algorithm::max`.
 */

#ifndef BOOST_MPL11_ALGORITHM_MAX_HPP
#define BOOST_MPL11_ALGORITHM_MAX_HPP

#include <boost/mpl11/dispatch.hpp>
#include <boost/mpl11/tags.hpp>


namespace boost { namespace mpl11 { namespace algorithm {
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
}}} // end namespace boost::mpl11::algorithm

#ifndef BOOST_MPL11_DONT_INCLUDE_DEFAULTS
#   include <boost/mpl11/detail/default/max.hpp>
#endif

#endif // !BOOST_MPL11_ALGORITHM_MAX_HPP
