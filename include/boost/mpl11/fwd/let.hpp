/*!
 * @file
 * Forward declares `boost::mpl11::let` and defines `boost::mpl11::binding`.
 */

#ifndef BOOST_MPL11_FWD_LET_HPP
#define BOOST_MPL11_FWD_LET_HPP

#include <boost/mpl11/fwd/imap.hpp>
#include <boost/mpl11/fwd/pair.hpp>


namespace boost { namespace mpl11 {
    namespace let_detail {
        template <typename Bindings, typename Body>
        struct let_expr;
    }

    /*!
     * @ingroup metafunction_classes
     *
     * Creates a `MetafunctionClass` with a user-provided body, optionally
     * capturing variables in the enclosing scope.
     *
     * The body of `mpl11::let` must be specified by a `PlaceholderExpression`
     * provided by instantiating the nested `in` template with it:
     * `mpl11::let<Bindings...>::in<Body>`.
     *
     * `Bindings...` must be an arbitrary sequence of specializations of
     * `mpl11::as` representing the context used when evaluating the body.
     *
     * Evaluation of the body and bindings is performed as documented in the
     * `PlaceholderExpression` concept.
     *
     *
     * @note
     * To avoid potentially cumbersome invocations of `mpl11::let` in
     * dependent contexts, `mpl11::let<Bindings...>(Body)` is a valid
     * `MetafunctionClass` equivalent to `mpl11::let<Bindings...>::in<Body>`.
     */
    template <typename ...Bindings>
    struct let {
        template <typename Body>
        using in = let_detail::let_expr<imap<Bindings...>, Body>;
    };

    //!
    template <typename Name, typename Expression>
    using as = pair<Name, Expression>;
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_LET_HPP
