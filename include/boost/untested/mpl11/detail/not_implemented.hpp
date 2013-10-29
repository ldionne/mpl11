/*!
 * @file
 * Defines `boost::mpl11::detail::not_implemented`.
 */

#ifndef BOOST_MPL11_DETAIL_NOT_IMPLEMENTED_HPP
#define BOOST_MPL11_DETAIL_NOT_IMPLEMENTED_HPP

#include <boost/mpl11/detail/dependent_on.hpp>


namespace boost { namespace mpl11 { namespace detail {
    template <typename Operation>
    struct not_implemented {
        static_assert(dependent_on<Operation>::template value<bool, false>(),
        "Attempt to perform an operation that is not implemented.");

        struct type;
    };
}}} // end namespace boost::mpl11::detail

#endif // !BOOST_MPL11_DETAIL_NOT_IMPLEMENTED_HPP
