/*!
 * @file
 * Forward declares
 * `boost::mpl11::detail::fast_random_access_iterator_adaptor`.
 */

#ifndef BOOST_MPL11_DETAIL_FAST_RANDOM_ACCESS_ITERATOR_ADAPTOR_FWD_HPP
#define BOOST_MPL11_DETAIL_FAST_RANDOM_ACCESS_ITERATOR_ADAPTOR_FWD_HPP

namespace boost { namespace mpl11 { namespace detail {
    /*!
     * @ingroup adaptors
     *
     * `Adaptor` for `RandomAccessIterator`s.
     *
     *
     * @todo
     * Find a way to _not_ reimplement all of the subconcepts requirements.
     */
    template <typename Iterator, typename Tag>
    struct fast_random_access_iterator_adaptor;
}}} // end namespace boost::mpl11::detail

#endif // !BOOST_MPL11_DETAIL_FAST_RANDOM_ACCESS_ITERATOR_ADAPTOR_FWD_HPP
