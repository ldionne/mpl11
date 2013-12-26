/*!
 * @file
 * Defines `boost::mpl11::Comparable`.
 */

#ifndef BOOST_MPL11_COMPARABLE_HPP
#define BOOST_MPL11_COMPARABLE_HPP

#include <boost/mpl11/v2/fwd/comparable.hpp>

#include <boost/mpl11/integral_c.hpp>
#include <boost/mpl11/not.hpp>
#include <boost/mpl11/v2/equal.hpp>
#include <boost/mpl11/v2/not_equal.hpp>


namespace boost { namespace mpl11 {
    namespace defaults {
        struct Comparable {
            template <typename L, typename R>
            using equal_impl = not_<not_equal<L, R>>;

            template <typename L, typename R>
            using not_equal_impl = not_<equal<L, R>>;
        };
    } // end namespace defaults

    namespace detail {
        template <typename TagL, typename TagR>
        struct flip_Comparable {
            template <typename L, typename R>
            using equal_impl = typename Comparable<TagR, TagL>::
                               template equal_impl<R, L>;

            template <typename L, typename R>
            using not_equal_impl = typename Comparable<TagR, TagL>::
                                   template not_equal_impl<R, L>;
        };
    } // end namespace detail

    template <typename TagL, typename TagR>
    struct Comparable {
        template <typename L, typename R>
        struct equal_impl : false_ { };

        template <typename T>
        struct equal_impl<T, T> : true_ { };


        template <typename L, typename R>
        struct not_equal_impl : true_ { };

        template <typename T>
        struct not_equal_impl<T, T> : false_ { };
    };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_COMPARABLE_HPP
