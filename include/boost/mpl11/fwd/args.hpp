/*!
 * @file
 * Forward declares `boost::mpl11::args` and `boost::mpl11::_args`.
 */

#ifndef BOOST_MPL11_FWD_ARGS_HPP
#define BOOST_MPL11_FWD_ARGS_HPP

namespace boost { namespace mpl11 {
    /*!
     * @ingroup metafunctions
     *
     * @ref MetafunctionClass and @ref Placeholder returning a `mpl::vector`
     * containing the arguments in the range delimited by [`First`, `Last`).
     *
     * If `Last` is not provided, it defaults to `sizeof...(Args)`, where
     * `Args...` are the arguments applied to `mpl11::args`.
     */
    template <unsigned long long First = 0, unsigned long long ...Last>
    struct args;

    //! @ingroup metafunctions
    //! Alias to `mpl11::args<>`; provided for convenience.
    using _args = args<>;
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_ARGS_HPP
