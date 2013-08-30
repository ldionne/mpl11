/*!
 * @file
 * Defines `boost::mpl11::always` and `boost::mpl11::lazy_always`.
 */

#ifndef BOOST_MPL11_ALWAYS_HPP
#define BOOST_MPL11_ALWAYS_HPP

#include <boost/mpl11/detail/either.hpp>
#include <boost/mpl11/empty_base.hpp>
#include <boost/mpl11/identity.hpp>


namespace boost { namespace mpl11 {
    /*!
     * Metafunction class always returning `T`, regardless of the
     * number and types of passed arguments.
     */
    template <typename T>
    struct always {
        template <typename ...>
        struct apply
            : identity<T>
        { };
    };

    /*!
     * Metafunction class always returning `F::type` if it is a valid
     * expression, regardless of the number and types of passed arguments.
     *
     * If `F::type` is not a valid expression, `lazy_always<F>::apply<...>`
     * does not have a nested type.
     */
    template <typename F>
    struct lazy_always {
        template <typename ...>
        struct apply
            : detail::either<F, empty_base>
        { };
    };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_ALWAYS_HPP
