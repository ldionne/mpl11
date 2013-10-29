/*!
 * @file
 * Forward declares `boost::mpl::bool_` and defines `boost::mpl11::true_` and
 * `boost::mpl11::false_`.
 */

#ifndef BOOST_MPL11_FWD_BOOL_HPP
#define BOOST_MPL11_FWD_BOOL_HPP

#include <boost/mpl11/detail/doxygen_only.hpp>


namespace boost { namespace mpl11 {
    /*!
     * @ingroup datatypes
     *
     * Holder for a compile-time truth value.
     *
     *
     * @note
     * This type can't be used as a base class, nor can its MPL class.
     *
     * @warning
     * This is not a simple alias to `integral_c` as in the original MPL.
     */
    template <bool B>
    struct bool_ BOOST_MPL11_DOXYGEN_ONLY({ });

    //! Alias to `bool_<true>`; provided for convenience.
    using true_ = bool_<true>;

    //! Alias to `bool_<false>`; provided for convenience.
    using false_ = bool_<false>;
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_BOOL_HPP
