/*!
 * @file
 * Defines `boost::mpl11::hset`.
 */

#ifndef BOOST_MPL11_HSET_HPP
#define BOOST_MPL11_HSET_HPP

#include <boost/mpl11/fwd/hset.hpp>

#include <boost/mpl11/and.hpp>
#include <boost/mpl11/associative_container.hpp>
#include <boost/mpl11/associative_sequence.hpp>
#include <boost/mpl11/begin.hpp>
#include <boost/mpl11/contains.hpp>
#include <boost/mpl11/detail/complete.hpp>
#include <boost/mpl11/detail/conditional.hpp>
#include <boost/mpl11/end.hpp>
#include <boost/mpl11/foldl.hpp>
#include <boost/mpl11/has_key.hpp>
#include <boost/mpl11/hash.hpp>
#include <boost/mpl11/identity.hpp>
#include <boost/mpl11/insert_keys.hpp>
#include <boost/mpl11/integral_c.hpp>
#include <boost/mpl11/join.hpp>
#include <boost/mpl11/not.hpp>
#include <boost/mpl11/push_back.hpp>
#include <boost/mpl11/vector.hpp>


namespace boost { namespace mpl11 {
namespace hset_detail {
    struct hset_class;

    template <typename Next, typename ...Elements>
    struct inserted
        : Next, detail::complete<Next, hash_t<Elements>, Elements>...
    {
        using contents = join<
            vector<Elements...>, typename Next::contents
        >;

        using mpl_class = hset_class;

        template <typename KeyHash, typename Element>
        friend true_
        hset_has_key(detail::complete<Next, KeyHash, Element>*, inserted*);

        template <typename KeyHash, typename Default, typename Element>
        friend identity<Element>
        hset_at_key(detail::complete<Next, KeyHash, Element>*, inserted*);
    };

    template <typename Next, typename ...Elements>
    struct erased
        : Next, detail::complete<Next, hash_t<Elements>, Elements>...
    {
        using mpl_class = hset_class;

        template <typename KeyHash, typename Element>
        friend false_
        hset_has_key(detail::complete<Next, KeyHash, Element>*, erased*);

        template <typename KeyHash, typename Default, typename Element>
        friend Default
        hset_at_key(detail::complete<Next, KeyHash, Element>*, erased*);
    };

    template <typename KeyHash>
    false_ hset_has_key(...);

    template <typename KeyHash, typename Default>
    Default hset_at_key(...);

    struct empty {
        using contents = vector<>;
        using mpl_class = hset_class;
    };

    template <typename Set>
    struct add_contents {
        template <typename Contents, typename Key>
        using apply = typename detail::conditional<
            and_<has_key<Set, Key>, not_<contains<Contents, Key>>>::value,
            push_back<Contents, Key>,
            identity<Contents>
        >::type;
    };

    template <typename Set>
    using contents = foldl_t<
        typename Set::contents, vector<>, add_contents<Set>
    >;

    //! @todo
    //! FIX THE IMPLEMENTATION OF ITERATORS. Use join and filter if possible.
    struct hset_class final : AssociativeSequence, AssociativeContainer {
        /////////////////////////////////
        // Sequence
        /////////////////////////////////
        template <typename Set>
        using begin_impl = begin<contents<Set>>;

        template <typename Set>
        using end_impl = end<contents<Set>>;

        //! @todo Remove this once Clang is fixed.
        using AssociativeSequence::length_impl;

        /////////////////////////////////
        // AssociativeSequence
        /////////////////////////////////
        template <typename Set, typename Key, typename Default>
        using at_key_def_impl = decltype(
            hset_at_key<hash_t<Key>, Default>(
                (Set*)nullptr, (Set*)nullptr
            )
        );

        template <typename Set, typename Key>
        using has_key_impl = decltype(
            hset_has_key<hash_t<Key>>(
                (Set*)nullptr, (Set*)nullptr
            )
        );

        template <typename Set, typename Element>
        using key_of_impl = identity<Element>;

        template <typename Set, typename Element>
        using value_of_impl = identity<Element>;

        /////////////////////////////////
        // Container
        /////////////////////////////////
        struct new_impl_ {
            template <typename Sequence>
            using apply = insert_keys<hset<>, Sequence>;
        };

        //! @todo Decide semantics and write unit test.
        template <typename Set>
        using new_impl = new_impl_;

        template <typename Set>
        using clear_impl = identity<hset<>>;

        /////////////////////////////////
        // AssociativeContainer
        /////////////////////////////////
        template <typename Set, typename Key>
        struct insert_key_impl {
            using type = inserted<Set, Key>;
        };

        template <typename Set, typename Key>
        struct erase_key_impl {
            using type = erased<Set, Key>;
        };
    };
} // end namespace hset_detail

template <typename ...Elements>
struct hset
    : hset_detail::inserted<hset_detail::empty, Elements...>
{ };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_HSET_HPP
