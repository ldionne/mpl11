/*!
 * @file
 * Defines `boost::mpl11::SequenceContainer::pop_back`.
 */

#ifndef BOOST_MPL11_SEQUENCE_CONTAINER_POP_BACK_HPP
#define BOOST_MPL11_SEQUENCE_CONTAINER_POP_BACK_HPP

#include <boost/mpl11/detail/not_implemented.hpp>
#include <boost/mpl11/sequence_container/sequence_container.hpp>


namespace boost { namespace mpl11 {
    template <typename SC>
    struct SequenceContainer::pop_back
        : detail::not_implemented<pop_back<SC>>
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_SEQUENCE_CONTAINER_POP_BACK_HPP
