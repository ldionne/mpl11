/*!
 * @file
 * Forward declares `boost::mpl11::cons`.
 */

#ifndef BOOST_MPL11_FWD_CONS_HPP
#define BOOST_MPL11_FWD_CONS_HPP

namespace boost { namespace mpl11 {
    /*!
     * @ingroup metafunctions
     *
     * Prepends an element to a `Sequence`.
     */
    template <typename Head, typename Tail>
    struct cons;

    template <typename Head, typename Tail>
    using cons_t = typename cons<Head, Tail>::type;
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_CONS_HPP
