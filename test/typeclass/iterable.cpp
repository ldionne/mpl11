/*!
 * @file
 * Contains unit tests for the @ref Iterable typeclass.
 */

#include <boost/mpl11/iterable.hpp>

#include <boost/mpl11/bool.hpp>
#include <boost/mpl11/core.hpp>
#include <boost/mpl11/detail/test/iterable.hpp>


struct Minimal;
template <typename ...xs>
struct minimal_ { using mpl_datatype = Minimal; };

template <typename ...xs>
struct minimal { using type = minimal_<xs...>; };

namespace boost { namespace mpl11 {
    template <>
    struct Iterable<Minimal> : instantiate<Iterable>::with<Minimal> {
        template <typename>
        struct head_impl;

        template <typename x, typename ...xs>
        struct head_impl<minimal_<x, xs...>> : x { };

        template <typename>
        struct tail_impl;

        template <typename x, typename ...xs>
        struct tail_impl<minimal_<x, xs...>>
            : minimal<xs...>
        { };

        template <typename>
        struct is_empty_impl;

        template <typename ...xs>
        struct is_empty_impl<minimal_<xs...>>
            : bool_<sizeof...(xs) == 0>
        { };
    };
}} // end namespace boost::mpl11

struct tests
    : boost::mpl11::detail::test_Iterable<minimal>
{ };


int main() { }
