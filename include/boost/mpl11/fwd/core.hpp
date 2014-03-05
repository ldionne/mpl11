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
     * Any datatype can be converted to `Foreign`; conversion to `Foreign` is
     * just the identity transformation.
     *
     * Also, `Foreign` types can be compared; equality and inequality for
     * `Foreign` types is defined in terms of `std::is_same`.
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
     *
     * @todo
     * Consider allowing multiple arguments here; this would replace
     * `common_datatype`.
     */
    template <typename ctor>
    struct datatype;

    /*!
     * Undefined type.
     *
     * @todo
     * - If there's something more to document here, do it. Otherwise,
     * remove this todo.
     * - Consider making `undefined` an alias to something that asserts when
     * instantiated.
     */
    struct undefined BOOST_MPL11_IF_DOXYGEN({ });

    //! Boxes its argument.
    template <typename x>
    struct box;

    /*!
     * Returns a datatype to which instances of both `Left` and `Right` may
     * be converted.
     */
    template <typename Left, typename Right>
    struct common_datatype;

    /*!
     * Metafunction class converting an object of the `From` datatype to
     * an object of the `To` datatype.
     *
     * By default, this metafunction class is equivalent to `To::from<From>`.
     * However, if `From` and `To` are the same datatypes, `cast` does not
     * perform anything.
     *
     * `cast` may be specialized to customize its behavior.
     */
    template <typename From, typename To>
    struct cast;
    //! @}
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_CORE_HPP
