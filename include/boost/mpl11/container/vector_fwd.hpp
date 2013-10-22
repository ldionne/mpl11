/*!
 * @file
 * Forward declares `boost::mpl11::container::vector`.
 */

#ifndef BOOST_MPL11_CONTAINER_VECTOR_FWD_HPP
#define BOOST_MPL11_CONTAINER_VECTOR_FWD_HPP

#include <boost/mpl11/detail/doxygen_only.hpp>


namespace boost { namespace mpl11 { namespace container {
    /*!
     * @ingroup containers
     * Contiguous sequence of types accessed by index.
     *
     * `vector` is a  @ref RandomAccessSequence and a
     * @ref RandomExtensibleSequence.
     */
    template <typename ...Elements>
    struct vector BOOST_MPL11_DOXYGEN_ONLY({ });
}}} // end namespace boost::mpl11::container

#endif // !BOOST_MPL11_CONTAINER_VECTOR_FWD_HPP
