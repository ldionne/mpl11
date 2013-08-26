/*!
 * @file
 * Defines `boost::mpl11::detail::tag_dispatched`.
 */

#ifndef BOOST_MPL11_DETAIL_TAG_DISPATCHED_HPP
#define BOOST_MPL11_DETAIL_TAG_DISPATCHED_HPP

#include <boost/mpl11/apply.hpp>
#include <boost/mpl11/apply_wrap.hpp>
#include <boost/mpl11/detail/always_false.hpp>
#include <boost/mpl11/detail/either.hpp>
#include <boost/mpl11/dispatch.hpp>
#include <boost/mpl11/tag_of.hpp>


namespace boost { namespace mpl11 {
namespace tag_dispatched_detail {
    struct no_default {
        template <typename Operation, typename ...Args>
        struct apply {
            static_assert(detail::always_false<Operation, Args...>::value,
            "Attempt to perform an operation that is not implemented "
            "for the provided arguments and for which no default "
            "implementation is available.");

            struct type;
        };
    };

    template <typename Default, typename Operation, typename ...Args>
    struct invalid_default {
        static_assert(detail::always_false<Default, Operation, Args...>::value,
        "Attempt to use a default implementation that is invalid. A default "
        "implementation was specified for the operation, but it is not a "
        "valid MetafunctionClass for the provided arguments.");

        struct type;
    };
} // end namespace tag_dispatched_detail

namespace detail {
    template <typename Operation, typename ...Args>
    struct tag_dispatched {
        template <typename Default = tag_dispatched_detail::no_default>
        struct with_default
            : either<
                apply_wrap<
                    dispatch<
                        typename tag_of<Operation>::type,
                        typename tag_of<Args>::type...
                    >,
                    Operation, Args...
                >,
                apply<Default, Operation, Args...>,
                tag_dispatched_detail::invalid_default<
                    Default, Operation, Args...
                >
            >
        { };
    };
} // end namespace detail
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_DETAIL_TAG_DISPATCHED_HPP
