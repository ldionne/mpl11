/*!
 * @file
 * Defines `boost::mpl11::Sequence`.
 */

#ifndef BOOST_MPL11_SEQUENCE_HPP
#define BOOST_MPL11_SEQUENCE_HPP

#include <boost/mpl11/fwd/sequence.hpp>

#include <boost/mpl11/begin.hpp>
#include <boost/mpl11/distance.hpp>
#include <boost/mpl11/end.hpp>
#include <boost/mpl11/equal.hpp>


namespace boost { namespace mpl11 {
    struct Sequence {
        //! This operation must be provided by the user.
        template <typename Seq>
        struct begin_impl;

        //! This operation must be provided by the user.
        template <typename Seq>
        struct end_impl;

        //! Returns the distance between both ends of the sequence.
        template <typename Seq>
        struct size_impl
            : distance<
                typename begin<Seq>::type,
                typename end<Seq>::type
            >
        { };

        //! Returns whether `begin<Seq>::type` is equal to `end<Seq>::type`.
        template <typename Seq>
        struct is_empty_impl
            : equal<
                typename begin<Seq>::type,
                typename end<Seq>::type
            >
        { };
    };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_SEQUENCE_HPP
