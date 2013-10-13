/*!
 * @file
 * Forward declares `boost::mpl11::insert`.
 */

#ifndef BOOST_MPL11_ALGORITHM_INSERT_FWD_HPP
#define BOOST_MPL11_ALGORITHM_INSERT_FWD_HPP

#include <boost/mpl11/detail/doxygen_only.hpp>
#include <boost/mpl11/detail/optional.hpp>
#include <boost/mpl11/dispatch.hpp>


namespace boost { namespace mpl11 {
    namespace tag { struct insert; }

    /*!
     * @ingroup algorithms
     * Overloaded algorithm for inserting elements in a sequence.
     */
    template <typename, typename, typename = detail::optional>
    struct insert;

    /*!
     * @ingroup algorithms
     * Inserts an element at an arbitrary position in a @ref ForwardSequence.
     *
     *
     * ### Semantics and default implementation
     *
     * Equivalent to
       @code
            insert_range<
                Sequence,
                Position,
                view::single_element<Element>
            >
       @endcode
     */
    template <typename Sequence, typename Position, typename Element>
    struct insert BOOST_MPL11_DOXYGEN_ONLY(<Sequence, Position, Element>)
        : dispatch<tag::insert, Sequence, Position, Element>
    { };

    /*!
     * @ingroup algorithms
     * Inserts an element in an @ref AssociativeSequence.
     *
     *
     * ### Semantics and default implementation
     *
     * Equivalent to
     * @code
     *     insert_range<
     *         Sequence,
     *         view::single_element<Element>
     *     >
     * @endcode
     */
    template <typename Sequence, typename Element>
    struct insert<Sequence, Element>
        : dispatch<tag::insert, Sequence, Element>
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_ALGORITHM_INSERT_FWD_HPP
