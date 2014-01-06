/*!
 * @file
 * Forward declares `boost::mpl11::any`.
 */

#ifndef BOOST_MPL11_FWD_ANY_HPP
#define BOOST_MPL11_FWD_ANY_HPP

#include <boost/mpl11/fwd/none.hpp>
#include <boost/mpl11/fwd/not.hpp>


namespace boost { namespace mpl11 {
    /*!
     * @ingroup metafunctions
     *
     * Boolean `StaticConstant` representing whether any element of a
     * `Sequence` satisfies the given `Predicate`.
     */
    template <typename Predicate, typename Sequence>
    using any = not_<none<Predicate, Sequence>>;

    template <typename Predicate, typename Sequence>
    using any_t = typename any<Predicate, Sequence>::type;
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_ANY_HPP
