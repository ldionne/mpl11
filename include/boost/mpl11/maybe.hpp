/*!
 * @file
 * Defines the @ref Maybe datatype.
 *
 *
 * @copyright Louis Dionne 2014
 * Distributed under the Boost Software License, Version 1.0.
 *         (See accompanying file LICENSE.md or copy at
 *             http://www.boost.org/LICENSE_1_0.txt)
 */

#ifndef BOOST_MPL11_MAYBE_HPP
#define BOOST_MPL11_MAYBE_HPP

#include <boost/mpl11/fwd/maybe.hpp>

#include <boost/mpl11/core.hpp>
#include <boost/mpl11/detail/dependent.hpp>
#include <boost/mpl11/functor.hpp>

#include <boost/mpl11/bool.hpp>       // required by fwd/maybe.hpp
#include <boost/mpl11/functional.hpp> //


namespace boost { namespace mpl11 {
    template <typename x>
    struct just {
        using type = just;
        using mpl_datatype = Maybe;

        template <typename def, typename f>
        using maybe_ = typename f::type::template apply<x>;
    };

    struct nothing {
        using type = nothing;
        using mpl_datatype = Maybe;

        template <typename def, typename f>
        using maybe_ = def;
    };

    template <typename def, typename f, typename m>
    struct maybe
        : m::type::template maybe_<def, f>
    { };

    namespace maybe_detail {
        template <typename ...dum>
        struct err_from_just {
            static_assert(detail::dependent<dum...>::value(false),
            "Using from_just on a nothing.");

            struct type;
        };
    }

    template <>
    struct Functor<Maybe> : instantiate<Functor>::with<Maybe> {
        template <typename f, typename m>
        using fmap_impl = typename m::template maybe_<nothing, f>;
    };

#if 0
    template <typename T, typename U>
    struct Comparable<Maybe<T>, Maybe<U>, typename Comparable<T, U>::type>
        : instantiate<Comparable>::with<Maybe<T>, Maybe<U>>
    {
        template <typename x, typename y>
        struct equal_impl
            : equal_impl<typename x::type, typename y::type>
        { };

        template <>
        struct equal_impl<nothing, nothing>
            : true_
        { };

        template <typename x, typename y>
        struct equal_impl<just<x>, just<y>>
            : equal<x, y>
        { };
    };
#endif
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_MAYBE_HPP
