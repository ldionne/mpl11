/*!
 * @file
 * Defines `boost::mpl11::intrinsic::is_empty`.
 */

#ifndef BOOST_MPL11_INTRINSIC_IS_EMPTY_HPP
#define BOOST_MPL11_INTRINSIC_IS_EMPTY_HPP

#include <boost/mpl11/always.hpp>
#include <boost/mpl11/detail/tag_dispatched.hpp>
#include <boost/mpl11/intrinsic/begin.hpp>
#include <boost/mpl11/intrinsic/end.hpp>
#include <boost/mpl11/intrinsic/equal_to.hpp>
#include <boost/mpl11/tags.hpp>


namespace boost { namespace mpl11 { namespace intrinsic {
    /*!
     * @ingroup intrinsic
     *
     * Returns whether a sequence is empty.
     *
     *
     * ### Semantics and default implementation
     *
     * Equivalent to `equal_to<begin<Sequence>::type, end<Sequence>::type>`.
     *
     *
     * @warning
     * This metafunction replaces `mpl::empty` from the original MPL.
     */
    template <typename Sequence>
    struct is_empty
        : detail::tag_dispatched<tag::is_empty, Sequence>::template
          with_default<
            lazy_always<
                equal_to<
                    typename begin<Sequence>::type,
                    typename end<Sequence>::type
                >
            >
          >
    { };
}}} // end namespace boost::mpl11::intrinsic

#endif // !BOOST_MPL11_INTRINSIC_IS_EMPTY_HPP
