/**
 * This file defines unit tests for the `unpack_args` metafunction class.
 */

#include <mpl11/unpack_args.hpp>
#include <mpl11/apply.hpp>
#include <mpl11/pack.hpp>
#include <mpl11/placeholders.hpp>

#include <type_traits>


using namespace mpl11;

static_assert(std::is_same<
                apply<
                    unpack_args<pack<_3, _2, _1, _all>>,
                    pack<int, float, void>
                >::type,
                pack<void, float, int, int, float, void>
              >::value, "");
