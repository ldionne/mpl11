/*!
 * @file
 * Defines `boost::mpl11::hset`.
 */

#ifndef BOOST_MPL11_HSET_HPP
#define BOOST_MPL11_HSET_HPP

#include <boost/mpl11/fwd/hset.hpp>

#include <boost/mpl11/and.hpp>
#include <boost/mpl11/arg.hpp>
#include <boost/mpl11/associative_container.hpp>
#include <boost/mpl11/associative_sequence.hpp>
#include <boost/mpl11/begin.hpp>
#include <boost/mpl11/contains.hpp>
#include <boost/mpl11/detail/complete.hpp>
#include <boost/mpl11/detail/vector_concat.hpp>
#include <boost/mpl11/end.hpp>
#include <boost/mpl11/foldl.hpp>
#include <boost/mpl11/has_key.hpp>
#include <boost/mpl11/hash.hpp>
#include <boost/mpl11/identity.hpp>
#include <boost/mpl11/if.hpp>
#include <boost/mpl11/insert_keys.hpp>
#include <boost/mpl11/integral_c.hpp>
#include <boost/mpl11/lambda.hpp>
#include <boost/mpl11/not.hpp>
#include <boost/mpl11/push_back.hpp>
#include <boost/mpl11/vector.hpp>


namespace boost { namespace mpl11 {
namespace hset_detail {
    struct hset_class;

    template <typename Next, typename ...Elements>
    struct inserted
        : Next, detail::complete<
            Next, hash_t<Elements>, Elements
        >...
    {
        using contents = typename detail::vector_concat<
            vector<Elements...>, typename Next::contents
        >::type;

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
        : Next, detail::complete<
            Next, hash_t<Elements>, Elements
        >...
    {
        using mpl_class = hset_class;

        template <typename KeyHash, typename Element>
        friend false_
        hset_has_key(detail::complete<Next, KeyHash, Element>*, erased*);

        template <typename KeyHash, typename Default, typename Element>
        friend identity<Default>
        hset_at_key(detail::complete<Next, KeyHash, Element>*, erased*);
    };

    struct empty {
        using contents = vector<>;

        using mpl_class = hset_class;

        template <typename KeyHash>
        friend false_ hset_has_key(void*, empty*);

        template <typename KeyHash, typename Default>
        friend identity<Default> hset_at_key(void*, empty*);
    };

    template <typename Set>
    using contents = foldl_t<
        typename Set::contents,
        vector<>,
        lambda<
            if_<and_<has_key<Set, _2>, not_<contains<_1, _2>>>,
                push_back<_1, _2>,
                _1
            >
        >
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
