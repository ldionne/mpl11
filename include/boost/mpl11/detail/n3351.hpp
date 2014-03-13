/*!
 * @file
 * Defines `boost::mpl11::detail::N3351`.
 */

#ifndef BOOST_MPL11_DETAIL_N3351_HPP
#define BOOST_MPL11_DETAIL_N3351_HPP

#include <boost/mpl11/core.hpp>
#include <boost/mpl11/detail/std_is_same.hpp>
#include <boost/mpl11/logical.hpp>


namespace boost { namespace mpl11 { namespace detail {
    /*!
     * @ingroup details
     *
     * Returns whether two datatypes satisfy the requirements to be used
     * in mixed datatype operations.
     */
    template <template <typename ...> class Typeclass,
              typename Left, typename Right>
    using N3351 = typename and_<
        not_<std_is_same<Left, Right>>,
        Typeclass<Left>,
        Typeclass<Right>,
        // has_common_datatype<Left, Right>, // this is trivially true if we have Foreign... is this embarassing?
        Typeclass<typename common_datatype<Left, Right>::type>
    >::type;
}}} // end namespace boost::mpl11::detail

#endif // !BOOST_MPL11_DETAIL_N3351_HPP
