/*!
 * @file
 * Defines `boost::mpl11::all_of`.
 */

#ifndef BOOST_MPL11_ALL_OF_HPP
#define BOOST_MPL11_ALL_OF_HPP

#include <boost/mpl11/fwd/all_of.hpp>

#include <boost/mpl11/apply.hpp>
#include <boost/mpl11/identity.hpp> // for default Predicate
#include <boost/mpl11/none_of.hpp>
#include <boost/mpl11/not.hpp>
#include <boost/mpl11/quote.hpp> // for default Predicate


namespace boost { namespace mpl11 {
    namespace all_of_detail {
        template <typename Predicate>
        struct negation_of {
            template <typename ...Args>
            struct apply
                : not_<mpl11::apply<Predicate, Args...>>
            { };
        };
    } // end namespace all_of_detail

    template <typename Sequence, typename Predicate>
    struct all_of
        : none_of<Sequence, all_of_detail::negation_of<Predicate>>
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_ALL_OF_HPP
