/*!
 * @file
 * Defines unit tests for `Functor`s.
 *
 *
 * @copyright Louis Dionne 2014
 * Distributed under the Boost Software License, Version 1.0.
 *         (See accompanying file LICENSE.md or copy at
 *             http://www.boost.org/LICENSE_1_0.txt)
 */

#ifndef BOOST_MPL11_TEST_FUNCTOR_HPP
#define BOOST_MPL11_TEST_FUNCTOR_HPP

#include <boost/mpl11/functor.hpp>

#include <boost/mpl11/core.hpp>
#include <boost/mpl11/functional.hpp>
#include <boost/mpl11/test/expect.hpp>


namespace boost { namespace mpl11 { namespace test {
namespace functor_detail {
template <typename ...x>
struct f { using type = f<typename x::type...>; };

struct x0 { using type = x0; };
struct x1 { using type = x1; };
struct x2 { using type = x2; };
struct x3 { using type = x3; };
struct x4 { using type = x4; };
using u = undefined;

template <template <typename ...> class s>
struct test_fmap {
    template <typename ...xs>
    using _fmap = fmap<lift<f>, s<xs...>>;

    struct go
        : expect<_fmap<>>::template to_eq<s<>>
        , expect<_fmap<x0>>::template to_eq<s<f<x0>>>
        , expect<_fmap<x0, x1>>::template to_eq<s<f<x0>, f<x1>>>
        , expect<_fmap<x0, x1, x2>>::template to_eq<s<f<x0>, f<x1>, f<x2>>>
        , expect<_fmap<x0, x1, x2, x3>>::template
            to_eq<s<f<x0>, f<x1>, f<x2>, f<x3>>>
        , expect<_fmap<x0, x1, x2, x3, x4>>::template
            to_eq<s<f<x0>, f<x1>, f<x2>, f<x3>, f<x4>>>
    { };

    static_assert(sizeof(go), "");
};

template <template <typename ...> class functor>
struct test_datatype {
    template <typename ...xs>
    using _datatype = typename expect<
        typename datatype<typename functor<xs...>::type>::type
    >::template to_satisfy<lift<mpl11::Functor>>;

    static_assert(
        sizeof(_datatype<>) +
        sizeof(_datatype<u>) +
        sizeof(_datatype<u, u>) +
        sizeof(_datatype<u, u, u>)
    , "");
};
} // end namespace functor_detail

template <template <typename ...> class functor>
struct Functor
    : functor_detail::test_fmap<functor>
    , functor_detail::test_datatype<functor>
{ };
}}} // end namespace boost::mpl11::test

#endif // !BOOST_MPL11_TEST_FUNCTOR_HPP
