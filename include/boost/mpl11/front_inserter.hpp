/*!
 * @file
 * Defines `boost::mpl11::front_inserter`.
 */

#ifndef BOOST_MPL11_FRONT_INSERTER_HPP
#define BOOST_MPL11_FRONT_INSERTER_HPP

#include <boost/mpl11/arg.hpp>
#include <boost/mpl11/inserter.hpp>
#include <boost/mpl11/push_front.hpp>


namespace boost { namespace mpl11 {
    /*!
     * Inserter inserting elements at the beginning of a sequence.
     *
     * Equivalent to `inserter<Sequence, push_front<_1, _2>>`.
     */
    template <typename Sequence>
    struct front_inserter
        : inserter<Sequence, push_front<_1, _2>>
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FRONT_INSERTER_HPP
