/*!
 * @file
 * Contains unit tests for the @ref Foldable typeclass.
 */

#include <boost/mpl11/foldable.hpp>

#include <boost/mpl11/core.hpp>
#include <boost/mpl11/test/foldable.hpp>


struct Minimal;
template <typename ...xs>
struct minimal_ { using mpl_datatype = Minimal; };

template <typename ...xs>
struct minimal { using type = minimal_<xs...>; };

namespace boost { namespace mpl11 {
    template <>
    struct Foldable<Minimal> : instantiate<Foldable>::with<Minimal> {
        template <typename f, typename z, typename t>
        struct foldr_impl : z { };

        template <typename f, typename z, typename x, typename ...xs>
        struct foldr_impl<f, z, minimal_<x, xs...>>
            : f::type::template apply<
                x, foldr_impl<f, z, minimal_<xs...>>
            >
        { };

        template <typename f, typename z, typename t>
        struct foldl_impl : z { };

        template <typename f, typename z, typename x, typename ...xs>
        struct foldl_impl<f, z, minimal_<x, xs...>>
            : foldl_impl<
                f, typename f::type::template apply<z, x>, minimal_<xs...>
            >
        { };
    };

#if 0
    template <>
    struct Foldable<FoldMap> : instantiate<Foldable>::with<FoldMap> {
        template <typename MonoidType, typename f, typename t>
        struct fold_map_impl : zero<MonoidType> { };

        template <typename MonoidType, typename f,
            template <typename ...> class t, typename x, typename ...xs>
        struct fold_map_impl<MonoidType, f, t<x, xs...>>
            : plus<
                typename f::type::template apply<x>,
                fold_map_impl<MonoidType, f, t<xs...>>
            >
        { };
    };
#endif
}} // end namespace boost::mpl11

struct tests
    : boost::mpl11::test::Foldable<minimal>
{ };


int main() { }
