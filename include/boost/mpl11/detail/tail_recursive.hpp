/*!
 * @file
 * Defines `boost::mpl11::detail::tail_recursive`.
 */

#ifndef BOOST_MPL11_DETAIL_TAIL_RECURSIVE_HPP
#define BOOST_MPL11_DETAIL_TAIL_RECURSIVE_HPP


namespace boost { namespace mpl11 { namespace detail {
namespace tail_recursive_detail {
    template <unsigned long long N, typename F>
    struct recurse {
        using type = typename recurse<N - N/2,
            typename recurse<N/2, F>::type
        >::type;
    };

    template <typename F>
    struct recurse<0, F> { using type = F; };

    template <typename F>
    struct recurse<1, F> { using type = typename F::tail_call; };
} // end namespace tail_recursive_detail

/*!
 * @ingroup details
 *
 * Wrapper enabling "tail call optimization" for metafunctions.
 *
 * Using the protocol described here enables conforming metafunctions
 * to recurse to _very large_ depths without exceeding the recursive
 * template instantiation depth limit of the compiler.
 *
 * @note
 * "tail call optimization" is not really what's happenning, but the
 * effect is similar so I'm using that term.
 *
 * However, only metafunctions whose outermost expression is a recursive call
 * to themselves can be optimized. Specifically, metafunctions of the form
 *
 * @code

        template <typename ...Args>
        struct metafunction {
            using type = typename metafunction<
                arbitrary...
            >::type;
        };

 * @endcode
 *
 * can be optimized, while others can't. I think it's only a limitation of
 * the current system and the same optimization could be performed for
 * arbitrary metafunctions; I still need to experiment.
 *
 * ### How to make your metafunction tail recursive
 * Say we have a recursive metafunction
 *
 * @code

        template <typename x>
        struct f;

 * @endcode
 *
 * with a base case
 *
 * @code

        template <typename x>
        struct base_case;

 * @endcode
 *
 * Note that `base_case` will usually be implemented as a specialization
 * of `f` or as a condition inside `f`. In order to make `f` tail recursive,
 * we'll change it to the following:
 *
 * @code

        // The actual metafunction, which was previously named `f`.
        template <typename x>
        struct f_impl;

        // The interface of `f` does not need to change; it just needs
        // to wrap the call to `f_impl` as shown.
        template <typename x>
        struct f {
            using type = typename tail_recursive<f_impl<x>>::type;
        };

 * @endcode
 *
 * Then, we must change `f_impl` from something like
 *
 * @code

        template <typename x>
        struct f_impl {
            using type = typename f_impl<...>::type;
        };

        template <typename x>
        struct base_case {
            using type = FINAL_RESULT;
        };

 * @endcode
 *
 * to something like
 *
 * @code

        template <typename x>
        struct f_impl {
            using tail_call = f_impl<...>;
        };

        template <typename x>
        struct base_case {
            using tail_call = base_case;
            using type = FINAL_RESULT;
        };

 * @endcode
 *
 * So instead of calling `f_impl` recursively, we "return" it lazily
 * under the name `tail_call`. We do the same thing for `base_case`,
 * except that this time we also provide the result as a normal
 * metafunction. The fact that `base_case::tail_call` is idempotent
 * is the key to the success of the technique. Read the code for details.
 *
 *
 * @warning
 * The number of recursive invocations that can be handled by this technique
 * is currently ~100k. Since this should be _way_ above what you will ever
 * need, this limit is not customizeable. Also, no attempt has been made to
 * make this construct user-friendly in case of error.
 *
 * If you find yourself in need of a larger limit, I want to meet you
 * in person, superman.
 */
template <typename F>
struct tail_recursive {
    using type = typename tail_recursive_detail::recurse<
        100000, F
    >::type::type;
};
}}} // end namespace boost::mpl11::detail

#endif // !BOOST_MPL11_DETAIL_TAIL_RECURSIVE_HPP
