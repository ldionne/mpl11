/*!
 * @file
 * Forward declares `boost::mpl11::vector` and `boost::mpl11::vector_c`.
 */

#ifndef BOOST_MPL11_FWD_VECTOR_HPP
#define BOOST_MPL11_FWD_VECTOR_HPP

#include <boost/mpl11/detail/doxygen_only.hpp>
#include <boost/mpl11/fwd/integral_c.hpp>


namespace boost { namespace mpl11 {
    /*!
     * @ingroup containers
     *
     * Contiguous sequence of types accessed by index.
     *
     * `mpl11::vector` is a `RandomAccessSequence` and a
     * `RandomExtensibleContainer`.
     *
     *
     * @todo
     * Consider adding a custom implementation of `equal` using variadics.
     */
    template <typename ...Elements>
    struct vector BOOST_MPL11_DOXYGEN_ONLY({ });

    //! @ingroup containers
    //! Alias to `vector<integral_c<T, v>...>`; provided for convenience.
    template <typename T, T ...v>
    using vector_c = vector<integral_c<T, v>...>;
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_VECTOR_HPP
