/*!
 * @file
 * Defines `boost::mpl11::MetafunctionClass`.
 */

#ifndef BOOST_MPL11_METAFUNCTION_CLASS_HPP
#define BOOST_MPL11_METAFUNCTION_CLASS_HPP

#include <boost/mpl11/fwd/metafunction_class.hpp>

#include <boost/mpl11/object.hpp>


namespace boost { namespace mpl11 {
    struct MetafunctionClass : Object {
    private:
        template <typename F, typename G>
        struct compose {
            struct type {
                using mpl_class = MetafunctionClass;

                template <typename ...Args>
                struct apply
                    : mpl11::apply<F, typename apply<G, Args...>::type>
                { };
            };
        };

    public:
        // Is this a good thing?
        template <typename Self>
        struct not_
            : compose<quote<not_>, Self>
        { };

        template <typename Self, typename ...Args>
        struct apply
            : Self::template apply<Args...>
        { };
    };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_METAFUNCTION_CLASS_HPP
