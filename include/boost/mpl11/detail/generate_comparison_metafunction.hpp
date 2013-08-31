/*!
 * @file
 * Generates the default implementation for comparison metafunctions.
 */

#include <boost/mpl11/always.hpp>
#include <boost/mpl11/and.hpp>
#include <boost/mpl11/arg.hpp>
#include <boost/mpl11/categories.hpp>
#include <boost/mpl11/detail/best_category_for.hpp>
#include <boost/mpl11/detail/tag_dispatched.hpp>
#include <boost/mpl11/identity.hpp>
#include <boost/mpl11/integral_c.hpp>
#include <boost/mpl11/tags.hpp>


namespace boost { namespace mpl11 {
namespace comparison_metafunction_detail {
    template <typename Category1, typename T1, typename Category2, typename T2>
    struct BOOST_MPL11_OPERATOR_NAME;

    template <typename T1, typename T2>
    struct BOOST_MPL11_OPERATOR_NAME<category::integral_constant, T1,
                                     category::integral_constant, T2>
        : identity<bool_<T1::value BOOST_MPL11_OPERATOR T2::value>>>
    { };
} // end namespace comparison_metafunction_detail

template <typename T1, typename T2, typename ...Tn>
struct BOOST_MPL11_OPERATOR_NAME
    : detail::tag_dispatched<tag::BOOST_MPL11_OPERATOR_NAME, T1, T2, Tn...>
      ::template with_default<
        lazy_always<
            and_<
                BOOST_MPL11_OPERATOR_NAME<T1, T2>,
                BOOST_MPL11_OPERATOR_NAME<T2, Tn...>
            >
        >
      >
{ };

template <typename T1, typename T2>
struct BOOST_MPL11_OPERATOR_NAME<T1, T2>
    : detail::tag_dispatched<tag::BOOST_MPL11_OPERATOR_NAME, T1, T2>
      ::template with_default<
        comparison_metafunction_detail::BOOST_MPL11_OPERATOR_NAME<
            detail::best_category_for<_1, category::integral_constant>, _1,
            detail::best_category_for<_2, category::integral_constant>, _2
        >
      >
{ };
}} // end namespace boost::mpl11

#undef BOOST_MPL11_OPERATOR_NAME
#undef BOOST_MPL11_OPERATOR
