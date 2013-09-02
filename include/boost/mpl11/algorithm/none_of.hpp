/*!
 * @file
 * Defines `boost::mpl11::algorithm::none_of`.
 */

#ifndef BOOST_MPL11_ALGORITHM_NONE_OF_HPP
#define BOOST_MPL11_ALGORITHM_NONE_OF_HPP

#include <boost/mpl11/algorithm/find_if.hpp>
#include <boost/mpl11/arg.hpp>
#include <boost/mpl11/detail/doxygen_only.hpp>
#include <boost/mpl11/detail/optional.hpp>
#include <boost/mpl11/dispatch.hpp>
#include <boost/mpl11/intrinsic/end.hpp>
#include <boost/mpl11/intrinsic/equal_to.hpp>
#include <boost/mpl11/tags.hpp>


namespace boost { namespace mpl11 { namespace algorithm {
    /*!
     * @ingroup algorithm
     *
     * Overloaded algorithm for querying a sequence about the truth value of
     * its elements.
     */
    template <typename Sequence, typename Predicate = detail::optional>
    struct none_of;

    /*!
     * @ingroup algorithm
     *
     * Returns whether no element of a sequence satisfies a given `Predicate`.
     *
     *
     * ### Semantics and default implementation
     *
     * Equivalent to
       @code
            equal_to<
                find_if<Sequence, Predicate>::type,
                end<Sequence>::type
            >
       @endcode
     */
    template <typename Sequence, typename Predicate>
    struct none_of BOOST_MPL11_DOXYGEN_ONLY(<Sequence, Predicate>)
        : dispatch<tag::none_of, Sequence, Predicate>
    { };

    /*!
     * @ingroup algorithm
     *
     * Returns whether no element of a sequence is a `true`-valued boolean
     * `IntegralConstant`.
     *
     *
     * ### Semantics and default implementation
     *
     * Equivalent to `none_of<Sequence, _1>`.
     */
    template <typename Sequence>
    struct none_of<Sequence>
        : dispatch<tag::none_of, Sequence>
    { };
} // end namespace algorithm

template <typename Sequence>
struct dispatch<detail::default_<tag::none_of>, Sequence>
    : algorithm::none_of<Sequence, _1>
{ };

template <typename Sequence, typename Predicate>
struct dispatch<detail::default_<tag::none_of>, Sequence, Predicate>
    : intrinsic::equal_to<
        typename algorithm::find_if<Sequence, Predicate>::type,
        typename intrinsic::end<Sequence>::type
    >
{ };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_ALGORITHM_NONE_OF_HPP
