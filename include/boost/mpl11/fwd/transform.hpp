/*!
 * @file
 * Forward declares `boost::mpl11::transform`.
 */

#ifndef BOOST_MPL11_FWD_TRANSFORM_HPP
#define BOOST_MPL11_FWD_TRANSFORM_HPP

#include <boost/mpl11/detail/fast_sequence_adaptor_fwd.hpp>


namespace boost { namespace mpl11 {
    namespace transform_detail {
        template <typename F>
        struct transform_with;
    }

    /*!
     * @ingroup algorithms
     * @ingroup sequences
     *
     * `Sequence` containing the result of applying `F` to each element
     * of `%Sequence`.
     *
     * Additionally, `mpl11::transform` is an algorithm returning a new
     * `Container` created with the elements of `mpl11::transform`. To use
     * `mpl11::transform` as an algorithm, `%Sequence` must be a `Container`.
     */
    template <typename Sequence, typename F>
    using transform = detail::fast_sequence_adaptor<
        Sequence, transform_detail::transform_with<F>
    >;

    template <typename Sequence, typename F>
    using transform_t = typename transform<Sequence, F>::type;
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_TRANSFORM_HPP
