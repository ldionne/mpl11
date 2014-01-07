/*!
 * @file
 * Defines `boost::mpl11::drop_while`.
 */

#ifndef BOOST_MPL11_SEQUENCE_DROP_WHILE_HPP
#define BOOST_MPL11_SEQUENCE_DROP_WHILE_HPP

#include <boost/mpl11/fwd/sequence.hpp>

#include <boost/mpl11/apply.hpp>
#include <boost/mpl11/id.hpp>
#include <boost/mpl11/if.hpp>


namespace boost { namespace mpl11 {
    namespace drop_while_detail {
        template <typename Pred, typename Seq, bool = is_empty<Seq>::value>
        struct consume {
            using type = Seq;
        };

        template <typename Pred, typename Seq>
        struct consume<Pred, Seq, false>
            : if_c<
                apply<Pred, typename head<Seq>::type>::type::value,
                consume<Pred, typename tail<Seq>::type>,
                id<Seq>
            >::type
        { };
    } // end namespace drop_while_detail

    template <typename Pred, typename Seq>
    struct drop_while {
        using type = typename drop_while_detail::consume<Pred, Seq>::type;
    };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_SEQUENCE_DROP_WHILE_HPP
