/*!
 * @file
 * Forward declares `boost::mpl11::pair`.
 */

#ifndef BOOST_MPL11_FWD_PAIR_HPP
#define BOOST_MPL11_FWD_PAIR_HPP

#include <boost/mpl11/detail/doxygen_only.hpp>


namespace boost { namespace mpl11 {
    /*!
     * @ingroup datatypes
     *
     * Minimal implementation of the `Couple` concept.
     *
     *
     * @note
     * This type can't be used as a base class, nor can its MPL class.
     *
     * @todo
     * Consider making pairs compatible with `Iterable`s.
     */
    template <typename First, typename Second>
    struct pair BOOST_MPL11_DOXYGEN_ONLY({ });
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_PAIR_HPP
