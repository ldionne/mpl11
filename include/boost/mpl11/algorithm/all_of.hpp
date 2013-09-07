/*!
 * @file
 * Defines `boost::mpl11::algorithm::all_of`.
 */

#ifndef BOOST_MPL11_ALGORITHM_ALL_OF_HPP
#define BOOST_MPL11_ALGORITHM_ALL_OF_HPP

#include <boost/mpl11/detail/doxygen_only.hpp>
#include <boost/mpl11/detail/optional.hpp>
#include <boost/mpl11/dispatch.hpp>
#include <boost/mpl11/tags.hpp>


namespace boost { namespace mpl11 { namespace algorithm {
    /*!
     * @ingroup algorithm
     *
     * Overloaded algorithm for querying a sequence about the truth value of
     * its elements.
     */
    template <typename Sequence, typename Predicate = detail::optional>
    struct all_of;

    /*!
     * @ingroup algorithm
     *
     * Returns whether all the elements of a sequence satisfy a given
     * `Predicate`.
     *
     *
     * ### Semantics and default implementation
     *
     * Equivalent to
       @code
            none_of<
                Sequence,
                not_<apply_wrap<lambda<Predicate>::type, _1>>
            >
       @endcode
     */
    template <typename Sequence, typename Predicate>
    struct all_of BOOST_MPL11_DOXYGEN_ONLY(<Sequence, Predicate>)
        : dispatch<tag::all_of, Sequence, Predicate>
    { };

    /*!
     * @ingroup algorithm
     *
     * Returns whether all the elements of a sequence are `true`-valued
     * boolean `IntegralConstant`s.
     *
     *
     * ### Semantics and default implementation
     *
     * Equivalent to `all_of<Sequence, _1>`.
     */
    template <typename Sequence>
    struct all_of<Sequence>
        : dispatch<tag::all_of, Sequence>
    { };
}}} // end namespace boost::mpl11::algorithm

#ifndef BOOST_MPL11_DONT_INCLUDE_DEFAULTS
#   include <boost/mpl11/detail/default/all_of.hpp>
#endif

#endif // !BOOST_MPL11_ALGORITHM_ALL_OF_HPP
