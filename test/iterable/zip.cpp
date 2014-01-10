/*!
 * @file
 * Contains unit tests for `boost::mpl11::zip`.
 */

#include <boost/mpl11/iterable/zip.hpp>

#include <boost/mpl11/detail/box.hpp>
#include <boost/mpl11/detail/iterable_test.hpp>


using namespace boost::mpl11;

template <typename ...Sn>
struct zipping {
    template <typename ...Zipped>
    struct is :
        detail::iterable_test<
            zip<Sn...>,
            Zipped...
        >
    { };
};

template <typename ...T>
using seq = detail::minimal_iterable<detail::box<T>...>;

struct w0; struct w1; struct w2; struct w3; struct w4;
struct x0; struct x1; struct x2; struct x3; struct x4;
struct y0; struct y1; struct y2; struct y3; struct y4;
struct z0; struct z1; struct z2; struct z3; struct z4;

struct tests :
   // zip 2 iterables
    zipping<seq<>, seq<>>::is<>,
    zipping<seq<>, seq<x0>>::is<>,
    zipping<seq<>, seq<x0, x1>>::is<>,

    zipping<seq<w0>, seq<>>::is<>,
    zipping<seq<w0>, seq<x0>>::is<seq<w0, x0>>,
    zipping<seq<w0>, seq<x0, x1>>::is<seq<w0, x0>>,

    zipping<seq<w0, w1>, seq<>>::is<>,
    zipping<seq<w0, w1>, seq<x0>>::is<seq<w0, x0>>,
    zipping<seq<w0, w1>, seq<x0, x1>>::is<seq<w0, x0>, seq<w1, x1>>,

    // zip 3 iterables
    zipping<seq<>, seq<>, seq<y0>>::is<>,
    zipping<seq<>, seq<x0>, seq<>>::is<>,
    zipping<seq<>, seq<x0>, seq<y0>>::is<>,
    zipping<seq<w0>, seq<>, seq<>>::is<>,
    zipping<seq<w0>, seq<>, seq<y0>>::is<>,
    zipping<seq<w0>, seq<x0>, seq<>>::is<>,
    zipping<seq<w0>, seq<x0>, seq<y0>>::is<seq<w0, x0, y0>>,

    // zip 4 iterables with (sometimes) different sizes
    zipping<
        seq<w0, w1, w2, w3>,
        seq<x0, x1, x2, x3, x4>,
        seq<y0, y1, y2>,
        seq<z0, z1, z2, z3, z4>
    >::is<
        seq<w0, x0, y0, z0>,
        seq<w1, x1, y1, z1>,
        seq<w2, x2, y2, z2>
    >
{ };


int main() { }
