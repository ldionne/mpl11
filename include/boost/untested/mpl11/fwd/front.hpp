/*!
 * @file
 * Forward declares `boost::mpl11::front`.
 */

#ifndef BOOST_MPL11_FWD_FRONT_HPP
#define BOOST_MPL11_FWD_FRONT_HPP

#include <boost/mpl11/dispatch.hpp>


namespace boost { namespace mpl11 {
    namespace tag { struct front; }

    /*!
     * @ingroup algorithms
     * Returns the first element in a @ref ForwardSequence.
     *
     *
     * ### Semantics and default implementation
     *
     * Equivalent to `deref<begin<Sequence>::type>` if
     * `is_empty<Sequence>::type::value` is `false`, and
     * a compile-time assertion is triggered otherwise.
     *
     *
     * @warning
     * Differences from the original MPL:
     * - A compile-time assertion is triggered if the sequence is empty.
     */
    template <typename Sequence>
    struct front
        : dispatch<tag::front, Sequence>
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_FRONT_HPP
