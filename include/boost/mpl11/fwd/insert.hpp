/*!
 * @file
 * Forward declares `boost::mpl11::insert`.
 */

#ifndef BOOST_MPL11_FWD_INSERT_HPP
#define BOOST_MPL11_FWD_INSERT_HPP

#include <boost/mpl11/detail/doxygen_only.hpp>
#include <boost/mpl11/detail/optional.hpp>


namespace boost { namespace mpl11 {
    /*!
     * @ingroup intrinsics
     *
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
                single_view<Element>
            >
        @endcode
     */
    template <typename Sequence, typename Position, typename Element>
    struct insert BOOST_MPL11_DOXYGEN_ONLY(<Sequence, Position, Element>);

    /*!
     * @ingroup intrinsics
     *
     * Inserts an element in an @ref AssociativeSequence.
     *
     *
     * ### Semantics and default implementation
     *
     * Let `Filtered` be the same as
     * `erase_key<Sequence, key_of<Sequence, Element>::type>::type`.
     *
     * Then, `insert` is equivalent to
        @code
            identity<
                indexed_view<
                    joined_view<
                        Filtered,
                        indexed_view<
                            single_view<Element>,
                            lambda<key_of<Filtered, _1>>::type,
                            lambda<value_of<Filtered, _1>>::type
                        >
                    >,
                    lambda<key_of<Filtered, _1>>::type,
                    lambda<value_of<Filtered, _1>>::type
                >
            >
        @endcode
     */
    template <typename Sequence, typename Element>
    struct insert<Sequence, Element>;
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_INSERT_HPP
