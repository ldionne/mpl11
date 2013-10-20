/*!
 * @file
 * Forward declares `boost::mpl11::parent`.
 */

#ifndef BOOST_MPL11_FWD_PARENT_HPP
#define BOOST_MPL11_FWD_PARENT_HPP

#include <boost/mpl11/dispatch.hpp>


namespace boost { namespace mpl11 {
    namespace tag { struct parent; }

    /*!
     * @ingroup intrinsics
     * Returns the parent or a @ref Category.
     */
    template <typename Category>
    struct parent
        : dispatch<tag::parent, Category>
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_PARENT_HPP
