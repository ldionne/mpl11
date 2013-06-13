/*!
 * @file
 * This file defines the `boost::mpl11::variadic` container.
 */

#ifndef BOOST_MPL11_CONTAINER_VARIADIC_HPP
#define BOOST_MPL11_CONTAINER_VARIADIC_HPP

#include <boost/mpl11/bool.hpp>
#include <boost/mpl11/container/set.hpp>
#include <boost/mpl11/container/vector.hpp>
#include <boost/mpl11/if.hpp>
#include <boost/mpl11/quote.hpp>


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
    quote<clear>,
    quote<push_front>, quote<push_back>,
    quote<pop_back>, quote<pop_front>
>;

template <template <typename ...> class Algo>
struct requires_transfer
    : has_key<algos_returning_the_container, quote<Algo>>
{ };

template <template <typename ...> class Algo,
          template <typename ...> class Destination,
          typename Source>
struct transfer_if_required
    : if_<requires_transfer<Algo>,
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
                template <template <typename ...> class Impl,
                          typename Ignore, typename ...Args>
                struct apply
                    : Impl<Iterator, Args...>
                { };

                template <typename Ignore, typename ...Args>
                struct apply<next, Ignore, Args...> {
                    using type = iterator<
                        typename next<Iterator, Args...>::type
                    >;
                };

                template <typename Ignore, typename ...Args>
                struct apply<prior, Ignore, Args...> {
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
            template <template <typename ...> class Algo,
                      typename Ignore, typename ...Args>
            struct apply
                : variadic_detail::transfer_if_required<Algo, Template,
                    typename Algo<vector<TemplateParams...>, Args...>::type
                >
            { };

            template <typename Ignore, typename ...Args>
            struct apply<begin, Ignore, Args...> {
                using type = iterator<
                    typename begin<vector<TemplateParams...>, Args...>::type
                >;
            };

            template <typename Ignore, typename ...Args>
            struct apply<end, Ignore, Args...> {
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
