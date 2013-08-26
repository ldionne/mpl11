/*!
 * @file
 * This file contains unit tests for `boost::mpl11::advance`.
 */

#include <boost/mpl11/advance.hpp>

#include <boost/mpl11/always.hpp>
#include <boost/mpl11/dispatch.hpp>
#include <boost/mpl11/traversal_categories.hpp>


template <typename Category, int Position>
struct iterator {
    static constexpr int position = Position;
};

namespace boost { namespace mpl11 {
    namespace tag { struct next; struct prior; struct traversal_category_of; }

    template <typename Category, int Position>
    struct dispatch<tag::traversal_category_of, iterator<Category, Position>>
        : always<Category>
    { };

    template <typename Category, int Position>
    struct dispatch<tag::next, iterator<Category, Position>>
        : always<iterator<Category, Position + 1>>
    { };

    template <typename Category, int Position>
    struct dispatch<tag::prior, iterator<Category, Position>>
        : always<iterator<Category, Position - 1>>
    { };
}} // end namespace boost::mpl11

using namespace boost::mpl11;

template <typename Tag>
void test_forward_iterator() {
    static_assert(advance_c<
        iterator<Tag, 0>, 0
    >::type::position == 0, "");

    static_assert(advance_c<
        iterator<Tag, 0>, 1
    >::type::position == 1, "");

    static_assert(advance_c<
        iterator<Tag, 0>, 2
    >::type::position == 2, "");

    static_assert(advance_c<
        iterator<Tag, 2>, 3
    >::type::position == 5, "");
}

template <typename Tag>
void test_bidirectional_iterator() {
    test_forward_iterator<Tag>();

    static_assert(advance_c<
        iterator<Tag, 0>, -1
    >::type::position == -1, "");

    static_assert(advance_c<
        iterator<Tag, -3>, -4
    >::type::position == -7, "");

    static_assert(advance_c<
        iterator<Tag, -3>, 0
    >::type::position == -3, "");
}

template <typename Tag>
void test_random_access_iterator() {
    test_bidirectional_iterator<Tag>();
    // nothing to add.
}


int main() {
    test_forward_iterator<tag::forward>();
    test_bidirectional_iterator<tag::bidirectional>();
    test_random_access_iterator<tag::random_access>();
}
