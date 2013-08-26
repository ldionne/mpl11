/*!
 * @file
 * Defines `boost::mpl11::is_permutation`.
 */

#ifndef BOOST_MPL11_IS_PERMUTATION_HPP
#define BOOST_MPL11_IS_PERMUTATION_HPP

#include <boost/mpl11/detail/tag_dispatched.hpp>

namespace boost { namespace mpl11 {
namespace is_permutation_detail {
    template <typename Sequence1, typename Sequence2, typename Predicate>
    class is_same_size_permutation_impl {
        using First1 = typename begin<Sequence1>::type;
        using Last1 = typename end<Sequence1>::type;

        template <typename Iter>
        struct apply_next
            : apply<typename next<Iter>::type>
        { };

        template <typename Iter>
        struct satisfies_predicate_for {
            template <typename Element>
            struct apply
                : apply_wrap<Predicate, typename deref<Iter>::type, Element>
            { };
        };

        template <typename Iter>
        struct compare_counts {
            using InSequence1 = count_if<
                iterator_range<Iter, Last1>,
                satisfies_predicate_for<Iter>
            >;

            using InSequence2 = count_if<
                Sequence2,
                satisfies_predicate_for<Iter>
            >;

            using type = typename and_<
                not_eq_<InSequence2, ulong<0>>,
                eq<InSequence1, InSequence2>,
                apply_next<Iter>
            >::type;
        };

        template <typename Iter>
        struct was_already_counted
            : any_of<
                iterator_range<First1, Iter>,
                satisfies_predicate_for<Iter>
            >
        { };

        template <typename Iter>
        struct apply
            : if_<was_already_counted<Iter>,
                apply_next<Iter>,
                compare_counts<Iter>
            >
        { };

    public:
        using type = typename apply<First1>::type;
    };

    template <typename Sequence1, typename Sequence2, typename Predicate>
    struct is_permutation_impl
        : and_<
            eq<size<Sequence1>, size<Sequence2>>,
            is_same_size_permutation_impl<Sequence1, Sequence2, Predicate>
        >
    { };
} // end namespace is_permutation_detail


namespace tag { struct is_permutation; }


template <typename Sequence1, typename Sequence2, typename ...Predicate>
struct is_permutation {
    static_assert(false, "");
    struct type;
};

/*!
 *
 */
template <typename Sequence1, typename Sequence2, typename Predicate>
struct is_permutation<Sequence1, Sequence2, Predicate>
    : detail::tag_dispatched<
        tag::is_permutation, Sequence1, Sequence2, Predicate
      >::template with_default<
        is_permutation_detail::is_permutation_impl<_2, _3, lambda<_4>>
      >
{ };

template <typename Sequence1, typename Sequence2>
struct is_permutation<Sequence1, Sequence2>
    : detail::tag_dispatched<tag::is_permutation, Sequence1, Sequence2>
      ::template with_default<is_permutation<_2, _3, quote<is_same>>>
{ };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_IS_PERMUTATION_HPP
