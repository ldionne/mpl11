/*!
 * @file
 * Defines `boost::mpl11::detail::is_inplace_transformation`.
 */

#ifndef BOOST_MPL11_DETAIL_IS_INPLACE_TRANSFORMATION_HPP
#define BOOST_MPL11_DETAIL_IS_INPLACE_TRANSFORMATION_HPP

#include <boost/mpl11/bool.hpp>
#include <boost/mpl11/tags.hpp>


namespace boost { namespace mpl11 { namespace detail {
    template <typename Operation>
    struct is_inplace_transformation
        : false_
    { };

#define BOOST_MPL11_IS_INPLACE_TRANSFORMATION(TAG)                          \
    template <>                                                             \
    struct is_inplace_transformation<tag::TAG>                              \
        : true_                                                             \
    { };                                                                    \
/**/

    // Algorithms
    BOOST_MPL11_IS_INPLACE_TRANSFORMATION(advance)
    BOOST_MPL11_IS_INPLACE_TRANSFORMATION(copy)

    // Intrinsics
    BOOST_MPL11_IS_INPLACE_TRANSFORMATION(clear)
    BOOST_MPL11_IS_INPLACE_TRANSFORMATION(erase)
    BOOST_MPL11_IS_INPLACE_TRANSFORMATION(erase_key)
    BOOST_MPL11_IS_INPLACE_TRANSFORMATION(insert)
    BOOST_MPL11_IS_INPLACE_TRANSFORMATION(insert_range)
    BOOST_MPL11_IS_INPLACE_TRANSFORMATION(next)
    BOOST_MPL11_IS_INPLACE_TRANSFORMATION(pop_back)
    BOOST_MPL11_IS_INPLACE_TRANSFORMATION(pop_front)
    BOOST_MPL11_IS_INPLACE_TRANSFORMATION(prior)
    BOOST_MPL11_IS_INPLACE_TRANSFORMATION(push_back)
    BOOST_MPL11_IS_INPLACE_TRANSFORMATION(push_front)

#undef BOOST_MPL11_IS_INPLACE_TRANSFORMATION
}}} // end namespace boost::mpl11::detail

#endif // !BOOST_MPL11_DETAIL_IS_INPLACE_TRANSFORMATION_HPP
