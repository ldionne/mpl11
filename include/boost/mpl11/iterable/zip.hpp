/*!
 * @file
 * Defines `boost::mpl11::zip`.
 */

#ifndef BOOST_MPL11_ITERABLE_ZIP_HPP
#define BOOST_MPL11_ITERABLE_ZIP_HPP

#include <boost/mpl11/fwd/iterable.hpp>

#include <boost/mpl11/and.hpp>
#include <boost/mpl11/detail/std_size_t.hpp>
#include <boost/mpl11/fwd/orderable.hpp>
#include <boost/mpl11/fwd/sequence_traits.hpp>
#include <boost/mpl11/fwd/tag_of.hpp>
#include <boost/mpl11/integral_c.hpp>
#include <boost/mpl11/iterable/iterable.hpp>
#include <boost/mpl11/list.hpp>
#include <boost/mpl11/or.hpp>


namespace boost { namespace mpl11 {
    template <typename S1, typename S2, typename ...Sn>
    struct zip { using type = zip; };

    template <typename ...Sn>
    struct tag_of<zip<Sn...>> { using type = iterable_tag; };

    template <typename ...Sn>
    struct sequence_traits<zip<Sn...>> {
        static constexpr bool has_O1_length = and_<
            bool_<sequence_traits<Sn>::has_O1_length>...
        >::value;

        static constexpr bool has_O1_unpack = false;

        static constexpr bool is_finite = or_<
            bool_<sequence_traits<Sn>::is_finite>...
        >::value;
    };

    template <typename ...Sn>
    struct head_impl<zip<Sn...>> {
        using type = list<typename head<Sn>::type...>;
    };

    template <typename ...Sn>
    struct tail_impl<zip<Sn...>> {
        using type = zip<typename tail<Sn>::type...>;
    };

    template <typename ...Sn>
    struct is_empty_impl<zip<Sn...>>
        : or_<typename is_empty<Sn>::type...>
    { };

    template <typename ...Sn>
    struct length_impl<zip<Sn...>>
        : min<typename length<Sn>::type...>::type
    { };

    //! @todo
    //! Knowing whether `at_c` is fast for the zipped iterables could
    //! allow us to use this implementation only if it's faster than
    //! iterating to the given index.
    template <typename ...Sn, detail::std_size_t Index>
    struct at_c_impl<zip<Sn...>, Index> {
        using type = list<typename at_c<Sn, Index>::type...>;
    };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_ITERABLE_ZIP_HPP
