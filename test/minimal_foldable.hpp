/*!
 * @file
 * Defines the `minimal_foldable` helper for unit tests.
 */

#ifndef BOOST_MPL11_TEST_MINIMAL_FOLDABLE_HPP
#define BOOST_MPL11_TEST_MINIMAL_FOLDABLE_HPP

#include <boost/mpl11/foldable.hpp>


struct MinimalFoldable;

template <typename ...x>
struct minimal_foldable {
    using type = minimal_foldable;
    using mpl_datatype = MinimalFoldable;
};

namespace boost { namespace mpl11 {
    template <>
    struct Foldable<MinimalFoldable> {
    private:
        template <typename f, typename state, typename structure>
        struct fold_left : state { };

        template <typename f, typename state, typename x, typename ...xs>
        struct fold_left<f, state, minimal_foldable<x, xs...>>
            : fold_left<
                f,
                typename f::type::template apply<state, x>,
                minimal_foldable<xs...>
            >
        { };


        template <typename f, typename state, typename structure>
        struct fold_right : state { };

        template <typename f, typename state, typename x, typename ...xs>
        struct fold_right<f, state, minimal_foldable<x, xs...>>
            : f::type::template apply<
                x, fold_right<f, state, minimal_foldable<xs...>>
            >
        { };


        template <typename f, typename structure>
        struct fold_right1;

        template <typename f, typename x>
        struct fold_right1<f, minimal_foldable<x>> : x { };

        template <typename f, typename x, typename ...xs>
        struct fold_right1<f, minimal_foldable<x, xs...>>
            : f::type::template apply<
                x, fold_right1<f, minimal_foldable<xs...>>
            >
        { };

    public:
        template <typename f, typename structure>
        struct foldl1_impl
            : foldl1_impl<f, typename structure::type>
        { };

        template <typename f, typename x, typename ...xs>
        struct foldl1_impl<f, minimal_foldable<x, xs...>>
            : fold_left<f, x, minimal_foldable<xs...>>
        { };

        template <typename f, typename structure>
        using foldr1_impl = fold_right1<f, typename structure::type>;

        template <typename f, typename state, typename structure>
        using foldl_impl = fold_left<f, state, typename structure::type>;

        template <typename f, typename state, typename structure>
        using foldr_impl = fold_right<f, state, typename structure::type>;
    };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_TEST_MINIMAL_FOLDABLE_HPP
