/*!
 * @file
 * Forward declares `boost::mpl11::detail::fast_sequence_adaptor`.
 */

#ifndef BOOST_MPL11_DETAIL_FAST_SEQUENCE_ADAPTOR_FWD_HPP
#define BOOST_MPL11_DETAIL_FAST_SEQUENCE_ADAPTOR_FWD_HPP

namespace boost { namespace mpl11 { namespace detail {
#ifdef BOOST_MPL11_DOXYGEN_INVOKED
    /*!
     * @ingroup concepts
     *
     * An `Adaptor` for a given concept is a type whose default
     * implementation is provided by another model of the same concept.
     *
     * The goal of `Adaptor`s is to serve as a basis for the implementation
     * of new models of a given concept. The way this is implemented is
     * unspecified in the general case and should be documented in an
     * `Adaptor`'s documentation.
     *
     *
     * @note
     * This concept only lives in the documentation. There exists no such
     * `struct` in the library.
     */
    struct Adaptor { };
#endif

    /*!
     * @ingroup details
     * @defgroup adaptors Adaptors
     *
     * `Adaptor`s provided by the library.
     *
     * Note that `Adaptor`s are not yet part of the public interface of the
     * library because there are still several issues to be handled before
     * we can incorporate this into the public interface.
     */

    /*!
     * @ingroup adaptors
     *
     * `Adaptor` for `Sequence`s.
     *
     * `fast_sequence_adaptor` is an `Adaptor` for the `Sequence` concept.
     * By specifying a custom `Tag` uniquely identifying a specialization
     * of `fast_sequence_adaptor`, it is possible to specialize the desired
     * operations and to let the other operations be forwarded to the
     * adapted `%Sequence`.
     *
     * It is allowed to specialize the `fast_sequence_adaptor` arbitrarily.
     * For example, an algorithm providing a lazy `Sequence` view of itself
     * could be defined as an alias to `fast_sequence_adaptor`. Then, one
     * would specialize the `Sequence` operations required for the very
     * algorithm and would specialize `fast_sequence_adaptor` to make it a
     * proper `Metafunction`.
     *
     *
     * @todo
     * Consider specializing optimization traits, `unpack` and
     * other non-intrinsics.
     *
     * @todo
     * Consider using a more flexible dispatch method like in
     * `detail/adaptors.hpp`. I must determine whether the added
     * indirections represent a non-negligible compile-time overhead
     * as done in `detail/adaptors.hpp` before choosing one implementation
     * over the other.
     */
    template <typename Sequence, typename Tag>
    struct fast_sequence_adaptor;
}}} // end namespace boost::mpl11::detail

#endif // !BOOST_MPL11_DETAIL_FAST_SEQUENCE_ADAPTOR_FWD_HPP
