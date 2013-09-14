/*!
 * @file
 * Defines `boost::mpl11::inserter::into`.
 */

#ifndef BOOST_MPL11_INSERTER_INTO_HPP
#define BOOST_MPL11_INSERTER_INTO_HPP

#include <boost/mpl11/detail/doxygen_only.hpp>
#include <boost/mpl11/detail/optional.hpp>


namespace boost { namespace mpl11 { namespace inserter {
    /*!
     * @ingroup inserters
     *
     *
     * ### Semantics of copy
     *
     * - `foldl<Sequence, clear<Sequence>::type, push_back<_1, _2>>` if
     *   `Sequence` is a @ref BackExtensibleSequence
     * - `foldr<Sequence, clear<Sequence>::type, push_front<_1, _2>>` if
     *   `Sequence` is a @ref FrontExtensibleSequence
     * - `foldl<Sequence, clear<Sequence>::type, insert<_1, _2>>` if
     *   `Sequence` is an @ref ExtensibleAssociativeSequence
     */
    template <typename Sequence, typename Operation = detail::optional>
    struct into BOOST_MPL11_DOXYGEN_ONLY({ });
}}} // end namespace boost::mpl11::inserter


#include <boost/mpl11/algorithm/foldl.hpp>
#include <boost/mpl11/algorithm/foldr.hpp>
#include <boost/mpl11/categories.hpp>
#include <boost/mpl11/dispatch.hpp>
#include <boost/mpl11/functional/quote.hpp>
#include <boost/mpl11/intrinsic/category_of.hpp>
#include <boost/mpl11/intrinsic/insert.hpp>
#include <boost/mpl11/intrinsic/push_back.hpp>
#include <boost/mpl11/intrinsic/push_front.hpp>
#include <boost/mpl11/tags.hpp>


namespace boost { namespace mpl11 {
namespace into_detail {
    template <typename From, typename To>
    auto copy_impl(category::back_extensible_sequence*, int)
        -> algorithm::foldl<From, To, quote<push_back>>
    ;

    template <typename From, typename To>
    auto copy_impl(category::extensible_associative_sequence*, int)
        -> algorithm::foldl<From, To, quote<insert>>
    ;

    template <typename From, typename To>
    auto copy_impl(category::front_extensible_sequence*, ...)
        -> algorithm::foldr<From, To, quote<push_front>>
    ;
} // end namespace into_detail

template <typename Source, typename Destination, typename Operation>
struct dispatch<tag::copy, Source, inserter::into<Destination, Operation>>
    : algorithm::foldl<Source, Destination, Operation>
{ };

template <typename Source, typename Destination>
struct dispatch<tag::copy, Source, inserter::into<Destination>>
    : decltype(
        into_detail::copy_impl<Source, Destination>(
            (typename category_of<Destination>::type*)nullptr, int()
        )
    )
{ };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_INSERTER_INTO_HPP
