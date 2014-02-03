/*!
 * @file
 * Defines the @ref Comparable typeclass.
 */

#ifndef BOOST_MPL11_COMPARABLE_HPP
#define BOOST_MPL11_COMPARABLE_HPP

#include <boost/mpl11/fwd/comparable.hpp>

#include <boost/mpl11/core.hpp>
#include <boost/mpl11/detail/common_method.hpp>
#include <boost/mpl11/detail/std_is_same.hpp>
#include <boost/mpl11/logical.hpp>


namespace boost { namespace mpl11 {
    template <typename Left, typename Right>
    struct Comparable {
    private:
        using Common = Comparable<typename common_datatype<Left, Right>::type>;

    public:
        template <typename x, typename y>
        using equal_impl =
            typename detail::common_method<Left, Right>::
            template apply<Common::template equal_impl, x, y>;

        template <typename x, typename y>
        using not_equal_impl =
            typename detail::common_method<Left, Right>::
            template apply<Common::template not_equal_impl, x, y>;
    };

    template <>
    struct Comparable<typeclass<Comparable>> {
        template <typename left, typename right>
        using equal_impl = not_<not_equal<box<left>, box<right>>>;

        template <typename left, typename right>
        using not_equal_impl = not_<equal<box<left>, box<right>>>;
    };

    template <typename x1, typename x2, typename ...xs>
    struct equal
        : and_<equal<x1, x2>, equal<x2, xs...>>
    { };

    template <typename x1, typename x2>
    struct equal<x1, x2> :
        Comparable<
            typename datatype<typename x1::type>::type,
            typename datatype<typename x2::type>::type
        >::template equal_impl<typename x1::type, typename x2::type>
    { };

    template <typename x, typename y>
    struct not_equal :
        Comparable<
            typename datatype<typename x::type>::type,
            typename datatype<typename y::type>::type
        >::template not_equal_impl<typename x::type, typename y::type>
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_COMPARABLE_HPP
