/*!
 * @file
 * Forward declares `boost::mpl11::vector`.
 */

#ifndef BOOST_MPL11_FWD_VECTOR_HPP
#define BOOST_MPL11_FWD_VECTOR_HPP

#include <boost/mpl11/detail/doxygen.hpp>
#include <boost/mpl11/fwd/integral_c.hpp>


namespace boost { namespace mpl11 {
    /*!
     * @ingroup datatypes
     *
     * Contiguous sequence of types accessed by index.
     *
     *
     * @todo
     * Consider making two element `vector`s models of `Couple`.
     *
     * @todo
     * Find out how to minimize the number of instantiations. In the current
     * implementation, the whole vector has to be reindexed each time we
     * modify it.
     */
    template <typename ...T>
    struct vector;

    /*!
     * @ingroup datatypes
     *
     * Alias to `vector<integral_c<T, v>...>`; provided for convenience.
     */
    template <typename T, T ...v>
    BOOST_MPL11_DOXYGEN_ALIAS(vector_c, vector<integral_c<T, v>...>);
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_VECTOR_HPP
