/*!
 * @file
 * Forward declares `boost::mpl11::empty_sequence`.
 */

#ifndef BOOST_MPL11_FWD_EMPTY_SEQUENCE_HPP
#define BOOST_MPL11_FWD_EMPTY_SEQUENCE_HPP

#include <boost/mpl11/detail/doxygen.hpp>


namespace boost { namespace mpl11 {
    /*!
     * @ingroup datatypes
     *
     * Iterable containing no elements at all.
     *
     *
     * @note
     * Using any method that requires the iterable to be non-empty will
     * result in an error.
     */
    struct empty_sequence BOOST_MPL11_IF_DOXYGEN({ });
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_EMPTY_SEQUENCE_HPP
