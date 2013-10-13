/*!
 * @file
 * Contains unit tests for `boost::mpl11::algorithm::distance`.
 */

#include <boost/mpl11/distance.hpp>

#include <boost/mpl11/categories.hpp>
#include <boost/mpl11/dispatch.hpp>
#include <boost/mpl11/identity.hpp>
#include <boost/mpl11/tags.hpp>


template <int Position>
struct iterator;

namespace boost { namespace mpl11 {
    template <int Position>
    struct dispatch<tag::category_of, iterator<Position>>
        : identity<category::forward_iterator>
    { };

    template <int Position>
    struct dispatch<tag::next, iterator<Position>>
        : identity<iterator<Position + 1>>
    { };

    template <int Position>
    struct dispatch<tag::deref, iterator<Position>>
        : identity<iterator<Position>>
    { };
}} // end namespace boost::mpl11

using namespace boost::mpl11;
using algorithm::distance;

static_assert(distance<
    iterator<0>, iterator<0>
>::type::value == 0, "");

static_assert(distance<
    iterator<0>, iterator<1>
>::type::value == 1, "");

static_assert(distance<
    iterator<0>, iterator<2>
>::type::value == 2, "");

static_assert(distance<
    iterator<2>, iterator<5>
>::type::value == 3, "");


int main() { }
