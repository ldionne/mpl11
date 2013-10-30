/*!
 * @file
 * Contains unit tests for `boost::mpl11::Sequence`.
 */

#include <boost/mpl11/sequence.hpp>

#include <boost/mpl11/begin.hpp>
#include <boost/mpl11/detail/is_same.hpp>
#include <boost/mpl11/end.hpp>
#include <boost/mpl11/forward_iterator.hpp>
#include <boost/mpl11/integral_c.hpp>
#include <boost/mpl11/is_empty.hpp>
#include <boost/mpl11/size.hpp>


using namespace boost::mpl11;
using detail::is_same;

template <unsigned long Position>
struct iterator {
    static constexpr auto position = Position;

    struct mpl_class : ForwardIterator {
        template <typename Self, typename Other>
        struct equal_impl
            : bool_<Self::position == Other::position>
        { };

        template <typename Self>
        struct next_impl {
            using type = iterator<Self::position + 1>;
        };
    };
};

template <unsigned long Size>
struct sequence {
    static constexpr auto size = Size;

    struct mpl_class : Sequence {
        template <typename Self>
        struct begin_impl { using type = iterator<0>; };

        template <typename Self>
        struct end_impl { using type = iterator<Self::size>; };
    };
};

// begin
static_assert(is_same<begin<sequence<0>>::type, iterator<0>>::value, "");
static_assert(is_same<begin<sequence<1>>::type, iterator<0>>::value, "");
static_assert(is_same<begin<sequence<2>>::type, iterator<0>>::value, "");

// end
static_assert(is_same<end<sequence<0>>::type, iterator<0>>::value, "");
static_assert(is_same<end<sequence<1>>::type, iterator<1>>::value, "");
static_assert(is_same<end<sequence<2>>::type, iterator<2>>::value, "");

// size
static_assert(size<sequence<0>>::value == 0, "");
static_assert(size<sequence<1>>::value == 1, "");
static_assert(size<sequence<2>>::value == 2, "");
static_assert(size<sequence<3>>::value == 3, "");
static_assert(size<sequence<4>>::value == 4, "");

// is_empty
static_assert( is_empty<sequence<0>>::value, "");
static_assert(!is_empty<sequence<1>>::value, "");
static_assert(!is_empty<sequence<2>>::value, "");
static_assert(!is_empty<sequence<3>>::value, "");


int main() { }
