/*!
 * @file
 * Contains unit tests for `boost::mpl11::detail::move`.
 */

#include <boost/mpl11/detail/move.hpp>

#include <boost/mpl11/detail/is_same.hpp>


using namespace boost::mpl11;
using detail::is_same;
using detail::move;

template <typename Integer>
struct increment { using type = typename Integer::next; };

template <typename Integer>
struct decrement { using type = typename Integer::prev; };

template <int i>
struct integer {
    using next = integer<i + 1>;
    using prev = integer<i - 1>;
};

#define BOOST_MPL11_ASSERT_INCREMENT(START, INCREMENT)                      \
    static_assert(is_same<                                                  \
        move<increment, integer<(START)>, (INCREMENT)>::type,               \
        integer<(START) + (INCREMENT)>                                      \
    >::value, "")                                                           \
/**/

#define BOOST_MPL11_ASSERT_DECREMENT(START, DECREMENT)                      \
    static_assert(is_same<                                                  \
        move<decrement, integer<(START)>, (DECREMENT)>::type,               \
        integer<(START) - (DECREMENT)>                                      \
    >::value, "")                                                           \
/**/

BOOST_MPL11_ASSERT_INCREMENT(0, 0);
BOOST_MPL11_ASSERT_INCREMENT(0, 1);
BOOST_MPL11_ASSERT_INCREMENT(0, 2);
BOOST_MPL11_ASSERT_INCREMENT(0, 3);
BOOST_MPL11_ASSERT_INCREMENT(1, 0);
BOOST_MPL11_ASSERT_INCREMENT(1, 1);
BOOST_MPL11_ASSERT_INCREMENT(1, 2);
BOOST_MPL11_ASSERT_INCREMENT(1, 3);
BOOST_MPL11_ASSERT_INCREMENT(2, 0);
BOOST_MPL11_ASSERT_INCREMENT(2, 1);
BOOST_MPL11_ASSERT_INCREMENT(2, 2);
BOOST_MPL11_ASSERT_INCREMENT(2, 3);

BOOST_MPL11_ASSERT_DECREMENT(0, 0);
BOOST_MPL11_ASSERT_DECREMENT(0, 1);
BOOST_MPL11_ASSERT_DECREMENT(0, 2);
BOOST_MPL11_ASSERT_DECREMENT(0, 3);
BOOST_MPL11_ASSERT_DECREMENT(1, 0);
BOOST_MPL11_ASSERT_DECREMENT(1, 1);
BOOST_MPL11_ASSERT_DECREMENT(1, 2);
BOOST_MPL11_ASSERT_DECREMENT(1, 3);
BOOST_MPL11_ASSERT_DECREMENT(2, 0);
BOOST_MPL11_ASSERT_DECREMENT(2, 1);
BOOST_MPL11_ASSERT_DECREMENT(2, 2);
BOOST_MPL11_ASSERT_DECREMENT(2, 3);


int main() { }
