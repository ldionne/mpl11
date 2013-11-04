/*!
 * @file
 * Contains unit tests for `boost::mpl11::FrontExtensibleContainer`.
 */

#include <boost/mpl11/front_extensible_container.hpp>

#include <boost/mpl11/apply.hpp>
#include <boost/mpl11/begin.hpp>
#include <boost/mpl11/clear.hpp>
#include <boost/mpl11/detail/is_same.hpp>
#include <boost/mpl11/end.hpp>
#include <boost/mpl11/new.hpp>
#include <boost/mpl11/pop_front.hpp>
#include <boost/mpl11/push_front.hpp>
#include <boost/mpl11/vector.hpp>


using namespace boost::mpl11;
using detail::is_same;

template <typename Impl>
struct minimal_front_extensible_container {
    struct mpl_class : FrontExtensibleContainer {
        template <typename> using begin_impl = begin<Impl>;
        template <typename> using end_impl = end<Impl>;

        template <typename, typename X>
        struct push_front_impl {
            using type = minimal_front_extensible_container<
                typename push_front<Impl, X>::type
            >;
        };

        template <typename>
        struct pop_front_impl {
            using type = minimal_front_extensible_container<
                typename pop_front<Impl>::type
            >;
        };

        template <typename>
        struct clear_impl {
            using type = minimal_front_extensible_container<
                typename clear<Impl>::type
            >;
        };
    };
};

template <typename ...T>
using container = minimal_front_extensible_container<vector<T...>>;

struct x; struct y; struct z;

//! @todo
//! Don't assume that `push_front<vector<>, X>::type` is `vector<X>`.
//! If we used a different implementation for `push_front` for a `vector`,
//! the test below could break.

// push_front
static_assert(is_same<
    push_front<container<>, x>::type, container<x>
>::value, "");
static_assert(is_same<
    push_front<container<x>, y>::type, container<y, x>
>::value, "");
static_assert(is_same<
    push_front<container<y, x>, z>::type, container<z, y, x>
>::value, "");

// pop_front
static_assert(is_same<
    pop_front<container<x>>::type, container<>
>::value, "");
static_assert(is_same<
    pop_front<container<x, y>>::type, container<y>
>::value, "");
static_assert(is_same<
    pop_front<container<x, y, z>>::type, container<y, z>
>::value, "");

// new_
static_assert(is_same<
    apply<new_<container<>>>::type, container<>
>::value, "");
static_assert(is_same<
    apply<new_<container<>>, x>::type, container<x>
>::value, "");
static_assert(is_same<
    apply<new_<container<>>, x, y>::type, container<x, y>
>::value, "");
static_assert(is_same<
    apply<new_<container<>>, x, y, z>::type, container<x, y, z>
>::value, "");


int main() { }
