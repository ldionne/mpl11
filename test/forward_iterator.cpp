/*!
 * @file
 * Contains unit tests for `boost::mpl11::ForwardIterator`.
 */

#include <boost/mpl11/forward_iterator.hpp>

#include <boost/mpl11/advance.hpp>
#include <boost/mpl11/deref.hpp>
#include <boost/mpl11/detail/is_same.hpp>
#include <boost/mpl11/distance.hpp>
#include <boost/mpl11/integral_c.hpp>
#include <boost/mpl11/next.hpp>


using namespace boost::mpl11;
using detail::is_same;

template <unsigned int i>
struct iterator {
    static constexpr auto position = i;

    struct mpl_class : ForwardIterator {
        template <typename Self, typename Other>
        struct equal_impl
            : bool_<Self::position == Other::position>
        { };

        template <typename Self>
        struct next_impl {
            using type = iterator<Self::position + 1>;
        };

        template <typename Self>
        struct deref_impl {
            using type = Self;
        };
    };
};

// next
static_assert(next<iterator<0>>::type::position == 0 + 1, "");
static_assert(next<iterator<1>>::type::position == 1 + 1, "");
static_assert(next<iterator<2>>::type::position == 2 + 1, "");


// deref
static_assert(is_same<deref<iterator<0>>::type, iterator<0>>::value, "");
static_assert(is_same<deref<iterator<1>>::type, iterator<1>>::value, "");
static_assert(is_same<deref<iterator<2>>::type, iterator<2>>::value, "");


// advance
static_assert(advance_c<iterator<0>, 0>::type::position == 0 + 0, "");
static_assert(advance_c<iterator<0>, 1>::type::position == 0 + 1, "");
static_assert(advance_c<iterator<0>, 2>::type::position == 0 + 2, "");

static_assert(advance_c<iterator<1>, 0>::type::position == 1 + 0, "");
static_assert(advance_c<iterator<1>, 1>::type::position == 1 + 1, "");
static_assert(advance_c<iterator<1>, 2>::type::position == 1 + 2, "");

static_assert(advance_c<iterator<2>, 0>::type::position == 2 + 0, "");
static_assert(advance_c<iterator<2>, 1>::type::position == 2 + 1, "");
static_assert(advance_c<iterator<2>, 2>::type::position == 2 + 2, "");

static_assert(advance_c<iterator<0>, 100>::type::position == 0 + 100, "");


// distance
static_assert(distance<iterator<0>, iterator<0>>::value == 0 - 0, "");
static_assert(distance<iterator<0>, iterator<1>>::value == 1 - 0, "");
static_assert(distance<iterator<0>, iterator<2>>::value == 2 - 0, "");

static_assert(distance<iterator<1>, iterator<1>>::value == 1 - 1, "");
static_assert(distance<iterator<1>, iterator<2>>::value == 2 - 1, "");
static_assert(distance<iterator<1>, iterator<3>>::value == 3 - 1, "");

static_assert(distance<iterator<2>, iterator<2>>::value == 2 - 2, "");
static_assert(distance<iterator<2>, iterator<3>>::value == 3 - 2, "");
static_assert(distance<iterator<2>, iterator<4>>::value == 4 - 2, "");

static_assert(distance<iterator<0>, iterator<100>>::value == 100 - 0, "");


int main() { }
