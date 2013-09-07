/*!
 * @file
 * Defines `boost::mpl11::algorithm::foldr`.
 */

#ifndef BOOST_MPL11_ALGORITHM_FOLDR_HPP
#define BOOST_MPL11_ALGORITHM_FOLDR_HPP

#include <boost/mpl11/dispatch.hpp>
#include <boost/mpl11/tags.hpp>


namespace boost { namespace mpl11 { namespace algorithm {
    /*!
     * @ingroup algorithm
     *
     * Accumulates the elements of a sequence from an initial state using a
     * custom operation.
     *
     * Specifically, returns the result of the successive application of the
     * binary operation `F` to the result of the next `F` invocation (or
     * `State` for the first application) and every element of the sequence
     * in order.
     *
     *
     * ### Semantics and default implementation
     *
     * Equivalent to the following:
     * Let `First` be the same as `begin<Sequence>::type` and  `Last`
     * the same as `end<Sequence>::type`. `foldr` is equivalent to
     * `foldr_impl<First, Last, State, F>`, where `foldr_impl` is
     * equivalent to `identity<State>` if `equal_to<First, Last>::type::value`
     * is `true` and
       @code
            apply<
                F,
                foldr_impl<next<First>::type, Last, State, F>::type,
                deref<First>::type
            >
       @endcode
     * otherwise.
     */
    template <typename Sequence, typename State, typename F>
    struct foldr
        : dispatch<tag::foldr, Sequence, State, F>
    { };
}}} // end namespace boost::mpl11::algorithm

#ifndef BOOST_MPL11_DONT_INCLUDE_DEFAULTS
#   include <boost/mpl11/detail/default/foldr.hpp>
#endif

#endif // !BOOST_MPL11_ALGORITHM_FOLDR_HPP
