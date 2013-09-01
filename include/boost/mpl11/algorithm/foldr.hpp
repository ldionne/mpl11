/*!
 * @file
 * Defines `boost::mpl11::algorithm::foldr`.
 */

#ifndef BOOST_MPL11_ALGORITHM_FOLDR_HPP
#define BOOST_MPL11_ALGORITHM_FOLDR_HPP

#include <boost/mpl11/algorithm/iter_foldr.hpp>
#include <boost/mpl11/always.hpp>
#include <boost/mpl11/apply_wrap.hpp>
#include <boost/mpl11/arg.hpp>
#include <boost/mpl11/detail/tag_dispatched.hpp>
#include <boost/mpl11/intrinsic/deref.hpp>
#include <boost/mpl11/lambda.hpp>
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
     * Equivalent to
       @code
            iter_foldr<
                Sequence, State,
                apply_wrap<lambda<F>::type, _1, deref<_2>>
            >
       @endcode
     */
    template <typename Sequence, typename State, typename F>
    struct foldr
        : detail::tag_dispatched<tag::foldr, Sequence, State, F>
          ::template with_default<
            lazy_always<
                iter_foldr<
                    Sequence,
                    State,
                    apply_wrap<
                        typename lambda<F>::type, _1, intrinsic::deref<_2>
                    >
                >
            >
          >
    { };
}}} // end namespace boost::mpl11::algorithm

#endif // !BOOST_MPL11_ALGORITHM_FOLDR_HPP
