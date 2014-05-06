/*!
 * @file
 * Defines unit tests for index-based lookup algorithms.
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

#ifndef BOOST_MPL11_DETAIL_TEST_AT_INDEX_HPP
#define BOOST_MPL11_DETAIL_TEST_AT_INDEX_HPP

#include <boost/mpl11/core.hpp>
#include <boost/mpl11/detail/std_is_same.hpp>
#include <boost/mpl11/detail/std_size_t.hpp>
#include <boost/mpl11/detail/test/expect.hpp>


namespace boost { namespace mpl11 { namespace detail {
namespace test_at_index_detail {
    template <int> struct x { struct type; };
    using u = undefined;

    template <template <std_size_t, typename ...> class at_index>
    struct test_at_index
        : instantiate<
             typename expect<at_index<0, x<0>>>::
 template to_eq<x<0>>
,

 typename expect<at_index<0, x<0>, u>>::
 template to_eq<x<0>>
,
 typename expect<at_index<1, u, x<1>>>::
 template to_eq<x<1>>
,

 typename expect<at_index<0, x<0>, u, u>>::
 template to_eq<x<0>>
,
 typename expect<at_index<1, u, x<1>, u>>::
 template to_eq<x<1>>
,
 typename expect<at_index<2, u, u, x<2>>>::
 template to_eq<x<2>>
,

 typename expect<at_index<0, x<0>, u, u, u>>::
 template to_eq<x<0>>
,
 typename expect<at_index<1, u, x<1>, u, u>>::
 template to_eq<x<1>>
,
 typename expect<at_index<2, u, u, x<2>, u>>::
 template to_eq<x<2>>
,
 typename expect<at_index<3, u, u, u, x<3>>>::
 template to_eq<x<3>>
,

 typename expect<at_index<0, x<0>, u, u, u, u>>::
 template to_eq<x<0>>
,
 typename expect<at_index<1, u, x<1>, u, u, u>>::
 template to_eq<x<1>>
,
 typename expect<at_index<2, u, u, x<2>, u, u>>::
 template to_eq<x<2>>
,
 typename expect<at_index<3, u, u, u, x<3>, u>>::
 template to_eq<x<3>>
,
 typename expect<at_index<4, u, u, u, u, x<4>>>::
 template to_eq<x<4>>
,

 typename expect<at_index<0, x<0>, u, u, u, u, u>>::
 template to_eq<x<0>>
,
 typename expect<at_index<1, u, x<1>, u, u, u, u>>::
 template to_eq<x<1>>
,
 typename expect<at_index<2, u, u, x<2>, u, u, u>>::
 template to_eq<x<2>>
,
 typename expect<at_index<3, u, u, u, x<3>, u, u>>::
 template to_eq<x<3>>
,
 typename expect<at_index<4, u, u, u, u, x<4>, u>>::
 template to_eq<x<4>>
,
 typename expect<at_index<5, u, u, u, u, u, x<5>>>::
 template to_eq<x<5>>
,

 typename expect<at_index<0, x<0>, u, u, u, u, u, u>>::
 template to_eq<x<0>>
,
 typename expect<at_index<1, u, x<1>, u, u, u, u, u>>::
 template to_eq<x<1>>
,
 typename expect<at_index<2, u, u, x<2>, u, u, u, u>>::
 template to_eq<x<2>>
,
 typename expect<at_index<3, u, u, u, x<3>, u, u, u>>::
 template to_eq<x<3>>
,
 typename expect<at_index<4, u, u, u, u, x<4>, u, u>>::
 template to_eq<x<4>>
,
 typename expect<at_index<5, u, u, u, u, u, x<5>, u>>::
 template to_eq<x<5>>
,
 typename expect<at_index<6, u, u, u, u, u, u, x<6>>>::
 template to_eq<x<6>>
,

 typename expect<at_index<0, x<0>, u, u, u, u, u, u, u>>::
 template to_eq<x<0>>
,
 typename expect<at_index<1, u, x<1>, u, u, u, u, u, u>>::
 template to_eq<x<1>>
,
 typename expect<at_index<2, u, u, x<2>, u, u, u, u, u>>::
 template to_eq<x<2>>
,
 typename expect<at_index<3, u, u, u, x<3>, u, u, u, u>>::
 template to_eq<x<3>>
,
 typename expect<at_index<4, u, u, u, u, x<4>, u, u, u>>::
 template to_eq<x<4>>
,
 typename expect<at_index<5, u, u, u, u, u, x<5>, u, u>>::
 template to_eq<x<5>>
,
 typename expect<at_index<6, u, u, u, u, u, u, x<6>, u>>::
 template to_eq<x<6>>
,
 typename expect<at_index<7, u, u, u, u, u, u, u, x<7>>>::
 template to_eq<x<7>>
,

 typename expect<at_index<0, x<0>, u, u, u, u, u, u, u, u>>::
 template to_eq<x<0>>
,
 typename expect<at_index<1, u, x<1>, u, u, u, u, u, u, u>>::
 template to_eq<x<1>>
,
 typename expect<at_index<2, u, u, x<2>, u, u, u, u, u, u>>::
 template to_eq<x<2>>
,
 typename expect<at_index<3, u, u, u, x<3>, u, u, u, u, u>>::
 template to_eq<x<3>>
,
 typename expect<at_index<4, u, u, u, u, x<4>, u, u, u, u>>::
 template to_eq<x<4>>
,
 typename expect<at_index<5, u, u, u, u, u, x<5>, u, u, u>>::
 template to_eq<x<5>>
,
 typename expect<at_index<6, u, u, u, u, u, u, x<6>, u, u>>::
 template to_eq<x<6>>
,
 typename expect<at_index<7, u, u, u, u, u, u, u, x<7>, u>>::
 template to_eq<x<7>>
,
 typename expect<at_index<8, u, u, u, u, u, u, u, u, x<8>>>::
 template to_eq<x<8>>
,

 typename expect<at_index<0, x<0>, u, u, u, u, u, u, u, u, u>>::
 template to_eq<x<0>>
,
 typename expect<at_index<1, u, x<1>, u, u, u, u, u, u, u, u>>::
 template to_eq<x<1>>
,
 typename expect<at_index<2, u, u, x<2>, u, u, u, u, u, u, u>>::
 template to_eq<x<2>>
,
 typename expect<at_index<3, u, u, u, x<3>, u, u, u, u, u, u>>::
 template to_eq<x<3>>
,
 typename expect<at_index<4, u, u, u, u, x<4>, u, u, u, u, u>>::
 template to_eq<x<4>>
,
 typename expect<at_index<5, u, u, u, u, u, x<5>, u, u, u, u>>::
 template to_eq<x<5>>
,
 typename expect<at_index<6, u, u, u, u, u, u, x<6>, u, u, u>>::
 template to_eq<x<6>>
,
 typename expect<at_index<7, u, u, u, u, u, u, u, x<7>, u, u>>::
 template to_eq<x<7>>
,
 typename expect<at_index<8, u, u, u, u, u, u, u, u, x<8>, u>>::
 template to_eq<x<8>>
,
 typename expect<at_index<9, u, u, u, u, u, u, u, u, u, x<9>>>::
 template to_eq<x<9>>

        >
    { };
}

using test_at_index_detail::test_at_index;
}}} // end namespace boost::mpl11::detail

#endif // !BOOST_MPL11_DETAIL_TEST_AT_INDEX_HPP
