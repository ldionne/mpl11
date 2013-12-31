/*!
 * @file
 * Forward declares `boost::mpl11::args`.
 */

#ifndef BOOST_MPL11_FWD_ARGS_HPP
#define BOOST_MPL11_FWD_ARGS_HPP

#include <boost/mpl11/detail/std_size_t.hpp>


namespace boost { namespace mpl11 {
    /*!
     * @ingroup metafunction_classes
     *
     * `MetafunctionClass` returning a `vector` containing the arguments
     * in the range delimited by [`First`, `Last`).
     *
     * If `Last` is not provided, it defaults to `sizeof...(Args)`, where
     * `Args...` are the arguments `args` is invoked with.
     */
    template <detail::std_size_t First = 0, detail::std_size_t ...Last>
    struct args;
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_FWD_ARGS_HPP
