/*!
 * @file
 * Defines helpers to avoid repetition in the unit tests.
 */

#ifndef BOOST_MPL11_MINIMAL_REQUIREMENTS_HPP
#define BOOST_MPL11_MINIMAL_REQUIREMENTS_HPP

#include <boost/mpl11/apply.hpp>
#include <boost/mpl11/detail/optional.hpp>
#include <boost/mpl11/fwd/advance.hpp>
#include <boost/mpl11/fwd/associative_sequence.hpp>
#include <boost/mpl11/fwd/at_key.hpp>
#include <boost/mpl11/fwd/back_extensible_container.hpp>
#include <boost/mpl11/fwd/begin.hpp>
#include <boost/mpl11/fwd/bidirectional_iterator.hpp>
#include <boost/mpl11/fwd/bidirectional_sequence.hpp>
#include <boost/mpl11/fwd/clear.hpp>
#include <boost/mpl11/fwd/comparable.hpp>
#include <boost/mpl11/fwd/container.hpp>
#include <boost/mpl11/fwd/couple.hpp>
#include <boost/mpl11/fwd/deref.hpp>
#include <boost/mpl11/fwd/directional_sequence.hpp>
#include <boost/mpl11/fwd/distance.hpp>
#include <boost/mpl11/fwd/end.hpp>
#include <boost/mpl11/fwd/equal.hpp>
#include <boost/mpl11/fwd/first.hpp>
#include <boost/mpl11/fwd/forward_iterator.hpp>
#include <boost/mpl11/fwd/front_extensible_container.hpp>
#include <boost/mpl11/fwd/has_key.hpp>
#include <boost/mpl11/fwd/key_of.hpp>
#include <boost/mpl11/fwd/less.hpp>
#include <boost/mpl11/fwd/new.hpp>
#include <boost/mpl11/fwd/next.hpp>
#include <boost/mpl11/fwd/orderable.hpp>
#include <boost/mpl11/fwd/pop_back.hpp>
#include <boost/mpl11/fwd/pop_front.hpp>
#include <boost/mpl11/fwd/prev.hpp>
#include <boost/mpl11/fwd/push_back.hpp>
#include <boost/mpl11/fwd/push_front.hpp>
#include <boost/mpl11/fwd/random_access_iterator.hpp>
#include <boost/mpl11/fwd/random_access_sequence.hpp>
#include <boost/mpl11/fwd/second.hpp>
#include <boost/mpl11/fwd/sequence.hpp>
#include <boost/mpl11/fwd/value_of.hpp>


namespace boost { namespace mpl11 { namespace test {
    template <typename Class, typename T>
    struct wrapper {
        template <typename U>
        using rebind = wrapper<Class, U>;

        using mpl_class = Class;
    };

    template <typename T>
    struct unwrap;

    template <typename Class, typename T>
    struct unwrap<wrapper<Class, T>> {
        using type = T;
    };

    template <typename Concept, bool Inherit>
    struct minimal_requirements_base { };

    template <typename Concept>
    struct minimal_requirements_base<Concept, true>
        : Concept
    { };

    template <typename Concept, bool InheritConcept = true>
    struct minimal_requirements;

    template <bool Inherit>
    struct minimal_requirements<Comparable, Inherit>
        : minimal_requirements_base<Comparable, Inherit>
    {
        template <typename C1, typename C2>
        struct equal_impl
            : equal<typename unwrap<C1>::type, typename unwrap<C2>::type>
        { };
    };

    template <bool Inherit>
    struct minimal_requirements<Orderable, Inherit>
        : minimal_requirements_base<Orderable, Inherit>
    {
        template <typename O1, typename O2>
        struct less_impl
            : less<typename unwrap<O1>::type, typename unwrap<O2>::type>
        { };
    };

    template <bool Inherit>
    struct minimal_requirements<Couple, Inherit>
        : minimal_requirements_base<Couple, Inherit>
    {
        template <typename C>
        struct first_impl
            : first<typename unwrap<C>::type>
        { };

        template <typename C>
        struct second_impl
            : second<typename unwrap<C>::type>
        { };
    };

    //////////////////////////////////////////////////////////////////////////
    // Iterators
    //////////////////////////////////////////////////////////////////////////
    template <bool Inherit>
    struct minimal_requirements<ForwardIterator, Inherit>
        : minimal_requirements<Comparable, false>,
          minimal_requirements_base<ForwardIterator, Inherit>
    {
        template <typename I>
        struct next_impl {
            using type = typename I::template rebind<
                typename next<typename unwrap<I>::type>::type
            >;
        };

        template <typename I>
        struct deref_impl
            : deref<typename unwrap<I>::type>
        { };
    };

    template <bool Inherit>
    struct minimal_requirements<BidirectionalIterator, Inherit>
        : minimal_requirements<ForwardIterator, false>,
          minimal_requirements_base<BidirectionalIterator, Inherit>
    {
        template <typename I>
        struct prev_impl {
            using type = typename I::template rebind<
                typename prev<typename unwrap<I>::type>::type
            >;
        };
    };

    template <bool Inherit>
    struct minimal_requirements<RandomAccessIterator, Inherit>
        : minimal_requirements<BidirectionalIterator, false>,
          minimal_requirements_base<RandomAccessIterator, Inherit>
    {
        template <typename I, typename N>
        struct advance_impl {
            using type = typename I::template rebind<
                typename advance<typename unwrap<I>::type, N>::type
            >;
        };

        template <typename I1, typename I2>
        struct distance_impl
            : distance<typename unwrap<I1>::type, typename unwrap<I2>::type>
        { };
    };

    //////////////////////////////////////////////////////////////////////////
    // Sequences
    //////////////////////////////////////////////////////////////////////////
    template <bool Inherit>
    struct minimal_requirements<Sequence, Inherit>
        : minimal_requirements_base<Sequence, Inherit>
    {
        template <typename S>
        struct begin_impl {
            using type = wrapper<
                minimal_requirements<ForwardIterator>,
                typename begin<typename unwrap<S>::type>::type
            >;
        };

        template <typename S>
        struct end_impl {
            using type = wrapper<
                minimal_requirements<ForwardIterator>,
                typename end<typename unwrap<S>::type>::type
            >;
        };
    };

    template <>
    struct minimal_requirements<DirectionalSequence, false>
        : minimal_requirements<Sequence, false>,
          minimal_requirements<Comparable, false>,
          minimal_requirements<Orderable, false>
    { };

    template <>
    struct minimal_requirements<DirectionalSequence, true>
        : DirectionalSequence,
          minimal_requirements<DirectionalSequence, false>
    {
        using DirectionalSequence::equal_impl;
        using DirectionalSequence::less_impl;
    };

    template <bool Inherit>
    struct minimal_requirements<BidirectionalSequence, Inherit>
        : minimal_requirements<DirectionalSequence, false>,
          minimal_requirements_base<BidirectionalSequence, Inherit>
    {
        template <typename S>
        struct begin_impl {
            using type = wrapper<
                minimal_requirements<BidirectionalIterator>,
                typename begin<typename unwrap<S>::type>::type
            >;
        };

        template <typename S>
        struct end_impl {
            using type = wrapper<
                minimal_requirements<BidirectionalIterator>,
                typename end<typename unwrap<S>::type>::type
            >;
        };
    };

    template <bool Inherit>
    struct minimal_requirements<RandomAccessSequence, Inherit>
        : minimal_requirements<BidirectionalSequence, false>,
          minimal_requirements_base<RandomAccessSequence, Inherit>
    {
        template <typename S>
        struct begin_impl {
            using type = wrapper<
                minimal_requirements<RandomAccessIterator>,
                typename begin<typename unwrap<S>::type>::type
            >;
        };

        template <typename S>
        struct end_impl {
            using type = wrapper<
                minimal_requirements<RandomAccessIterator>,
                typename end<typename unwrap<S>::type>::type
            >;
        };
    };

    template <bool Inherit>
    struct minimal_requirements<AssociativeSequence, Inherit>
        : minimal_requirements<Sequence, false>,
          minimal_requirements_base<AssociativeSequence, Inherit>
    {
        template <typename S, typename K>
        struct has_key_impl
            : has_key<typename unwrap<S>::type, K>
        { };

        template <typename S, typename E>
        struct key_of_impl
            : key_of<typename unwrap<S>::type, E>
        { };

        template <typename S, typename E>
        struct value_of_impl
            : value_of<typename unwrap<S>::type, E>
        { };

        template <typename S, typename K, typename D = detail::optional>
        struct at_key_impl
            : at_key<typename unwrap<S>::type, K, D>
        { };

        template <typename S, typename K>
        struct at_key_impl<S, K>
            : AssociativeSequence::template at_key_impl<S, K>
        { };
    };

    //////////////////////////////////////////////////////////////////////////
    // Containers
    //////////////////////////////////////////////////////////////////////////
    template <bool Inherit>
    struct minimal_requirements<Container, Inherit>
        : minimal_requirements<Sequence, false>,
          minimal_requirements_base<Container, Inherit>
    {
        template <typename C>
        struct new_impl {
            template <typename Sequence>
            struct apply {
                using type = typename C::template rebind<
                    typename mpl11::apply<
                        new_<typename unwrap<C>::type>, Sequence
                    >::type
                >;
            };
        };

        template <typename C>
        struct clear_impl {
            using type = typename C::template rebind<
                typename clear<typename unwrap<C>::type>::type
            >;
        };
    };

    template <>
    struct minimal_requirements<BackExtensibleContainer, false>
        : minimal_requirements<Container, false>
    {
        template <typename C>
        struct pop_back_impl {
            using type = typename C::template rebind<
                typename pop_back<typename unwrap<C>::type>::type
            >;
        };

        template <typename C, typename X>
        struct push_back_impl {
            using type = typename C::template rebind<
                typename push_back<typename unwrap<C>::type, X>::type
            >;
        };
    };

    template <>
    struct minimal_requirements<BackExtensibleContainer, true>
        : minimal_requirements<BackExtensibleContainer, false>,
          BackExtensibleContainer
    {
        using BackExtensibleContainer::new_impl;
    };

    template <>
    struct minimal_requirements<FrontExtensibleContainer, false>
        : minimal_requirements<Container, false>
    {
        template <typename C>
        struct pop_front_impl {
            using type = typename C::template rebind<
                typename pop_front<typename unwrap<C>::type>::type
            >;
        };

        template <typename C, typename X>
        struct push_front_impl {
            using type = typename C::template rebind<
                typename push_front<typename unwrap<C>::type, X>::type
            >;
        };
    };

    template <>
    struct minimal_requirements<FrontExtensibleContainer, true>
        : minimal_requirements<FrontExtensibleContainer, false>,
          FrontExtensibleContainer
    {
        using FrontExtensibleContainer::new_impl;
    };
}}} // end namespace boost::mpl11::test

#endif // !BOOST_MPL11_MINIMAL_REQUIREMENTS_HPP
