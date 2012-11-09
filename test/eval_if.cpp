/**
 * This file defines unit tests for the @em eval_if metafunction.
 */

#include <mpl11/eval_if.hpp>
#include <mpl11/identity.hpp>
#include <mpl11/types.hpp>

#include <type_traits>


using namespace mpl11;

static_assert(std::is_same<
                eval_if<
                     true_, identity<float>, identity<char>
                >::type,
                float
              >::value, "");

static_assert(std::is_same<
                eval_if<
                     false_, identity<float>, identity<char>
                >::type,
                char
              >::value, "");

static_assert(eval_if<
                true_, true_, false_
              >::value, "");
