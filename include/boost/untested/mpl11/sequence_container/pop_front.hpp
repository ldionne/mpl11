/*!
 * @file
 * Defines `boost::mpl11::SequenceContainer::pop_front`.
 */

#ifndef BOOST_MPL11_SEQUENCE_CONTAINER_POP_FRONT_HPP
#define BOOST_MPL11_SEQUENCE_CONTAINER_POP_FRONT_HPP

#include <boost/mpl11/detail/not_implemented.hpp>
#include <boost/mpl11/sequence_container/sequence_container.hpp>


namespace boost { namespace mpl11 {
    template <typename SC>
    struct SequenceContainer::pop_front
        : detail::not_implemented<pop_front<SC>>
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_SEQUENCE_CONTAINER_POP_FRONT_HPP
