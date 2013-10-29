/*!
 * @file
 * Defines `boost::mpl11::detail::test_couple`.
 */

#ifndef BOOST_MPL11_DETAIL_TEST_COUPLE_HPP
#define BOOST_MPL11_DETAIL_TEST_COUPLE_HPP

#include <boost/mpl11/detail/is_same.hpp>
#include <boost/mpl11/equal.hpp>
#include <boost/mpl11/first.hpp>
#include <boost/mpl11/greater.hpp>
#include <boost/mpl11/greater_equal.hpp>
#include <boost/mpl11/integral_c.hpp>
#include <boost/mpl11/less.hpp>
#include <boost/mpl11/less_equal.hpp>
#include <boost/mpl11/not_equal.hpp>
#include <boost/mpl11/second.hpp>


namespace boost { namespace mpl11 { namespace detail {
    /*!
     * @ingroup details
     *
     * Generic unit test for `Couple`s.
     */
    template <template <typename, typename> class couple>
    class test_couple {
        struct First;
        struct Second;

        // first
        static_assert(is_same<
            typename first<couple<First, Second>>::type, First
        >::value, "");

        // second
        static_assert(is_same<
            typename second<couple<First, Second>>::type, Second
        >::value, "");

        template <int x, int y>
        using couple_c = couple<int_<x>, int_<y>>;

#define BOOST_MPL11_CHECK_BINOP(NAME, X1, Y1, X2, Y2)                       \
        static_assert(NAME<                                                 \
            couple_c<(X1), (Y1)>, couple_c<(X2), (Y2)>                      \
        >::value, "");                                                      \
/**/

        // Comparable
        BOOST_MPL11_CHECK_BINOP(equal, 0, 0, 0, 0)

        BOOST_MPL11_CHECK_BINOP(not_equal, 1, 0, 0, 0)
        BOOST_MPL11_CHECK_BINOP(not_equal, 0, 1, 0, 0)
        BOOST_MPL11_CHECK_BINOP(not_equal, 0, 0, 1, 0)
        BOOST_MPL11_CHECK_BINOP(not_equal, 0, 0, 0, 1)

        // Orderable
        BOOST_MPL11_CHECK_BINOP(less, 0, 0,
                                      1, 0)
        BOOST_MPL11_CHECK_BINOP(less, 0, 0,
                                      0, 1)
        BOOST_MPL11_CHECK_BINOP(less, 0, 1,
                                      1, 0)

        BOOST_MPL11_CHECK_BINOP(less_equal, 0, 0,
                                            1, 0)
        BOOST_MPL11_CHECK_BINOP(less_equal, 0, 0,
                                            0, 1)
        BOOST_MPL11_CHECK_BINOP(less_equal, 0, 1,
                                            1, 0)
        BOOST_MPL11_CHECK_BINOP(less_equal, 0, 0,
                                            0, 0)

        BOOST_MPL11_CHECK_BINOP(greater, 1, 0,
                                         0, 0)
        BOOST_MPL11_CHECK_BINOP(greater, 1, 0,
                                         0, 1)
        BOOST_MPL11_CHECK_BINOP(greater, 0, 1,
                                         0, 0)

        BOOST_MPL11_CHECK_BINOP(greater_equal, 1, 0,
                                               0, 0)
        BOOST_MPL11_CHECK_BINOP(greater_equal, 1, 0,
                                               0, 1)
        BOOST_MPL11_CHECK_BINOP(greater_equal, 0, 1,
                                               0, 0)
        BOOST_MPL11_CHECK_BINOP(greater_equal, 0, 0,
                                               0, 0)

#undef BOOST_MPL11_CHECK_BINOP
    };
}}} // end namespace boost::mpl11::detail

#endif // !BOOST_MPL11_DETAIL_TEST_COUPLE_HPP
