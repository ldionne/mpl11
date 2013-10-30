/*!
 * @file
 * Forward declares `boost::mpl11::at` and defines `boost::mpl::at_c`.
 */

#ifndef BOOST_MPL11_FWD_AT_HPP
#define BOOST_MPL11_FWD_AT_HPP

#include <boost/mpl11/detail/doxygen_only.hpp>
#include <boost/mpl11/detail/optional.hpp>
#include <boost/mpl11/fwd/integral_c.hpp>


namespace boost { namespace mpl11 {
    /*!
     * @ingroup intrinsics
     *
     * @todo Move the doc to the proper concept
     * @todo There is no default implementation when a default is provided
     *       right now, maybe there should be one?
     * Returns the element associated to a key in an @ref AssociativeSequence,
     * or a default value if no such element exists and a default is provided.
     *
     *
     * ### Semantics and default implementation
     *
     * When no `Default` is provided, equivalent to `at<Sequence, Key, X>`,
     * where `X` is a type such that a compile-time assertion is triggered
     * if `X` is returned.
     *
     * When a `Default` is provided, let `Iter` be the same as
       @code
            find_if<
                Sequence,
                equal_to<key_of<Sequence, _1>, Key>
            >::type
       @endcode
     * Then, `at` is equivalent to `value_of<Sequence, deref<Iter>::type>` if
       @code
            equal_to<
                Iter, end<Sequence>::type
            >::type::value
       @endcode
     * is `false`, and `identity<Default>` otherwise.
     *
     *
     * @warning
     * Differences from the original MPL:
     * - A compile-time assertion is triggered when no `Default` is provided
     *   and `Key` can't be found.
     */
    template <
        typename Sequence,
        typename Key,
        typename Default = detail::optional
    >
    struct at BOOST_MPL11_DOXYGEN_ONLY(<Sequence, Key, Default>);
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_AT_HPP
