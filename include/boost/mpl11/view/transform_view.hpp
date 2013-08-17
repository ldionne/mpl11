/*!
 * @file
 * This file defines the `boost::mpl11::transform_view` view.
 */

#ifndef BOOST_MPL11_VIEW_TRANSFORM_VIEW_HPP
#define BOOST_MPL11_VIEW_TRANSFORM_VIEW_HPP

namespace boost { namespace mpl11 { inline namespace v2 {
namespace transform_view_detail {
using wrapped_by_transform_iterator = set<
    intrinsic::next, intrinsic::prior, algorithm::advance
>;

template <typename Iterator, typename UnaryOp>
class transform_iterator {
    struct implementation {
        template <typename Operation, typename ...Args>
        struct apply
            : if_<has_key<wrapped_by_transform_iterator, Operation>,
                transform_iterator<
                    typename mpl11::apply<Operation, Iterator, Args...>::type,
                    UnaryOp
                >
            >
        { };

        template <typename ...Ignore>
        struct apply<intrinsic::deref, Ignore...> {
            using type = typename mpl11::apply<
                UnaryOp, typename deref<Iterator>::type
            >::type;
        };
    };
};
} // end namespace transform_view_detail

template <typename Sequence, typename UnaryOp>
class transform_view {
    template <typename Operation, typename ...Args>
    using forward = apply<Operation, Sequence, Args...>;

    template <typename Operation, typename ...Args>
    struct apply_to_forwarded
        : eval<apply<
            UnaryOp,
            eval<forward<Operation, Args...>>
        >>
    { };

    template <typename Operation, typename ...Args>
    struct forward_transformed {
        using type = typename apply<
            Operation, typename transform<Sequence, UnaryOp>::type, Args...
        >::type;
    };

    template <typename Operation, typename ...Args>
    struct wrap_forwarded {
        using type = transform_view<
            typename forward<Operation, Args...>::type, UnaryOp
        >;
    };

    struct implementation {
        template <typename Operation, typename ...Args>
        struct apply;

        template <typename ...Args>
        struct apply<intrinsic::at, Args...>
            : apply_to_forwarded<intrinsic::at, Args...>
        { };

        template <typename ...Ignore>
        struct apply<intrinsic::back, Ignore...>
            : apply_to_forwarded<intrinsic::back>
        { };

        template <typename ...Ignore>
        struct apply<intrinsic::begin, Ignore...> {
            using type = transform_iterator<
                typename begin<Sequence>::type, UnaryOp
            >;
        };

        template <typename ...Ignore>
        struct apply<intrinsic::clear, Ignore...>
            : wrap_forwarded<intrinsic::clear>
        { };

        template <typename ...Ignore>
        struct apply<intrinsic::empty, Ignore...>
            : forward<intrinsic::empty>
        { };

        template <typename ...Ignore>
        struct apply<intrinsic::end, Ignore...> {
            using type = transform_iterator<
                typename end<Sequence>::type, UnaryOp
            >;
        };

        template <typename ...Ignore>
        struct apply<intrinsic::size, Ignore...>
            : forward<intrinsic::size>
        { };

        // quoi faire pour les trucs genre erase? par exemple, pour erase_key
        // il faudrait qu'on le fasse sur la séquence transformée. est-ce
        // que c'est souhaitable ou on la rend juste pas disponible?
        // c'est sûrement la raison pour laquelle les views de la mpl actuelle
        // n'implémentent pas ce genre d'intrinsics.


        // On peut aller chercher des bonnes optimisations en forwardant
        // certains algorithmes après avoir utilisé transform sur notre
        // sequence. le résultat est équivalent mais on n'utilise pas le
        // transform_iterator et les algos par défaut, ce qui peut être
        // dramatiquement plus rapide.
        template <typename F, typename Inserter>
        struct apply<algorithm::transform, F, Inserter>
            : forward_transformed<algorithm::transform, F, Inserter>
        { };

        template <typename Inserter>
        struct apply<algorithm::copy, Inserter>
            : forward_transformed<algorithm::copy, Inserter>
        { };
    };

public:
    struct mpl11 {
        using dispatcher = implementation;
    };
};
}}}

#endif // !BOOST_MPL11_VIEW_TRANSFORM_VIEW_HPP
