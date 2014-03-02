/*!
 * @file
 * Contains unit tests for `boost::mpl11::detail::strict_variadic_foldl`.
 */

#include <boost/mpl11/detail/strict_variadic_foldl.hpp>

#include <boost/mpl11/detail/std_is_same.hpp>
#include <boost/mpl11/functional.hpp>
#include <boost/mpl11/integer.hpp>


using namespace boost::mpl11;

template <typename x, typename y>
struct f { using type = f<typename x::type, typename y::type>; };

template <int state, int ...xs>
struct folding {
    template <typename f_expr>
    struct is {
        static_assert(detail::std_is_same<
            typename detail::strict_variadic_foldl<
                quote<f>, int_<state>, int_<xs>...
            >::type,
            f_expr
        >::value, "");
    };
};

struct tests :
    folding<0>::is<int_<0>>,

    folding<0, 1>::is<f<int_<0>, int_<1>>>,

    folding<0, 1, 2>::is<
        f<f<int_<0>, int_<1>>, int_<2>>
    >,

    folding<0, 1, 2, 3>::is<
        f<f<f<int_<0>, int_<1>>, int_<2>>, int_<3>>
    >,

    folding<0, 1, 2, 3, 4>::is<
        f<f<f<f<int_<0>, int_<1>>, int_<2>>, int_<3>>, int_<4>>
    >
{ };


int main() { }
