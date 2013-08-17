/*!
 * @file
 * This file defines the `boost::mpl11::vector` container.
 */

#ifndef BOOST_MPL11_CONTAINER_VECTOR_HPP
#define BOOST_MPL11_CONTAINER_VECTOR_HPP

#include <boost/mpl11/container/variadic.hpp>


namespace boost { namespace mpl11 { inline namespace v2 {
template <typename ...T>
struct vector {
    struct mpl11 {
        using dispatcher = variadic_sequence_dispatcher<
            sequence_characteristics, vector
        >;
    };
};
}}}

#endif // !BOOST_MPL11_CONTAINER_VECTOR_HPP
