/*!
 * @file
 * This file defines the `boost::mpl11::set` container.
 */

#ifndef BOOST_MPL11_CONTAINER_SET_HPP
#define BOOST_MPL11_CONTAINER_SET_HPP

#include <boost/mpl11/container/map.hpp>


namespace boost { namespace mpl11 { inline namespace v2 {
namespace set_detail {
template <typename MapImplementation>
struct set_implementation : MapImplementation {
    template <template <typename ...> class Impl, typename ...Args>
    struct apply
        : MapImplementation::template apply<Impl, Args...>
    { };


};
} // end namespace set_detail


template <typename ...Elements>
class set : public map<pair<Elements, Elements>...> {
    using Base = map<pair<Elements, Elements>...>;

    template <typename MapIterator>
    struct set_iterator : MapIterator {
        using BaseDispatcher = typename MapIterator::mpl11::dispatcher;

        struct mpl11 : MapIterator::mpl11 {
            struct dispatcher : BaseDispatcher {
                template <template <typename ...> class Impl, typename ...Args>
                struct apply
                    : BaseDispatcher::template apply<Impl, Args...>
                { };

                template <typename Iterator>
                struct apply<deref, Iterator>
                    : key<Base, typename deref<Iterator>::type>
                { };
            };
        };
    };

    using BaseDispatcher = typename Base::mpl11::dispatcher;

    template <template <typename ...> class Algo, typename ...Args>
    struct wrap_into_set_iterator {
        using type = set_iterator<
            typename BaseDispatcher::template apply<Algo, Args...>::type
        >;
    };

public:
    struct mpl11 : Base::mpl11 {
        struct dispatcher : BaseDispatcher {
            template <template <typename ...> class Impl, typename ...Args>
            struct apply
                : BaseDispatcher::template apply<Impl, Args...>
            { };

            template <typename ...Args>
            struct apply<begin, Args...>
                : wrap_into_set_iterator<begin, Args...>
            { };

            template <typename ...Args>
            struct apply<end, Args...>
                : wrap_into_set_iterator<end, Args...>
            { };

        };
    };

public:
    struct mpl11 { using dispatcher = implementation; };
};
}}}

#endif // !BOOST_MPL11_CONTAINER_SET_HPP
