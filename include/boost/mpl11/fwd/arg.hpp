/*!
 * @file
 * Forward declares `boost::mpl11::arg`.
 */

#ifndef BOOST_MPL11_FWD_ARG_HPP
#define BOOST_MPL11_FWD_ARG_HPP

#include <boost/mpl11/detail/std_size_t.hpp>


namespace boost { namespace mpl11 {
    /*!
     * @ingroup metafunction_classes
     *
     * `MetafunctionClass` returning the `N`th of its arguments.
     */
    template <detail::std_size_t N>
    struct arg;
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_ARG_HPP
