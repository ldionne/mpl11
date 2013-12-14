/*!
 * @file
 * Defines `boost::mpl11::transform`.
 */

#ifndef BOOST_MPL11_TRANSFORM_HPP
#define BOOST_MPL11_TRANSFORM_HPP

#include <boost/mpl11/fwd/transform.hpp>

#include <boost/mpl11/apply.hpp>
#include <boost/mpl11/detail/fast_random_access_iterator_adaptor.hpp>
#include <boost/mpl11/detail/fast_sequence_adaptor.hpp>
#include <boost/mpl11/detail/nested_alias.hpp>
#include <boost/mpl11/fwd/begin.hpp>
#include <boost/mpl11/fwd/deref.hpp>
#include <boost/mpl11/fwd/end.hpp>
#include <boost/mpl11/fwd/unpack.hpp>
#include <boost/mpl11/new.hpp>


namespace boost { namespace mpl11 {
namespace transform_detail {
    template <typename Iterator, typename F>
    using transform_iterator = detail::fast_random_access_iterator_adaptor<
        Iterator, transform_with<F>
    >;

    template <typename F, typename Dest>
    struct fast_transform_into {
        template <typename ...Args>
        BOOST_MPL11_NESTED_ALIAS(apply,
            mpl11::apply<Dest, typename mpl11::apply<F, Args>::type...>);
    };
} // end namespace transform_detail

template <typename Iterator, typename F>
struct deref<transform_detail::transform_iterator<Iterator, F>>
    : apply<F, typename deref<Iterator>::type>
{ };

namespace detail {
    template <typename Sequence, typename F>
    struct fast_sequence_adaptor<Sequence, transform_detail::transform_with<F>>
        : apply<new_<Sequence>, transform<Sequence, F>>
    { };
}

template <typename Sequence, typename F>
struct begin<transform<Sequence, F>> {
    using type = transform_detail::transform_iterator<
        typename begin<Sequence>::type, F
    >;
};

template <typename Sequence, typename F>
struct end<transform<Sequence, F>> {
    using type = transform_detail::transform_iterator<
        typename end<Sequence>::type, F
    >;
};

template <typename Sequence, typename F, typename Dest>
struct unpack<transform<Sequence, F>, Dest>
    : unpack<Sequence, transform_detail::fast_transform_into<F, Dest>>
{ };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_TRANSFORM_HPP
