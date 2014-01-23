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
     * Returns the `N`th of its arguments.
     *
     * Indexing starts at 1, so that `arg<1>` returns the 1st argument,
     * `arg<2>` the 2nd and so on. Using `arg<0>` is an error.
     *
     *
     * @todo
     * Implement this in O(1).
     */
    template <detail::std_size_t N>
    struct arg;
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_ARG_HPP
