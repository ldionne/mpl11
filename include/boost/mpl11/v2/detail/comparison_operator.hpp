/*!
 * @file
 * Header defining a comparison operator.
 *
 * Before including this header, the following macros must be defined with
 * the described semantics:
 *
 * - `BOOST_MPL11_OPERATOR`
 *
 *   The name of the comparison operator to generate.
 *
 * - `BOOST_MPL11_OPERATOR_IMPL`
 *
 *   The name used to fetch the implementation of the operator inside the
 *   typeclass.
 *
 * - `BOOST_MPL11_TYPECLASS`
 *
 *   The name of the typeclass defining the operator.
 *
 * These macros are automatically undefined by the header.
 *
 * For example, if one wants to generate the `equal` operator:
 *
        #define BOOST_MPL11_OPERATOR equal
        #define BOOST_MPL11_OPERATOR_IMPL equal_impl
        #define BOOST_MPL11_TYPECLASS Comparable
        #include <boost/mpl11/detail/comparison_operator.hpp>
 *
 *
 * @note
 * This header is meant for multiple inclusion, hence the lack of
 * include guards.
 */

#include <boost/mpl11/and.hpp>
#include <boost/mpl11/v2/tag_of.hpp>


namespace boost { namespace mpl11 {
    namespace comparison_operator_detail {
        template <bool Only2>
        struct BOOST_MPL11_OPERATOR_IMPL;

        template <>
        struct BOOST_MPL11_OPERATOR_IMPL<false> {
            template <typename T1, typename T2, typename ...Tn>
            using apply = and_<
                BOOST_MPL11_OPERATOR<T1, T2>,
                BOOST_MPL11_OPERATOR<T2, Tn...>
            >;
        };

        template <>
        struct BOOST_MPL11_OPERATOR_IMPL<true> {
            template <typename T1, typename T2>
            using apply = typename BOOST_MPL11_TYPECLASS<
                typename tag_of<T1>::type,
                typename tag_of<T2>::type
            >::template BOOST_MPL11_OPERATOR_IMPL<T1, T2>;
        };
    } // end namespace comparison_operator_detail

    // Note that we don't specialize the operator for two arguments because
    // that could make some (user defined) partial specializations ambiguous.
    template <typename T1, typename T2, typename ...Tn>
    struct BOOST_MPL11_OPERATOR
        : comparison_operator_detail::BOOST_MPL11_OPERATOR_IMPL<
            sizeof...(Tn) == 0
        >::template apply<T1, T2, Tn...>
    { };
}} // end namespace boost::mpl11

#undef BOOST_MPL11_OPERATOR_IMPL
#undef BOOST_MPL11_OPERATOR
#undef BOOST_MPL11_TYPECLASS
