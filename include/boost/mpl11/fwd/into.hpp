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
     * `MetafunctionClass` returning a specialization of `Template` with
     * the provided arguments.
     *
     * Specifically, `mpl11::apply<mpl11::into<Template>, Args...>::type`
     * is identical to `Template<Args...>`.
     *
     *
     * @see `mpl11::quote`
     */
    template <template <typename ...> class Template>
    struct into;
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_INTO_HPP
