/*!
 * @file
 * This file defines `boost::mpl11::kwarg`.
 */

#ifndef BOOST_MPL11_FUNCTIONAL_KWARG_HPP
#define BOOST_MPL11_FUNCTIONAL_KWARG_HPP

#include <boost/mpl11/at.hpp>
#include <boost/mpl11/view/single_view.hpp>


namespace boost { namespace mpl11 {
    template <typename Name>
    struct kwarg {
        struct mpl11 { struct is_placeholder; };

        template <typename Args, typename Kwargs>
        struct apply {
            using type = single_view<typename at<Kwargs, Name>::type>;
        };
    };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FUNCTIONAL_KWARG_HPP
