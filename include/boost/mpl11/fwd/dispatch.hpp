/*!
 * @file
 * Forward declares `boost::mpl11::dispatch` and `tag::default_`.
 */

#ifndef BOOST_MPL11_FWD_DISPATCH_HPP
#define BOOST_MPL11_FWD_DISPATCH_HPP

namespace boost { namespace mpl11 {
    namespace tag { template <typename Operation> struct default_; }

    template <typename Operation, typename ...Args>
    struct dispatch;
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_DISPATCH_HPP
