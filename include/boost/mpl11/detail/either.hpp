/*!
 * @file
 * Defines `boost::mpl11::detail::either`.
 */

#ifndef BOOST_MPL11_DETAIL_EITHER_HPP
#define BOOST_MPL11_DETAIL_EITHER_HPP

namespace boost { namespace mpl11 {
namespace either_detail {
    template <typename Left, typename Right>
    auto pick(typename Left::type*) -> Left;

    template <typename Left, typename Right>
    auto pick(...) -> Right;
} // end namespace either_detail

namespace detail {
    /*!
     * @ingroup details
     *
     * Returns the nested `::type` of the first argument with a
     * valid nested `::type`.
     */
    template <typename Left, typename Right, typename ...More>
    struct either
        : either<Left, either<Right, More...>>
    { };

    template <typename Left, typename Right>
    struct either<Left, Right>
        : decltype(either_detail::pick<Left, Right>(nullptr))
    { };
} // end namespace detail
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_DETAIL_EITHER_HPP
