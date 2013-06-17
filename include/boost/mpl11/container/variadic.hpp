/*!
 * @file
 * This file defines the `boost::mpl11::variadic` container.
 */

#ifndef BOOST_MPL11_CONTAINER_VARIADIC_HPP
#define BOOST_MPL11_CONTAINER_VARIADIC_HPP

#include <boost/mpl11/apply.hpp>
#include <boost/mpl11/container/vector.hpp>
#include <boost/mpl11/detail/transfer.hpp>
#include <boost/mpl11/detail/wrap_with.hpp>
#include <boost/mpl11/if.hpp>
#include <boost/mpl11/trait/is_inplace_transformation.hpp>


namespace boost { namespace mpl11 { inline namespace v2 {
namespace variadic_detail {
template <typename Operation,
          template <typename ...> class Destination,
          typename Source>
struct transfer_if_required
    : if_<trait::is_inplace_transformation<Operation>,
        eval<detail::transfer<Destination, Source>>,
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
                    : detail::wrap<
                        typename boost::mpl11::apply<
                            Operation, Iterator, Args...
                        >::type
                    >:: template with<variadic::iterator>
                    ::template if_<trait::is_inplace_transformation<Operation>>
                { };
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
