/*!
 * @file
 * Defines @ref BOOST_MPL11_ASSERTION.
 */

#ifndef BOOST_MPL11_DETAIL_ASSERTION_HPP
#define BOOST_MPL11_DETAIL_ASSERTION_HPP

#if defined(BOOST_MPL11_DOXYGEN_INVOKED)
    /*!
     * @ingroup details
     *
     * When defined, optional assertions and consistency checks are
     * performed by the library.
     *
     * Since this can have a negative impact on compile-time performance,
     * it is disabled by default. However, it is strongly recommended to
     * enable this when debugging template code.
     */
#   define BOOST_MPL11_ENABLE_ASSERTIONS
#endif

#if defined(BOOST_MPL11_DOXYGEN_INVOKED) || \
    defined(BOOST_MPL11_ENABLE_ASSERTIONS)
    /*!
     * @ingroup details
     *
     * Expands to nothing when BOOST_MPL11_ENABLE_ASSERTIONS is not
     * defined, and to its argument(s) otherwise.
     *
     * The arguments should be a statement like a static assert that one
     * wants enabled only when BOOST_MPL11_ENABLE_ASSERTIONS is defined.
     */
#   define BOOST_MPL11_ASSERTION(...) __VA_ARGS__
#else
#   define BOOST_MPL11_ASSERTION(...) /* nothing */
#endif

#endif // !BOOST_MPL11_DETAIL_ASSERTION_HPP
