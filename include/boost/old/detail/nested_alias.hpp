/*!
 * @file
 * Defines `BOOST_MPL11_NESTED_ALIAS`.
 */

#ifndef BOOST_MPL11_DETAIL_NESTED_ALIAS_HPP
#define BOOST_MPL11_DETAIL_NESTED_ALIAS_HPP

#if defined(__clang__) || defined(__GNUC__) || \
    defined(BOOST_MPL11_DOXYGEN_INVOKED)
    /*!
     * @ingroup details
     *
     * Workaround for a bug in Clang and GCC.
     *
     *
     * @todo
     * Remove this as soon as it's fixed.
     */
#   define BOOST_MPL11_NESTED_ALIAS(name, ...)  \
        struct name : __VA_ARGS__ { }           \
    /**/
#else
#   define BOOST_MPL11_NESTED_ALIAS(name, ...)  \
        using name = __VA_ARGS__                \
    /**/
#endif

#endif // !BOOST_MPL11_DETAIL_NESTED_ALIAS_HPP
