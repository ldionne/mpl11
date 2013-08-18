/*!
 * @file
 * This file defines the `boost::mpl11::MetafunctionClass` concept.
 */

#ifndef BOOST_MPL11_CONCEPT_METAFUNCTION_CLASS_HPP
#define BOOST_MPL11_CONCEPT_METAFUNCTION_CLASS_HPP

#include <boost/mpl11/concept/metafunction.hpp>
#include <boost/mpl11/detail/nested_apply.hpp>

#include <boost/concept/assert.hpp>
#include <boost/concept/usage.hpp>


namespace boost { namespace mpl11 {
    /*!
     *
     */
    template <typename F, typename ...Args>
    struct MetafunctionClass {
        BOOST_CONCEPT_USAGE(MetafunctionClass) {
            using NestedApply = typename detail::nested_apply<F, Args...>::type;
            BOOST_CONCEPT_ASSERT((Metafunction<NestedApply>));
        }
    };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_CONCEPT_METAFUNCTION_CLASS_HPP
