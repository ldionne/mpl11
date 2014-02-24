/*!
 * @file
 * Forward declares the `boost::mpl11::List` datatype.
 */

#ifndef BOOST_MPL11_FWD_LIST_HPP
#define BOOST_MPL11_FWD_LIST_HPP

#include <boost/mpl11/detail/doxygen.hpp>


namespace boost { namespace mpl11 {
    /*!
     * @ingroup datatypes
     * @defgroup List List
     *
     * A sequence of types.
     *
     *
     * ### Instance of
     * `Iterable`
     *
     * @todo
     * - Find out how to minimize the number of instantiations. In the
     * current implementation, the whole list has to be re-indexed
     * each time we modify it.
     *
     * @{
     */
    struct List BOOST_MPL11_IF_DOXYGEN({ });

    //! A `List` containing the given elements.
    template <typename ...xs>
    struct list;

    //! A `List` created by prepending an element to an @ref Iterable.
    template <typename x, typename xs>
    struct cons;
    //! @}
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_LIST_HPP
