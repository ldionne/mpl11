/*!
 * @file
 * Contains unit tests for variadic folds.
 */

#include <boost/mpl11/detail/lazy_variadic_foldr.hpp>
#include <boost/mpl11/detail/strict_variadic_foldl.hpp>

#include <boost/mpl11/test/foldable.hpp>


struct Test;
template <typename ...xs>
struct foldable_ { using mpl_datatype = Test; };

template <typename ...xs>
struct foldable { using type = foldable_<xs...>; };

namespace boost { namespace mpl11 {
    template <>
    struct Foldable<Test> : instantiate<Foldable>::with<Test> {
        template <typename f, typename z, typename t>
        struct foldr_impl;

        template <typename f, typename z, typename t>
        struct foldl_impl;


        template <typename f, typename z, typename ...xs>
        struct foldr_impl<f, z, foldable_<xs...>>
            : detail::lazy_variadic_foldr<f, z, xs...>
        { };

        template <typename f, typename z, typename ...xs>
        struct foldl_impl<f, z, foldable_<xs...>>
            : detail::strict_variadic_foldl<f, z, xs...>
        { };
    };
}}

struct tests
    : boost::mpl11::test::Foldable<foldable>
{ };


int main() { }
