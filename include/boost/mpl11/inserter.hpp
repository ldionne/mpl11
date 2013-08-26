/*!
 * @file
 * Defines `boost::mpl11::inserter`.
 */

#ifndef BOOST_MPL11_INSERTER_HPP
#define BOOST_MPL11_INSERTER_HPP

namespace boost { namespace mpl11 {
    template <typename Sequence, typename Operation>
    struct inserter {
        using state = Sequence;
        using operation = Operation;
    };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_INSERTER_HPP
