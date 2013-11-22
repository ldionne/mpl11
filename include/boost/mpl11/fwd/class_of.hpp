/*!
 * @file
 * Forward declares `boost::mpl11::class_of`.
 */

#ifndef BOOST_MPL11_FWD_CLASS_OF_HPP
#define BOOST_MPL11_FWD_CLASS_OF_HPP

namespace boost { namespace mpl11 {
    /*!
     * @ingroup metafunctions
     *
     * Returns the MPL class of a type.
     *
     * The default implementation returns `T::mpl_class` if it is a valid
     * expression and `Type` otherwise.
     */
    template <typename T>
    struct class_of;

    template <typename T>
    using class_of_t = typename class_of<T>::type;
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_CLASS_OF_HPP
