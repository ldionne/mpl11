/*!
 * @file
 * Defines `boost::mpl11::pair`.
 */

#ifndef BOOST_MPL11_PAIR_HPP
#define BOOST_MPL11_PAIR_HPP

#include <boost/mpl11/fwd/pair.hpp>

#include <boost/mpl11/couple.hpp>
#include <boost/mpl11/fwd/class_of.hpp>
#include <boost/mpl11/identity.hpp>


namespace boost { namespace mpl11 {
    template <typename First, typename Second>
    struct class_of<pair<First, Second>> {
        struct type final : Couple {
            template <typename>
            using first_impl = identity<First>;

            template <typename>
            using second_impl = identity<Second>;
        };
    };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_PAIR_HPP
