/*!
 * @file
 * Forward declares `boost::mpl11::tag_of`.
 */

#ifndef BOOST_MPL11_FWD_TAG_OF_HPP
#define BOOST_MPL11_FWD_TAG_OF_HPP

namespace boost { namespace mpl11 {
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
