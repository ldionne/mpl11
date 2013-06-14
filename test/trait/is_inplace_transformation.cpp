/*!
 * @file
 * This file contains unit tests for
 * `boost::mpl11::trait::is_inplace_transformation`.
 */

#include <boost/mpl11/trait/is_inplace_transformation.hpp>
#include <boost/mpl11/bool.hpp>


using namespace boost::mpl11;

struct not_inplace_trans1;
struct not_inplace_trans2 { };
struct not_inplace_trans3 { struct mpl11; };
struct not_inplace_trans4 { struct mpl11 { }; };

struct inplace_trans1 { struct mpl11 { struct is_inplace_transformation; }; };

struct inplace_trans2;
namespace boost { namespace mpl11 { namespace trait {
    template <>
    struct is_inplace_transformation<inplace_trans2> : true_ { };
}}}

static_assert(!trait::is_inplace_transformation<not_inplace_trans1>::value, "");
static_assert(!trait::is_inplace_transformation<not_inplace_trans2>::value, "");
static_assert(!trait::is_inplace_transformation<not_inplace_trans3>::value, "");
static_assert(!trait::is_inplace_transformation<not_inplace_trans4>::value, "");
static_assert(trait::is_inplace_transformation<inplace_trans1>::value, "");
static_assert(trait::is_inplace_transformation<inplace_trans2>::value, "");


int main() { }
