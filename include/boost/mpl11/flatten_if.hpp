/*!
 * @file
 * Defines `boost::mpl11::flatten_if`.
 */

#ifndef BOOST_MPL11_FLATTEN_IF_HPP
#define BOOST_MPL11_FLATTEN_IF_HPP

#include <boost/mpl11/fwd/flatten_if.hpp>

#include <boost/mpl11/apply.hpp>
#include <boost/mpl11/begin.hpp>
#include <boost/mpl11/deref.hpp>
#include <boost/mpl11/detail/adaptors.hpp>
#include <boost/mpl11/detail/conditional.hpp>
#include <boost/mpl11/end.hpp>
#include <boost/mpl11/fwd/class_of.hpp>
#include <boost/mpl11/identity.hpp>
#include <boost/mpl11/is_empty.hpp>
#include <boost/mpl11/iterator_range.hpp>
#include <boost/mpl11/join.hpp>
#include <boost/mpl11/new.hpp>
#include <boost/mpl11/next.hpp>
#include <boost/mpl11/vector.hpp>


namespace boost { namespace mpl11 {
namespace flatten_if_detail {
    template <typename Sequence, typename Predicate>
    struct nonempty_adapted {
        using Begin = begin_t<Sequence>;
        using End = end_t<Sequence>;
        using FirstElement = deref_t<Begin>;

        using type = join<
            typename detail::conditional<
                apply_t<Predicate, FirstElement>::value,
                FirstElement,
                vector<FirstElement>
            >::type,
            flatten_if<
                iterator_range<next_t<Begin>, End>,
                Predicate
            >
        >;
    };

    struct flatten_if_class final : detail::sequence_adaptor {
        template <typename Flatten>
        struct adapted_impl;

        template <typename Sequence, typename Predicate>
        struct adapted_impl<flatten_if<Sequence, Predicate>>
            : detail::conditional<is_empty<Sequence>::value,
                identity<vector<>>,
                nonempty_adapted<Sequence, Predicate>
            >::type
        { };
    };
} // end namespace flatten_if_detail

template <typename Sequence, typename Predicate, typename Default>
struct class_of<flatten_if<Sequence, Predicate>, Default> {
    using type = flatten_if_detail::flatten_if_class;
};

template <typename Sequence, typename Predicate>
struct flatten_if
    : apply<new_<Sequence>, flatten_if<Sequence, Predicate>>
{ };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FLATTEN_IF_HPP
