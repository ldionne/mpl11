/*!
 * @file
 * This file defines `boost::mpl11::kwargs`.
 */

#ifndef BOOST_MPL11_FUNCTIONAL_KWARGS_HPP
#define BOOST_MPL11_FUNCTIONAL_KWARGS_HPP

namespace boost { namespace mpl11 {
    struct kwargs {
        struct mpl11 { struct is_placeholder; };

        template <typename Args, typename Kwargs>
        struct apply {
            using type = Kwargs;
        };
    };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FUNCTIONAL_KWARGS_HPP
