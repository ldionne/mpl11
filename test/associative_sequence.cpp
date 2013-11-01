/*!
 * @file
 * Contains unit tests for `boost::mpl11::AssociativeSequence`.
 */

#include <boost/mpl11/associative_sequence.hpp>

#include <boost/mpl11/at.hpp>
#include <boost/mpl11/comparable.hpp>
#include <boost/mpl11/detail/is_same.hpp>
#include <boost/mpl11/detail/variadic_at.hpp>
#include <boost/mpl11/equal.hpp>
#include <boost/mpl11/equal.hpp>
#include <boost/mpl11/first.hpp>
#include <boost/mpl11/forward_iterator.hpp>
#include <boost/mpl11/fwd/class_of.hpp>
#include <boost/mpl11/has_key.hpp>
#include <boost/mpl11/integral_c.hpp>
#include <boost/mpl11/key_of.hpp>
#include <boost/mpl11/pair.hpp>
#include <boost/mpl11/second.hpp>
#include <boost/mpl11/value_of.hpp>


using namespace boost::mpl11;
using detail::is_same;

template <typename T> struct wrapper;

template <typename ...Elements>
struct lookup;

template <>
struct lookup<> {
    template <typename Key>
    static false_ has_key_(wrapper<Key>*);

    template <typename Default, typename Key>
    static Default at_key_(wrapper<Key>*);
};

template <typename Head, typename ...Tail>
struct lookup<Head, Tail...> : lookup<Tail...> {
    using lookup<Tail...>::has_key_;
    static true_ has_key_(wrapper<typename first<Head>::type>*);

    using lookup<Tail...>::at_key_;
    template <typename Default>
    static typename second<Head>::type
    at_key_(wrapper<typename first<Head>::type>*);
};

template <typename ...Elements>
struct sequence : lookup<Elements...> {
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

            template <typename Self>
            struct deref_impl
                : detail::variadic_at_c<Self::position, Elements...>
            { };
        };
    };

    struct mpl_class : AssociativeSequence {
        template <typename Self>
        struct begin_impl {
            using type = iterator<0>;
        };

        template <typename Self>
        struct end_impl {
            using type = iterator<sizeof...(Elements)>;
        };

        template <typename Self, typename Key>
        struct has_key_impl
            : decltype(Self::has_key_((wrapper<Key>*)nullptr))
        { };

        template <typename Self, typename Key, typename Default = struct opt>
        struct at_impl {
            using type = decltype(
                Self::template at_key_<Default>((wrapper<Key>*)nullptr)
            );
        };

        template <typename Self, typename Key>
        struct at_impl<Self, Key>
            : AssociativeSequence::at_impl<Self, Key>
        { };

        template <typename Self, typename Element>
        struct value_of_impl
            : second<Element>
        { };

        template <typename Self, typename Element>
        struct key_of_impl
            : first<Element>
        { };
    };
};

struct is_same_comparable : Comparable {
    template <typename X, typename Y>
    struct equal_impl
        : bool_<is_same<X, Y>::value>
    { };
};

// We want to keep k and v incomplete types to make sure we don't assume too
// much about them, so we don't provide a nested mpl_class.
template <int> struct k;
template <int> struct v;

namespace boost { namespace mpl11 {
    template <int i>
    struct class_of<k<i>> { using type = is_same_comparable; };

    template <int i>
    struct class_of<v<i>> { using type = is_same_comparable; };
}} // end namespace boost::mpl11

// equal
static_assert(equal<
    sequence<>,
    sequence<>
>::value, "");
static_assert(!equal<
    sequence<>,
    sequence<pair<k<0>, v<0>>>
>::value, "");
static_assert(!equal<
    sequence<>,
    sequence<pair<k<0>, v<0>>, pair<k<1>, v<1>>>
>::value, "");

static_assert(!equal<
    sequence<pair<k<0>, v<0>>>,
    sequence<>
>::value, "");
static_assert(equal<
    sequence<pair<k<0>, v<0>>>,
    sequence<pair<k<0>, v<0>>>
>::value, "");
static_assert(!equal<
    sequence<pair<k<0>, v<0>>>,
    sequence<pair<k<1>, v<0>>>
>::value, "");
static_assert(!equal<
    sequence<pair<k<0>, v<0>>>,
    sequence<pair<k<0>, v<1>>>
>::value, "");
static_assert(!equal<
    sequence<pair<k<0>, v<0>>>,
    sequence<pair<k<0>, v<0>>, pair<k<1>, v<1>>>
>::value, "");
static_assert(!equal<
    sequence<pair<k<0>, v<0>>>,
    sequence<pair<k<0>, v<0>>, pair<k<1>, v<1>>>
>::value, "");

static_assert(!equal<
    sequence<pair<k<0>, v<0>>, pair<k<1>, v<1>>>,
    sequence<>
>::value, "");
static_assert(!equal<
    sequence<pair<k<0>, v<0>>, pair<k<1>, v<1>>>,
    sequence<pair<k<0>, v<0>>>
>::value, "");
static_assert(equal<
    sequence<pair<k<0>, v<0>>, pair<k<1>, v<1>>>,
    sequence<pair<k<0>, v<0>>, pair<k<1>, v<1>>>
>::value, "");
static_assert(equal<
    sequence<pair<k<0>, v<0>>, pair<k<1>, v<1>>>,
    sequence<pair<k<1>, v<1>>, pair<k<0>, v<0>>>
>::value, "");
static_assert(!equal<
    sequence<pair<k<0>, v<0>>, pair<k<1>, v<1>>>,
    sequence<pair<k<0>, v<2>>, pair<k<1>, v<1>>>
>::value, "");
static_assert(!equal<
    sequence<pair<k<0>, v<0>>, pair<k<1>, v<1>>>,
    sequence<pair<k<0>, v<0>>, pair<k<1>, v<1>>, pair<k<2>, v<2>>>
>::value, "");

// Both sequences contain pair<k<0-9>, v<0-9>> in different orders.
static_assert(equal<
    sequence<
        pair<k<5>, v<5>>,
        pair<k<8>, v<8>>,
        pair<k<0>, v<0>>,
        pair<k<6>, v<6>>,
        pair<k<2>, v<2>>,
        pair<k<4>, v<4>>,
        pair<k<7>, v<7>>,
        pair<k<3>, v<3>>,
        pair<k<1>, v<1>>,
        pair<k<9>, v<9>>
    >,
    sequence<
        pair<k<6>, v<6>>,
        pair<k<3>, v<3>>,
        pair<k<8>, v<8>>,
        pair<k<0>, v<0>>,
        pair<k<5>, v<5>>,
        pair<k<7>, v<7>>,
        pair<k<9>, v<9>>,
        pair<k<2>, v<2>>,
        pair<k<1>, v<1>>,
        pair<k<4>, v<4>>
    >
>::value, "");


// key_of
static_assert(is_same<
    key_of<sequence<>, pair<k<0>, v<0>>>::type,
    k<0>
>::value, "");

static_assert(is_same<
    key_of<sequence<pair<k<0>, v<0>>>, pair<k<0>, v<0>>>::type,
    k<0>
>::value, "");


// value_of
static_assert(is_same<
    value_of<sequence<>, pair<k<0>, v<0>>>::type,
    v<0>
>::value, "");

static_assert(is_same<
    value_of<sequence<pair<k<0>, v<0>>>, pair<k<0>, v<0>>>::type,
    v<0>
>::value, "");


// has_key
static_assert(!has_key<sequence<>, k<0>>::value, "");

static_assert(has_key<sequence<pair<k<0>, v<0>>>, k<0>>::value, "");
static_assert(!has_key<sequence<pair<k<0>, v<0>>>, k<1>>::value, "");

static_assert(has_key<
    sequence<pair<k<0>, v<0>>, pair<k<1>, v<1>>>, k<0>
>::value, "");
static_assert(has_key<
    sequence<pair<k<0>, v<0>>, pair<k<1>, v<1>>>, k<1>
>::value, "");
static_assert(!has_key<
    sequence<pair<k<0>, v<0>>, pair<k<1>, v<1>>>, k<2>
>::value, "");

static_assert(has_key<
    sequence<pair<k<0>, v<0>>, pair<k<1>, v<1>>, pair<k<2>, v<2>>>, k<0>
>::value, "");
static_assert(has_key<
    sequence<pair<k<0>, v<0>>, pair<k<1>, v<1>>, pair<k<2>, v<2>>>, k<1>
>::value, "");
static_assert(has_key<
    sequence<pair<k<0>, v<0>>, pair<k<1>, v<1>>, pair<k<2>, v<2>>>, k<2>
>::value, "");
static_assert(!has_key<
    sequence<pair<k<0>, v<0>>, pair<k<1>, v<1>>, pair<k<2>, v<2>>>, k<3>
>::value, "");


// at without default
static_assert(is_same<
    at<sequence<pair<k<0>, v<0>>>, k<0>>::type, v<0>
>::value, "");

static_assert(is_same<
    at<sequence<pair<k<0>, v<0>>, pair<k<1>, v<1>>>, k<0>>::type, v<0>
>::value, "");
static_assert(is_same<
    at<sequence<pair<k<0>, v<0>>, pair<k<1>, v<1>>>, k<1>>::type, v<1>
>::value, "");

static_assert(is_same<
    at<sequence<pair<k<0>, v<0>>, pair<k<1>, v<1>>, pair<k<2>, v<2>>>, k<0>>::type, v<0>
>::value, "");
static_assert(is_same<
    at<sequence<pair<k<0>, v<0>>, pair<k<1>, v<1>>, pair<k<2>, v<2>>>, k<1>>::type, v<1>
>::value, "");
static_assert(is_same<
    at<sequence<pair<k<0>, v<0>>, pair<k<1>, v<1>>, pair<k<2>, v<2>>>, k<2>>::type, v<2>
>::value, "");


// at with default
static_assert(is_same<
    at<sequence<>, k<0>, struct def>::type,
    struct def
>::value, "");

static_assert(is_same<
    at<sequence<pair<k<0>, v<0>>>, k<0>, struct def>::type, v<0>
>::value, "");
static_assert(is_same<
    at<sequence<pair<k<0>, v<0>>>, k<1>, struct def>::type, struct def
>::value, "");

static_assert(is_same<
    at<sequence<pair<k<0>, v<0>>, pair<k<1>, v<1>>>, k<0>, struct def>::type, v<0>
>::value, "");
static_assert(is_same<
    at<sequence<pair<k<0>, v<0>>, pair<k<1>, v<1>>>, k<1>, struct def>::type, v<1>
>::value, "");
static_assert(is_same<
    at<sequence<pair<k<0>, v<0>>, pair<k<1>, v<1>>>, k<2>, struct def>::type, struct def
>::value, "");


int main() { }
