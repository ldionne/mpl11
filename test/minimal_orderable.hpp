/*!
 * @file
 * Defines the `minimal_orderable` helper for unit tests.
 */

#ifndef BOOST_MPL11_TEST_MINIMAL_ORDERABLE_HPP
#define BOOST_MPL11_TEST_MINIMAL_ORDERABLE_HPP

#include <boost/mpl11/bool.hpp>
#include <boost/mpl11/core.hpp>
#include <boost/mpl11/orderable.hpp>


struct MinimalOrderable;

template <unsigned v>
struct minimal_orderable {
    static constexpr auto value = v;
    using type = minimal_orderable;
    using mpl_datatype = MinimalOrderable;
};

namespace boost { namespace mpl11 {
    template <>
    struct Orderable<MinimalOrderable>
        : instantiate<Orderable>::with<MinimalOrderable>
    {
        template <typename x, typename y>
        using less_impl = bool_<(x::type::value < y::type::value)>;
    };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_TEST_MINIMAL_ORDERABLE_HPP
