/*!
 * @file
 * Defines unit tests for `logical or`s.
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

#ifndef BOOST_MPL11_DETAIL_TEST_LOGICAL_OR_HPP
#define BOOST_MPL11_DETAIL_TEST_LOGICAL_OR_HPP

#include <boost/mpl11/bool.hpp>
#include <boost/mpl11/core.hpp>
#include <boost/mpl11/detail/test/expect.hpp>


namespace boost { namespace mpl11 { namespace detail {
    

    template <template <typename ...> class or_>
    struct test_logical_or_strict
        : instantiate<
            typename expect<or_<>>::template to_eq<false_>
            
                
                    ,typename expect<
                        or_<true_>
                    >::template to_eq<
                        bool_<true>
                    >
                
                    ,typename expect<
                        or_<false_>
                    >::template to_eq<
                        bool_<false>
                    >
                
            
                
                    ,typename expect<
                        or_<true_,true_>
                    >::template to_eq<
                        bool_<true>
                    >
                
                    ,typename expect<
                        or_<true_,false_>
                    >::template to_eq<
                        bool_<true>
                    >
                
                    ,typename expect<
                        or_<false_,true_>
                    >::template to_eq<
                        bool_<true>
                    >
                
                    ,typename expect<
                        or_<false_,false_>
                    >::template to_eq<
                        bool_<false>
                    >
                
            
                
                    ,typename expect<
                        or_<true_,true_,true_>
                    >::template to_eq<
                        bool_<true>
                    >
                
                    ,typename expect<
                        or_<true_,true_,false_>
                    >::template to_eq<
                        bool_<true>
                    >
                
                    ,typename expect<
                        or_<true_,false_,true_>
                    >::template to_eq<
                        bool_<true>
                    >
                
                    ,typename expect<
                        or_<true_,false_,false_>
                    >::template to_eq<
                        bool_<true>
                    >
                
                    ,typename expect<
                        or_<false_,true_,true_>
                    >::template to_eq<
                        bool_<true>
                    >
                
                    ,typename expect<
                        or_<false_,true_,false_>
                    >::template to_eq<
                        bool_<true>
                    >
                
                    ,typename expect<
                        or_<false_,false_,true_>
                    >::template to_eq<
                        bool_<true>
                    >
                
                    ,typename expect<
                        or_<false_,false_,false_>
                    >::template to_eq<
                        bool_<false>
                    >
                
            
                
                    ,typename expect<
                        or_<true_,true_,true_,true_>
                    >::template to_eq<
                        bool_<true>
                    >
                
                    ,typename expect<
                        or_<true_,true_,true_,false_>
                    >::template to_eq<
                        bool_<true>
                    >
                
                    ,typename expect<
                        or_<true_,true_,false_,true_>
                    >::template to_eq<
                        bool_<true>
                    >
                
                    ,typename expect<
                        or_<true_,true_,false_,false_>
                    >::template to_eq<
                        bool_<true>
                    >
                
                    ,typename expect<
                        or_<true_,false_,true_,true_>
                    >::template to_eq<
                        bool_<true>
                    >
                
                    ,typename expect<
                        or_<true_,false_,true_,false_>
                    >::template to_eq<
                        bool_<true>
                    >
                
                    ,typename expect<
                        or_<true_,false_,false_,true_>
                    >::template to_eq<
                        bool_<true>
                    >
                
                    ,typename expect<
                        or_<true_,false_,false_,false_>
                    >::template to_eq<
                        bool_<true>
                    >
                
                    ,typename expect<
                        or_<false_,true_,true_,true_>
                    >::template to_eq<
                        bool_<true>
                    >
                
                    ,typename expect<
                        or_<false_,true_,true_,false_>
                    >::template to_eq<
                        bool_<true>
                    >
                
                    ,typename expect<
                        or_<false_,true_,false_,true_>
                    >::template to_eq<
                        bool_<true>
                    >
                
                    ,typename expect<
                        or_<false_,true_,false_,false_>
                    >::template to_eq<
                        bool_<true>
                    >
                
                    ,typename expect<
                        or_<false_,false_,true_,true_>
                    >::template to_eq<
                        bool_<true>
                    >
                
                    ,typename expect<
                        or_<false_,false_,true_,false_>
                    >::template to_eq<
                        bool_<true>
                    >
                
                    ,typename expect<
                        or_<false_,false_,false_,true_>
                    >::template to_eq<
                        bool_<true>
                    >
                
                    ,typename expect<
                        or_<false_,false_,false_,false_>
                    >::template to_eq<
                        bool_<false>
                    >
                
            
                
                    ,typename expect<
                        or_<true_,true_,true_,true_,true_>
                    >::template to_eq<
                        bool_<true>
                    >
                
                    ,typename expect<
                        or_<true_,true_,true_,true_,false_>
                    >::template to_eq<
                        bool_<true>
                    >
                
                    ,typename expect<
                        or_<true_,true_,true_,false_,true_>
                    >::template to_eq<
                        bool_<true>
                    >
                
                    ,typename expect<
                        or_<true_,true_,true_,false_,false_>
                    >::template to_eq<
                        bool_<true>
                    >
                
                    ,typename expect<
                        or_<true_,true_,false_,true_,true_>
                    >::template to_eq<
                        bool_<true>
                    >
                
                    ,typename expect<
                        or_<true_,true_,false_,true_,false_>
                    >::template to_eq<
                        bool_<true>
                    >
                
                    ,typename expect<
                        or_<true_,true_,false_,false_,true_>
                    >::template to_eq<
                        bool_<true>
                    >
                
                    ,typename expect<
                        or_<true_,true_,false_,false_,false_>
                    >::template to_eq<
                        bool_<true>
                    >
                
                    ,typename expect<
                        or_<true_,false_,true_,true_,true_>
                    >::template to_eq<
                        bool_<true>
                    >
                
                    ,typename expect<
                        or_<true_,false_,true_,true_,false_>
                    >::template to_eq<
                        bool_<true>
                    >
                
                    ,typename expect<
                        or_<true_,false_,true_,false_,true_>
                    >::template to_eq<
                        bool_<true>
                    >
                
                    ,typename expect<
                        or_<true_,false_,true_,false_,false_>
                    >::template to_eq<
                        bool_<true>
                    >
                
                    ,typename expect<
                        or_<true_,false_,false_,true_,true_>
                    >::template to_eq<
                        bool_<true>
                    >
                
                    ,typename expect<
                        or_<true_,false_,false_,true_,false_>
                    >::template to_eq<
                        bool_<true>
                    >
                
                    ,typename expect<
                        or_<true_,false_,false_,false_,true_>
                    >::template to_eq<
                        bool_<true>
                    >
                
                    ,typename expect<
                        or_<true_,false_,false_,false_,false_>
                    >::template to_eq<
                        bool_<true>
                    >
                
                    ,typename expect<
                        or_<false_,true_,true_,true_,true_>
                    >::template to_eq<
                        bool_<true>
                    >
                
                    ,typename expect<
                        or_<false_,true_,true_,true_,false_>
                    >::template to_eq<
                        bool_<true>
                    >
                
                    ,typename expect<
                        or_<false_,true_,true_,false_,true_>
                    >::template to_eq<
                        bool_<true>
                    >
                
                    ,typename expect<
                        or_<false_,true_,true_,false_,false_>
                    >::template to_eq<
                        bool_<true>
                    >
                
                    ,typename expect<
                        or_<false_,true_,false_,true_,true_>
                    >::template to_eq<
                        bool_<true>
                    >
                
                    ,typename expect<
                        or_<false_,true_,false_,true_,false_>
                    >::template to_eq<
                        bool_<true>
                    >
                
                    ,typename expect<
                        or_<false_,true_,false_,false_,true_>
                    >::template to_eq<
                        bool_<true>
                    >
                
                    ,typename expect<
                        or_<false_,true_,false_,false_,false_>
                    >::template to_eq<
                        bool_<true>
                    >
                
                    ,typename expect<
                        or_<false_,false_,true_,true_,true_>
                    >::template to_eq<
                        bool_<true>
                    >
                
                    ,typename expect<
                        or_<false_,false_,true_,true_,false_>
                    >::template to_eq<
                        bool_<true>
                    >
                
                    ,typename expect<
                        or_<false_,false_,true_,false_,true_>
                    >::template to_eq<
                        bool_<true>
                    >
                
                    ,typename expect<
                        or_<false_,false_,true_,false_,false_>
                    >::template to_eq<
                        bool_<true>
                    >
                
                    ,typename expect<
                        or_<false_,false_,false_,true_,true_>
                    >::template to_eq<
                        bool_<true>
                    >
                
                    ,typename expect<
                        or_<false_,false_,false_,true_,false_>
                    >::template to_eq<
                        bool_<true>
                    >
                
                    ,typename expect<
                        or_<false_,false_,false_,false_,true_>
                    >::template to_eq<
                        bool_<true>
                    >
                
                    ,typename expect<
                        or_<false_,false_,false_,false_,false_>
                    >::template to_eq<
                        bool_<false>
                    >
                
            
        >
    { };

    template <template <typename ...> class or_>
    struct test_logical_or_lazy
        : instantiate<
            test_logical_or_strict<or_>
            
                
                    ,typename expect<
                        or_<true_,undefined>
                    >::template to_eq<
                        bool_<true>
                    >
                
            
                
                    ,typename expect<
                        or_<true_,undefined,undefined>
                    >::template to_eq<
                        bool_<true>
                    >
                
                    ,typename expect<
                        or_<false_,true_,undefined>
                    >::template to_eq<
                        bool_<true>
                    >
                
            
                
                    ,typename expect<
                        or_<true_,undefined,undefined,undefined>
                    >::template to_eq<
                        bool_<true>
                    >
                
                    ,typename expect<
                        or_<false_,true_,undefined,undefined>
                    >::template to_eq<
                        bool_<true>
                    >
                
                    ,typename expect<
                        or_<false_,false_,true_,undefined>
                    >::template to_eq<
                        bool_<true>
                    >
                
            
                
                    ,typename expect<
                        or_<true_,undefined,undefined,undefined,undefined>
                    >::template to_eq<
                        bool_<true>
                    >
                
                    ,typename expect<
                        or_<false_,true_,undefined,undefined,undefined>
                    >::template to_eq<
                        bool_<true>
                    >
                
                    ,typename expect<
                        or_<false_,false_,true_,undefined,undefined>
                    >::template to_eq<
                        bool_<true>
                    >
                
                    ,typename expect<
                        or_<false_,false_,false_,true_,undefined>
                    >::template to_eq<
                        bool_<true>
                    >
                
            
                
                    ,typename expect<
                        or_<true_,undefined,undefined,undefined,undefined,undefined>
                    >::template to_eq<
                        bool_<true>
                    >
                
                    ,typename expect<
                        or_<false_,true_,undefined,undefined,undefined,undefined>
                    >::template to_eq<
                        bool_<true>
                    >
                
                    ,typename expect<
                        or_<false_,false_,true_,undefined,undefined,undefined>
                    >::template to_eq<
                        bool_<true>
                    >
                
                    ,typename expect<
                        or_<false_,false_,false_,true_,undefined,undefined>
                    >::template to_eq<
                        bool_<true>
                    >
                
                    ,typename expect<
                        or_<false_,false_,false_,false_,true_,undefined>
                    >::template to_eq<
                        bool_<true>
                    >
                
            
                
                    ,typename expect<
                        or_<true_,undefined,undefined,undefined,undefined,undefined,undefined>
                    >::template to_eq<
                        bool_<true>
                    >
                
                    ,typename expect<
                        or_<false_,true_,undefined,undefined,undefined,undefined,undefined>
                    >::template to_eq<
                        bool_<true>
                    >
                
                    ,typename expect<
                        or_<false_,false_,true_,undefined,undefined,undefined,undefined>
                    >::template to_eq<
                        bool_<true>
                    >
                
                    ,typename expect<
                        or_<false_,false_,false_,true_,undefined,undefined,undefined>
                    >::template to_eq<
                        bool_<true>
                    >
                
                    ,typename expect<
                        or_<false_,false_,false_,false_,true_,undefined,undefined>
                    >::template to_eq<
                        bool_<true>
                    >
                
                    ,typename expect<
                        or_<false_,false_,false_,false_,false_,true_,undefined>
                    >::template to_eq<
                        bool_<true>
                    >
                
            
                
                    ,typename expect<
                        or_<true_,undefined,undefined,undefined,undefined,undefined,undefined,undefined>
                    >::template to_eq<
                        bool_<true>
                    >
                
                    ,typename expect<
                        or_<false_,true_,undefined,undefined,undefined,undefined,undefined,undefined>
                    >::template to_eq<
                        bool_<true>
                    >
                
                    ,typename expect<
                        or_<false_,false_,true_,undefined,undefined,undefined,undefined,undefined>
                    >::template to_eq<
                        bool_<true>
                    >
                
                    ,typename expect<
                        or_<false_,false_,false_,true_,undefined,undefined,undefined,undefined>
                    >::template to_eq<
                        bool_<true>
                    >
                
                    ,typename expect<
                        or_<false_,false_,false_,false_,true_,undefined,undefined,undefined>
                    >::template to_eq<
                        bool_<true>
                    >
                
                    ,typename expect<
                        or_<false_,false_,false_,false_,false_,true_,undefined,undefined>
                    >::template to_eq<
                        bool_<true>
                    >
                
                    ,typename expect<
                        or_<false_,false_,false_,false_,false_,false_,true_,undefined>
                    >::template to_eq<
                        bool_<true>
                    >
                
            
                
                    ,typename expect<
                        or_<true_,undefined,undefined,undefined,undefined,undefined,undefined,undefined,undefined>
                    >::template to_eq<
                        bool_<true>
                    >
                
                    ,typename expect<
                        or_<false_,true_,undefined,undefined,undefined,undefined,undefined,undefined,undefined>
                    >::template to_eq<
                        bool_<true>
                    >
                
                    ,typename expect<
                        or_<false_,false_,true_,undefined,undefined,undefined,undefined,undefined,undefined>
                    >::template to_eq<
                        bool_<true>
                    >
                
                    ,typename expect<
                        or_<false_,false_,false_,true_,undefined,undefined,undefined,undefined,undefined>
                    >::template to_eq<
                        bool_<true>
                    >
                
                    ,typename expect<
                        or_<false_,false_,false_,false_,true_,undefined,undefined,undefined,undefined>
                    >::template to_eq<
                        bool_<true>
                    >
                
                    ,typename expect<
                        or_<false_,false_,false_,false_,false_,true_,undefined,undefined,undefined>
                    >::template to_eq<
                        bool_<true>
                    >
                
                    ,typename expect<
                        or_<false_,false_,false_,false_,false_,false_,true_,undefined,undefined>
                    >::template to_eq<
                        bool_<true>
                    >
                
                    ,typename expect<
                        or_<false_,false_,false_,false_,false_,false_,false_,true_,undefined>
                    >::template to_eq<
                        bool_<true>
                    >
                
            
                
                    ,typename expect<
                        or_<true_,undefined,undefined,undefined,undefined,undefined,undefined,undefined,undefined,undefined>
                    >::template to_eq<
                        bool_<true>
                    >
                
                    ,typename expect<
                        or_<false_,true_,undefined,undefined,undefined,undefined,undefined,undefined,undefined,undefined>
                    >::template to_eq<
                        bool_<true>
                    >
                
                    ,typename expect<
                        or_<false_,false_,true_,undefined,undefined,undefined,undefined,undefined,undefined,undefined>
                    >::template to_eq<
                        bool_<true>
                    >
                
                    ,typename expect<
                        or_<false_,false_,false_,true_,undefined,undefined,undefined,undefined,undefined,undefined>
                    >::template to_eq<
                        bool_<true>
                    >
                
                    ,typename expect<
                        or_<false_,false_,false_,false_,true_,undefined,undefined,undefined,undefined,undefined>
                    >::template to_eq<
                        bool_<true>
                    >
                
                    ,typename expect<
                        or_<false_,false_,false_,false_,false_,true_,undefined,undefined,undefined,undefined>
                    >::template to_eq<
                        bool_<true>
                    >
                
                    ,typename expect<
                        or_<false_,false_,false_,false_,false_,false_,true_,undefined,undefined,undefined>
                    >::template to_eq<
                        bool_<true>
                    >
                
                    ,typename expect<
                        or_<false_,false_,false_,false_,false_,false_,false_,true_,undefined,undefined>
                    >::template to_eq<
                        bool_<true>
                    >
                
                    ,typename expect<
                        or_<false_,false_,false_,false_,false_,false_,false_,false_,true_,undefined>
                    >::template to_eq<
                        bool_<true>
                    >
                
            
        >
    { };
}}} // end namespace boost::mpl11::detail

#endif // !BOOST_MPL11_DETAIL_TEST_LOGICAL_OR_HPP
