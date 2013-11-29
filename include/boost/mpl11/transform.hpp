/*!
 * @file
 * Defines `boost::mpl11::transform`.
 */

#ifndef BOOST_MPL11_TRANSFORM_HPP
#define BOOST_MPL11_TRANSFORM_HPP

#include <boost/mpl11/fwd/transform.hpp>

#include <boost/mpl11/apply.hpp>
#include <boost/mpl11/detail/adaptors.hpp>
#include <boost/mpl11/detail/nested_alias.hpp>
#include <boost/mpl11/fwd/begin.hpp>
#include <boost/mpl11/fwd/class_of.hpp>
#include <boost/mpl11/fwd/deref.hpp>
#include <boost/mpl11/fwd/end.hpp>
#include <boost/mpl11/fwd/unpack.hpp>
#include <boost/mpl11/new.hpp>


namespace boost { namespace mpl11 {
namespace transform_detail {
    template <typename Iterator, typename F>
    struct transform_iterator;

    struct transform_iterator_class final
        : detail::random_access_iterator_adaptor
    {
        template <typename Iterator>                   struct deref_impl;
        template <typename Self, typename NewIterator> struct adapt_impl;
        template <typename Iterator>                   struct adapted_impl;

        template <typename Iterator, typename F>
        struct deref_impl<transform_iterator<Iterator, F>>
            : apply<F, deref_t<Iterator>>
        { };

        template <typename Old, typename F, typename NewIterator>
        struct adapt_impl<transform_iterator<Old, F>, NewIterator> {
            using type = transform_iterator<NewIterator, F>;
        };

        template <typename Iterator, typename F>
        struct adapted_impl<transform_iterator<Iterator, F>> {
            using type = Iterator;
        };
    };

    struct transform_class final : detail::sequence_adaptor {
        template <typename Sequence>                   struct begin_impl;
        template <typename Sequence>                   struct end_impl;
        template <typename Self, typename NewSequence> struct adapt_impl;
        template <typename Sequence>                   struct adapted_impl;

        template <typename Sequence, typename F>
        struct begin_impl<transform<Sequence, F>> {
            using type = transform_iterator<begin_t<Sequence>, F>;
        };

        template <typename Sequence, typename F>
        struct end_impl<transform<Sequence, F>> {
            using type = transform_iterator<end_t<Sequence>, F>;
        };

        template <typename Old, typename F, typename NewSequence>
        struct adapt_impl<transform<Old, F>, NewSequence> {
            using type = transform<NewSequence, F>;
        };

        template <typename Sequence, typename F>
        struct adapted_impl<transform<Sequence, F>> {
            using type = Sequence;
        };
    };

    template <typename F, typename Destination>
    struct fast_transform_into {
        template <typename ...Args>
        BOOST_MPL11_NESTED_ALIAS(apply,
            mpl11::apply<Destination, apply_t<F, Args>...>);
    };
} // end namespace transform_detail

template <typename Sequence, typename F>
struct transform
    : apply<new_<Sequence>, transform<Sequence, F>>
{ };

template <typename Sequence, typename F, typename Default>
struct class_of<transform<Sequence, F>, Default> {
    using type = transform_detail::transform_class;
};

template <typename Iterator, typename F, typename Default>
struct class_of<transform_detail::transform_iterator<Iterator, F>, Default> {
    using type = transform_detail::transform_iterator_class;
};

template <typename Sequence, typename F, typename Dest>
struct unpack<transform<Sequence, F>, Dest>
    : unpack<Sequence, transform_detail::fast_transform_into<F, Dest>>
{ };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_TRANSFORM_HPP
