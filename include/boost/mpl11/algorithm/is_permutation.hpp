/*!
 * @file
 * Defines `boost::mpl11::algorithm::is_permutation`.
 */

#ifndef BOOST_MPL11_ALGORITHM_IS_PERMUTATION_HPP
#define BOOST_MPL11_ALGORITHM_IS_PERMUTATION_HPP

#include <boost/mpl11/algorithm/count_if.hpp>
#include <boost/mpl11/apply_wrap.hpp>
#include <boost/mpl11/arg.hpp>
#include <boost/mpl11/bool.hpp>
#include <boost/mpl11/detail/doxygen_only.hpp>
#include <boost/mpl11/detail/optional.hpp>
#include <boost/mpl11/dispatch.hpp>
#include <boost/mpl11/identity.hpp>
#include <boost/mpl11/integral_c.hpp>
#include <boost/mpl11/intrinsic/and.hpp>
#include <boost/mpl11/intrinsic/begin.hpp>
#include <boost/mpl11/intrinsic/deref.hpp>
#include <boost/mpl11/intrinsic/end.hpp>
#include <boost/mpl11/intrinsic/equal_to.hpp>
#include <boost/mpl11/intrinsic/next.hpp>
#include <boost/mpl11/intrinsic/not_equal_to.hpp>
#include <boost/mpl11/intrinsic/size.hpp>
#include <boost/mpl11/lambda.hpp>
#include <boost/mpl11/quote.hpp>
#include <boost/mpl11/tags.hpp>
#include <boost/mpl11/view/bounded_by.hpp>


namespace boost { namespace mpl11 {
namespace algorithm {
    /*!
     * @ingroup algorithm
     *
     * Overloaded algorithm for determining whether a sequence is a
     * permutation of another.
     */
    template <typename Sequence1,
              typename Sequence2,
              typename Predicate = detail::optional>
    struct is_permutation;

    /*!
     * @ingroup algorithm
     *
     * Returns whether a sequence is a permutation of another sequence,
     * using a custom predicate to determine the equality of two elements.
     *
     *
     * ### Semantics and default implementation
     *
     * The default implementation returns whether both sequences have the
     * same number of elements and whether each element appear the same
     * number of times in each sequence.
     */
    template <typename Sequence1, typename Sequence2, typename Predicate>
    struct is_permutation
    BOOST_MPL11_DOXYGEN_ONLY(<Sequence1, Sequence2, Predicate>)
        : dispatch<tag::is_permutation, Sequence1, Sequence2, Predicate>
    { };

    /*!
     * @ingroup algorithm
     *
     * Returns whether a sequence is a permutation of another sequence.
     *
     *
     * ### Semantics and default implementation
     *
     * Equivalent to `is_permutation<Sequence1, Sequence2, equal_to<_1, _2>>`.
     */
    template <typename Sequence1, typename Sequence2>
    struct is_permutation<Sequence1, Sequence2>
        : dispatch<tag::is_permutation, Sequence1, Sequence2>
    { };
} // end namespace algorithm

namespace is_permutation_detail {
    //////////////////////////////////////////////////////////////////////////
    // A very simple set-like class to support O1 membership testing.
    template <typename T> struct wrap { };

    struct empty_basic_set {
        template <typename Element>
        static false_ has_key(wrap<Element>);
    };

    template <typename Element, typename Next>
    struct basic_set : Next {
        using Next::has_key;
        static true_ has_key(wrap<Element>);
    };
    //////////////////////////////////////////////////////////////////////////

    template <typename T, typename U>
    struct lazy_equal_to
        : intrinsic::equal_to<typename T::type, typename U::type>
    { };

    template <typename Sequence1, typename Sequence2, typename Predicate>
    class is_permutation_impl {
        using Last = typename intrinsic::end<Sequence1>::type;

        template <typename Iter, typename Counted,
                  bool = intrinsic::equal_to<Iter, Last>::type::value>
        struct contains_same_elements;

        template <typename Iter, typename Counted,
                  typename Element = typename intrinsic::deref<Iter>::type,
                  bool = decltype(Counted::has_key(wrap<Element>{}))::value>
        struct continue_;

        template <typename Iter, typename Counted>
        struct contains_same_elements<Iter, Counted, true /* Iter == Last */>
            : identity<true_>
        { };

        template <typename Iter, typename Counted>
        struct contains_same_elements<Iter, Counted, false /* Iter == Last */>
            : continue_<Iter, Counted>
        { };

        template <typename Iter, typename Counted>
        struct check_next
            : contains_same_elements<
                typename intrinsic::next<Iter>::type, Counted
            >
        { };

        template <typename Iter, typename Counted, typename Element>
        struct continue_<Iter, Counted, Element, true /* already counted */>
            : check_next<Iter, Counted>
        { };

        template <typename Iter, typename Counted, typename Element>
        struct continue_<Iter, Counted, Element, false /* already counted */> {
            using Pred = typename lambda<
                apply_wrap<Predicate, Element, _1>
            >::type;

            using InSequence1 = algorithm::count_if<
                view::bounded_by<Iter, Last>, Pred
            >;

            using InSequence2 = algorithm::count_if<
                Sequence2, Pred
            >;

            using type = typename intrinsic::and_<
                intrinsic::not_equal_to<typename InSequence2::type, ulong<0>>,
                lazy_equal_to<InSequence1, InSequence2>,
                check_next<Iter, basic_set<Element, Counted>>
            >::type;
        };

    public:
        using type = typename intrinsic::and_<
            intrinsic::equal_to<
                typename intrinsic::size<Sequence1>::type,
                typename intrinsic::size<Sequence2>::type
            >,
            contains_same_elements<
                typename intrinsic::begin<Sequence1>::type,
                empty_basic_set
            >
        >::type;
    };
} // end namespace is_permutation_detail

template <typename S1, typename S2, typename Pred>
struct dispatch<detail::default_<tag::is_permutation>, S1, S2, Pred>
    : is_permutation_detail::is_permutation_impl<
        S1, S2, typename lambda<Pred>::type
    >
{ };

template <typename S1, typename S2>
struct dispatch<detail::default_<tag::is_permutation>, S1, S2>
    : algorithm::is_permutation<S1, S2, quote<intrinsic::equal_to>>
{ };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_ALGORITHM_IS_PERMUTATION_HPP
