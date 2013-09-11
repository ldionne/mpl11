/*!
 * @file
 * Defines `boost::mpl11::detail::best_category_for`.
 */

#ifndef BOOST_MPL11_DETAIL_BEST_CATEGORY_FOR_HPP
#define BOOST_MPL11_DETAIL_BEST_CATEGORY_FOR_HPP

#include <boost/mpl11/identity.hpp>
#include <boost/mpl11/intrinsic/category_of.hpp>


namespace boost { namespace mpl11 {
namespace best_category_for_detail {
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
} // end namespace best_category_for_detail

namespace detail {
    template <typename T, typename ...Categories>
    struct best_category_for
        : identity<decltype(
            best_category_for_detail::best_match<Categories...>::template
                pick<typename category_of<T>::type>(
                    (typename category_of<T>::type*)nullptr
                )
        )>
    { };
} // end namespace detail
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_DETAIL_BEST_CATEGORY_FOR_HPP
