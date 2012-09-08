/**
 * This file defines the transform metafunction.
 */

#ifndef DUCK_TRANSFORM_HPP
#define DUCK_TRANSFORM_HPP

#include <duck/apply.hpp>
#include <duck/pack.hpp>


namespace duck {

/**
 * Apply a metafunction to each parameter in a parameter pack and
 * store the result in ``type''.
 *
 * Note: The result is in packed form.
 */
template <typename F, typename ...Range>
struct transform : transform<F, pack<Range...>, pack<>> { };

template <typename F, typename ...Results>
struct transform<F, pack<>, pack<Results...>> {
    using type = pack<Results...>;
};

template <typename F, typename First, typename ...Rest, typename ...Results>
struct transform<F, pack<First, Rest...>, pack<Results...>>
    : transform<F,
        pack<Rest...>,
        pack<Results..., typename apply<F, First>::type>
    >
{ };

} // end namespace duck

#endif // !DUCK_TRANSFORM_HPP
