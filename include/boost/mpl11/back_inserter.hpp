/*!
 * @file
 * Defines `boost::mpl11::back_inserter`.
 */

#ifndef BOOST_MPL11_BACK_INSERTER_HPP
#define BOOST_MPL11_BACK_INSERTER_HPP

#include <boost/mpl11/arg.hpp>
#include <boost/mpl11/inserter.hpp>
#include <boost/mpl11/push_back.hpp>


namespace boost { namespace mpl11 {
    /*!
     * Inserter inserting elements at the end of a sequence.
     *
     * Equivalent to `inserter<Sequence, push_back<_1, _2>>`.
     */
    template <typename Sequence>
    struct back_inserter
        : inserter<Sequence, push_back<_1, _2>>
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_BACK_INSERTER_HPP
