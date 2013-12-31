/*!
 * @file
 * Defines `boost::mpl11::zip`.
 */

#ifndef BOOST_MPL11_ZIP_HPP
#define BOOST_MPL11_ZIP_HPP

#include <boost/mpl11/fwd/zip.hpp>

#include <boost/mpl11/detail/default_unpack.hpp>
#include <boost/mpl11/fwd/at.hpp>
#include <boost/mpl11/fwd/head.hpp>
#include <boost/mpl11/fwd/init.hpp>
#include <boost/mpl11/fwd/is_empty.hpp>
#include <boost/mpl11/fwd/last.hpp>
#include <boost/mpl11/fwd/length.hpp>
#include <boost/mpl11/fwd/slice.hpp>
#include <boost/mpl11/fwd/tail.hpp>
#include <boost/mpl11/fwd/unpack.hpp>
#include <boost/mpl11/min.hpp>
#include <boost/mpl11/or.hpp>
#include <boost/mpl11/vector.hpp>


namespace boost { namespace mpl11 {
    /////////////////////////////////
    // ForwardSequence
    /////////////////////////////////
    template <typename ...Sn>
    struct head<zip<Sn...>> {
        using type = vector<typename head<Sn>::type...>;
    };

    template <typename ...Sn>
    struct tail<zip<Sn...>> {
        using type = zip<typename tail<Sn>::type...>;
    };

    template <typename ...Sn>
    struct is_empty<zip<Sn...>>
        : or_<typename is_empty<Sn>::type...>
    { };


    /////////////////////////////////
    // FiniteSequence
    /////////////////////////////////
    template <typename ...Sn>
    struct length<zip<Sn...>>
        : min<typename length<Sn>::type...>::type
    { };

    template <typename ...Sn, typename F>
    struct unpack<zip<Sn...>, F>
        : detail::default_unpack<zip<Sn...>, F>
    { };


#if 0
    /////////////////////////////////
    // BidirectionalSequence
    /////////////////////////////////
    template <typename ...Sn>
    struct last<zip<Sn...>> {

    };

    template <typename ...Sn>
    struct init<zip<Sn...>> {
        using type = zip<typename init<Sn>::type...>;
    };
#endif


    /////////////////////////////////
    // RandomAccessSequence
    /////////////////////////////////
    template <typename ...Sn, typename Index>
    struct at<zip<Sn...>, Index> {
        using type = vector<typename at<Sn, Index>::type...>;
    };

    template <typename ...Sn, typename Start, typename Stop>
    struct slice<zip<Sn...>, Start, Stop> {
        using type = zip<typename slice<Sn, Start, Stop>::type...>;
    };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_ZIP_HPP
