/*!
 * @file
 * Forward declares `boost::mpl11::count_if`.
 */

#ifndef BOOST_MPL11_ALGORITHM_COUNT_IF_FWD_HPP
#define BOOST_MPL11_ALGORITHM_COUNT_IF_FWD_HPP

#include <boost/mpl11/dispatch.hpp>


namespace boost { namespace mpl11 {
    namespace tag { struct count_if; }

    /*!
     * @ingroup algorithms
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
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_ALGORITHM_COUNT_IF_FWD_HPP
