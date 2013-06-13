/*!
 * @file
 * This file defines the `boost::mpl11::variadic` container.
 */

#ifndef BOOST_MPL11_CONTAINER_VARIADIC_HPP
#define BOOST_MPL11_CONTAINER_VARIADIC_HPP

#include <boost/mpl11/bool.hpp>
#include <boost/mpl11/container/map.hpp>
#include <boost/mpl11/container/pair.hpp>
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

class variadic_implementation {
    // until we have a proper set.
    using algos_returning_the_container = map<
        pair<quote<clear>           , void>,
        pair<quote<push_front>      , void>,
        pair<quote<push_back>       , void>,
        pair<quote<pop_back>        , void>,
        pair<quote<pop_front>       , void>
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

public:
    template <template <typename ...> class Algo, typename ...Args>
    struct apply;

    template <template <typename ...> class Algo,
              template <typename ...> class Variadic,
              template <typename ...> class Template,
              typename ...TemplateParams,
              typename ...Args>
    struct apply<Algo, Variadic<Template<TemplateParams...>>, Args...>
        : transfer_if_required<Algo, Template,
            typename Algo<vector<TemplateParams...>, Args...>::type
        >
    { };
};
} // end namespace variadic_detail

template <typename Template>
struct variadic;

template <template <typename ...> class Template, typename ...Elements>
struct variadic<Template<Elements...>> {
    using type = variadic;

    struct mpl11 {
        using dispatcher = variadic_detail::variadic_implementation;
    };
};
}}}

#endif // !BOOST_MPL11_CONTAINER_VARIADIC_HPP
