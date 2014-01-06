/*!
 * @file
 * Defines `boost::mpl11::detail::variadic_last`.
 */

#ifndef BOOST_MPL11_DETAIL_VARIADIC_LAST_HPP
#define BOOST_MPL11_DETAIL_VARIADIC_LAST_HPP

namespace boost { namespace mpl11 { namespace detail {
    /*!
     * @ingroup details
     *
     * Returns the last element of a variadic parameter pack.
     */
    template <typename Head, typename ...Tail>
    struct variadic_last;
}}}


#include <boost/mpl11/id.hpp>


namespace boost { namespace mpl11 { namespace detail {
    namespace variadic_last_detail {
        template <typename ...Head>
        struct impl {
            template <typename Last>
            static id<Last> apply(Head..., id<Last>*);
        };
    }

    template <typename Head, typename ...Tail>
    struct variadic_last
        : decltype(
            variadic_last_detail::impl<
                decltype((void*)(Tail*)nullptr)...
            >::apply((id<Head>*)nullptr, (id<Tail>*)nullptr...)
        )
    { };
}}} // end namespace boost::mpl11::detail

#endif // !BOOST_MPL11_DETAIL_VARIADIC_LAST_HPP
