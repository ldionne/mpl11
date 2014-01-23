/*!
 * @file
 * Forward declares the @ref Core module.
 */

#ifndef BOOST_MPL11_FWD_CORE_HPP
#define BOOST_MPL11_FWD_CORE_HPP

#include <boost/mpl11/detail/doxygen.hpp>


namespace boost { namespace mpl11 {
    /*!
     * @defgroup Core Core
     *
     * Module containing miscellaneous core utilities.
     *
     * @{
     */

    //! Wrapper allowing typeclasses to be considered as normal C++ types.
    template <template <typename ...> class>
    struct typeclass BOOST_MPL11_IF_DOXYGEN({ });

    /*!
     * Datatype for data constructors that are foreign to the library.
     *
     * @ingroup datatypes
     */
    struct Foreign;

    /*!
     * Returns the datatype of the given data constructor.
     *
     * By default, this metafunction returns `ctor::mpl_datatype` if that
     * expression is valid, and `Foreign` otherwise. It can also be
     * specialized to customize the datatype of data constructors without
     * requiring the constructor to have a nested `mpl_datatype` type.
     *
     * @note
     * This metafunction must be invoked with an unboxed type. The reason
     * for this special behavior is to allow specialization by users.
     */
    template <typename ctor>
    struct datatype;

    /*!
     * Undefined type.
     *
     * @todo
     * If there's something more to document here, do it. Otherwise,
     * remove this todo.
     */
    struct undefined BOOST_MPL11_IF_DOXYGEN({ });

    //! Boxes its argument.
    template <typename x>
    struct box;

    //! @}
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_CORE_HPP
