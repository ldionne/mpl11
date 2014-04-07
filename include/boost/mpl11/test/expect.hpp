/*!
 * @file
 * Defines utilities to write unit tests.
 *
 *
 * @copyright Louis Dionne 2014
 * Distributed under the Boost Software License, Version 1.0.
 *         (See accompanying file LICENSE.md or copy at
 *             http://www.boost.org/LICENSE_1_0.txt)
 */

#ifndef BOOST_MPL11_TEST_EXPECT_HPP
#define BOOST_MPL11_TEST_EXPECT_HPP

#include <boost/mpl11/detail/std_size_t.hpp>
#include <boost/mpl11/functional.hpp>
#include <boost/mpl11/fwd/comparable.hpp>
#include <boost/mpl11/logical.hpp>


namespace boost { namespace mpl11 { namespace test {
    template <typename ...xs>
    struct instantiate {
        // We avoid empty arrays by adding a dummy 0.
        static constexpr detail::std_size_t go[] = {0, sizeof(xs)...};

        using type = instantiate;
    };

    template <typename expr>
    struct expect {
        template <template <typename ...> class Bool>
        struct _to {
            template <typename r>
            struct eq {
                static_assert(Bool<equal<expr, r>>::value, "");
                static_assert(!Bool<not_equal<expr, r>>::value, "");
            };

            template <typename predicate>
            struct satisfy {
                static_assert(Bool<
                    typename predicate::type::template apply<expr>
                >::value, "");
            };

            template <typename comparison>
            struct be {
                template <typename r>
                struct than {
                    static_assert(Bool<
                        typename comparison::type::template apply<expr, r>
                    >::value, "");
                };
            };

            template <template <typename ...> class f>
            using be_ = be<lift<f>>;
        };

        using to = _to<id>;
        using not_to = _to<not_>;

        template <typename r>
        using to_eq = typename to::template eq<r>;

        template <typename pred>
        using to_satisfy = typename to::template satisfy<pred>;
    };
}}} // end namespace boost::mpl11::test

#endif // !BOOST_MPL11_TEST_EXPECT_HPP
