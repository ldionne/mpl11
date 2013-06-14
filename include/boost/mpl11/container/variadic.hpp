/*!
 * @file
 * This file defines the `boost::mpl11::variadic` container.
 */

#ifndef BOOST_MPL11_CONTAINER_VARIADIC_HPP
#define BOOST_MPL11_CONTAINER_VARIADIC_HPP

#include <boost/mpl11/apply.hpp>
#include <boost/mpl11/container/set.hpp>
#include <boost/mpl11/container/vector.hpp>
#include <boost/mpl11/if.hpp>


namespace boost { namespace mpl11 { inline namespace v2 {
namespace variadic_detail {
template <template <typename ...> class Destination, typename Source>
struct transfer;

template <template <typename ...> class Destination,
          template <typename ...> class Source,
          typename ...Content>
struct transfer<Destination, Source<Content...>> {
    using type = Destination<Content...>;
};

using algos_returning_the_container = set<
    intrinsic::clear,
    intrinsic::push_back, intrinsic::push_front,
    intrinsic::pop_back, intrinsic::pop_front
>;

template <typename Operation>
struct requires_transfer
    : has_key<algos_returning_the_container, Operation>
{ };

template <typename Operation,
          template <typename ...> class Destination,
          typename Source>
struct transfer_if_required
    : if_<requires_transfer<Operation>,
        eval<transfer<Destination, Source>>,
        Source
    >
{ };
} // end namespace variadic_detail

template <typename Template>
class variadic;

template <template <typename ...> class Template, typename ...TemplateParams>
class variadic<Template<TemplateParams...>> {
    template <typename Iterator>
    struct iterator {
        struct mpl11 {
            struct dispatcher {
                template <typename Operation, typename ...Args>
                struct apply
                    : boost::mpl11::apply<
                        Operation, Iterator, Args...
                    >
                { };

                template <typename ...Args>
                struct apply<intrinsic::next, Args...> {
                    using type = iterator<
                        typename next<Iterator, Args...>::type
                    >;
                };

                template <typename ...Args>
                struct apply<intrinsic::prior, Args...> {
                    using type = iterator<
                        typename prior<Iterator, Args...>::type
                    >;
                };
            };
        };
    };

public:
    struct mpl11 {
        struct dispatcher {
            template <typename Operation, typename ...Args>
            struct apply
                : variadic_detail::transfer_if_required<Operation, Template,
                    typename boost::mpl11::apply<
                        Operation, vector<TemplateParams...>, Args...
                    >::type
                >
            { };

            template <typename ...Args>
            struct apply<intrinsic::begin, Args...> {
                using type = iterator<
                    typename begin<vector<TemplateParams...>, Args...>::type
                >;
            };

            template <typename ...Args>
            struct apply<intrinsic::end, Args...> {
                using type = iterator<
                    typename end<vector<TemplateParams...>, Args...>::type
                >;
            };
        };
    };

    using type = variadic;
};
}}}

#endif // !BOOST_MPL11_CONTAINER_VARIADIC_HPP
