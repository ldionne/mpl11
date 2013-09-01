/*!
 * @file
 * Defines `boost::mpl11::algorithm::copy`.
 */

#ifndef BOOST_MPL11_ALGORITHM_COPY_HPP
#define BOOST_MPL11_ALGORITHM_COPY_HPP

#include <boost/mpl11/algorithm/foldl.hpp>
#include <boost/mpl11/algorithm/foldr.hpp>
#include <boost/mpl11/always.hpp>
#include <boost/mpl11/arg.hpp>
#include <boost/mpl11/categories.hpp>
#include <boost/mpl11/detail/doxygen_only.hpp>
#include <boost/mpl11/detail/optional.hpp>
#include <boost/mpl11/detail/tag_dispatched.hpp>
#include <boost/mpl11/intrinsic/category_of.hpp>
#include <boost/mpl11/intrinsic/insert.hpp>
#include <boost/mpl11/intrinsic/push_back.hpp>
#include <boost/mpl11/intrinsic/push_front.hpp>
#include <boost/mpl11/lambda.hpp>
#include <boost/mpl11/tags.hpp>


namespace boost { namespace mpl11 {
namespace algorithm {
    /*!
     * @ingroup algorithm
     *
     * Overloaded algorithm for copying elements from a sequence to another.
     */
    template <typename From, typename To, typename Insert = detail::optional>
    struct copy;

    /*!
     * @ingroup algorithm
     *
     * Copies the content of a sequence from a sequence to another using a
     * custom operation for insertion.
     *
     *
     * ### Semantics and default implementation
     *
     * Equivalent to `foldl<From, To, lambda<Insert>::type>`.
     *
     *
     * @warning
     * Differences from the original MPL:
     * - Inserters are not used in this version; the destination sequence and
     *   the operation are specified separately.
     */
    template <typename From, typename To, typename Insert>
    struct copy BOOST_MPL11_DOXYGEN_ONLY(<From, To, Insert>)
        : detail::tag_dispatched<tag::copy, From, To, Insert>::template
          with_default<
            lazy_always<
                foldl<From, To, typename lambda<Insert>::type>
            >
          >
    { };
} // end namespace algorithm

namespace copy_detail {
    template <typename From, typename To>
    auto copy_dispatch(category::back_extensible_sequence*, int)
        -> algorithm::foldl<From, To, intrinsic::push_back<_1, _2>>
    ;

    template <typename From, typename To>
    auto copy_dispatch(category::extensible_associative_sequence*, int)
        -> algorithm::foldl<From, To, intrinsic::insert<_1, _2>>
    ;

    template <typename From, typename To>
    auto copy_dispatch(category::front_extensible_sequence*, ...)
        -> algorithm::foldr<From, To, intrinsic::push_front<_1, _2>>
    ;

    template <typename From, typename To>
    struct pick_best_copy
        : decltype(
            copy_dispatch<From, To>(
                (typename intrinsic::category_of<To>::type*)nullptr, int()
            )
        )
    { };
} // end namespace copy_detail

namespace algorithm {
    /*!
     * @ingroup algorithm
     *
     * Copies the content of a sequence from a sequence to another.
     *
     *
     * ### Semantics and default implementation
     *
     * Equivalent to
     * - `foldl<From, To, push_back<_1, _2>>` for `BackExtensibleSequence`s
     * - `foldr<From, To, push_front<_1, _2>>` for `FrontExtensibleSequence`s
     * - `foldl<From, To, insert<_1, _2>>` for
     *   `ExtensibleAssociativeSequence`s
     *
     *
     * @warning
     * Differences from the original MPL:
     * - Inserters are not used in this version.
     * - It is mandatory to specify a destination sequence.
     */
    template <typename From, typename To>
    struct copy<From, To>
        : detail::tag_dispatched<tag::copy, From, To>::template
          with_default<
            lazy_always<
                copy_detail::pick_best_copy<From, To>
            >
          >
    { };
} // end namespace algorithm
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_ALGORITHM_COPY_HPP
