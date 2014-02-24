/*!
 * @file
 * Defines the `minimal_iterable` helper for unit tests.
 */

#ifndef BOOST_MPL11_TEST_MINIMAL_ITERABLE_HPP
#define BOOST_MPL11_TEST_MINIMAL_ITERABLE_HPP

#include <boost/mpl11/bool.hpp>
#include <boost/mpl11/iterable.hpp>


struct MinimalIterable;

/*!
 * Minimal iterable for testing purposes.
 *
 * When testing your own iterables, always use this iterable instead
 * of, say, `list`, because `list` could specialize some operations
 * for efficiency reasons. `minimal_iterable` is guaranteed not to
 * specialize anything unnecessary, i.e. to have the most default
 * behavior possible.
 */
template <typename ...xs>
struct minimal_iterable {
    using type = minimal_iterable;
    using mpl_datatype = MinimalIterable;
};

namespace boost { namespace mpl11 {
    template <>
    struct Iterable<MinimalIterable> {
        template <typename s>
        struct head_impl : head_impl<typename s::type> { };

        template <typename x, typename ...xs>
        struct head_impl<minimal_iterable<x, xs...>> : x { };


        template <typename s>
        struct tail_impl : tail_impl<typename s::type> { };

        template <typename x, typename ...xs>
        struct tail_impl<minimal_iterable<x, xs...>>
            : minimal_iterable<xs...>
        { };


        template <typename s>
        struct is_empty_impl : is_empty_impl<typename s::type> { };

        template <typename ...xs>
        struct is_empty_impl<minimal_iterable<xs...>>
            : bool_<sizeof...(xs) == 0>
        { };
    };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_TEST_MINIMAL_ITERABLE_HPP
