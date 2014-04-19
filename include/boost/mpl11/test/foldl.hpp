/*!
 * @file
 * Defines unit tests for left fold algorithms.
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

#ifndef BOOST_MPL11_TEST_FOLDL_HPP
#define BOOST_MPL11_TEST_FOLDL_HPP

#include <boost/mpl11/functional.hpp>
#include <boost/mpl11/test/expect.hpp>


namespace boost { namespace mpl11 { namespace test {
    namespace foldl_detail {
        template <int> struct x { using type = x; };

        template <typename ...x>
        struct f { using type = f<typename x::type...>; };

        

        template <
            template <typename ...> class fold,
            template <typename ...> class foldable>
        struct test_foldl :
            
                                expect<fold<lift<f>, x<0>, foldable<
                    
                >>>::template to_eq<
                    x<0>
                >
            
                ,                expect<fold<lift<f>, x<0>, foldable<
                    x<1>
                >>>::template to_eq<
                    f<x<0>, x<1>>
                >
            
                ,                expect<fold<lift<f>, x<0>, foldable<
                    x<1>,x<2>
                >>>::template to_eq<
                    f<f<x<0>, x<1>>, x<2>>
                >
            
                ,                expect<fold<lift<f>, x<0>, foldable<
                    x<1>,x<2>,x<3>
                >>>::template to_eq<
                    f<f<f<x<0>, x<1>>, x<2>>, x<3>>
                >
            
                ,                expect<fold<lift<f>, x<0>, foldable<
                    x<1>,x<2>,x<3>,x<4>
                >>>::template to_eq<
                    f<f<f<f<x<0>, x<1>>, x<2>>, x<3>>, x<4>>
                >
            
                ,                expect<fold<lift<f>, x<0>, foldable<
                    x<1>,x<2>,x<3>,x<4>,x<5>
                >>>::template to_eq<
                    f<f<f<f<f<x<0>, x<1>>, x<2>>, x<3>>, x<4>>, x<5>>
                >
            
                ,                expect<fold<lift<f>, x<0>, foldable<
                    x<1>,x<2>,x<3>,x<4>,x<5>,x<6>
                >>>::template to_eq<
                    f<f<f<f<f<f<x<0>, x<1>>, x<2>>, x<3>>, x<4>>, x<5>>, x<6>>
                >
            
                ,                expect<fold<lift<f>, x<0>, foldable<
                    x<1>,x<2>,x<3>,x<4>,x<5>,x<6>,x<7>
                >>>::template to_eq<
                    f<f<f<f<f<f<f<x<0>, x<1>>, x<2>>, x<3>>, x<4>>, x<5>>, x<6>>, x<7>>
                >
            
                ,                expect<fold<lift<f>, x<0>, foldable<
                    x<1>,x<2>,x<3>,x<4>,x<5>,x<6>,x<7>,x<8>
                >>>::template to_eq<
                    f<f<f<f<f<f<f<f<x<0>, x<1>>, x<2>>, x<3>>, x<4>>, x<5>>, x<6>>, x<7>>, x<8>>
                >
            
                ,                expect<fold<lift<f>, x<0>, foldable<
                    x<1>,x<2>,x<3>,x<4>,x<5>,x<6>,x<7>,x<8>,x<9>
                >>>::template to_eq<
                    f<f<f<f<f<f<f<f<f<x<0>, x<1>>, x<2>>, x<3>>, x<4>>, x<5>>, x<6>>, x<7>>, x<8>>, x<9>>
                >
            
                ,                expect<fold<lift<f>, x<0>, foldable<
                    x<1>,x<2>,x<3>,x<4>,x<5>,x<6>,x<7>,x<8>,x<9>,x<10>
                >>>::template to_eq<
                    f<f<f<f<f<f<f<f<f<f<x<0>, x<1>>, x<2>>, x<3>>, x<4>>, x<5>>, x<6>>, x<7>>, x<8>>, x<9>>, x<10>>
                >
            
                ,                expect<fold<lift<f>, x<0>, foldable<
                    x<1>,x<2>,x<3>,x<4>,x<5>,x<6>,x<7>,x<8>,x<9>,x<10>,x<11>
                >>>::template to_eq<
                    f<f<f<f<f<f<f<f<f<f<f<x<0>, x<1>>, x<2>>, x<3>>, x<4>>, x<5>>, x<6>>, x<7>>, x<8>>, x<9>>, x<10>>, x<11>>
                >
            
                ,                expect<fold<lift<f>, x<0>, foldable<
                    x<1>,x<2>,x<3>,x<4>,x<5>,x<6>,x<7>,x<8>,x<9>,x<10>,x<11>,x<12>
                >>>::template to_eq<
                    f<f<f<f<f<f<f<f<f<f<f<f<x<0>, x<1>>, x<2>>, x<3>>, x<4>>, x<5>>, x<6>>, x<7>>, x<8>>, x<9>>, x<10>>, x<11>>, x<12>>
                >
            
                ,                expect<fold<lift<f>, x<0>, foldable<
                    x<1>,x<2>,x<3>,x<4>,x<5>,x<6>,x<7>,x<8>,x<9>,x<10>,x<11>,x<12>,x<13>
                >>>::template to_eq<
                    f<f<f<f<f<f<f<f<f<f<f<f<f<x<0>, x<1>>, x<2>>, x<3>>, x<4>>, x<5>>, x<6>>, x<7>>, x<8>>, x<9>>, x<10>>, x<11>>, x<12>>, x<13>>
                >
            
                ,                expect<fold<lift<f>, x<0>, foldable<
                    x<1>,x<2>,x<3>,x<4>,x<5>,x<6>,x<7>,x<8>,x<9>,x<10>,x<11>,x<12>,x<13>,x<14>
                >>>::template to_eq<
                    f<f<f<f<f<f<f<f<f<f<f<f<f<f<x<0>, x<1>>, x<2>>, x<3>>, x<4>>, x<5>>, x<6>>, x<7>>, x<8>>, x<9>>, x<10>>, x<11>>, x<12>>, x<13>>, x<14>>
                >
            
                ,                expect<fold<lift<f>, x<0>, foldable<
                    x<1>,x<2>,x<3>,x<4>,x<5>,x<6>,x<7>,x<8>,x<9>,x<10>,x<11>,x<12>,x<13>,x<14>,x<15>
                >>>::template to_eq<
                    f<f<f<f<f<f<f<f<f<f<f<f<f<f<f<x<0>, x<1>>, x<2>>, x<3>>, x<4>>, x<5>>, x<6>>, x<7>>, x<8>>, x<9>>, x<10>>, x<11>>, x<12>>, x<13>>, x<14>>, x<15>>
                >
            
                ,                expect<fold<lift<f>, x<0>, foldable<
                    x<1>,x<2>,x<3>,x<4>,x<5>,x<6>,x<7>,x<8>,x<9>,x<10>,x<11>,x<12>,x<13>,x<14>,x<15>,x<16>
                >>>::template to_eq<
                    f<f<f<f<f<f<f<f<f<f<f<f<f<f<f<f<x<0>, x<1>>, x<2>>, x<3>>, x<4>>, x<5>>, x<6>>, x<7>>, x<8>>, x<9>>, x<10>>, x<11>>, x<12>>, x<13>>, x<14>>, x<15>>, x<16>>
                >
            
                ,                expect<fold<lift<f>, x<0>, foldable<
                    x<1>,x<2>,x<3>,x<4>,x<5>,x<6>,x<7>,x<8>,x<9>,x<10>,x<11>,x<12>,x<13>,x<14>,x<15>,x<16>,x<17>
                >>>::template to_eq<
                    f<f<f<f<f<f<f<f<f<f<f<f<f<f<f<f<f<x<0>, x<1>>, x<2>>, x<3>>, x<4>>, x<5>>, x<6>>, x<7>>, x<8>>, x<9>>, x<10>>, x<11>>, x<12>>, x<13>>, x<14>>, x<15>>, x<16>>, x<17>>
                >
            
                ,                expect<fold<lift<f>, x<0>, foldable<
                    x<1>,x<2>,x<3>,x<4>,x<5>,x<6>,x<7>,x<8>,x<9>,x<10>,x<11>,x<12>,x<13>,x<14>,x<15>,x<16>,x<17>,x<18>
                >>>::template to_eq<
                    f<f<f<f<f<f<f<f<f<f<f<f<f<f<f<f<f<f<x<0>, x<1>>, x<2>>, x<3>>, x<4>>, x<5>>, x<6>>, x<7>>, x<8>>, x<9>>, x<10>>, x<11>>, x<12>>, x<13>>, x<14>>, x<15>>, x<16>>, x<17>>, x<18>>
                >
            
                ,                expect<fold<lift<f>, x<0>, foldable<
                    x<1>,x<2>,x<3>,x<4>,x<5>,x<6>,x<7>,x<8>,x<9>,x<10>,x<11>,x<12>,x<13>,x<14>,x<15>,x<16>,x<17>,x<18>,x<19>
                >>>::template to_eq<
                    f<f<f<f<f<f<f<f<f<f<f<f<f<f<f<f<f<f<f<x<0>, x<1>>, x<2>>, x<3>>, x<4>>, x<5>>, x<6>>, x<7>>, x<8>>, x<9>>, x<10>>, x<11>>, x<12>>, x<13>>, x<14>>, x<15>>, x<16>>, x<17>>, x<18>>, x<19>>
                >
            
                ,                expect<fold<lift<f>, x<0>, foldable<
                    x<1>,x<2>,x<3>,x<4>,x<5>,x<6>,x<7>,x<8>,x<9>,x<10>,x<11>,x<12>,x<13>,x<14>,x<15>,x<16>,x<17>,x<18>,x<19>,x<20>
                >>>::template to_eq<
                    f<f<f<f<f<f<f<f<f<f<f<f<f<f<f<f<f<f<f<f<x<0>, x<1>>, x<2>>, x<3>>, x<4>>, x<5>>, x<6>>, x<7>>, x<8>>, x<9>>, x<10>>, x<11>>, x<12>>, x<13>>, x<14>>, x<15>>, x<16>>, x<17>>, x<18>>, x<19>>, x<20>>
                >
            
        { };
    } // end namespace foldl_detail

    using foldl_detail::test_foldl;
}}} // end namespace boost::mpl11::test

#endif // !BOOST_MPL11_TEST_FOLDL_HPP
