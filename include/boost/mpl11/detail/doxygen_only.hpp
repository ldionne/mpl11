/*!
 * @file
 * Defines @ref BOOST_MPL11_DOXYGEN_ONLY.
 */

#ifndef BOOST_MPL11_DETAIL_DOXYGEN_ONLY_HPP
#define BOOST_MPL11_DETAIL_DOXYGEN_ONLY_HPP

#ifdef BOOST_MPL11_DOXYGEN_INVOKED
    /*!
     * @ingroup details
     *
     * Macro expanding to its argument(s) when generating the
     * documentation with Doxygen and to nothing otherwise.
     */
#   define BOOST_MPL11_DOXYGEN_ONLY(...) __VA_ARGS__
#else
#   define BOOST_MPL11_DOXYGEN_ONLY(...) /* nothing */
#endif

#endif // !BOOST_MPL11_DETAIL_DOXYGEN_ONLY_HPP
