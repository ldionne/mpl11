/*!
 * @file
 * Defines unit tests for `Iterable`s.
 *
 *
 * @copyright Louis Dionne 2014
 * Distributed under the Boost Software License, Version 1.0.
 *         (See accompanying file LICENSE.md or copy at
 *             http://www.boost.org/LICENSE_1_0.txt)
 */

#ifndef BOOST_MPL11_DETAIL_TEST_ITERABLE_HPP
#define BOOST_MPL11_DETAIL_TEST_ITERABLE_HPP

#include <boost/mpl11/iterable.hpp>

#include <boost/mpl11/core.hpp>
#include <boost/mpl11/detail/test/expect.hpp>
#include <boost/mpl11/detail/test/foldable.hpp>
#include <boost/mpl11/functional.hpp>
#include <boost/mpl11/integer.hpp>
#include <boost/mpl11/logical.hpp>


#define static_assert_(...) static_assert(__VA_ARGS__, # __VA_ARGS__)

namespace boost { namespace mpl11 { namespace detail {
namespace iterable_detail {
template <typename ...x>
struct f { using type = f<typename x::type...>; };

struct x { using type = x; };
struct x0 { using type = x0; };
struct x1 { using type = x1; };
struct x2 { using type = x2; };
struct x3 { using type = x3; };

using u = undefined;

template <template <typename ...> class s>
struct test_head
    : expect<head<s<x>>>::template to_eq<x>
    , expect<head<s<x, u>>>::template to_eq<x>
    , expect<head<s<x, u, u>>>::template to_eq<x>
    , expect<head<s<x, u, u, u>>>::template to_eq<x>
{ };

template <template <typename ...> class s>
struct test_tail
    : expect<tail<s<x0>>>::template to_eq<s<>>
    , expect<tail<s<x0, x1>>>::template to_eq<s<x1>>
    , expect<tail<s<x0, x1, x2>>>::template to_eq<s<x1, x2>>
    , expect<tail<s<x0, x1, x2, x3>>>::template to_eq<s<x1, x2, x3>>
{ };

template <template <typename ...> class structure>
struct test_is_empty {
    static_assert_( is_empty<structure<>>::value);
    static_assert_(!is_empty<structure<u>>::value);
    static_assert_(!is_empty<structure<u, u>>::value);
};

template <template <typename ...> class s>
struct test_last
    : expect<last<s<x>>>::template to_eq<x>
    , expect<last<s<u, x>>>::template to_eq<x>
    , expect<last<s<u, u, x>>>::template to_eq<x>
    , expect<last<s<u, u, u, x>>>::template to_eq<x>
    , expect<last<s<u, u, u, u, x>>>::template to_eq<x>
{ };

template <template <typename ...> class s>
struct test_at
    : expect<at_c<0, s<x0>>>::template to_eq<x0>
    , expect<at_c<0, s<x0, x1>>>::template to_eq<x0>
    , expect<at_c<0, s<x0, x1, x2>>>::template to_eq<x0>
    , expect<at_c<0, s<x0, x1, x2, x3>>>::template to_eq<x0>

    , expect<at_c<1, s<x0, x1>>>::template to_eq<x1>
    , expect<at_c<1, s<x0, x1, x2>>>::template to_eq<x1>
    , expect<at_c<1, s<x0, x1, x2, x3>>>::template to_eq<x1>

    , expect<at_c<2, s<x0, x1, x2>>>::template to_eq<x2>
    , expect<at_c<2, s<x0, x1, x2, x3>>>::template to_eq<x2>

    , expect<at_c<3, s<x0, x1, x2, x3>>>::template to_eq<x3>
{ };

template <template <typename ...> class structure>
struct test_length {
    static_assert_(length<structure<>>::value == 0);
    static_assert_(length<structure<u>>::value == 1);
    static_assert_(length<structure<u, u>>::value == 2);
    static_assert_(length<structure<u, u, u>>::value == 3);
    static_assert_(length<structure<u, u, u, u>>::value == 4);
};

template <template <typename ...> class s>
struct test_drop
    : expect<drop_c<0, s<>>>::template to_eq<s<>>
    , expect<drop_c<1, s<>>>::template to_eq<s<>>
    , expect<drop_c<2, s<>>>::template to_eq<s<>>
    , expect<drop_c<3, s<>>>::template to_eq<s<>>

    , expect<drop_c<0, s<x0>>>::template to_eq<s<x0>>
    , expect<drop_c<1, s<x0>>>::template to_eq<s<>>
    , expect<drop_c<2, s<x0>>>::template to_eq<s<>>
    , expect<drop_c<3, s<x0>>>::template to_eq<s<>>

    , expect<drop_c<0, s<x0, x1>>>::template to_eq<s<x0, x1>>
    , expect<drop_c<1, s<x0, x1>>>::template to_eq<s<x1>>
    , expect<drop_c<2, s<x0, x1>>>::template to_eq<s<>>
    , expect<drop_c<3, s<x0, x1>>>::template to_eq<s<>>

    , expect<drop_c<0, s<x0, x1, x2>>>::template to_eq<s<x0, x1, x2>>
    , expect<drop_c<1, s<x0, x1, x2>>>::template to_eq<s<x1, x2>>
    , expect<drop_c<2, s<x0, x1, x2>>>::template to_eq<s<x2>>
    , expect<drop_c<3, s<x0, x1, x2>>>::template to_eq<s<>>
    , expect<drop_c<4, s<x0, x1, x2>>>::template to_eq<s<>>
    , expect<drop_c<5, s<x0, x1, x2>>>::template to_eq<s<>>

    , expect<drop_c<0, s<x0, x1, x2, x3>>>::template to_eq<s<x0, x1, x2, x3>>
    , expect<drop_c<1, s<x0, x1, x2, x3>>>::template to_eq<s<x1, x2, x3>>
    , expect<drop_c<2, s<x0, x1, x2, x3>>>::template to_eq<s<x2, x3>>
    , expect<drop_c<3, s<x0, x1, x2, x3>>>::template to_eq<s<x3>>
    , expect<drop_c<4, s<x0, x1, x2, x3>>>::template to_eq<s<>>
    , expect<drop_c<5, s<x0, x1, x2, x3>>>::template to_eq<s<>>
{ };

template <template <typename ...> class structure>
struct test_drop_while {
    template <int ...xs>
    using s = structure<int_<xs>...>;

    template <int ...xs>
    using dlz = drop_while<lift<not_>, s<xs...>>;

    struct go
        : expect<dlz<>>::template to_eq<s<>>

        , expect<dlz<0>>::template to_eq<s<>>
        , expect<dlz<1>>::template to_eq<s<1>>

        , expect<dlz<0, 0>>::template to_eq<s<>>
        , expect<dlz<0, 2>>::template to_eq<s<2>>
        , expect<dlz<1, 0>>::template to_eq<s<1, 0>>
        , expect<dlz<1, 2>>::template to_eq<s<1, 2>>

        , expect<dlz<0, 0, 0>>::template to_eq<s<>>
        , expect<dlz<0, 0, 3>>::template to_eq<s<3>>
        , expect<dlz<0, 2, 0>>::template to_eq<s<2, 0>>
        , expect<dlz<0, 2, 3>>::template to_eq<s<2, 3>>
        , expect<dlz<1, 0, 0>>::template to_eq<s<1, 0, 0>>
        , expect<dlz<1, 0, 3>>::template to_eq<s<1, 0, 3>>
        , expect<dlz<1, 2, 0>>::template to_eq<s<1, 2, 0>>
        , expect<dlz<1, 2, 3>>::template to_eq<s<1, 2, 3>>
    { };

    static_assert_(sizeof(go));
};

template <template <typename ...> class structure>
struct test_drop_until {
    // Tested by drop_while
};

template <template <typename ...> class s>
struct test_comparable
    : expect<s<>>::    to::template eq<s<>>
    , expect<s<>>::not_to::template eq<s<x0>>
    , expect<s<>>::not_to::template eq<s<x0, x1>>
    , expect<s<>>::not_to::template eq<s<x0, x1, x2>>

    , expect<s<x0>>::not_to::template eq<s<>>
    , expect<s<x0>>::    to::template eq<s<x0>>
    , expect<s<x0>>::not_to::template eq<s<x0, x1>>
    , expect<s<x0>>::not_to::template eq<s<x0, x1, x2>>

    , expect<s<x0, x1>>::not_to::template eq<s<>>
    , expect<s<x0, x1>>::not_to::template eq<s<x0>>
    , expect<s<x0, x1>>::    to::template eq<s<x0, x1>>
    , expect<s<x0, x1>>::not_to::template eq<s<x0, x1, x2>>

    , expect<s<x0, x1, x2>>::not_to::template eq<s<>>
    , expect<s<x0, x1, x2>>::not_to::template eq<s<x0>>
    , expect<s<x0, x1, x2>>::not_to::template eq<s<x0, x1>>
    , expect<s<x0, x1, x2>>::    to::template eq<s<x0, x1, x2>>
{ };

template <template <typename ...> class structure>
struct test_orderable {
    template <int ...xs>
    using s = structure<int_<xs>...>;

    template <typename x, typename y>
    struct _less
        : expect<x>::to::template be_<less>::template than<y>
        , expect<x>::to::template be_<less_equal>::template than<y>
    { };

    struct go
        : _less<s<>, s<0>>
        , _less<s<>, s<0, 1>>
        , _less<s<>, s<0, 1, 2>>
        , _less<s<>, s<0, 1, 2, 3>>

        , _less<s<0>, s<1>>
        , _less<s<0>, s<0, 0>>
        , _less<s<0>, s<0, 1>>

        , _less<s<0, 1>, s<1, 0>>
        , _less<s<0, 1>, s<0, 2>>

        , _less<s<0, 1, 2>, s<0, 1, 3>>
        , _less<s<0, 1, 2>, s<0, 2>>
        , _less<s<0, 1, 2>, s<1>>
    { };

    static_assert_(sizeof(go));
};

template <template <typename ...> class structure>
struct test_datatype {
    template <typename ...xs>
    using _datatype = typename expect<
        typename datatype<typename structure<xs...>::type>::type
    >::template to_satisfy<lift<mpl11::Iterable>>;

    static_assert_(
        sizeof(_datatype<>) +
        sizeof(_datatype<u>) +
        sizeof(_datatype<u, u>) +
        sizeof(_datatype<u, u, u>)
    );
};
} // end namespace iterable_detail

template <template <typename ...> class structure>
struct test_Iterable
    : test_Foldable<structure>

    , iterable_detail::test_head<structure>
    , iterable_detail::test_tail<structure>
    , iterable_detail::test_is_empty<structure>
    , iterable_detail::test_last<structure>
    , iterable_detail::test_at<structure>
    , iterable_detail::test_length<structure>
    , iterable_detail::test_drop<structure>
    , iterable_detail::test_drop_while<structure>
    , iterable_detail::test_drop_until<structure>

    , iterable_detail::test_comparable<structure>
    , iterable_detail::test_orderable<structure>

    , iterable_detail::test_datatype<structure>
{ };
}}} // end namespace boost::mpl11::detail

#endif // !BOOST_MPL11_DETAIL_TEST_ITERABLE_HPP
