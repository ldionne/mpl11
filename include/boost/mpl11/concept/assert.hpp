/*!
 * @file
 * Defines `BOOST_MPL11_CONCEPT_ASSERT`.
 */

#ifndef BOOST_MPL11_CONCEPT_ASSERT_HPP
#define BOOST_MPL11_CONCEPT_ASSERT_HPP

namespace boost { namespace mpl11 { namespace concept_assert_detail {
    template <unsigned long>
    struct always_true {
        static constexpr bool value = true;
    };
}}}

#define BOOST_MPL11_CONCEPT_ASSERT(.../* concept checking class */)         \
    static_assert(                                                          \
        ::boost::mpl11::concept_assert_detail::always_true<                 \
            sizeof(__VA_ARGS__)                                             \
        >::value,                                                           \
        "Concept check failed: " #__VA_ARGS__)                              \
/**/

#endif // !BOOST_MPL11_CONCEPT_ASSERT_HPP
