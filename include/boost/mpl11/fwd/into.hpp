/*!
 * @file
 * Forward declares `boost::mpl11::into`.
 */

#ifndef BOOST_MPL11_FWD_INTO_HPP
#define BOOST_MPL11_FWD_INTO_HPP

namespace boost { namespace mpl11 {
    /*!
     * @ingroup metafunctions
     *
     * @ref MetafunctionClass returning a specialization of `Template` with
     * the provided arguments.
     *
     *
     * @todo
     * Document use cases and precise semantics.
     */
    template <template <typename ...> class Template>
    struct into;
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_INTO_HPP
