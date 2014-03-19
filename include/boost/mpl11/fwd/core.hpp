/*!
 * @file
 * Forward declares the @ref Core module.
 *
 *
 * @copyright Louis Dionne 2014
 * Distributed under the Boost Software License, Version 1.0.
 *         (See accompanying file LICENSE.md or copy at
 *             http://www.boost.org/LICENSE_1_0.txt)
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

    /*!
     * Holds default methods of typeclasses.
     *
     * This should be specialized for typeclasses wishing to provide a
     * default implementation for some methods. Usage:
     *
        @code
            template <>
            struct SomeTypeclass<MyDatatype>
                : instantiate<SomeTypeclass>::with<MyDatatype>
            {
                // ...
            };
        @endcode
     *
     * Hence, typeclasses should provide their default methods in the nested
     * `with` member template. `instantiate<...>::%with<...>` should always
     * inherit from `true_`; specializations of `instantiate` should conserve
     * that. The primary `instantiate` template provides a member template
     * `with<...>` equivalent to `true_`.
     */
    template <template <typename ...> class Typeclass>
    struct instantiate;

    /*!
     * Datatype for data constructors that are foreign to the library.
     *
     * Any datatype can be converted to `Foreign`; conversion to `Foreign`
     * makes the constructor lose everything except type identity. In other
     * words, two data constructors with different C++ types will map to
     * a different C++ type when converted to `Foreign`.
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

    namespace core_detail { template <typename...> struct undefined_; }

    /*!
     * Represents the _bottom_ value of most functional programming languages.
     *
     * Specifically, this is a an invalid boxed type triggering a compile-time
     * error whenever it is unboxed. Note that instantiating `undefined` in
     * a SFINAE-able context will _still_ trigger an error.
     */
    BOOST_MPL11_DOXYGEN_ALIAS(undefined, core_detail::undefined_<>);

    //! Boxes its argument.
    template <typename x>
    struct box;

    /*!
     * Metafunction class converting an object of the `From` datatype to
     * an object of the `To` datatype.
     *
     * By default, `cast` does not perform anything if `From` and `To` are
     * the same datatypes. However, it must be specialized to customize its
     * behavior further. Note that the arguments to `cast<From, To>` are
     * data constructors, which do not need to be boxed. Hence, `cast`
     * is a call-by-value metafunction class.
     */
    template <typename From, typename To>
    struct cast;

    /*!
     * Metafunction class converting an object to the `To` datatype.
     *
     * Note that `cast_to` is a call-by-value metafunction class.
     */
    template <typename To>
    struct cast_to;

    /*!
     * Convenience namespace containing everything provided by the
     * @ref Core module.
     */
    namespace core {
        using mpl11::instantiate;
        using mpl11::Foreign;
        using mpl11::datatype;
        using mpl11::undefined;
        using mpl11::box;
        using mpl11::cast;
        using mpl11::cast_to;
    }
    //! @}
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_CORE_HPP
