/*!
 * @file
 * Defines `boost::mpl11::detail::test_value`.
 */

#ifndef BOOST_MPL11_DETAIL_TEST_VALUE_HPP
#define BOOST_MPL11_DETAIL_TEST_VALUE_HPP

namespace boost { namespace mpl11 { namespace detail {
    /*!
     * @ingroup details
     *
     * Generic unit test for `Value`s.
     */
    template <typename V>
    class test_value {
        using ValueType = typename V::value_type;
        static constexpr ValueType x = V{};
        static constexpr ValueType y = V::value;
    };
}}} // end namespace boost::mpl11::detail

#endif // !BOOST_MPL11_DETAIL_TEST_VALUE_HPP
