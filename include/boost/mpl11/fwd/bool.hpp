/*!
 * @file
 * Forward declares the @ref Bool datatype.
 */

#ifndef BOOST_MPL11_FWD_BOOL_HPP
#define BOOST_MPL11_FWD_BOOL_HPP

#include <boost/mpl11/detail/doxygen.hpp>


namespace boost { namespace mpl11 {
    /*!
     * @ingroup datatypes
     * @defgroup Bool Bool
     *
     * @ref StaticConstant holding a boolean value.
     *
     *
     * ### Instance of
     * `Comparable`, `Orderable` and `Enumerable`.
     *
     * @{
     */
    struct Bool;

    //! `Bool` holding the specified value.
    template <bool b>
    struct bool_;

    //! Alias to `bool_<true>`; provided for convenience.
    BOOST_MPL11_DOXYGEN_ALIAS(true_, bool_<true>);

    //! Alias to `bool_<false>`; provided for convenience.
    BOOST_MPL11_DOXYGEN_ALIAS(false_, bool_<false>);
    //! @}
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_BOOL_HPP
