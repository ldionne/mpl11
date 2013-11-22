/*!
 * @file
 * Forward declares `boost::mpl11::none_of`.
 */

#ifndef BOOST_MPL11_FWD_NONE_OF_HPP
#define BOOST_MPL11_FWD_NONE_OF_HPP

#include <boost/mpl11/fwd/identity.hpp>
#include <boost/mpl11/fwd/quote.hpp>


namespace boost { namespace mpl11 {
    /*!
     * @ingroup algorithms
     *
     * Returns whether no element of a `Sequence` satisfies a
     * given `Predicate`.
     *
     *
     * ### Semantics and default implementation
     *
     * Equivalent to
     *
            equal<
                find_if<Sequence, Predicate>::type,
                end<Sequence>::type
            >
     * .
     */
    template <typename Sequence, typename Predicate = quote<identity>>
    struct none_of;

    template <typename Sequence, typename ...Predicate>
    using none_of_t = typename none_of<Sequence, Predicate...>::type;
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_NONE_OF_HPP
