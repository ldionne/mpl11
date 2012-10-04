/**
 * This file defines unit tests for the @em eval_if metafunction.
 */

#include <mpl11/eval_if.hpp>
#include <mpl11/identity.hpp>

#include <type_traits>


using namespace mpl11;

static_assert(std::is_same<
                eval_if<
                     std::true_type, identity<float>, identity<char>
                >::type,
                float
              >::value, "");

static_assert(std::is_same<
                eval_if<
                     std::false_type, identity<float>, identity<char>
                >::type,
                char
              >::value, "");

static_assert(eval_if<
                std::true_type, std::true_type, std::false_type
              >::value, "");
