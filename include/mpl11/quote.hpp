/**
 * This file defines the quote metafunction.
 */

#ifndef MPL11_QUOTE_HPP
#define MPL11_QUOTE_HPP

namespace mpl11 {

/**
 * Metafunction creating a metafunction class from a metafunction.
 */
template <template <typename ...> class F>
struct quote {
    template <typename ...Args>
    struct apply : F<Args...> { };
};

} // end namespace mpl11

#endif // !MPL11_QUOTE_HPP
