/*!
 * @file
 * Defines `boost::mpl11::single_view`.
 */

#ifndef BOOST_MPL11_SINGLE_VIEW_HPP
#define BOOST_MPL11_SINGLE_VIEW_HPP

#error FINISH IMPLEMENTATION

namespace boost { namespace mpl11 {
namespace single_view_detail {
    template <typename Element>
    struct begin_iterator;

    template <typename Element>
    struct end_iterator;
}

template <typename Element>
struct single_view;

template <typename Element>
struct dispatch<tag::begin, single_view<Element>>
    : always<>
{ };

template <typename Element>
struct dispatch<tag::end, single_view<Element>>
    : always<>
{ };

template <typename Element>
struct dispatch<tag::category_of, single_view<Element>>
    : always<tag::random_access<tag::sequence>>
{ };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_SINGLE_VIEW_HPP
