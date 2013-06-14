/*!
 * @file
 * This file contains unit tests for `boost::mpl11::lambda`.
 */

#include <boost/mpl11/lambda.hpp>
#include <boost/mpl11/bind.hpp>
#include <boost/mpl11/protect.hpp>
#include <boost/mpl11/quote.hpp>
#include <boost/mpl11/trait/is_placeholder.hpp>

#include <boost/type_traits/is_same.hpp>


using namespace boost;
using namespace boost::mpl11;

struct a0;
struct a1;

template <typename NotPlaceholder, typename Placeholder>
struct do_test {
    template <typename ...> struct pack;

    // Non-placeholder expressions should not be modified.
    static_assert(is_same<
        typename lambda<NotPlaceholder>::type,
        NotPlaceholder
    >::value, "");

    static_assert(is_same<
        typename lambda<pack<NotPlaceholder>>::type,
        pack<NotPlaceholder>
    >::value, "");

    static_assert(is_same<
        typename lambda<pack<pack<NotPlaceholder>>>::type,
        pack<pack<NotPlaceholder>>
    >::value, "");

    // Placeholder expressions should be replaced, but placeholders (templates
    // or not) should not be touched.
    static_assert(is_same<
        typename lambda<Placeholder>::type, Placeholder
    >::value, "");

    static_assert(is_same<
        typename lambda<pack<Placeholder, NotPlaceholder>>::type,
        protect<bind<quote<pack>, Placeholder, NotPlaceholder>>
    >::value, "");
};

template <typename ...>
struct Placeholder { struct mpl11 { struct is_placeholder; }; };

struct non_template_not_a_placeholder;
template <typename> struct unary_not_a_placeholder;
template <typename ...> struct nary_not_a_placeholder;


template struct do_test<non_template_not_a_placeholder, Placeholder<>>;
template struct do_test<unary_not_a_placeholder<int>, Placeholder<>>;
template struct do_test<nary_not_a_placeholder<>, Placeholder<>>;
template struct do_test<nary_not_a_placeholder<int>, Placeholder<>>;
template struct do_test<nary_not_a_placeholder<int, float>, Placeholder<>>;

// Same tests, but use a placeholder nested inside another placeholder.
template struct do_test<non_template_not_a_placeholder, Placeholder<Placeholder<>>>;
template struct do_test<unary_not_a_placeholder<int>, Placeholder<Placeholder<>>>;
template struct do_test<nary_not_a_placeholder<>, Placeholder<Placeholder<>>>;
template struct do_test<nary_not_a_placeholder<int>, Placeholder<Placeholder<>>>;
template struct do_test<nary_not_a_placeholder<int, float>, Placeholder<Placeholder<>>>;


int main() { }
