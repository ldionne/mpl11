/*!
 * @file
 * This header contains the forward declaration of the functional components.
 */

#ifndef BOOST_MPL11_FUNCTIONAL_FWD_HPP
#define BOOST_MPL11_FUNCTIONAL_FWD_HPP

namespace boost { namespace mpl11 {
    template <typename> struct always;
    template <typename, typename ...> struct apply;
    template <typename, typename ...> struct apply_raw;
    template <typename ...> struct bind;
    template <typename> struct lambda;
    template <typename, typename> struct named_argument;
    template <typename> struct kwarg;
    template <int> struct arg;
    template <int, int> struct args;
    template <typename> struct protect;
    template <template <typename ...> class> struct quote;
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FUNCTIONAL_FWD_HPP
