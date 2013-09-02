/*!
 * @file
 * Defines `boost::mpl11::algorithm::copy`.
 */

#ifndef BOOST_MPL11_ALGORITHM_COPY_HPP
#define BOOST_MPL11_ALGORITHM_COPY_HPP

#include <boost/mpl11/algorithm/foldl.hpp>
#include <boost/mpl11/algorithm/foldr.hpp>
#include <boost/mpl11/categories.hpp>
#include <boost/mpl11/detail/doxygen_only.hpp>
#include <boost/mpl11/detail/forward_decls.hpp>
#include <boost/mpl11/dispatch.hpp>
#include <boost/mpl11/intrinsic/category_of.hpp>
#include <boost/mpl11/intrinsic/insert.hpp>
#include <boost/mpl11/intrinsic/push_back.hpp>
#include <boost/mpl11/intrinsic/push_front.hpp>
#include <boost/mpl11/quote.hpp>
#include <boost/mpl11/tags.hpp>


namespace boost { namespace mpl11 {
namespace algorithm {
    /*!
     * @ingroup algorithm
     *
     * Copies the content of a sequence from a sequence to another using a
     * custom operation for insertion.
     *
     *
     * ### Semantics and default implementation
     *
     * Equivalent to `foldl<From, To, Insert>`.
     *
     *
     * @warning
     * Differences from the original MPL:
     * - Inserters are not used in this version; the destination sequence and
     *   the operation are specified separately.
     */
    template <typename From, typename To, typename Insert>
    struct copy BOOST_MPL11_DOXYGEN_ONLY(<From, To, Insert>)
        : dispatch<tag::copy, From, To, Insert>
    { };

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
        : dispatch<tag::copy, From, To>
    { };
} // end namespace algorithm

namespace copy_detail {
    template <typename From, typename To>
    auto copy_impl(category::back_extensible_sequence*, int)
        -> algorithm::foldl<From, To, quote<intrinsic::push_back>>
    ;

    template <typename From, typename To>
    auto copy_impl(category::extensible_associative_sequence*, int)
        -> algorithm::foldl<From, To, quote<intrinsic::insert>>
    ;

    template <typename From, typename To>
    auto copy_impl(category::front_extensible_sequence*, ...)
        -> algorithm::foldr<From, To, quote<intrinsic::push_front>>
    ;
} // end namespace copy_detail

template <typename From, typename To, typename Insert>
struct dispatch<detail::default_<tag::copy>, From, To, Insert>
    : algorithm::foldl<From, To, Insert>
{ };

template <typename From, typename To>
struct dispatch<detail::default_<tag::copy>, From, To>
    : decltype(
        copy_detail::copy_impl<From, To>(
            (typename intrinsic::category_of<To>::type*)nullptr, int()
        )
    )
{ };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_ALGORITHM_COPY_HPP
