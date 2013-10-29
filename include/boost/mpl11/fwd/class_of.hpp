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
     * The default implementation uses `T::mpl_class`. Users may specialize
     * `class_of` to change its default behavior.
     */
    template <typename T>
    struct class_of;
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_CLASS_OF_HPP
