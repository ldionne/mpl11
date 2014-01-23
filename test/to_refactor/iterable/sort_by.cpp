/*!
 * @file
 * Contains unit tests for `boost::mpl11::sort_by`.
 */

#include <boost/mpl11/iterable/sort_by.hpp>

#include <boost/mpl11/detail/iterable_test.hpp>
#include <boost/mpl11/integral_c.hpp>


using namespace boost::mpl11;

template <typename Pred, int ...It>
struct sorting_by {
    template <int ...Sorted>
    struct is
        : detail::iterable_test<
            sort_by<Pred, detail::minimal_iterable<int_<It>...>>,
            int_<Sorted>...
        >
    { };
};

//! @todo Generate more data by using a permutation generator.
template <typename Less>
struct sort_less :
    sorting_by<Less>::template is<>,
    sorting_by<Less, 0>::template is<0>,
    sorting_by<Less, 0, 1>::template is<0, 1>,
    sorting_by<Less, 1, 0>::template is<0, 1>,
    sorting_by<Less, 0, 1, 2>::template is<0, 1, 2>,
    sorting_by<Less, 1, 0, 2>::template is<0, 1, 2>,
    sorting_by<Less, 5, 1, 0, 2, 3, 0>::template is<0, 0, 1, 2, 3, 5>
{ };

struct tests :
    sort_less<quote<less>>,
    sort_less<quote<less_equal>>
{ };


int main() { }
