
#ifndef BOOST_MPL11_FWD_HEAD_HPP
#define BOOST_MPL11_FWD_HEAD_HPP

namespace boost { namespace mpl11 {
    template <typename S>
    struct head;

    template <typename S>
    using head_t = typename head<S>::type;
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_HEAD_HPP
