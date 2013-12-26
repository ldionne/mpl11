/*!
 * @file
 * Defines `boost::mpl11::Orderable`.
 */

#ifndef BOOST_MPL11_ORDERABLE_HPP
#define BOOST_MPL11_ORDERABLE_HPP

#include <boost/mpl11/v2/fwd/orderable.hpp>

#include <boost/mpl11/not.hpp>
#include <boost/mpl11/v2/less.hpp>


namespace boost { namespace mpl11 {
    namespace defaults {
        struct Orderable {
            template <typename L, typename R>
            using less_equal_impl = not_<less<R, L>>;

            template <typename L, typename R>
            using greater_impl = less<R, L>;

            template <typename L, typename R>
            using greater_equal_impl = not_<less<L, R>>;
        };
    } // end namespace defaults

    namespace detail {
        template <typename TagL, typename TagR>
        struct flip_Orderable {
            template <typename L, typename R>
            using less_impl = typename Orderable<TagR, TagL>::
                              template less_impl<R, L>;

            template <typename L, typename R>
            using less_equal_impl = typename Orderable<TagR, TagL>::
                                    template less_equal_impl<R, L>;

            template <typename L, typename R>
            using greater_impl = typename Orderable<TagR, TagL>::
                                 template greater_impl<R, L>;

            template <typename L, typename R>
            using greater_equal_impl = typename Orderable<TagR, TagL>::
                                       template greater_equal_impl<R, L>;
        };
    } // end namespace detail
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_ORDERABLE_HPP
