/*!
 * @file
 * Defines `boost::mpl11::detail::test_logical`.
 */

#ifndef BOOST_MPL11_DETAIL_TEST_LOGICAL_HPP
#define BOOST_MPL11_DETAIL_TEST_LOGICAL_HPP

#include <boost/mpl11/and.hpp>
#include <boost/mpl11/detail/is_same.hpp>
#include <boost/mpl11/identity.hpp>
#include <boost/mpl11/not.hpp>
#include <boost/mpl11/or.hpp>


namespace boost { namespace mpl11 { namespace detail {
    /*!
     * @ingroup details
     *
     * Generic unit test for `Logical` types.
     *
     *
     * @tparam True  A `Logical` representing `true`.
     * @tparam False A `Logical` representing `false`.
     */
    template <typename False, typename True>
    class test_logical {
        template <typename ...Conditions>
        using and_ = mpl11::and_<identity<Conditions>...>;

        template <typename ...Conditions>
        using or_ = mpl11::or_<identity<Conditions>...>;

        template <typename Condition>
        using not_ = mpl11::not_<identity<Condition>>;

        // not_
        static_assert(!not_<True>::value, "");
        static_assert(not_<False>::value, "");

        // and_
        static_assert(is_same<
            typename and_<True, True>::type, True
        >::value, "");
        static_assert(is_same<
            typename and_<True, False>::type, False
        >::value, "");
        static_assert(is_same<
            typename and_<False, True>::type, False
        >::value, "");
        static_assert(is_same<
            typename and_<False, False>::type, False
        >::value, "");

        // or_
        static_assert(is_same<
            typename or_<True, True>::type, True
        >::value, "");
        static_assert(is_same<
            typename or_<True, False>::type, True
        >::value, "");
        static_assert(is_same<
            typename or_<False, True>::type, True
        >::value, "");
        static_assert(is_same<
            typename or_<False, False>::type, False
        >::value, "");

        // test short-circuit evaluation
        static_assert(is_same<
            typename and_<False, struct must_not_evaluate>::type, False
        >::value, "");
        static_assert(is_same<
            typename or_<True, struct must_not_evaluate>::type, True
        >::value, "");
    };
}}} // end namespace boost::mpl11::detail

#endif // !BOOST_MPL11_DETAIL_TEST_LOGICAL_HPP
