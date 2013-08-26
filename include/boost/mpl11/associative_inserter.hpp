/*!
 * @file
 * Defines `boost::mpl11::associative_inserter`.
 */

#ifndef BOOST_MPL11_ASSOCIATIVE_INSERTER_HPP
#define BOOST_MPL11_ASSOCIATIVE_INSERTER_HPP

#include <boost/mpl11/arg.hpp>
#include <boost/mpl11/insert.hpp>
#include <boost/mpl11/inserter.hpp>


namespace boost { namespace mpl11 {
    /*!
     * Inserter inserting elements in an associative sequence.
     *
     * Equivalent to `inserter<AssociativeSequence, insert<_1, _2>>`.
     */
    template <typename AssociativeSequence>
    struct associative_inserter
        : inserter<AssociativeSequence, insert<_1, _2>>
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_ASSOCIATIVE_INSERTER_HPP
