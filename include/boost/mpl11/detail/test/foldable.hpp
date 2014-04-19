/*!
 * @file
 * Defines unit tests for `Foldable`s.
 *
 *
 * @copyright Louis Dionne 2014
 * Distributed under the Boost Software License, Version 1.0.
 *         (See accompanying file LICENSE.md or copy at
 *             http://www.boost.org/LICENSE_1_0.txt)
 */

#ifndef BOOST_MPL11_DETAIL_TEST_FOLDABLE_HPP
#define BOOST_MPL11_DETAIL_TEST_FOLDABLE_HPP

#include <boost/mpl11/foldable.hpp>

#include <boost/mpl11/bool.hpp>
#include <boost/mpl11/core.hpp>
#include <boost/mpl11/detail/std_is_same.hpp>
#include <boost/mpl11/detail/test/expect.hpp>
#include <boost/mpl11/detail/test/foldl.hpp>
#include <boost/mpl11/functional.hpp>
#include <boost/mpl11/integer.hpp>


#define static_assert_(...) static_assert(__VA_ARGS__, # __VA_ARGS__)

namespace boost { namespace mpl11 { namespace detail {
namespace foldable_detail {
template <typename ...x>
struct f { using type = f<typename x::type...>; };
struct x0 { using type = x0; };
struct x1 { using type = x1; };
struct x2 { using type = x2; };
struct x3 { using type = x3; };
struct x4 { using type = x4; };
struct x5 { using type = x5; };

struct t { using type = t; };
struct x { using type = x; };
struct y { using type = y; };
struct z { using type = z; };

using u = undefined;

template <template <typename ...> class structure>
struct test_foldr {
    template <typename ...xs>
    using _foldr = foldr<lift<f>, x0, structure<xs...>>;

    struct go
        : expect<_foldr<>>::template to_eq<x0>
        , expect<_foldr<x1>>::template to_eq<f<x1, x0>>
        , expect<_foldr<x1, x2>>::template to_eq<f<x1, f<x2, x0>>>
        , expect<_foldr<x1, x2, x3>>::template to_eq<f<x1, f<x2, f<x3, x0>>>>
        , expect<_foldr<x1, x2, x3, x4>>::template
            to_eq<f<x1, f<x2, f<x3, f<x4, x0>>>>>
    { };

    static_assert_(sizeof(go));
};

template <template <typename ...> class structure>
struct test_foldr1 {
    template <typename ...xs>
    using _foldr1 = foldr1<lift<f>, structure<xs...>>;

    struct go
        : expect<_foldr1<x1>>::template to_eq<x1>
        , expect<_foldr1<x1, x2>>::template to_eq<f<x1, x2>>
        , expect<_foldr1<x1, x2, x3>>::template to_eq<f<x1, f<x2, x3>>>
        , expect<_foldr1<x1, x2, x3, x4>>::template
            to_eq<f<x1, f<x2, f<x3, x4>>>>
        , expect<_foldr1<x1, x2, x3, x4, x5>>::template
            to_eq<f<x1, f<x2, f<x3, f<x4, x5>>>>>
    { };

    static_assert_(sizeof(go));
};

template <template <typename ...> class structure>
struct test_foldl1 {
    template <typename ...xs>
    using _foldl1 = foldl1<lift<f>, structure<xs...>>;

    struct go
        : expect<_foldl1<x1>>::template to_eq<x1>
        , expect<_foldl1<x1, x2>>::template to_eq<f<x1, x2>>
        , expect<_foldl1<x1, x2, x3>>::template to_eq<f<f<x1, x2>, x3>>
        , expect<_foldl1<x1, x2, x3, x4>>::template
            to_eq<f<f<f<x1, x2>, x3>, x4>>
        , expect<_foldl1<x1, x2, x3, x4, x5>>::template
            to_eq<f<f<f<f<x1, x2>, x3>, x4>, x5>>
    { };

    static_assert_(sizeof(go));
};

template <template <typename ...> class structure>
struct test_any {
    template <typename predicate, typename ...xs>
    using _any = any<predicate, structure<xs...>>;

    static_assert_(!_any<u>::value);

    static_assert_(!_any<always<false_>, u>::value);
    static_assert_(!_any<always<false_>, u, u>::value);

    static_assert_( _any<always<true_>, u>::value);
    static_assert_( _any<always<true_>, u, u>::value);

    using is_t = rsect_<equal, t>;
    static_assert_( _any<is_t, t>::value);
    static_assert_(!_any<is_t, x>::value);

    static_assert_( _any<is_t, t, u>::value);
    static_assert_( _any<is_t, x, t>::value);
    static_assert_(!_any<is_t, x, y>::value);

    static_assert_( _any<is_t, t, u, u>::value);
    static_assert_( _any<is_t, x, t, u>::value);
    static_assert_( _any<is_t, x, y, t>::value);
    static_assert_(!_any<is_t, x, y, z>::value);
};

template <template <typename ...> class structure>
struct test_none {
    template <typename predicate, typename ...xs>
    using _none = none<predicate, structure<xs...>>;

    static_assert_(_none<u>::value);

    static_assert_(_none<always<false_>, u>::value);
    static_assert_(_none<always<false_>, u, u>::value);

    static_assert_(!_none<always<true_>, u>::value);
    static_assert_(!_none<always<true_>, u, u>::value);

    using is_t = rsect_<equal, t>;
    static_assert_(!_none<is_t, t>::value);
    static_assert_( _none<is_t, x>::value);

    static_assert_(!_none<is_t, t, u>::value);
    static_assert_(!_none<is_t, x, t>::value);
    static_assert_( _none<is_t, x, y>::value);

    static_assert_(!_none<is_t, t, u, u>::value);
    static_assert_(!_none<is_t, x, t, u>::value);
    static_assert_(!_none<is_t, x, y, t>::value);
    static_assert_( _none<is_t, x, y, z>::value);
};

template <template <typename ...> class structure>
struct test_all {
    template <typename predicate, typename ...xs>
    using _all = all<predicate, structure<xs...>>;

    static_assert_(_all<u>::value);

    static_assert_(!_all<always<false_>, u>::value);
    static_assert_(!_all<always<false_>, u, u>::value);

    static_assert_(_all<always<true_>, u>::value);
    static_assert_(_all<always<true_>, u, u>::value);

    using is_t = rsect_<equal, t>;
    static_assert_( _all<is_t, t>::value);
    static_assert_(!_all<is_t, x>::value);

    static_assert_( _all<is_t, t, t>::value);
    static_assert_(!_all<is_t, t, y>::value);
    static_assert_(!_all<is_t, x, u>::value);

    static_assert_( _all<is_t, t, t, t>::value);
    static_assert_(!_all<is_t, t, t, z>::value);
    static_assert_(!_all<is_t, t, y, u>::value);
    static_assert_(!_all<is_t, x, u, u>::value);
};

template <template <typename ...> class structure>
struct test_all_of {
    template <typename ...xs>
    using _all_of = all_of<structure<xs...>>;

    static_assert_(_all_of<>::value);

    static_assert_( _all_of<true_>::value);
    static_assert_(!_all_of<false_>::value);

    static_assert_( _all_of<true_, true_>::value);
    static_assert_(!_all_of<true_, false_>::value);
    static_assert_(!_all_of<false_, u>::value);
    static_assert_(!_all_of<false_, u>::value);

    static_assert_( _all_of<true_, true_, true_>::value);
    static_assert_(!_all_of<true_, true_, false_>::value);
    static_assert_(!_all_of<true_, false_, u>::value);
    static_assert_(!_all_of<false_, u, u>::value);
};

template <template <typename ...> class structure>
struct test_any_of {
    template <typename ...xs>
    using _any_of = any_of<structure<xs...>>;

    static_assert_(!_any_of<>::value);

    static_assert_( _any_of<true_>::value);
    static_assert_(!_any_of<false_>::value);

    static_assert_( _any_of<true_, u>::value);
    static_assert_( _any_of<false_, true_>::value);
    static_assert_(!_any_of<false_, false_>::value);

    static_assert_( _any_of<true_, u, u>::value);
    static_assert_( _any_of<false_, true_, u>::value);
    static_assert_( _any_of<false_, false_, true_>::value);
    static_assert_(!_any_of<false_, false_, false_>::value);
};

template <template <typename ...> class structure>
struct test_none_of {
    template <typename ...xs>
    using _none_of = none_of<structure<xs...>>;

    static_assert_( _none_of<>::value);

    static_assert_(!_none_of<true_>::value);
    static_assert_(_none_of<false_>::value);

    static_assert_(!_none_of<true_, u>::value);
    static_assert_(!_none_of<false_, true_>::value);
    static_assert_( _none_of<false_, false_>::value);

    static_assert_(!_none_of<true_, u, u>::value);
    static_assert_(!_none_of<false_, true_, u>::value);
    static_assert_(!_none_of<false_, false_, true_>::value);
    static_assert_( _none_of<false_, false_, false_>::value);
};

template <template <typename ...> class structure>
struct test_sum {
    template <int ...xs>
    using _sum = sum<structure<int_<xs>...>>;

    static_assert_(_sum<>::value == 0);

    static_assert_(_sum<0>::value == 0);
    static_assert_(_sum<1>::value == 1);
    static_assert_(_sum<2>::value == 2);

    static_assert_(_sum<0, 1>::value == 1);
    static_assert_(_sum<1, 2>::value == 3);

    static_assert_(_sum<1, 2, 3, 4>::value == 1 + 2 + 3 + 4);
    static_assert_(_sum<1, 2, 3, 4, 5, 0>::value == 1 + 2 + 3 + 4 + 5 + 0);
};

template <template <typename ...> class structure>
struct test_product {
    template <int ...xs>
    using _prod = product<structure<int_<xs>...>>;

    static_assert_(_prod<>::value == 1);

    static_assert_(_prod<0>::value == 0);
    static_assert_(_prod<1>::value == 1);
    static_assert_(_prod<2>::value == 2);

    static_assert_(_prod<0, 1>::value == 0);
    static_assert_(_prod<1, 2>::value == 2);

    static_assert_(_prod<2, 3, 4>::value == 2 * 3 * 4);
    static_assert_(_prod<1, 2, 3, 4, 5, 0>::value == 0);
};

template <template <typename ...> class structure>
struct test_maximum {
    template <int ...xs>
    using _max = typename maximum<structure<int_<xs>...>>::type;

    static_assert_(_max<0>::value == 0);
    static_assert_(_max<1>::value == 1);
    static_assert_(_max<1, 2, 3>::value == 3);
    static_assert_(_max<1, 3, 0>::value == 3);
    static_assert_(_max<1, 3, 0, 50>::value == 50);
    static_assert_(_max<50, 3, 0, 1>::value == 50);
    static_assert_(_max<50, 3, 0, 50>::value == 50);
};

template <template <typename ...> class structure>
struct test_maximum_by {
    template <int ...xs>
    using _max = typename maximum_by<lift<less>, structure<int_<xs>...>>::type;

    static_assert_(_max<0>::value == 0);
    static_assert_(_max<1>::value == 1);
    static_assert_(_max<1, 2, 3>::value == 3);
    static_assert_(_max<1, 3, 0>::value == 3);
    static_assert_(_max<1, 3, 0, 50>::value == 50);
    static_assert_(_max<50, 3, 0, 1>::value == 50);
    static_assert_(_max<50, 3, 0, 50>::value == 50);
};

template <template <typename ...> class structure>
struct test_minimum {
    template <int ...xs>
    using _min = typename minimum<structure<int_<xs>...>>::type;

    static_assert_(_min<0>::value == 0);
    static_assert_(_min<1>::value == 1);
    static_assert_(_min<1, 2, 3>::value == 1);
    static_assert_(_min<1, 3, 0>::value == 0);
    static_assert_(_min<1, 3, 0, 50>::value == 0);
    static_assert_(_min<0, 3, 4, 0>::value == 0);
};

template <template <typename ...> class structure>
struct test_minimum_by {
    template <int ...xs>
    using _min = typename minimum_by<lift<less>, structure<int_<xs>...>>::type;

    static_assert_(_min<0>::value == 0);
    static_assert_(_min<1>::value == 1);
    static_assert_(_min<1, 2, 3>::value == 1);
    static_assert_(_min<1, 3, 0>::value == 0);
    static_assert_(_min<1, 3, 0, 50>::value == 0);
    static_assert_(_min<0, 3, 4, 0>::value == 0);
};

template <template <typename ...> class structure>
struct test_unpack {
    template <typename ...xs>
    using _unpack = detail::std_is_same<
        typename unpack<lift<f>, structure<xs...>>::type,
        typename f<xs...>::type
    >;

    static_assert_(_unpack<>::value);
    static_assert_(_unpack<x0>::value);
    static_assert_(_unpack<x0, x1>::value);
    static_assert_(_unpack<x0, x1, x2>::value);
    static_assert_(_unpack<x0, x1, x2, x3>::value);
    static_assert_(_unpack<x0, x1, x2, x3, x4>::value);
};

template <template <typename ...> class structure>
struct test_datatype {
    template <typename ...xs>
    using _datatype = typename expect<
        typename datatype<typename structure<xs...>::type>::type
    >::template to_satisfy<lift<mpl11::Foldable>>;

    static_assert_(
        sizeof(_datatype<>) +
        sizeof(_datatype<u>) +
        sizeof(_datatype<u, u>) +
        sizeof(_datatype<u, u, u>)
    );
};
} // end namespace foldable_detail

template <template <typename ...> class structure>
struct test_Foldable
    : test_foldl<foldl, structure>
    , foldable_detail::test_foldr<structure>
    , foldable_detail::test_foldl1<structure>
    , foldable_detail::test_foldr1<structure>

    , foldable_detail::test_all<structure>
    , foldable_detail::test_all_of<structure>
    , foldable_detail::test_any<structure>
    , foldable_detail::test_any_of<structure>
    , foldable_detail::test_none<structure>
    , foldable_detail::test_none_of<structure>

    , foldable_detail::test_sum<structure>
    , foldable_detail::test_product<structure>

    , foldable_detail::test_maximum<structure>
    , foldable_detail::test_maximum_by<structure>
    , foldable_detail::test_minimum<structure>
    , foldable_detail::test_minimum_by<structure>

    , foldable_detail::test_unpack<structure>
    , foldable_detail::test_datatype<structure>
{ };
}}} // end namespace boost::mpl11::detail

#endif // !BOOST_MPL11_DETAIL_TEST_FOLDABLE_HPP
