/*!
 * @file
 * Defines `boost::mpl11::detail::dispatch_category`.
 */

#ifndef BOOST_MPL11_DETAIL_DISPATCH_CATEGORY_HPP
#define BOOST_MPL11_DETAIL_DISPATCH_CATEGORY_HPP

#include <boost/mpl11/identity.hpp>


namespace boost { namespace mpl11 {
namespace dispatch_category_detail {
    template <typename ...T>
    struct best_match;

    template <>
    struct best_match<> {
        template <typename Otherwise>
        static auto pick(...) -> Otherwise;
    };

    template <typename T1, typename ...Tn>
    struct best_match<T1, Tn...> : best_match<Tn...> {
        using best_match<Tn...>::pick;

        template <typename Otherwise>
        static auto pick(T1*) -> T1;
    };
} // end namespace dispatch_category_detail

namespace detail {
    template <typename Category, typename ...Categories>
    struct dispatch_category
        : identity<decltype(
            dispatch_category_detail::best_match<Categories...>::
                template pick<Category>((Category*)nullptr)
        )>
    { };
} // end namespace detail
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_DETAIL_DISPATCH_CATEGORY_HPP
