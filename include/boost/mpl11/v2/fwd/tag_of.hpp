/*!
 * @file
 * Forward declares `boost::mpl11::tag_of`.
 */

#ifndef BOOST_MPL11_FWD_TAG_OF_HPP
#define BOOST_MPL11_FWD_TAG_OF_HPP

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
     */

    /*!
     * @ingroup tags
     *
     * Tag for types that are foreign to the library.
     */
    struct foreign_tag;

    /*!
     * @ingroup metafunctions
     *
     * Returns the tag of the given type.
     *
     * By default, `tag_of` returns `T::mpl_tag` if that expression is valid,
     * and `foreign_tag` otherwise.
     */
    template <typename T>
    struct tag_of;

    template <typename T>
    using tag_of_t = typename tag_of<T>::type;
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_TAG_OF_HPP
