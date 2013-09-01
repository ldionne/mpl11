/*!
 * @file
 * Generates the default implementation for comparison intrinsics.
 */

#include <boost/mpl11/always.hpp>
#include <boost/mpl11/categories.hpp>
#include <boost/mpl11/detail/best_category_for.hpp>
#include <boost/mpl11/detail/tag_dispatched.hpp>
#include <boost/mpl11/identity.hpp>
#include <boost/mpl11/integral_c.hpp>
#include <boost/mpl11/intrinsic/and.hpp>
#include <boost/mpl11/tags.hpp>


namespace boost { namespace mpl11 {
namespace comparison_intrinsic_detail {
    template <typename Category1, typename T1, typename Category2, typename T2>
    struct BOOST_MPL11_OPERATOR_NAME;

    template <typename T1, typename T2>
    struct BOOST_MPL11_OPERATOR_NAME<category::integral_constant, T1,
                                     category::integral_constant, T2>
        : identity<bool_<T1::value BOOST_MPL11_OPERATOR T2::value>>
    { };
} // end namespace comparison_intrinsic_detail

namespace intrinsic {
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
            lazy_always<
                comparison_intrinsic_detail::BOOST_MPL11_OPERATOR_NAME<
                    typename detail::best_category_for<
                        T1, category::integral_constant
                    >::type,
                    T1,
                    typename detail::best_category_for<
                        T2, category::integral_constant
                    >::type,
                    T2
                >
            >
          >
    { };
} // end namespace intrinsic
}} // end namespace boost::mpl11

#undef BOOST_MPL11_OPERATOR_NAME
#undef BOOST_MPL11_OPERATOR
