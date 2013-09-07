/*!
 * @file
 * Defines the default implementation of `boost::mpl11::algorithm::find_if`.
 */

#ifndef BOOST_MPL11_DETAIL_DEFAULT_FIND_IF_HPP
#define BOOST_MPL11_DETAIL_DEFAULT_FIND_IF_HPP

#include <boost/mpl11/apply_wrap.hpp>
#include <boost/mpl11/dispatch.hpp>
#include <boost/mpl11/identity.hpp>
#include <boost/mpl11/if.hpp>
#include <boost/mpl11/intrinsic/begin.hpp>
#include <boost/mpl11/intrinsic/deref.hpp>
#include <boost/mpl11/intrinsic/end.hpp>
#include <boost/mpl11/intrinsic/equal_to.hpp>
#include <boost/mpl11/intrinsic/next.hpp>
#include <boost/mpl11/lambda.hpp>
#include <boost/mpl11/tags.hpp>


namespace boost { namespace mpl11 {
namespace find_if_detail {
    template <typename First, typename Last, typename Predicate,
              bool = intrinsic::equal_to<First, Last>::type::value>
    struct find_if_impl
        : identity<Last>
    { };

    template <typename First, typename Last, typename Predicate>
    struct lazy_next_step
        : find_if_impl<
            typename intrinsic::next<First>::type, Last, Predicate
        >
    { };

    template <typename First, typename Last, typename Predicate>
    struct find_if_impl<First, Last, Predicate, false>
        : if_<apply_wrap<Predicate, typename intrinsic::deref<First>::type>,
            identity<First>,
            lazy_next_step<First, Last, Predicate>
        >::type
    { };
} // end namespace find_if_detail

template <typename Sequence, typename Predicate>
struct dispatch<detail::default_<tag::find_if>, Sequence, Predicate>
    : find_if_detail::find_if_impl<
        typename intrinsic::begin<Sequence>::type,
        typename intrinsic::end<Sequence>::type,
        typename lambda<Predicate>::type
    >
{ };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_DETAIL_DEFAULT_FIND_IF_HPP
