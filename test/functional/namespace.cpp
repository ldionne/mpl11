/*!
 * @file
 * Contains a unit test to make sure that we don't create ambiguities
 * by providing a `boost::mpl11::functional` namespace.
 *
 * @copyright Louis Dionne 2014
 * Distributed under the Boost Software License, Version 1.0.
 *         (See accompanying file LICENSE.md or copy at
 *             http://www.boost.org/LICENSE_1_0.txt)
 */

#include <boost/mpl11/functional.hpp>


namespace mpl11 = boost::mpl11;

template <typename ...> struct f;

using x1 = mpl11::id<int>;
using x2 = mpl11::functional::id<int>;

using x3 = mpl11::lift<f>;
using x4 = mpl11::functional::lift<f>;

namespace no_ambiguities1 {
    using namespace mpl11::functional;
    using y1 = id<int>;
    using y2 = lift<f>;
}

namespace no_ambiguities2 {
    using namespace mpl11;
    using y1 = id<int>;
    using y2 = lift<f>;
}

namespace no_ambiguities3 {
    using namespace mpl11::functional;
    using namespace mpl11;
    using y1 = id<int>;
    using y2 = lift<f>;
}


int main() { }
