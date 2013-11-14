/*!
 * @file
 * Defines `boost::mpl11::imap`.
 */

#ifndef BOOST_MPL11_IMAP_HPP
#define BOOST_MPL11_IMAP_HPP

#include <boost/mpl11/fwd/imap.hpp>

#include <boost/mpl11/associative_container.hpp>
#include <boost/mpl11/associative_sequence.hpp>
#include <boost/mpl11/detail/conditional.hpp>
#include <boost/mpl11/detail/dependent_on.hpp>
#include <boost/mpl11/detail/is_same.hpp>
#include <boost/mpl11/detail/no_decay.hpp>
#include <boost/mpl11/detail/optional.hpp>
#include <boost/mpl11/first.hpp>
#include <boost/mpl11/forward_iterator.hpp>
#include <boost/mpl11/fwd/class_of.hpp>
#include <boost/mpl11/identity.hpp>
#include <boost/mpl11/integral_c.hpp>
#include <boost/mpl11/second.hpp>


namespace boost { namespace mpl11 {
namespace imap_detail {
    struct imap_class;
    struct iterator_class;

    template <typename ...Elements>
    struct iterator;

    // The past-the-end iterator.
    template <>
    struct iterator<> {
        struct mpl_class final : ForwardIterator {
            template <typename Self>
            struct deref_impl {
                static_assert(
                detail::dependent_on<Self>::template value<bool, false>(),
                "Trying to dereference a past-the-end `imap` iterator.");

                struct type;
            };

            template <typename Self>
            struct next_impl {
                static_assert(
                detail::dependent_on<Self>::template value<bool, false>(),
                "Trying to increment a past-the-end `imap` iterator.");

                struct type;
            };

            // IMPORTANT: Don't use `Self` here. Otherwise, `Self` might
            // sometimes be an erased iterator whose next iterator is the
            // past-the-end iterator, since they share the same mpl_class.
            template <typename Self, typename Other>
            using equal_impl = detail::is_same<iterator /*not Self*/, Other>;
        };

    protected:
        friend imap_class;

        template <typename Default>
        static auto at_key(...) -> identity<Default>;

        static auto has_key(...) -> false_;
    };

    // Erased elements are skipped by iterators.
    struct erased;
    template <typename ...Rest>
    struct iterator<erased, Rest...>
        : iterator<Rest...>
    { };

    template <typename Current, typename ...Rest>
    struct iterator<Current, Rest...> : iterator<Rest...> {
        struct mpl_class final : ForwardIterator {
            template <typename>
            using deref_impl = identity<Current>;

            template <typename>
            using next_impl = identity<iterator<Rest...>>;

            template <typename Self, typename Other>
            using equal_impl = detail::is_same<Self, Other>;
        };

    protected:
        friend imap_class;
        using Key = typename first<Current>::type;

        using iterator<Rest...>::at_key;
        template <typename Default>
        static auto at_key(detail::no_decay<Key>*) -> second<Current>;

        using iterator<Rest...>::has_key;
        static auto has_key(detail::no_decay<Key>*) -> true_;
    };

    struct imap_class final : AssociativeSequence, AssociativeContainer {
        /////////////////////////////////
        // Sequence
        /////////////////////////////////
        template <typename Map> struct begin_impl;
        template <typename Map> struct end_impl;

        template <typename ...Elements>
        struct begin_impl<imap<Elements...>> {
            using type = iterator<Elements...>;
        };

        template <typename Map>
        struct end_impl {
            using type = iterator<>;
        };

        /////////////////////////////////
        // AssociativeSequence
        /////////////////////////////////
        template <
           typename Map, typename Key, typename Default = detail::optional
        >
        struct at_key_impl;
        template <typename Map, typename Key>
        struct has_key_impl;
        template <typename Map, typename Element>
        struct key_of_impl;
        template <typename Map, typename Element>
        struct value_of_impl;

        template <typename ...Elements, typename Key>
        struct at_key_impl<imap<Elements...>, Key>
            : AssociativeSequence::template at_key_impl<imap<Elements...>, Key>
        { };

        template <typename ...Elements, typename Key, typename Default>
        struct at_key_impl<imap<Elements...>, Key, Default>
            : decltype(
                iterator<Elements...>::template at_key<Default>(
                    (detail::no_decay<Key>*)nullptr
                )
            )
        { };

        template <typename ...Elements, typename Key>
        struct has_key_impl<imap<Elements...>, Key>
            : decltype(
                iterator<Elements...>::has_key(
                    (detail::no_decay<Key>*)nullptr
                )
            )
        { };

        template <typename Map, typename Element>
        struct key_of_impl
            : first<Element>
        { };

        template <typename Map, typename Element>
        struct value_of_impl
            : second<Element>
        { };

        /////////////////////////////////
        // Container
        /////////////////////////////////
        template <typename Map> struct new_impl;
        template <typename Map> struct clear_impl;

        //! @todo Decide the semantics of new_ for `imap` and test it.
        template <typename Map>
        struct new_impl {
            template <typename ...Elements>
            struct apply {
                using type = imap<Elements...>;
            };
        };

        template <typename Map>
        struct clear_impl {
            using type = imap<>;
        };

        /////////////////////////////////
        // AssociativeContainer
        /////////////////////////////////
        template <typename Map, typename Element>
        struct insert_key_impl;
        template <typename Map, typename Key>
        struct erase_key_impl;

        template <typename ...T, typename Element>
        struct insert_key_impl<imap<T...>, Element> {
            using type = imap<
                Element,
                typename detail::conditional<
                    detail::is_same<
                        typename first<Element>::type,
                        typename first<T>::type
                    >::value,
                    erased,
                    T
                >::type...
            >;
        };

        template <typename ...Elements, typename Key>
        struct erase_key_impl<imap<Elements...>, Key> {
            using type = imap<
                typename detail::conditional<
                    detail::is_same<
                        Key, typename first<Elements>::type
                    >::value,
                    erased,
                    Elements
                >::type...
            >;
        };
    };
} // end namespace imap_detail

template <typename ...Elements>
struct class_of<imap<Elements...>> {
    using type = imap_detail::imap_class;
};
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_IMAP_HPP
