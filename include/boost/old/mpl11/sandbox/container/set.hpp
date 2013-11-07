/*!
 * @file
 * This file defines the `boost::mpl11::set` container.
 */

#ifndef BOOST_MPL11_CONTAINER_SET_HPP
#define BOOST_MPL11_CONTAINER_SET_HPP

#include <boost/mpl11/map.hpp>
#include <boost/mpl11/pair.hpp>
#include <boost/mpl11/detail/wrap_with.hpp>
#include <boost/mpl11/apply.hpp>
#include <boost/mpl11/trait/is_inplace_transformation.hpp>


namespace boost { namespace mpl11 {
namespace set_detail {
template <typename Map>
class set_impl {
    template <typename Iterator>
    class iterator {
        struct implementation {
            template <typename Operation, typename ...Args>
            struct apply
                : detail::wrap<
                    typename boost::mpl11::apply<
                        Operation, Iterator, Args...
                    >::type
                >::template with<set_impl::iterator>
                ::template if_<trait::is_inplace_transformation<Operation>>
            { };

            template <typename ...Args>
            struct apply<intrinsic::deref, Args...>
                : key<Map, typename deref<Iterator, Args...>::type>
            { };
        };

    public:
        struct mpl11 { using delegate = implementation; };
    };

    struct implementation {
        template <typename Operation, typename ...Args>
        struct apply
            : detail::wrap<
                typename mpl11::apply<Operation, Map, Args...>::type
            >::template with<set_detail::set_impl>
            ::template if_<trait::is_inplace_transformation<Operation>>
        { };

        // Wrap insert to accept a single element instead of a pair.
        template <typename Hint, typename Element>
        struct apply<intrinsic::insert, Hint, Element>
            : apply<intrinsic::insert, Element>
        { };

        template <typename Element>
        struct apply<intrinsic::insert, Element>
            : detail::wrap<
                typename insert<Map, pair<Element, Element>>::type
            >::template with<set_detail::set_impl>
        { };

        // We wrap front so that it returns a single type instead of a pair.
        template <typename ...Args>
        struct apply<intrinsic::front, Args...>
            : key<Map, typename front<Map, Args...>::type>
        { };

        // We wrap value and key so that they return the element itself.
        template <typename Element>
        struct apply<intrinsic::key, Element> {
            using type = Element;
        };

        template <typename Element>
        struct apply<intrinsic::value, Element> {
            using type = Element;
        };

        // We wrap begin and end so that they return modified iterators
        template <typename ...Args>
        struct apply<intrinsic::begin, Args...> {
            using type = iterator<
                typename begin<Map, Args...>::type
            >;
        };

        template <typename ...Args>
        struct apply<intrinsic::end, Args...> {
            using type = iterator<
                typename end<Map, Args...>::type
            >;
        };
    };

public:
    using type = set_impl;
    struct mpl11 { using dispatcher = implementation; };
};
} // end namespace set_detail

template <typename ...Elements>
using set = set_detail::set_impl<map<pair<Elements, Elements>...>>;
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_CONTAINER_SET_HPP
