/*!
 * @file
 * Defines `boost::mpl11::detail::no_decay`.
 */

#ifndef BOOST_MPL11_DETAIL_NO_DECAY_HPP
#define BOOST_MPL11_DETAIL_NO_DECAY_HPP

#include <boost/mpl11/detail/doxygen_only.hpp>


namespace boost { namespace mpl11 { namespace detail {
    /*!
     * @ingroup details
     *
     * Avoids type decay when passing types as function arguments.
     *
     * @note
     * To avoid instantiating specializations of `no_decay` when unnecessary,
     * we leave `no_decay` incomplete and we use `no_decay<T>*` instead of
     * `no_decay<T>`.
     */
    template <typename T>
    struct no_decay BOOST_MPL11_DOXYGEN_ONLY({ });
}}} // end namespace boost::mpl11::detail

#endif // !BOOST_MPL11_DETAIL_NO_DECAY_HPP
