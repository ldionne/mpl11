/*!
 * @file
 * Contains unit tests for `boost::mpl11::inherit`.
 */

#include <boost/mpl11/inherit.hpp>

#include <boost/mpl11/detail/is_same.hpp>
#include <boost/mpl11/detail/is_specialization.hpp>


using namespace boost::mpl11;

template <typename ...Bases>
struct test_one {
    static_assert(!detail::is_specialization<
        typename inherit<Bases...>::type
    >::value, "");

    template <typename ...>
    struct all_different { };

    template <typename Base, typename ...Rest>
    struct all_different<Base, Rest...> : all_different<Rest...> {
        static_assert(!detail::is_same<
            typename inherit<Bases...>::type, Base
        >::value, "");
    };

    struct instantiate_all_different
        : all_different<Bases...>
    { };
};

template <int i> struct base { };

struct test_all
    : test_one<>,
      test_one<base<0>>,
      test_one<base<0>, base<1>>,
      test_one<base<0>, base<1>, base<2>>
{ };


int main() { }
