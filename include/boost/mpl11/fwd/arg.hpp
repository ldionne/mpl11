/*!
 * @file
 * Forward declares `boost::mpl11::arg`.
 */

#ifndef BOOST_MPL11_FWD_ARG_HPP
#define BOOST_MPL11_FWD_ARG_HPP

namespace boost { namespace mpl11 {
    /*!
     * @ingroup metafunction_classes
     *
     * `MetafunctionClass` returning the `N`th of its arguments.
     */
    template <unsigned long long N>
    struct arg;
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_ARG_HPP
