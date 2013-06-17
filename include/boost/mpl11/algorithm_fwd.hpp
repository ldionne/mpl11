/*!
 * @file
 * This header contains the forward declaration of all the algorithms.
 */

#ifndef BOOST_MPL11_ALGORITHM_FWD_HPP
#define BOOST_MPL11_ALGORITHM_FWD_HPP

namespace boost { namespace mpl11 { inline namespace v2 {
    namespace algorithm {
        struct advance;
        struct distance;
        struct fold;
        struct transform;
    }

    template <typename, typename ...> struct advance;
    template <typename, typename, typename ...> struct distance;
    template <typename, typename ...> struct fold;
    template <typename, typename ...> struct transform;
}}}

#endif // !BOOST_MPL11_ALGORITHM_FWD_HPP
