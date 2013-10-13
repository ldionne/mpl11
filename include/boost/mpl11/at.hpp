/*!
 * @file
 * Defines `boost::mpl11::at`.
 */

#ifndef BOOST_MPL11_AT_HPP
#define BOOST_MPL11_AT_HPP

#include <boost/mpl11/fwd/at.hpp>
#include <boost/mpl11/integral_c.hpp> // for at_c

#include <boost/mpl11/advance.hpp>
#include <boost/mpl11/arg.hpp>
#include <boost/mpl11/begin.hpp>
#include <boost/mpl11/categories.hpp>
#include <boost/mpl11/category_of.hpp>
#include <boost/mpl11/deref.hpp>
#include <boost/mpl11/detail/best_category_for.hpp>
#include <boost/mpl11/detail/is_same.hpp>
#include <boost/mpl11/detail/optional.hpp>
#include <boost/mpl11/dispatch.hpp>
#include <boost/mpl11/end.hpp>
#include <boost/mpl11/equal_to.hpp>
#include <boost/mpl11/find_if.hpp>
#include <boost/mpl11/identity.hpp>
#include <boost/mpl11/if.hpp>
#include <boost/mpl11/key_of.hpp>
#include <boost/mpl11/not_equal_to.hpp>
#include <boost/mpl11/value_of.hpp>


namespace boost { namespace mpl11 {
namespace at_detail {
    template <typename Sequence, typename Iterator>
    struct value_deref
        : value_of<
            Sequence,
            typename deref<Iterator>::type
        >
    { };

    template <typename Category, typename ...>
    struct at_impl;

    template <typename Sequence, typename Key, typename Default>
    struct at_impl<category::associative_sequence, Sequence, Key, Default> {
    private:
        using Iter = typename find_if<
            Sequence,
            equal_to<key_of<Sequence, _1>, Key>
        >::type;

        using WasNotFound = typename equal_to<
            Iter, typename end<Sequence>::type
        >::type;

    public:
        using type = typename if_<WasNotFound,
            identity<Default>,
            value_deref<Sequence, Iter>
        >::type::type;
    };

    struct not_found;

    template <typename Sequence, typename Key>
    struct at_impl<category::associative_sequence, Sequence, Key>
        : at<Sequence, Key, not_found>
    {
        static_assert(
            !detail::is_same<typename at_impl::type, not_found>::type::value,
        "Could not find the value associated to a given key in an associated "
        "sequence and no default return value was specified.");
    };

    template <typename Sequence, typename N>
    struct at_impl<category::forward_sequence, Sequence, N> {
    private:
        using Iter = typename advance<
            typename begin<Sequence>::type, N
        >::type;

        static_assert(
            N::value >= 0 &&
            not_equal_to<Iter, typename end<Sequence>::type>::type::value,
        "Trying to access a sequence at an index that is out of bounds.");

    public:
        using type = typename deref<Iter>::type;
    };
} // end namespace at_detail

template <typename Sequence, typename Key, typename ...Default>
struct dispatch<tag::default_<tag::at>, Sequence, Key, Default...>
    : at_detail::at_impl<
        typename detail::best_category_for<Sequence,
            category::associative_sequence,
            category::forward_sequence
        >::type,
        Sequence, Key, Default...
    >
{ };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_AT_HPP
