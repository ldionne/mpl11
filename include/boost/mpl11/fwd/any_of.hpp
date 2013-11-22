/*!
 * @file
 * Forward declares `boost::mpl11::any_of`.
 */

#ifndef BOOST_MPL11_FWD_ANY_OF_HPP
#define BOOST_MPL11_FWD_ANY_OF_HPP

#include <boost/mpl11/fwd/identity.hpp>
#include <boost/mpl11/fwd/quote.hpp>


namespace boost { namespace mpl11 {
    /*!
     * @ingroup algorithms
     *
     * Returns whether any of the elements of a `Sequence` satisfies
     * a given `Predicate`.
     *
     *
     * ### Semantics and default implementation
     *
     * Equivalent to `not_<none_of<%Sequence, Predicate>>`.
     */
    template <typename Sequence, typename Predicate = quote<identity>>
    struct any_of;

    template <typename Sequence, typename ...Predicate>
    using any_of_t = typename any_of<Sequence, Predicate...>::type;
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_ANY_OF_HPP
