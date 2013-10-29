/*!
 * @file
 * Contains unit tests for `boost::mpl11::advance`.
 */

#include <boost/mpl11/advance.hpp>

#include <boost/mpl11/category/bidirectional_iterator.hpp>
#include <boost/mpl11/category/forward_iterator.hpp>
#include <boost/mpl11/category/random_access_iterator.hpp>
#include <boost/mpl11/dispatch.hpp>
#include <boost/mpl11/fwd/category_of.hpp>
#include <boost/mpl11/fwd/next.hpp>
#include <boost/mpl11/fwd/prior.hpp>
#include <boost/mpl11/identity.hpp>


template <typename Category, int Position>
struct iterator {
    static constexpr int position = Position;
};

namespace boost { namespace mpl11 {
    template <typename Category, int Position>
    struct dispatch<tag::category_of, iterator<Category, Position>>
        : identity<Category>
    { };

    template <typename Category, int Position>
    struct dispatch<tag::next, iterator<Category, Position>>
        : identity<iterator<Category, Position + 1>>
    { };

    template <typename Category, int Position>
    struct dispatch<tag::prior, iterator<Category, Position>>
        : identity<iterator<Category, Position - 1>>
    { };
}} // end namespace boost::mpl11

using namespace boost::mpl11;

template <typename Category>
void test_forward_iterator() {
    static_assert(advance_c<
        iterator<Category, 0>, 0
    >::type::position == 0, "");

    static_assert(advance_c<
        iterator<Category, 0>, 1
    >::type::position == 1, "");

    static_assert(advance_c<
        iterator<Category, 0>, 2
    >::type::position == 2, "");

    static_assert(advance_c<
        iterator<Category, 2>, 3
    >::type::position == 5, "");
}

template <typename Category>
void test_bidirectional_iterator() {
    test_forward_iterator<Category>();

    static_assert(advance_c<
        iterator<Category, 0>, -1
    >::type::position == -1, "");

    static_assert(advance_c<
        iterator<Category, -3>, -4
    >::type::position == -7, "");

    static_assert(advance_c<
        iterator<Category, -3>, 0
    >::type::position == -3, "");
}

template <typename Category>
void test_random_access_iterator() {
    test_bidirectional_iterator<Category>();
    // nothing to add.
}


int main() {
    test_forward_iterator<category::forward_iterator>();
    test_bidirectional_iterator<category::bidirectional_iterator>();
    test_random_access_iterator<category::random_access_iterator>();
}
