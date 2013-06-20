/*!
 * @file
 * This file defines the `boost::mpl11::any_of` algorithm.
 */

#ifndef BOOST_MPL11_ALGORITHM_ANY_OF_HPP
#define BOOST_MPL11_ALGORITHM_ANY_OF_HPP

#include <boost/mpl11/bool.hpp>
#include <boost/mpl11/detail/tag_dispatched.hpp>
#include <boost/mpl11/eval.hpp>
#include <boost/mpl11/functional/apply_raw.hpp>
#include <boost/mpl11/functional/lambda.hpp>
#include <boost/mpl11/functional/quote.hpp>
#include <boost/mpl11/identity.hpp>
#include <boost/mpl11/if.hpp>
#include <boost/mpl11/intrinsic/begin.hpp>
#include <boost/mpl11/intrinsic/deref.hpp>
#include <boost/mpl11/intrinsic/end.hpp>
#include <boost/mpl11/intrinsic/next.hpp>
#include <boost/mpl11/is_same.hpp>
#include <boost/mpl11/or.hpp>


namespace boost { namespace mpl11 { inline namespace v2 {
namespace any_of_detail {
    template <typename First, typename Last, typename Pred>
    struct default_impl
        : if_<is_same<First, Last>,
            false_,
            eval<or_<
                apply_raw<Pred, eval<deref<First>>>,
                eval<default_impl<next<First>, Last, Pred>>
            >>
        >
    { };
}

namespace algorithm {
    struct any_of : detail::tag_dispatched<any_of> {
        struct mpl11 {
            struct returns_integral_c;

            struct default_implementation {
                template <typename Sequence, typename Pred>
                struct apply
                    : any_of_detail::default_impl<
                        typename begin<Sequence>::type,
                        typename end<Sequence>::type,
                        typename lambda<Pred>::type
                    >
                { };
            };
        };
    };
}

template <typename Sequence, typename Pred = quote<identity>>
struct any_of
    : apply_raw<algorithm::any_of, Sequence, Pred>
{ };
}}}

#endif // !BOOST_MPL11_ALGORITHM_ANY_OF_HPP
