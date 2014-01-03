/*!
 * @file
 * Forward declares `boost::mpl11::take_while`.
 */

#ifndef BOOST_MPL11_FWD_TAKE_WHILE_HPP
#define BOOST_MPL11_FWD_TAKE_WHILE_HPP

namespace boost { namespace mpl11 {
    /*!
     * @ingroup metafunctions
     *
     * Returns the longest prefix of a sequence in which all elements satisfy
     * the given `Predicate`.
     */
    template <typename Predicate, typename Sequence>
    struct take_while;

    template <typename Predicate, typename Sequence>
    using take_while_t = take_while<Predicate, Sequence>;
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_TAKE_WHILE_HPP
