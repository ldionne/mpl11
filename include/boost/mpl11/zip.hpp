/*!
 * @file
 * Defines `boost::mpl11::zip`.
 */

#ifndef BOOST_MPL11_ZIP_HPP
#define BOOST_MPL11_ZIP_HPP

#include <boost/mpl11/fwd/zip.hpp>

#include <boost/mpl11/apply.hpp>
#include <boost/mpl11/forward_iterator.hpp>
#include <boost/mpl11/fwd/begin.hpp>
#include <boost/mpl11/fwd/class_of.hpp>
#include <boost/mpl11/fwd/deref.hpp>
#include <boost/mpl11/fwd/end.hpp>
#include <boost/mpl11/fwd/equal.hpp>
#include <boost/mpl11/fwd/next.hpp>
#include <boost/mpl11/fwd/size.hpp>
#include <boost/mpl11/min.hpp>
#include <boost/mpl11/new.hpp>
#include <boost/mpl11/or.hpp>
#include <boost/mpl11/sequence.hpp>
#include <boost/mpl11/vector.hpp>


namespace boost { namespace mpl11 {
namespace zip_detail {
    template <typename ...Iterators>
    struct zip_iterator;

    struct zip_iterator_class final : ForwardIterator {
        template <typename Iterator>             struct deref_impl;
        template <typename Iterator>             struct next_impl;
        template <typename Self, typename Other> struct equal_impl;

        template <typename ...Iterators>
        struct deref_impl<zip_iterator<Iterators...>> {
            using type = vector<deref_t<Iterators>...>;
        };

        template <typename ...Iterators>
        struct next_impl<zip_iterator<Iterators...>> {
            using type = zip_iterator<next_t<Iterators>...>;
        };

        template <typename ...I1, typename ...I2>
        struct equal_impl<zip_iterator<I1...>, zip_iterator<I2...>>
            : or_c<equal<I1, I2>::value...>
        { };
    };

    struct zip_class final : Sequence {
        template <typename Zip> struct begin_impl;
        template <typename Zip> struct end_impl;
        template <typename Zip> struct size_impl;

        template <typename ...Sn>
        struct begin_impl<zip<Sn...>> {
            using type = zip_iterator<begin_t<Sn>...>;
        };

        template <typename ...Sn>
        struct end_impl<zip<Sn...>> {
            using type = zip_iterator<end_t<Sn>...>;
        };

        template <typename ...Sn>
        struct size_impl<zip<Sn...>>
            : min_t<size_t<Sn>...>
        { };
    };
} // end namespace zip_detail

template <typename ...In, typename Default>
struct class_of<zip_detail::zip_iterator<In...>, Default> {
    using type = zip_detail::zip_iterator_class;
};

template <typename ...Sn, typename Default>
struct class_of<zip<Sn...>, Default> {
    using type = zip_detail::zip_class;
};

template <typename S1, typename S2, typename ...Sn>
struct zip
    : apply<new_<S1>, zip<S1, S2, Sn...>>
{ };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_ZIP_HPP
