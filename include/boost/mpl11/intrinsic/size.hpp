/*!
 * @file
 * Defines `boost::mpl11::intrinsic::size`.
 */

#ifndef BOOST_MPL11_INTRINSIC_SIZE_HPP
#define BOOST_MPL11_INTRINSIC_SIZE_HPP

#include <boost/mpl11/algorithm/distance.hpp>
#include <boost/mpl11/always.hpp>
#include <boost/mpl11/detail/tag_dispatched.hpp>
#include <boost/mpl11/intrinsic/begin.hpp>
#include <boost/mpl11/intrinsic/end.hpp>
#include <boost/mpl11/tags.hpp>


namespace boost { namespace mpl11 { namespace intrinsic {
    /*!
     * @ingroup intrinsic
     *
     * Returns the number of elements in a sequence.
     *
     *
     * ### Semantics and default implementation
     *
     * Equivalent to `distance<begin<Sequence>::type, end<Sequence>::type>`.
     */
    template <typename Sequence>
    struct size
        : detail::tag_dispatched<tag::size, Sequence>::template
          with_default<
            lazy_always<
                algorithm::distance<
                    typename begin<Sequence>::type,
                    typename end<Sequence>::type
                >
            >
          >
    { };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_INTRINSIC_SIZE_HPP
