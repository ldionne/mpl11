/*!
 * @file
 * Forward declares `boost::mpl11::list`.
 */

#ifndef BOOST_MPL11_FWD_LIST_HPP
#define BOOST_MPL11_FWD_LIST_HPP

namespace boost { namespace mpl11 {
    /*!
     * @ingroup datatypes
     *
     * Canonical Iterable containing types.
     *
     *
     * @todo
     * Find out how to minimize the number of instantiations. In the current
     * implementation, the whole list has to be reindexed each time we modify
     * it.
     */
    template <typename ...>
    struct list;
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_LIST_HPP
