/*!
 * @file
 * Defines unit tests for right fold algorithms.
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

#ifndef BOOST_MPL11_DETAIL_TEST_FOLDR_HPP
#define BOOST_MPL11_DETAIL_TEST_FOLDR_HPP

#include <boost/mpl11/detail/test/expect.hpp>
#include <boost/mpl11/functional.hpp>


namespace boost { namespace mpl11 { namespace detail {
    namespace foldr_detail {
        template <int> struct x { using type = x; };

        template <typename ...x>
        struct f { using type = f<typename x::type...>; };

        

        template <
            template <typename ...> class fold,
            template <typename ...> class foldable>
        struct test_foldr :
            
                                expect<fold<lift<f>, x<0>, foldable<
                    
                >>>::template to_eq<
                    x<0>
                >
            
                ,                expect<fold<lift<f>, x<0>, foldable<
                    x<1>
                >>>::template to_eq<
                    f<x<1>, x<0>>
                >
            
                ,                expect<fold<lift<f>, x<0>, foldable<
                    x<1>,x<2>
                >>>::template to_eq<
                    f<x<1>, f<x<2>, x<0>>>
                >
            
                ,                expect<fold<lift<f>, x<0>, foldable<
                    x<1>,x<2>,x<3>
                >>>::template to_eq<
                    f<x<1>, f<x<2>, f<x<3>, x<0>>>>
                >
            
                ,                expect<fold<lift<f>, x<0>, foldable<
                    x<1>,x<2>,x<3>,x<4>
                >>>::template to_eq<
                    f<x<1>, f<x<2>, f<x<3>, f<x<4>, x<0>>>>>
                >
            
                ,                expect<fold<lift<f>, x<0>, foldable<
                    x<1>,x<2>,x<3>,x<4>,x<5>
                >>>::template to_eq<
                    f<x<1>, f<x<2>, f<x<3>, f<x<4>, f<x<5>, x<0>>>>>>
                >
            
                ,                expect<fold<lift<f>, x<0>, foldable<
                    x<1>,x<2>,x<3>,x<4>,x<5>,x<6>
                >>>::template to_eq<
                    f<x<1>, f<x<2>, f<x<3>, f<x<4>, f<x<5>, f<x<6>, x<0>>>>>>>
                >
            
                ,                expect<fold<lift<f>, x<0>, foldable<
                    x<1>,x<2>,x<3>,x<4>,x<5>,x<6>,x<7>
                >>>::template to_eq<
                    f<x<1>, f<x<2>, f<x<3>, f<x<4>, f<x<5>, f<x<6>, f<x<7>, x<0>>>>>>>>
                >
            
                ,                expect<fold<lift<f>, x<0>, foldable<
                    x<1>,x<2>,x<3>,x<4>,x<5>,x<6>,x<7>,x<8>
                >>>::template to_eq<
                    f<x<1>, f<x<2>, f<x<3>, f<x<4>, f<x<5>, f<x<6>, f<x<7>, f<x<8>, x<0>>>>>>>>>
                >
            
                ,                expect<fold<lift<f>, x<0>, foldable<
                    x<1>,x<2>,x<3>,x<4>,x<5>,x<6>,x<7>,x<8>,x<9>
                >>>::template to_eq<
                    f<x<1>, f<x<2>, f<x<3>, f<x<4>, f<x<5>, f<x<6>, f<x<7>, f<x<8>, f<x<9>, x<0>>>>>>>>>>
                >
            
                ,                expect<fold<lift<f>, x<0>, foldable<
                    x<1>,x<2>,x<3>,x<4>,x<5>,x<6>,x<7>,x<8>,x<9>,x<10>
                >>>::template to_eq<
                    f<x<1>, f<x<2>, f<x<3>, f<x<4>, f<x<5>, f<x<6>, f<x<7>, f<x<8>, f<x<9>, f<x<10>, x<0>>>>>>>>>>>
                >
            
                ,                expect<fold<lift<f>, x<0>, foldable<
                    x<1>,x<2>,x<3>,x<4>,x<5>,x<6>,x<7>,x<8>,x<9>,x<10>,x<11>
                >>>::template to_eq<
                    f<x<1>, f<x<2>, f<x<3>, f<x<4>, f<x<5>, f<x<6>, f<x<7>, f<x<8>, f<x<9>, f<x<10>, f<x<11>, x<0>>>>>>>>>>>>
                >
            
                ,                expect<fold<lift<f>, x<0>, foldable<
                    x<1>,x<2>,x<3>,x<4>,x<5>,x<6>,x<7>,x<8>,x<9>,x<10>,x<11>,x<12>
                >>>::template to_eq<
                    f<x<1>, f<x<2>, f<x<3>, f<x<4>, f<x<5>, f<x<6>, f<x<7>, f<x<8>, f<x<9>, f<x<10>, f<x<11>, f<x<12>, x<0>>>>>>>>>>>>>
                >
            
                ,                expect<fold<lift<f>, x<0>, foldable<
                    x<1>,x<2>,x<3>,x<4>,x<5>,x<6>,x<7>,x<8>,x<9>,x<10>,x<11>,x<12>,x<13>
                >>>::template to_eq<
                    f<x<1>, f<x<2>, f<x<3>, f<x<4>, f<x<5>, f<x<6>, f<x<7>, f<x<8>, f<x<9>, f<x<10>, f<x<11>, f<x<12>, f<x<13>, x<0>>>>>>>>>>>>>>
                >
            
                ,                expect<fold<lift<f>, x<0>, foldable<
                    x<1>,x<2>,x<3>,x<4>,x<5>,x<6>,x<7>,x<8>,x<9>,x<10>,x<11>,x<12>,x<13>,x<14>
                >>>::template to_eq<
                    f<x<1>, f<x<2>, f<x<3>, f<x<4>, f<x<5>, f<x<6>, f<x<7>, f<x<8>, f<x<9>, f<x<10>, f<x<11>, f<x<12>, f<x<13>, f<x<14>, x<0>>>>>>>>>>>>>>>
                >
            
                ,                expect<fold<lift<f>, x<0>, foldable<
                    x<1>,x<2>,x<3>,x<4>,x<5>,x<6>,x<7>,x<8>,x<9>,x<10>,x<11>,x<12>,x<13>,x<14>,x<15>
                >>>::template to_eq<
                    f<x<1>, f<x<2>, f<x<3>, f<x<4>, f<x<5>, f<x<6>, f<x<7>, f<x<8>, f<x<9>, f<x<10>, f<x<11>, f<x<12>, f<x<13>, f<x<14>, f<x<15>, x<0>>>>>>>>>>>>>>>>
                >
            
                ,                expect<fold<lift<f>, x<0>, foldable<
                    x<1>,x<2>,x<3>,x<4>,x<5>,x<6>,x<7>,x<8>,x<9>,x<10>,x<11>,x<12>,x<13>,x<14>,x<15>,x<16>
                >>>::template to_eq<
                    f<x<1>, f<x<2>, f<x<3>, f<x<4>, f<x<5>, f<x<6>, f<x<7>, f<x<8>, f<x<9>, f<x<10>, f<x<11>, f<x<12>, f<x<13>, f<x<14>, f<x<15>, f<x<16>, x<0>>>>>>>>>>>>>>>>>
                >
            
                ,                expect<fold<lift<f>, x<0>, foldable<
                    x<1>,x<2>,x<3>,x<4>,x<5>,x<6>,x<7>,x<8>,x<9>,x<10>,x<11>,x<12>,x<13>,x<14>,x<15>,x<16>,x<17>
                >>>::template to_eq<
                    f<x<1>, f<x<2>, f<x<3>, f<x<4>, f<x<5>, f<x<6>, f<x<7>, f<x<8>, f<x<9>, f<x<10>, f<x<11>, f<x<12>, f<x<13>, f<x<14>, f<x<15>, f<x<16>, f<x<17>, x<0>>>>>>>>>>>>>>>>>>
                >
            
                ,                expect<fold<lift<f>, x<0>, foldable<
                    x<1>,x<2>,x<3>,x<4>,x<5>,x<6>,x<7>,x<8>,x<9>,x<10>,x<11>,x<12>,x<13>,x<14>,x<15>,x<16>,x<17>,x<18>
                >>>::template to_eq<
                    f<x<1>, f<x<2>, f<x<3>, f<x<4>, f<x<5>, f<x<6>, f<x<7>, f<x<8>, f<x<9>, f<x<10>, f<x<11>, f<x<12>, f<x<13>, f<x<14>, f<x<15>, f<x<16>, f<x<17>, f<x<18>, x<0>>>>>>>>>>>>>>>>>>>
                >
            
                ,                expect<fold<lift<f>, x<0>, foldable<
                    x<1>,x<2>,x<3>,x<4>,x<5>,x<6>,x<7>,x<8>,x<9>,x<10>,x<11>,x<12>,x<13>,x<14>,x<15>,x<16>,x<17>,x<18>,x<19>
                >>>::template to_eq<
                    f<x<1>, f<x<2>, f<x<3>, f<x<4>, f<x<5>, f<x<6>, f<x<7>, f<x<8>, f<x<9>, f<x<10>, f<x<11>, f<x<12>, f<x<13>, f<x<14>, f<x<15>, f<x<16>, f<x<17>, f<x<18>, f<x<19>, x<0>>>>>>>>>>>>>>>>>>>>
                >
            
                ,                expect<fold<lift<f>, x<0>, foldable<
                    x<1>,x<2>,x<3>,x<4>,x<5>,x<6>,x<7>,x<8>,x<9>,x<10>,x<11>,x<12>,x<13>,x<14>,x<15>,x<16>,x<17>,x<18>,x<19>,x<20>
                >>>::template to_eq<
                    f<x<1>, f<x<2>, f<x<3>, f<x<4>, f<x<5>, f<x<6>, f<x<7>, f<x<8>, f<x<9>, f<x<10>, f<x<11>, f<x<12>, f<x<13>, f<x<14>, f<x<15>, f<x<16>, f<x<17>, f<x<18>, f<x<19>, f<x<20>, x<0>>>>>>>>>>>>>>>>>>>>>
                >
            
        { };
    } // end namespace foldr_detail

    using foldr_detail::test_foldr;
}}} // end namespace boost::mpl11::detail

#endif // !BOOST_MPL11_DETAIL_TEST_FOLDR_HPP
