/*!
 * @file
 * Forward declares `boost::mpl11::class_of`.
 */

#ifndef BOOST_MPL11_FWD_CLASS_OF_HPP
#define BOOST_MPL11_FWD_CLASS_OF_HPP

#include <boost/mpl11/detail/optional.hpp>


namespace boost { namespace mpl11 {
    /*!
     * @ingroup metafunctions
     *
     * Returns the MPL class of a type.
     *
     * The default implementation has the following behavior:
     * - If a `Default` is provided, returns `T::mpl_class` if that expression
     *   is valid and `Default` otherwise.
     *
     * - If no `Default` is provided, returns `T::mpl_class` if that
     *   expression is valid and triggers a compile-time failure otherwise.
     *
     *
     * @warning
     * While this metafunction may be specialized to customize the class of
     * a type, it is very important that one specializes it for all values
     * of `Default`. For example:
       @code
            template <>
            struct class_of<my_type> { ... };
       @endcode
     * is bad, while
       @code
            template <typename Default>
            struct class_of<my_type, Default> { ... };
       @endcode
     * is good.
     */
    template <typename T, typename Default = detail::optional>
    struct class_of;

    template <typename T, typename ...Default>
    using class_of_t = typename class_of<T, Default...>::type;
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_CLASS_OF_HPP
