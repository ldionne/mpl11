/*!
 * @file
 * Forward declares the contents of the `boost::mpl11::optimization` namespace.
 */

#ifndef BOOST_MPL11_FWD_OPTIMIZATION_HPP
#define BOOST_MPL11_FWD_OPTIMIZATION_HPP

#include <boost/mpl11/detail/doxygen_only.hpp>


namespace boost { namespace mpl11 {
    namespace optimization {
        /*!
         * @defgroup optimizations
         *
         * Tags representing various optimizations used in the library.
         *
         *
         * @see `has_optimization`
         */

        /*!
         * @ingroup optimizations
         *
         * Optimization for `Sequence`s whose `mpl11::length` operation
         * returns in O(1).
         */
        struct O1_length BOOST_MPL11_DOXYGEN_ONLY({ });

        /*!
         * @ingroup optimizations
         *
         * Optimization for `Sequence`s that can be `mpl11::unpack`ed in O(1).
         */
        struct O1_unpack BOOST_MPL11_DOXYGEN_ONLY({ });
    }
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_OPTIMIZATION_HPP
