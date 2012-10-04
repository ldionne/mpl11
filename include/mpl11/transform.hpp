/**
 * This file defines the transform metafunction.
 */

#ifndef MPL11_TRANSFORM_HPP
#define MPL11_TRANSFORM_HPP

#include <mpl11/apply.hpp>
#include <mpl11/pack.hpp>


namespace mpl11 {

/**
 * Apply a metafunction class to each parameter in a parameter pack and
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

} // end namespace mpl11

#endif // !MPL11_TRANSFORM_HPP
