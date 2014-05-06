/*!
 * @file
 * Defines unit tests for key-based lookup algorithms.
 *
 *
 * @copyright Louis Dionne 2014
 * Distributed under the Boost Software License, Version 1.0.
 *         (See accompanying file LICENSE.md or copy at
 *             http://www.boost.org/LICENSE_1_0.txt)
 */

//////////////////////////////////////////////////////////////////////////
// GENERATED HEADER: DO NOT EDIT.
//////////////////////////////////////////////////////////////////////////

#ifndef BOOST_MPL11_DETAIL_TEST_AT_KEY_HPP
#define BOOST_MPL11_DETAIL_TEST_AT_KEY_HPP

#include <boost/mpl11/core.hpp>
#include <boost/mpl11/detail/pair.hpp>
#include <boost/mpl11/detail/std_is_same.hpp>
#include <boost/mpl11/detail/test/expect.hpp>


namespace boost { namespace mpl11 { namespace detail {
namespace test_at_key_detail {
    template <int> struct k { struct type; };
    template <int> struct v { struct type; };
    using u = undefined;

    template <template <typename ...> class at_key>
    struct test_at_key
        : instantiate<
             typename expect<at_key<k<0>, pair<k<0>, v<0>>>>::
 template to_eq<v<0>>
,

 typename expect<at_key<k<0>, pair<k<0>, v<0>>, pair<k<1>, u>>>::
 template to_eq<v<0>>
,
 typename expect<at_key<k<1>, pair<k<0>, u>, pair<k<1>, v<1>>>>::
 template to_eq<v<1>>
,

 typename expect<at_key<k<0>, pair<k<0>, v<0>>, pair<k<1>, u>, pair<k<2>, u>>>::
 template to_eq<v<0>>
,
 typename expect<at_key<k<1>, pair<k<0>, u>, pair<k<1>, v<1>>, pair<k<2>, u>>>::
 template to_eq<v<1>>
,
 typename expect<at_key<k<2>, pair<k<0>, u>, pair<k<1>, u>, pair<k<2>, v<2>>>>::
 template to_eq<v<2>>
,

 typename expect<at_key<k<0>, pair<k<0>, v<0>>, pair<k<1>, u>, pair<k<2>, u>, pair<k<3>, u>>>::
 template to_eq<v<0>>
,
 typename expect<at_key<k<1>, pair<k<0>, u>, pair<k<1>, v<1>>, pair<k<2>, u>, pair<k<3>, u>>>::
 template to_eq<v<1>>
,
 typename expect<at_key<k<2>, pair<k<0>, u>, pair<k<1>, u>, pair<k<2>, v<2>>, pair<k<3>, u>>>::
 template to_eq<v<2>>
,
 typename expect<at_key<k<3>, pair<k<0>, u>, pair<k<1>, u>, pair<k<2>, u>, pair<k<3>, v<3>>>>::
 template to_eq<v<3>>
,

 typename expect<at_key<k<0>, pair<k<0>, v<0>>, pair<k<1>, u>, pair<k<2>, u>, pair<k<3>, u>, pair<k<4>, u>>>::
 template to_eq<v<0>>
,
 typename expect<at_key<k<1>, pair<k<0>, u>, pair<k<1>, v<1>>, pair<k<2>, u>, pair<k<3>, u>, pair<k<4>, u>>>::
 template to_eq<v<1>>
,
 typename expect<at_key<k<2>, pair<k<0>, u>, pair<k<1>, u>, pair<k<2>, v<2>>, pair<k<3>, u>, pair<k<4>, u>>>::
 template to_eq<v<2>>
,
 typename expect<at_key<k<3>, pair<k<0>, u>, pair<k<1>, u>, pair<k<2>, u>, pair<k<3>, v<3>>, pair<k<4>, u>>>::
 template to_eq<v<3>>
,
 typename expect<at_key<k<4>, pair<k<0>, u>, pair<k<1>, u>, pair<k<2>, u>, pair<k<3>, u>, pair<k<4>, v<4>>>>::
 template to_eq<v<4>>
,

 typename expect<at_key<k<0>, pair<k<0>, v<0>>, pair<k<1>, u>, pair<k<2>, u>, pair<k<3>, u>, pair<k<4>, u>, pair<k<5>, u>>>::
 template to_eq<v<0>>
,
 typename expect<at_key<k<1>, pair<k<0>, u>, pair<k<1>, v<1>>, pair<k<2>, u>, pair<k<3>, u>, pair<k<4>, u>, pair<k<5>, u>>>::
 template to_eq<v<1>>
,
 typename expect<at_key<k<2>, pair<k<0>, u>, pair<k<1>, u>, pair<k<2>, v<2>>, pair<k<3>, u>, pair<k<4>, u>, pair<k<5>, u>>>::
 template to_eq<v<2>>
,
 typename expect<at_key<k<3>, pair<k<0>, u>, pair<k<1>, u>, pair<k<2>, u>, pair<k<3>, v<3>>, pair<k<4>, u>, pair<k<5>, u>>>::
 template to_eq<v<3>>
,
 typename expect<at_key<k<4>, pair<k<0>, u>, pair<k<1>, u>, pair<k<2>, u>, pair<k<3>, u>, pair<k<4>, v<4>>, pair<k<5>, u>>>::
 template to_eq<v<4>>
,
 typename expect<at_key<k<5>, pair<k<0>, u>, pair<k<1>, u>, pair<k<2>, u>, pair<k<3>, u>, pair<k<4>, u>, pair<k<5>, v<5>>>>::
 template to_eq<v<5>>
,

 typename expect<at_key<k<0>, pair<k<0>, v<0>>, pair<k<1>, u>, pair<k<2>, u>, pair<k<3>, u>, pair<k<4>, u>, pair<k<5>, u>, pair<k<6>, u>>>::
 template to_eq<v<0>>
,
 typename expect<at_key<k<1>, pair<k<0>, u>, pair<k<1>, v<1>>, pair<k<2>, u>, pair<k<3>, u>, pair<k<4>, u>, pair<k<5>, u>, pair<k<6>, u>>>::
 template to_eq<v<1>>
,
 typename expect<at_key<k<2>, pair<k<0>, u>, pair<k<1>, u>, pair<k<2>, v<2>>, pair<k<3>, u>, pair<k<4>, u>, pair<k<5>, u>, pair<k<6>, u>>>::
 template to_eq<v<2>>
,
 typename expect<at_key<k<3>, pair<k<0>, u>, pair<k<1>, u>, pair<k<2>, u>, pair<k<3>, v<3>>, pair<k<4>, u>, pair<k<5>, u>, pair<k<6>, u>>>::
 template to_eq<v<3>>
,
 typename expect<at_key<k<4>, pair<k<0>, u>, pair<k<1>, u>, pair<k<2>, u>, pair<k<3>, u>, pair<k<4>, v<4>>, pair<k<5>, u>, pair<k<6>, u>>>::
 template to_eq<v<4>>
,
 typename expect<at_key<k<5>, pair<k<0>, u>, pair<k<1>, u>, pair<k<2>, u>, pair<k<3>, u>, pair<k<4>, u>, pair<k<5>, v<5>>, pair<k<6>, u>>>::
 template to_eq<v<5>>
,
 typename expect<at_key<k<6>, pair<k<0>, u>, pair<k<1>, u>, pair<k<2>, u>, pair<k<3>, u>, pair<k<4>, u>, pair<k<5>, u>, pair<k<6>, v<6>>>>::
 template to_eq<v<6>>
,

 typename expect<at_key<k<0>, pair<k<0>, v<0>>, pair<k<1>, u>, pair<k<2>, u>, pair<k<3>, u>, pair<k<4>, u>, pair<k<5>, u>, pair<k<6>, u>, pair<k<7>, u>>>::
 template to_eq<v<0>>
,
 typename expect<at_key<k<1>, pair<k<0>, u>, pair<k<1>, v<1>>, pair<k<2>, u>, pair<k<3>, u>, pair<k<4>, u>, pair<k<5>, u>, pair<k<6>, u>, pair<k<7>, u>>>::
 template to_eq<v<1>>
,
 typename expect<at_key<k<2>, pair<k<0>, u>, pair<k<1>, u>, pair<k<2>, v<2>>, pair<k<3>, u>, pair<k<4>, u>, pair<k<5>, u>, pair<k<6>, u>, pair<k<7>, u>>>::
 template to_eq<v<2>>
,
 typename expect<at_key<k<3>, pair<k<0>, u>, pair<k<1>, u>, pair<k<2>, u>, pair<k<3>, v<3>>, pair<k<4>, u>, pair<k<5>, u>, pair<k<6>, u>, pair<k<7>, u>>>::
 template to_eq<v<3>>
,
 typename expect<at_key<k<4>, pair<k<0>, u>, pair<k<1>, u>, pair<k<2>, u>, pair<k<3>, u>, pair<k<4>, v<4>>, pair<k<5>, u>, pair<k<6>, u>, pair<k<7>, u>>>::
 template to_eq<v<4>>
,
 typename expect<at_key<k<5>, pair<k<0>, u>, pair<k<1>, u>, pair<k<2>, u>, pair<k<3>, u>, pair<k<4>, u>, pair<k<5>, v<5>>, pair<k<6>, u>, pair<k<7>, u>>>::
 template to_eq<v<5>>
,
 typename expect<at_key<k<6>, pair<k<0>, u>, pair<k<1>, u>, pair<k<2>, u>, pair<k<3>, u>, pair<k<4>, u>, pair<k<5>, u>, pair<k<6>, v<6>>, pair<k<7>, u>>>::
 template to_eq<v<6>>
,
 typename expect<at_key<k<7>, pair<k<0>, u>, pair<k<1>, u>, pair<k<2>, u>, pair<k<3>, u>, pair<k<4>, u>, pair<k<5>, u>, pair<k<6>, u>, pair<k<7>, v<7>>>>::
 template to_eq<v<7>>
,

 typename expect<at_key<k<0>, pair<k<0>, v<0>>, pair<k<1>, u>, pair<k<2>, u>, pair<k<3>, u>, pair<k<4>, u>, pair<k<5>, u>, pair<k<6>, u>, pair<k<7>, u>, pair<k<8>, u>>>::
 template to_eq<v<0>>
,
 typename expect<at_key<k<1>, pair<k<0>, u>, pair<k<1>, v<1>>, pair<k<2>, u>, pair<k<3>, u>, pair<k<4>, u>, pair<k<5>, u>, pair<k<6>, u>, pair<k<7>, u>, pair<k<8>, u>>>::
 template to_eq<v<1>>
,
 typename expect<at_key<k<2>, pair<k<0>, u>, pair<k<1>, u>, pair<k<2>, v<2>>, pair<k<3>, u>, pair<k<4>, u>, pair<k<5>, u>, pair<k<6>, u>, pair<k<7>, u>, pair<k<8>, u>>>::
 template to_eq<v<2>>
,
 typename expect<at_key<k<3>, pair<k<0>, u>, pair<k<1>, u>, pair<k<2>, u>, pair<k<3>, v<3>>, pair<k<4>, u>, pair<k<5>, u>, pair<k<6>, u>, pair<k<7>, u>, pair<k<8>, u>>>::
 template to_eq<v<3>>
,
 typename expect<at_key<k<4>, pair<k<0>, u>, pair<k<1>, u>, pair<k<2>, u>, pair<k<3>, u>, pair<k<4>, v<4>>, pair<k<5>, u>, pair<k<6>, u>, pair<k<7>, u>, pair<k<8>, u>>>::
 template to_eq<v<4>>
,
 typename expect<at_key<k<5>, pair<k<0>, u>, pair<k<1>, u>, pair<k<2>, u>, pair<k<3>, u>, pair<k<4>, u>, pair<k<5>, v<5>>, pair<k<6>, u>, pair<k<7>, u>, pair<k<8>, u>>>::
 template to_eq<v<5>>
,
 typename expect<at_key<k<6>, pair<k<0>, u>, pair<k<1>, u>, pair<k<2>, u>, pair<k<3>, u>, pair<k<4>, u>, pair<k<5>, u>, pair<k<6>, v<6>>, pair<k<7>, u>, pair<k<8>, u>>>::
 template to_eq<v<6>>
,
 typename expect<at_key<k<7>, pair<k<0>, u>, pair<k<1>, u>, pair<k<2>, u>, pair<k<3>, u>, pair<k<4>, u>, pair<k<5>, u>, pair<k<6>, u>, pair<k<7>, v<7>>, pair<k<8>, u>>>::
 template to_eq<v<7>>
,
 typename expect<at_key<k<8>, pair<k<0>, u>, pair<k<1>, u>, pair<k<2>, u>, pair<k<3>, u>, pair<k<4>, u>, pair<k<5>, u>, pair<k<6>, u>, pair<k<7>, u>, pair<k<8>, v<8>>>>::
 template to_eq<v<8>>
,

 typename expect<at_key<k<0>, pair<k<0>, v<0>>, pair<k<1>, u>, pair<k<2>, u>, pair<k<3>, u>, pair<k<4>, u>, pair<k<5>, u>, pair<k<6>, u>, pair<k<7>, u>, pair<k<8>, u>, pair<k<9>, u>>>::
 template to_eq<v<0>>
,
 typename expect<at_key<k<1>, pair<k<0>, u>, pair<k<1>, v<1>>, pair<k<2>, u>, pair<k<3>, u>, pair<k<4>, u>, pair<k<5>, u>, pair<k<6>, u>, pair<k<7>, u>, pair<k<8>, u>, pair<k<9>, u>>>::
 template to_eq<v<1>>
,
 typename expect<at_key<k<2>, pair<k<0>, u>, pair<k<1>, u>, pair<k<2>, v<2>>, pair<k<3>, u>, pair<k<4>, u>, pair<k<5>, u>, pair<k<6>, u>, pair<k<7>, u>, pair<k<8>, u>, pair<k<9>, u>>>::
 template to_eq<v<2>>
,
 typename expect<at_key<k<3>, pair<k<0>, u>, pair<k<1>, u>, pair<k<2>, u>, pair<k<3>, v<3>>, pair<k<4>, u>, pair<k<5>, u>, pair<k<6>, u>, pair<k<7>, u>, pair<k<8>, u>, pair<k<9>, u>>>::
 template to_eq<v<3>>
,
 typename expect<at_key<k<4>, pair<k<0>, u>, pair<k<1>, u>, pair<k<2>, u>, pair<k<3>, u>, pair<k<4>, v<4>>, pair<k<5>, u>, pair<k<6>, u>, pair<k<7>, u>, pair<k<8>, u>, pair<k<9>, u>>>::
 template to_eq<v<4>>
,
 typename expect<at_key<k<5>, pair<k<0>, u>, pair<k<1>, u>, pair<k<2>, u>, pair<k<3>, u>, pair<k<4>, u>, pair<k<5>, v<5>>, pair<k<6>, u>, pair<k<7>, u>, pair<k<8>, u>, pair<k<9>, u>>>::
 template to_eq<v<5>>
,
 typename expect<at_key<k<6>, pair<k<0>, u>, pair<k<1>, u>, pair<k<2>, u>, pair<k<3>, u>, pair<k<4>, u>, pair<k<5>, u>, pair<k<6>, v<6>>, pair<k<7>, u>, pair<k<8>, u>, pair<k<9>, u>>>::
 template to_eq<v<6>>
,
 typename expect<at_key<k<7>, pair<k<0>, u>, pair<k<1>, u>, pair<k<2>, u>, pair<k<3>, u>, pair<k<4>, u>, pair<k<5>, u>, pair<k<6>, u>, pair<k<7>, v<7>>, pair<k<8>, u>, pair<k<9>, u>>>::
 template to_eq<v<7>>
,
 typename expect<at_key<k<8>, pair<k<0>, u>, pair<k<1>, u>, pair<k<2>, u>, pair<k<3>, u>, pair<k<4>, u>, pair<k<5>, u>, pair<k<6>, u>, pair<k<7>, u>, pair<k<8>, v<8>>, pair<k<9>, u>>>::
 template to_eq<v<8>>
,
 typename expect<at_key<k<9>, pair<k<0>, u>, pair<k<1>, u>, pair<k<2>, u>, pair<k<3>, u>, pair<k<4>, u>, pair<k<5>, u>, pair<k<6>, u>, pair<k<7>, u>, pair<k<8>, u>, pair<k<9>, v<9>>>>::
 template to_eq<v<9>>

        >
    { };
}

using test_at_key_detail::test_at_key;
}}} // end namespace boost::mpl11::detail

#endif // !BOOST_MPL11_DETAIL_TEST_AT_KEY_HPP
