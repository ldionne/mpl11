/*!
 * @file
 * Defines `BOOST_MPL11_INSTANTIATE_TEST`.
 */

#ifndef BOOST_MPL11_DETAIL_TEST_INSTANTIATE_HPP
#define BOOST_MPL11_DETAIL_TEST_INSTANTIATE_HPP

namespace boost { namespace mpl11 { namespace instantiate_test_detail {
    template <unsigned long>
    struct true_ { static constexpr bool value = true; };
}}}


#define BOOST_MPL11_INSTANTIATE_TEST(... /* unit test class */)             \
    static_assert(                                                          \
        ::boost::mpl11::instantiate_test_detail::true_<                     \
            sizeof(__VA_ARGS__)                                             \
        >::value,                                                           \
        # __VA_ARGS__                                                       \
    )                                                                       \
/**/

#endif // !BOOST_MPL11_DETAIL_TEST_INSTANTIATE_HPP
