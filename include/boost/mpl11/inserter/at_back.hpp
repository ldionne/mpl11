/*!
 * @file
 * Defines `boost::mpl11::inserter::at_back`.
 */

#ifndef BOOST_MPL11_INSERTER_AT_BACK_HPP
#define BOOST_MPL11_INSERTER_AT_BACK_HPP

#include <boost/mpl11/functional/quote.hpp>
#include <boost/mpl11/inserter/into.hpp>
#include <boost/mpl11/intrinsic/push_back.hpp>


namespace boost { namespace mpl11 { namespace inserter {
    /*!
     * @ingroup inserters
     */
    template <typename Sequence>
    using at_back = into<Sequence, quote<push_back>>;
}}} // end namespace boost::mpl11::inserter

#endif // !BOOST_MPL11_INSERTER_AT_BACK_HPP
