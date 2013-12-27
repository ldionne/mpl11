/*!
 * @file
 * Forward declares `boost::mpl11::always`.
 */

#ifndef BOOST_MPL11_FWD_ALWAYS_HPP
#define BOOST_MPL11_FWD_ALWAYS_HPP

namespace boost { namespace mpl11 {
    /*!
     * @ingroup metafunction_classes
     *
     * `MetafunctionClass` always returning `T`, regardless of the
     * number and types of passed arguments.
     */
    template <typename T>
    struct always;
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_ALWAYS_HPP
