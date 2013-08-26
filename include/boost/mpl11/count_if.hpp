/*!
 * @file
 * Defines `boost::mpl11::count_if`.
 */

#ifndef BOOST_MPL11_COUNT_IF_HPP
#define BOOST_MPL11_COUNT_IF_HPP

#include <boost/mpl11/apply_wrap.hpp>
#include <boost/mpl11/arg.hpp>
#include <boost/mpl11/detail/tag_dispatched.hpp>
#include <boost/mpl11/foldl.hpp>
#include <boost/mpl11/if.hpp>
#include <boost/mpl11/integral_c.hpp>
#include <boost/mpl11/lambda.hpp>
#include <boost/mpl11/next.hpp>


namespace boost { namespace mpl11 {
namespace count_if_detail {
    template <typename Sequence, typename Predicate>
    struct count_if_impl
        : foldl<
            Sequence,
            ulong<0>,
            if_<apply_wrap<typename lambda<Predicate>::type, _2>,
                next<_1>,
                _1
            >
        >
    { };
} // end namespace count_if_detail

namespace tag { struct count_if; }

/*!
 * Returns the number of elements in `Sequence` satisfying `Predicate`.
 *
 * The default implementation is equivalent to
   @code
        foldl<
            Sequence, ulong<0>,
            if_<apply_wrap<lambda<Predicate>::type, _2>,
                next<_1>,
                _1
            >
        >
   @endcode
 */
template <typename Sequence, typename Predicate>
struct count_if
    : detail::tag_dispatched<tag::count_if, Sequence, Predicate>::template
      with_default<count_if_detail::count_if_impl<_2, _3>>
{ };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_COUNT_IF_HPP
