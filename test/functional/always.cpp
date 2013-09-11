/*!
 * @file
 * Contains unit tests for `boost::mpl11::always` and
 * `boost::mpl11::lazy_always`.
 */

#include <boost/mpl11/functional/always.hpp>

#include <boost/mpl11/detail/has_type.hpp>
#include <boost/mpl11/functional/apply_wrap.hpp>
#include <boost/mpl11/operator/equal_to.hpp>


using namespace boost::mpl11;
using detail::has_type;

struct a0; struct a1;

namespace test_always {
    static_assert(equal_to<
        apply_wrap<always<struct anything>>::type,
        struct anything
    >::type::value, "");

    static_assert(equal_to<
        apply_wrap<always<struct anything>, a0>::type,
        struct anything
    >::type::value, "");

    static_assert(equal_to<
        apply_wrap<always<struct anything>, a0, a1>::type,
        struct anything
    >::type::value, "");
}

namespace test_lazy_always {
    struct metafunction { struct type; };

    static_assert(equal_to<
        apply_wrap<lazy_always<metafunction>>::type,
        metafunction::type
    >::type::value, "");

    static_assert(equal_to<
        apply_wrap<lazy_always<metafunction>, a0>::type,
        metafunction::type
    >::type::value, "");

    static_assert(equal_to<
        apply_wrap<lazy_always<metafunction>, a0, a1>::type,
        metafunction::type
    >::type::value, "");
}

template <typename NotAMetafunction>
void test_lazy_SFINAE_friendlyness() {
    static_assert(!has_type<
        typename lazy_always<NotAMetafunction>::template apply<>
    >::value, "");

    static_assert(!has_type<
        typename lazy_always<NotAMetafunction>::template apply<a0>
    >::value, "");

    static_assert(!has_type<
        typename lazy_always<NotAMetafunction>::template apply<a0, a1>
    >::value, "");
}

struct incomplete;
struct not_a_metafunction { };
using non_class = void;


int main() {
    test_lazy_SFINAE_friendlyness<incomplete>();
    test_lazy_SFINAE_friendlyness<not_a_metafunction>();
    test_lazy_SFINAE_friendlyness<non_class>();
}
