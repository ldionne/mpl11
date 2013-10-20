/*!
 * @file
 * Forward declares `boost::mpl11::class_`.
 */

#ifndef BOOST_MPL11_FWD_CLASS_HPP
#define BOOST_MPL11_FWD_CLASS_HPP

namespace boost { namespace mpl11 {
    /*!
     * @ingroup Object
     *
     * Returns the class of an `Object`.
     *
     * The default implementation fetches the nested `mpl_class` type.
     */
    template <typename Object>
    struct class_;
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_CLASS_HPP
