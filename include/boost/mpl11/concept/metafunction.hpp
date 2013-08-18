/*!
 * @file
 * This file defines the `boost::mpl11::Metafunction` concept.
 */

#ifndef BOOST_MPL11_CONCEPT_METAFUNCTION_HPP
#define BOOST_MPL11_CONCEPT_METAFUNCTION_HPP

#include <boost/concept/usage.hpp>


namespace boost { namespace mpl11 {
    /*!
     *
     */
    template <typename F>
    struct Metafunction {
        BOOST_CONCEPT_USAGE(Metafunction) {
            using Result = typename F::type;
        }
    };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_CONCEPT_METAFUNCTION_HPP
