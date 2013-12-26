/*!
 * @file
 * Forward declares most tags used in the library.
 */

#ifndef BOOST_MPL11_FWD_TAGS_HPP
#define BOOST_MPL11_FWD_TAGS_HPP

namespace boost { namespace mpl11 {
    /*!
     * @defgroup tags Tags
     *
     * Tags are types used to dispatch methods.
     *
     * Tags come in two flavors (the difference is only conceptual):
     *
     * ### Typeclass tags
     * A typeclass tag is a tag representing a single typeclass. For example,
     * the `forward_sequence_tag` is a typeclass tag because it represents
     * the `ForwardSequence` typeclass. These tags are used as a meeting
     * point between different datatype tags.
     *
     *
     * ### Datatype tags
     * A datatype tag represents a specific datatype. For example,
     * `vector_tag` is a datatype tag because it only represents the
     * `vector` datatype. These tags are only used to make datatypes
     * instances of typeclasses.
     *
     * @{
     */

    //! Tag for types that are foreign to the library.
    struct foreign_tag;

    //! Tag representing the `ForwardSequence` typeclass.
    struct forward_sequence_tag;

    //! Tag representing the `BidirectionalSequence` typeclass.
    struct bidirectional_sequence_tag;

    //! Tag representing the `RandomAccessSequence` typeclass.
    struct random_access_sequence_tag;

    //! Tag representing the `Integral` typeclass.
    struct integral_tag;

    //! @}
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_TAGS_HPP
