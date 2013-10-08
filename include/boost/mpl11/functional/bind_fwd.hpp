/*!
 * @file
 * Forward declares `boost::mpl11::bind`.
 */

#ifndef BOOST_MPL11_FUNCTIONAL_BIND_HPP
#define BOOST_MPL11_FUNCTIONAL_BIND_HPP

namespace boost { namespace mpl11 {
    /*!
     * @ingroup functional
     *
     * Higher order primitive for argument binding.
     *
     * `bind<F, An...>::apply<Args...>::type` is equivalent to
       @code
            apply_wrap<
                substitute<F, Args...>,
                substitute<An, Args...>...
            >::type
       @endcode
     * where `substitute<X, Args...>` is equivalent to
     * `apply_wrap<X, Args...>::type` if `X` is a @ref Placeholder,
     * and `X` otherwise.
     *
     * @warning
     * Differences from the original MPL:
     * - Nested bind expressions are not evaluated.
     */
    template <typename F, typename ...An>
    struct bind;
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FUNCTIONAL_BIND_HPP
