/*!
 * @file
 * Defines `boost::mpl11::erase`.
 */

#ifndef BOOST_MPL11_ERASE_HPP
#define BOOST_MPL11_ERASE_HPP

#include <boost/mpl11/fwd/erase.hpp>

#include <boost/mpl11/class.hpp>


namespace boost { namespace mpl11 {
    template <typename Sequence, typename Position>
    struct erase<Sequence, Position>
        : class_<Sequence>::type::template erase<Sequence, Position>
    { };

    template <typename Sequence, typename First, typename Last>
    struct erase
        : class_<Sequence>::type::template erase<Sequence, First, Last>
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_ERASE_HPP
