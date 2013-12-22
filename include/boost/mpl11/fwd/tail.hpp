
#ifndef BOOST_MPL11_FWD_TAIL_HPP
#define BOOST_MPL11_FWD_TAIL_HPP

namespace boost { namespace mpl11 {
    template <typename S>
    struct tail;

    template <typename S>
    using tail_t = typename tail<S>::type;
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_TAIL_HPP
