/*!
 * @file
 * Defines `boost::mpl11::detail::tag_dispatched`.
 */

#ifndef BOOST_MPL11_DETAIL_TAG_DISPATCHED_HPP
#define BOOST_MPL11_DETAIL_TAG_DISPATCHED_HPP

#include <boost/mpl11/apply_wrap.hpp>
#include <boost/mpl11/detail/always_false.hpp>
#include <boost/mpl11/detail/either.hpp>
#include <boost/mpl11/dispatch.hpp>
#include <boost/mpl11/tag_of.hpp>


namespace boost { namespace mpl11 {
namespace tag_dispatched_detail {
    template <typename OperationTag, typename ...Args>
    struct invalid_default {
        static_assert(detail::always_false<OperationTag, Args...>::value,
        "Attempt to use a default implementation that is invalid. A default "
        "implementation exists for the operation, but it is not a valid "
        "MetafunctionClass for the provided arguments.");

        struct type;
    };
} // end namespace tag_dispatched_detail

namespace detail {
    template <typename OperationTag>
    struct default_;

    template <typename OperationTag, typename ...Args>
    struct tag_dispatched
        : either<
            apply_wrap<
                dispatch<OperationTag, typename tag_of<Args>::type...>,
                Args...
            >,
            dispatch<default_<OperationTag>, Args...>,
            tag_dispatched_detail::invalid_default<
                OperationTag, Args...
            >
        >
    { };
} // end namespace detail

template <typename OperationTag, typename ...Args>
struct dispatch<detail::default_<OperationTag>, Args...> {
    static_assert(detail::always_false<OperationTag, Args...>::value,
    "Attempt to perform an operation that is not implemented "
    "for the provided arguments and for which no default "
    "implementation is available.");
};
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_DETAIL_TAG_DISPATCHED_HPP
