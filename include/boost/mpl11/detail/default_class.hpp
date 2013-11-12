/*!
 * @file
 * Defines `boost::mpl11::detail::default_class`.
 */

#ifndef BOOST_MPL11_DETAIL_DEFAULT_CLASS_HPP
#define BOOST_MPL11_DETAIL_DEFAULT_CLASS_HPP

namespace boost { namespace mpl11 { namespace detail {
    /*!
     * @ingroup details
     *
     * Default class returned by `class_of` and providing some
     * basic operations.
     */
    struct default_class {
        template <typename U, typename V>
        struct equal_impl;

        template <typename U, typename V>
        struct not_equal_impl;
    };
}}} // end namespace boost::mpl11::detail

#endif // !BOOST_MPL11_DETAIL_DEFAULT_CLASS_HPP
