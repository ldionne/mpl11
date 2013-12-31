/*!
 * @file
 * Forward declares `boost::mpl11::into`.
 */

#ifndef BOOST_MPL11_FWD_INTO_HPP
#define BOOST_MPL11_FWD_INTO_HPP

namespace boost { namespace mpl11 {
    /*!
     * @ingroup metafunction_classes
     *
     * Returns a specialization of the given `Template` with the
     * provided arguments.
     *
     * Specifically, `apply<into<Template>, Args...>::%type` is identical
     * to `Template<Args...>`.
     */
    template <template <typename ...> class Template>
    struct into;
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_INTO_HPP
