
#ifndef BOOST_MPL11_TAIL_HPP
#define BOOST_MPL11_TAIL_HPP

#include <boost/mpl11/fwd/tail.hpp>

#include <boost/mpl11/begin.hpp>
#include <boost/mpl11/end.hpp>
#include <boost/mpl11/into.hpp>
#include <boost/mpl11/iterator_range.hpp>
#include <boost/mpl11/next.hpp>
#include <boost/mpl11/unpack.hpp>
#include <boost/mpl11/vector.hpp>


namespace boost { namespace mpl11 {
    template <typename S>
    struct tail
        : unpack<iterator_range<next_t<begin_t<S>>, end_t<S>>, into<vector>>
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_TAIL_HPP
