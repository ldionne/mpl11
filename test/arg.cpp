/*!
 * @file
 * Contains unit tests for `boost::mpl11::arg`.
 */

#include <boost/mpl11/arg.hpp>

#include <boost/mpl11/apply.hpp>
#include <boost/mpl11/detail/is_same.hpp>


using namespace boost::mpl11;
using detail::is_same;

template <int> struct x { struct type; };

template <unsigned long N> struct arg_number {
    template <int ...Args> struct of {
        template <int X> struct is {
            static_assert(is_same<
                apply_t<arg<N>, x<Args>...>,
                typename x<X>::type
            >::value, "");
        };
    };
};

struct tests :
    arg_number<1>::of<1>::is<1>,
    arg_number<1>::of<1, 2>::is<1>,
    arg_number<1>::of<1, 2, 3>::is<1>,
    arg_number<1>::of<1, 2, 3, 4>::is<1>,

    arg_number<2>::of<1, 2>::is<2>,
    arg_number<2>::of<1, 2, 3>::is<2>,
    arg_number<2>::of<1, 2, 3, 4>::is<2>,
    arg_number<2>::of<1, 2, 3, 4, 5>::is<2>,

    arg_number<3>::of<1, 2, 3>::is<3>,
    arg_number<3>::of<1, 2, 3, 4>::is<3>,
    arg_number<3>::of<1, 2, 3, 4, 5>::is<3>
{ };


int main() { }
