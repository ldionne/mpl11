/*!
 * @file
 * Contains unit tests for `boost::mpl11::filter`.
 */

#include <boost/mpl11/iterable/filter.hpp>

#include <boost/mpl11/detail/iterable_test.hpp>
#include <boost/mpl11/id.hpp>
#include <boost/mpl11/integral_c.hpp>
#include <boost/mpl11/quote.hpp>


using namespace boost::mpl11;

template <int ...All>
struct nonzeros {
    template <int ...Filtered>
    struct are
        : detail::iterable_test<
            filter<quote<id>, detail::minimal_iterable<int_<All>...>>,
            int_<Filtered>...
        >
    { };
};

struct tests :
    nonzeros<>::are<>,

    nonzeros<0>::are<>,
    nonzeros<1>::are<1>,

    nonzeros<0, 0>::are<>,
    nonzeros<1, 0>::are<1>,
    nonzeros<0, 2>::are<2>,
    nonzeros<1, 2>::are<1, 2>,

    nonzeros<0, 0, 0>::are<>,
    nonzeros<0, 0, 3>::are<3>,
    nonzeros<0, 2, 0>::are<2>,
    nonzeros<0, 2, 3>::are<2, 3>,
    nonzeros<1, 0, 0>::are<1>,
    nonzeros<1, 0, 3>::are<1, 3>,
    nonzeros<1, 2, 0>::are<1, 2>,
    nonzeros<1, 2, 3>::are<1, 2, 3>
{ };


int main() { }
