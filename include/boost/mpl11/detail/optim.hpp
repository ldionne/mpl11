/*!
 * @file
 * Defines `boost::mpl11::detail::optim` and `boost::mpl11::detail::optims_of`.
 */

#ifndef BOOST_MPL11_DETAIL_OPTIM_HPP
#define BOOST_MPL11_DETAIL_OPTIM_HPP

namespace boost { namespace mpl11 { namespace detail {
    /*!
     * @ingroup details
     *
     * Tags representing various optimizations used in the library.
     *
     * These tags are meant to be used as bit flags. They can be manipulated
     * through the usual bitwise operations.
     */
    enum class optim : unsigned {
        none = 0,

        //! Tag for `Sequence`s whose `size` can be obtained in O(1).
        O1_size = 1 << 0,

        //! Tag for `Sequence`s that can be `unpack`ed in O(1).
        O1_unpack = 1 << 1
    };

    constexpr optim operator|(optim a, optim b)
    { return (optim)((unsigned)a | (unsigned)b); }

    constexpr optim operator&(optim a, optim b)
    { return (optim)((unsigned)a & (unsigned)b); }

    constexpr optim operator^(optim a, optim b)
    { return (optim)((unsigned)a ^ (unsigned)b); }

    constexpr optim operator~(optim a)
    { return (optim)~(unsigned)a; }

    /*!
     * @ingroup details
     *
     * Returns the optimizations available for a given type.
     *
     * By default, `optim::none` is returned.
     */
    template <typename T>
    struct optims_of {
        static constexpr optim value = optim::none;
    };
}}} // end namespace boost::mpl11::detail

#endif // !BOOST_MPL11_DETAIL_OPTIM_HPP
