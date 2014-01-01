/*!
 * @file
 * Defines `boost::mpl11::Orderable`.
 */

#ifndef BOOST_MPL11_ORDERABLE_HPP
#define BOOST_MPL11_ORDERABLE_HPP

#include <boost/mpl11/fwd/orderable.hpp>

#include <boost/mpl11/not.hpp>
#include <boost/mpl11/tag_of.hpp>


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

    #define BOOST_MPL11_ORDERABLE_METHOD(METHOD)                            \
        template <typename T1, typename T2>                                 \
        struct METHOD                                                       \
            : Orderable<                                                    \
                typename tag_of<T1>::type, typename tag_of<T2>::type        \
            >::template METHOD ## _impl<T1, T2>                             \
        { };                                                                \
    /**/
    BOOST_MPL11_ORDERABLE_METHOD(less)
    BOOST_MPL11_ORDERABLE_METHOD(less_equal)
    BOOST_MPL11_ORDERABLE_METHOD(greater)
    BOOST_MPL11_ORDERABLE_METHOD(greater_equal)
    #undef BOOST_MPL11_ORDERABLE_METHOD
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_ORDERABLE_HPP
