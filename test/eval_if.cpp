/**
 * This file defines unit tests for the @em eval_if metafunction.
 */

#include <duck/eval_if.hpp>
#include <duck/identity.hpp>

#include <type_traits>


using duck::identity;

static_assert(std::is_same<
                duck::eval_if<
                     std::true_type, identity<float>, identity<char>
                >::type,
                float
              >::value, "");

static_assert(std::is_same<
                duck::eval_if<
                     std::false_type, identity<float>, identity<char>
                >::type,
                char
              >::value, "");

static_assert(duck::eval_if<
                std::true_type, std::true_type, std::false_type
              >::value, "");
