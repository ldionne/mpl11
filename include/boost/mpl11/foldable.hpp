/*!
 * @file
 * Defines the methods of the @ref Foldable typeclass.
 *
 *
 * @copyright Louis Dionne 2014
 * Distributed under the Boost Software License, Version 1.0.
 *         (See accompanying file LICENSE.md or copy at
 *             http://www.boost.org/LICENSE_1_0.txt)
 */

#ifndef BOOST_MPL11_FOLDABLE_HPP
#define BOOST_MPL11_FOLDABLE_HPP

#include <boost/mpl11/fwd/foldable.hpp>

#include <boost/mpl11/core.hpp>
#include <boost/mpl11/detail/config.hpp>
#include <boost/mpl11/maybe.hpp>

#include <boost/mpl11/bool.hpp>       //
#include <boost/mpl11/functional.hpp> // required by fwd/foldable.hpp
#include <boost/mpl11/logical.hpp>    //


namespace boost { namespace mpl11 {
    template <typename Datatype, typename>
    struct Foldable : false_ { };

    template <>
    struct instantiate<Foldable> {
    private:
        template <typename f>
        struct maybe_f {
            using type = maybe_f;
            template <typename x, typename y>
            using apply = just<maybe<x, partial<f, x>, y>>;
        };

    public:
        template <typename Datatype>
        struct with : true_ {
            template <typename f, typename structure>
            using foldr1_impl = from_just<
                foldr<maybe_f<f>, nothing, box<structure>>
            >;

            template <typename f, typename structure>
            using foldl1_impl = from_just<
                foldl<flip<maybe_f<flip<f>>>, nothing, box<structure>>
            >;
        };
    };

    template <typename f, typename state, typename structure>
    struct foldr :
        Foldable<typename datatype<typename structure::type>::type>::
        template foldr_impl<f, state, typename structure::type>
    { };

    template <typename f, typename state, typename structure>
    struct foldl :
        Foldable<typename datatype<typename structure::type>::type>::
        template foldl_impl<f, state, typename structure::type>
    { };

    namespace foldable_detail {
        template <typename xs>
        using is_empty_structure = foldr<always<false_>, true_, xs>;

        template <typename structure>
        struct fold1_checks {
            static_assert(!is_empty_structure<structure>::value,
            "Invalid usage of foldr1 or foldl1 with an empty structure.");
        };
    }

    template <typename f, typename structure>
    struct foldr1 :
        BOOST_MPL11_IF_ASSERTIONS(foldable_detail::fold1_checks<structure>,)
        Foldable<typename datatype<typename structure::type>::type>::
        template foldr1_impl<f, typename structure::type>
    { };

    template <typename f, typename structure>
    struct foldl1 :
        BOOST_MPL11_IF_ASSERTIONS(foldable_detail::fold1_checks<structure>,)
        Foldable<typename datatype<typename structure::type>::type>::
        template foldl1_impl<f, typename structure::type>
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FOLDABLE_HPP
