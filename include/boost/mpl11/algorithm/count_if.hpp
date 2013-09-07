/*!
 * @file
 * Defines `boost::mpl11::algorithm::count_if`.
 */

#ifndef BOOST_MPL11_ALGORITHM_COUNT_IF_HPP
#define BOOST_MPL11_ALGORITHM_COUNT_IF_HPP

#include <boost/mpl11/dispatch.hpp>
#include <boost/mpl11/tags.hpp>


namespace boost { namespace mpl11 { namespace algorithm {
    /*!
     * @ingroup algorithm
     *
     * Returns the number of elements in `Sequence` satisfying `Predicate`.
     *
     *
     * ### Semantics and default implementation
     *
     * Equivalent to
       @code
            foldl<
                Sequence, ulong<0>,
                if_<apply_wrap<lambda<Predicate>::type, _2>,
                    next<_1>,
                    _1
                >
            >
       @endcode
     */
    template <typename Sequence, typename Predicate>
    struct count_if
        : dispatch<tag::count_if, Sequence, Predicate>
    { };
}}} // end namespace boost::mpl11::algorithm

#ifndef BOOST_MPL11_DONT_INCLUDE_DEFAULTS
#   include <boost/mpl11/detail/default/count_if.hpp>
#endif

#endif // !BOOST_MPL11_ALGORITHM_COUNT_IF_HPP
