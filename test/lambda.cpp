/*!
 * @file
 * This file contains unit tests for `boost::mpl11::lambda`.
 */

#include <boost/mpl11/lambda.hpp>
#include <boost/mpl11/bind.hpp>
#include <boost/mpl11/bool.hpp>
#include <boost/mpl11/protect.hpp>
#include <boost/mpl11/quote.hpp>
#include <boost/mpl11/trait/is_placeholder.hpp>

#include <boost/type_traits/is_same.hpp>


using namespace boost;
using namespace boost::mpl11;

template <typename ...> struct ph; // placeholder
template <typename ...> struct nph; // not a placeholder

namespace boost { namespace mpl11 { inline namespace v2 { namespace trait {
    template <typename ...T>
    struct is_placeholder<ph<T...>> : true_ { };
}}}}

static_assert(is_same<lambda<int>::type, int>::value, "");
static_assert(is_same<lambda<nph<int>>::type, nph<int>>::value, "");

static_assert(is_same<
    lambda<nph<ph<>>>::type,
    protect<bind<quote<nph>, ph<>>>
>::value, "");

static_assert(is_same<
    lambda<nph<ph<>, ph<int>>>::type,
    protect<bind<quote<nph>, ph<>, ph<int>>>
>::value, "");

static_assert(is_same<
    lambda<nph<ph<>, ph<ph<int>>>>::type,
    protect<bind<quote<nph>, ph<>, ph<ph<int>>>>
>::value, "");

static_assert(is_same<
    lambda<nph<nph<int, float>>>::type,
    nph<nph<int, float>>
>::value, "");


int main() { }
