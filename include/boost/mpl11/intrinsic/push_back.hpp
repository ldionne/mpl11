/*!
 * @file
 * Defines `boost::mpl11::intrinsic::push_back`.
 */

#ifndef BOOST_MPL11_INTRINSIC_PUSH_BACK_HPP
#define BOOST_MPL11_INTRINSIC_PUSH_BACK_HPP

#include <boost/mpl11/always.hpp>
#include <boost/mpl11/detail/tag_dispatched.hpp>
#include <boost/mpl11/intrinsic/end.hpp>
#include <boost/mpl11/intrinsic/insert.hpp>
#include <boost/mpl11/tags.hpp>


namespace boost { namespace mpl11 { namespace intrinsic {
    /*!
     * @ingroup intrinsic
     *
     * Inserts an element at the end of a sequence.
     *
     *
     * ### Semantics and default implementation
     *
     * Equivalent to `insert<Sequence, end<Sequence>::type, Element>`.
     */
    template <typename Sequence, typename Element>
    struct push_back
        : detail::tag_dispatched<tag::push_back, Sequence, Element>::template
          with_default<
            lazy_always<
                insert<Sequence, typename end<Sequence>::type, Element>
            >
          >
    { };
}}} // end namespace boost::mpl11::intrinsic

#endif // !BOOST_MPL11_INTRINSIC_PUSH_BACK_HPP
