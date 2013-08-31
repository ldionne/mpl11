/*!
 * @file
 * Defines `boost::mpl11::intrinsic::not_`.
 */

#ifndef BOOST_MPL11_INTRINSIC_NOT_HPP
#define BOOST_MPL11_INTRINSIC_NOT_HPP

#include <boost/mpl11/always.hpp>
#include <boost/mpl11/detail/tag_dispatched.hpp>
#include <boost/mpl11/integral_c.hpp>
#include <boost/mpl11/tags.hpp>


namespace boost { namespace mpl11 { namespace intrinsic {
    /*!
     * @ingroup logical_intrinsic
     *
     * Returns the result of _logical not_ (`!`) on the result of
     * its argument.
     *
     *
     * ### Semantics and default implementation
     *
     * Equivalent to `bool_<!F::type::value>`.
     */
    template <typename F>
    struct not_
        : detail::tag_dispatched<tag::not_, F>::template
          with_default<
            lazy_always<
                bool_<!F::type::value>
            >
          >
    { };
}}} // end namespace boost::mpl11::intrinsic

#endif // !BOOST_MPL11_INTRINSIC_NOT_HPP
