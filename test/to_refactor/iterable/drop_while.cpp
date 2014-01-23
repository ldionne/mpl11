/*!
 * @file
 * Contains unit tests for `boost::mpl11::drop_while`.
 */

#include <boost/mpl11/iterable/drop_while.hpp>

#include <boost/mpl11/detail/iterable_test.hpp>
#include <boost/mpl11/integral_c.hpp>
#include <boost/mpl11/not.hpp>
#include <boost/mpl11/quote.hpp>


using namespace boost::mpl11;

template <int ...All>
struct dropping_leading_zeros {
    template <int ...Suffix>
    struct is
        : detail::iterable_test<
            drop_while<quote<not_>, detail::minimal_iterable<int_<All>...>>,
            int_<Suffix>...
        >
    { };
};

struct tests :
    dropping_leading_zeros<>::is<>,

    dropping_leading_zeros<0>::is<>,
    dropping_leading_zeros<1>::is<1>,

    dropping_leading_zeros<0, 0>::is<>,
    dropping_leading_zeros<0, 2>::is<2>,
    dropping_leading_zeros<1, 0>::is<1, 0>,
    dropping_leading_zeros<1, 2>::is<1, 2>,

    dropping_leading_zeros<0, 0, 0>::is<>,
    dropping_leading_zeros<0, 0, 3>::is<3>,
    dropping_leading_zeros<0, 2, 0>::is<2, 0>,
    dropping_leading_zeros<0, 2, 3>::is<2, 3>,
    dropping_leading_zeros<1, 0, 0>::is<1, 0, 0>,
    dropping_leading_zeros<1, 0, 3>::is<1, 0, 3>,
    dropping_leading_zeros<1, 2, 0>::is<1, 2, 0>,
    dropping_leading_zeros<1, 2, 3>::is<1, 2, 3>
{ };


int main() { }
