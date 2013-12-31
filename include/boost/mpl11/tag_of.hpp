/*!
 * @file
 * Defines `boost::mpl11::tag_of`.
 */

#ifndef BOOST_MPL11_TAG_OF_HPP
#define BOOST_MPL11_TAG_OF_HPP

#include <boost/mpl11/fwd/tag_of.hpp>


namespace boost { namespace mpl11 {
    namespace tag_of_detail {
        template <typename T>
        typename T::mpl_tag pick(void*);

        template <typename T>
        foreign_tag pick(...);
    } // end namespace tag_of_detail

    template <typename T>
    struct tag_of {
        using type = decltype(tag_of_detail::pick<T>(nullptr));
    };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_TAG_OF_HPP
