/*!
 * @file
 * This file defines the `boost::mpl11::TagDispatchedMetafunctionClass`
 * concept.
 */

#ifndef BOOST_MPL11_CONCEPT_TAG_DISPATCHED_METAFUNCTION_CLASS_HPP
#define BOOST_MPL11_CONCEPT_TAG_DISPATCHED_METAFUNCTION_CLASS_HPP

#include <boost/concept/assert.hpp>
#include <boost/concept/usage.hpp>


namespace boost { namespace mpl11 {
    /*!
     *
     */
    template <typename F, typename Receiver, typename ...Args>
    struct DispatchedMetafunctionClass {
        BOOST_CONCEPT_USAGE(DispatchedMetafunctionClass) {
            using Result = typename apply_raw<F, Receiver, Args...>::type;


            using Dispatcher = typename trait::dispatcher_of<Receiver>::type;
            BOOST_CONCEPT_ASSERT((MetafunctionClass<Dispatcher, F>));

            using Implementation = typename apply_raw<Dispatcher, F>::type;
            BOOST_CONCEPT_ASSERT((MetafunctionClass<
                Implementation, Receiver, Args...
            >));

            using ExpectedResult = typename apply_raw<
                Implementation, Receiver, Args...
            >::type;

            static_assert(is_same<Result, ExpectedResult>::value, "");
        }
    };

    struct some_algo {
        template <typename F, typename Receiver, typename ...Args>
        struct apply
            : apply_raw<
                typename apply_raw<
                    typename dispatcher_of<Receiver>::type, F
                >::type,
                Receiver, Args...
            >
        { };
    };

    struct vector {
        struct dispatcher {
            template <typename F>
            struct apply { };

            template <>
            struct apply<intrinsic::foobar> {
                struct type {
                    template <typename Receiver, typename ...Args>
                    struct apply {

                    };
                };
            };
        };
    };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_CONCEPT_TAG_DISPATCHED_METAFUNCTION_CLASS_HPP
