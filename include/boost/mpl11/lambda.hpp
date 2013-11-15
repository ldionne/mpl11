/*!
 * @file
 * Defines `boost::mpl11::lambda`.
 */

#ifndef BOOST_MPL11_LAMBDA_HPP
#define BOOST_MPL11_LAMBDA_HPP

#include <boost/mpl11/fwd/lambda.hpp>

#include <boost/mpl11/apply.hpp>
#include <boost/mpl11/fwd/vector.hpp>
#include <boost/mpl11/identity.hpp>
#include <boost/mpl11/is_placeholder.hpp>


namespace boost { namespace mpl11 {
    namespace lambda_detail {
        template <
            typename F, typename Args, bool = is_placeholder<F>::value
        >
        struct lambda_impl;

        // In case we're dealing with a placeholder, we apply the placeholder
        // to the provided arguments.
        template <typename F, typename ...Args>
        struct lambda_impl<F, vector<Args...>, true> {
            static constexpr bool is_pe = true;
            using result = mpl11::apply<F, Args...>;
        };

        // In case we're dealing with a non-template type that is not a
        // placeholder, we return it unchanged.
        template <typename T, typename Args>
        struct lambda_impl<T, Args, false> {
            static constexpr bool is_pe = false;
            using result = identity<T>;
        };

        // In case we're dealing with `lambda` itself, we do as-if it was not
        // a template specialization because we don't want to evaluate those
        // recursively.
        template <typename F, typename Args>
        struct lambda_impl<lambda<F>, Args, false> {
            static constexpr bool is_pe = false;
            using result = identity<lambda<F>>;
        };

        template <
            template <typename ...> class Result, typename Args, bool IsPe
        >
        struct parser;

        // In case we're dealing with a template specialization, we must
        // proceed carefully. See below.
        template <
            template <typename ...> class F, typename ...T,
            typename Args
        >
        struct lambda_impl<F<T...>, Args, false>
            : parser<F, Args, false>::template parse<vector<>, vector<T...>>
        { };

        // Template specializations are tricky:
        // We won't know whether it really is a normal type or a placeholder
        // expression until we've examined each of its template parameters.
        // So we proceed to recursively examine them and change the token
        // whenever we find a parameter which is a placeholder expression.
        // When the token is changed, processing will continue in the
        // specialization of `parser` below.
        template <template <typename ...> class Result, typename Args>
        struct parser<Result, Args, false> {
            template <typename Parsed, typename Input>
            struct parse;

            template <typename ...Parsed>
            struct parse<vector<Parsed...>, vector<>> {
                static constexpr bool is_pe = false;
                using result = identity<Result<Parsed...>>;
            };

            template <typename ...Parsed, typename Head, typename ...Tail>
            struct parse<vector<Parsed...>, vector<Head, Tail...>>
                : parser<
                    Result,
                    Args,
                    lambda_impl<Head, Args>::is_pe
                >::template parse<
                    vector<
                        Parsed...,
                        typename lambda_impl<Head, Args>::result::type
                    >,
                    vector<Tail...>
                >
            { };
        };

        // Here we're dealing with a template specialization which we know
        // is a placeholder expression. This simplifies parsing because
        // we don't have to check `is_placeholder` anymore.
        template <template <typename ...> class Result, typename Args>
        struct parser<Result, Args, true> {
            template <typename Parsed, typename Input>
            struct parse;

            template <typename ...Parsed>
            struct parse<vector<Parsed...>, vector<>> {
                static constexpr bool is_pe = true;
                using result = Result<Parsed...>;
            };

            template <typename ...Parsed, typename Head, typename ...Tail>
            struct parse<vector<Parsed...>, vector<Head, Tail...>>
                : parse<
                    vector<
                        Parsed...,
                        typename lambda_impl<Head, Args>::result::type
                    >,
                    vector<Tail...>
                >
            { };
        };
    } // end namespace lambda_detail

    template <typename F>
    struct lambda {
        template <typename ...Args>
        struct apply
            : lambda_detail::lambda_impl<F, vector<Args...>>::result
        { };
    };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_LAMBDA_HPP
