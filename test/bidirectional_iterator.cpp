/*!
 * @file
 * Contains unit tests for `boost::mpl11::BidirectionalIterator`.
 */

#include <boost/mpl11/bidirectional_iterator.hpp>

#include <boost/mpl11/advance.hpp>
#include <boost/mpl11/detail/is_same.hpp>
#include <boost/mpl11/integral_c.hpp>
#include <boost/mpl11/prev.hpp>


using namespace boost::mpl11;
using detail::is_same;

template <int i>
struct iterator {
    static constexpr auto position = i;

    struct mpl_class : BidirectionalIterator {
        template <typename Self, typename Other>
        struct equal_impl
            : bool_<Self::position == Other::position>
        { };

        template <typename Self>
        struct next_impl {
            using type = iterator<Self::position + 1>;
        };

        template <typename Self>
        struct prev_impl {
            using type = iterator<Self::position - 1>;
        };
    };
};

// prev
static_assert(prev<iterator<0>>::type::position == 0 - 1, "");
static_assert(prev<iterator<1>>::type::position == 1 - 1, "");
static_assert(prev<iterator<2>>::type::position == 2 - 1, "");


// advance (negative)
static_assert(advance_c<iterator<-2>, -2>::type::position == -2 - 2, "");
static_assert(advance_c<iterator<-2>, -1>::type::position == -2 - 1, "");

static_assert(advance_c<iterator<-1>, -2>::type::position == -1 - 2, "");
static_assert(advance_c<iterator<-1>, -1>::type::position == -1 - 1, "");

static_assert(advance_c<iterator<0>, -2>::type::position == 0 - 2, "");
static_assert(advance_c<iterator<0>, -1>::type::position == 0 - 1, "");

static_assert(advance_c<iterator<1>, -2>::type::position == 1 - 2, "");
static_assert(advance_c<iterator<1>, -1>::type::position == 1 - 1, "");

static_assert(advance_c<iterator<2>, -2>::type::position == 2 - 2, "");
static_assert(advance_c<iterator<2>, -1>::type::position == 2 - 1, "");


// advance (positive or null)
static_assert(advance_c<iterator<0>, 0>::type::position == 0 + 0, "");
static_assert(advance_c<iterator<0>, 1>::type::position == 0 + 1, "");
static_assert(advance_c<iterator<0>, 2>::type::position == 0 + 2, "");

static_assert(advance_c<iterator<1>, 0>::type::position == 1 + 0, "");
static_assert(advance_c<iterator<1>, 1>::type::position == 1 + 1, "");
static_assert(advance_c<iterator<1>, 2>::type::position == 1 + 2, "");

static_assert(advance_c<iterator<2>, 0>::type::position == 2 + 0, "");
static_assert(advance_c<iterator<2>, 1>::type::position == 2 + 1, "");
static_assert(advance_c<iterator<2>, 2>::type::position == 2 + 2, "");


int main() { }
