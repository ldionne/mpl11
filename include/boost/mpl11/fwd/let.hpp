/*!
 * @file
 * Forward declares `boost::mpl11::let` and `boost::mpl11::local`.
 */

#ifndef BOOST_MPL11_FWD_LET_HPP
#define BOOST_MPL11_FWD_LET_HPP

#include <boost/mpl11/fwd/imap.hpp>
#include <boost/mpl11/fwd/pair.hpp>


namespace boost { namespace mpl11 {
#ifdef BOOST_MPL11_DOXYGEN_INVOKED
    /*!
     * @ingroup concepts
     *
     * `MetafunctionClass` with support for scoped local variables.
     *
     * @todo Document this thoroughly.
     *
     *
     * @note
     * This concept only lives in the documentation. There exists no such
     * `struct` in the library.
     */
    struct LetExpression { };
#endif

    namespace let_detail {
        template <typename Locals, typename Expression>
        struct let_expression;
    }

    /*!
     * @ingroup metafunction_classes
     *
     * Creates a `LetExpression` with user-provided body and local variables.
     *
     * Specifically, `mpl11::let` provides a nested template named `in` that
     * must be instantiated with the expression that will be evaluated when
     * `mpl11::let` is invoked.
     *
     * Explicit local variables must be specified using `mpl11::local`.
     *
     * @todo Document the specialization of `mpl11::apply` for `let<>()`.
     * @todo Implement support for variadic placeholders.
     * @todo Refactor the dirty implementation.
     */
    template <typename ...Locals>
    struct let {
        template <typename Expression>
        using in = let_detail::let_expression<imap<Locals...>, Expression>;
    };

    //! Alias to `mpl11::pair` for use in `mpl11::let`.
    template <typename Binding, typename Expression>
    using local = pair<Binding, Expression>;
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_LET_HPP
