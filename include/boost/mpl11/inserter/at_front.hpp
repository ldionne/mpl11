/*!
 * @file
 * Defines `boost::mpl11::inserter::at_front`.
 */

#ifndef BOOST_MPL11_INSERTER_AT_FRONT_HPP
#define BOOST_MPL11_INSERTER_AT_FRONT_HPP

#include <boost/mpl11/functional/quote.hpp>
#include <boost/mpl11/inserter/into.hpp>
#include <boost/mpl11/intrinsic/push_front.hpp>


namespace boost { namespace mpl11 { namespace inserter {
    /*!
     * @ingroup inserters
     */
    template <typename Sequence>
    using at_front = into<Sequence, quote<push_front>>;
}}} // end namespace boost::mpl11::inserter

#endif // !BOOST_MPL11_INSERTER_AT_FRONT_HPP
