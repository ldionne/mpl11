/*!
 * @file
 * Manages configurable options of the library.
 */

#ifndef BOOST_MPL11_DETAIL_CONFIG_HPP
#define BOOST_MPL11_DETAIL_CONFIG_HPP

namespace boost { namespace mpl11 { namespace detail {
#if defined(BOOST_MPL11_DOXYGEN_INVOKED)
    /*!
     * @ingroup details
     *
     * When defined, optional assertions and consistency checks are
     * __not__ performed by the library.
     *
     * Assertions can have a negative impact on compile-time performance;
     * they can be disabled if that is a problem. However, it is strongly
     * recommended to enable them when debugging template code.
     */
#   define BOOST_MPL11_NO_ASSERTIONS

    /*!
     * @ingroup details
     *
     * When defined, rewrite rules are disabled.
     *
     * Disabling rewrite rules can have a negative impact on compile-time
     * performance; this is mainly meant as a way to make sure rewrite rules
     * do not change the semantics of metaprograms.
     */
#   define BOOST_MPL11_NO_RULES
#endif

    /*!
     * @ingroup details
     *
     * Clang-3.5 has a bug causing `flip` to fail on binary metafunctions.
     */
#   define BOOST_MPL11_CLANG_FLIP_BUG

    /*!
     * @ingroup details
     *
     * GCC-4.9 has a bug making it an error to expand parameter packs in some
     * circumstances.
     */
#   define BOOST_MPL11_GCC_PACK_EXPANSION_BUG
}}} // end namespace boost::mpl11::detail

#endif // !BOOST_MPL11_DETAIL_CONFIG_HPP
