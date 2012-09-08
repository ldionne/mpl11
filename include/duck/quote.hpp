/**
 * This file defines the quote metafunction.
 */

#ifndef DUCK_QUOTE_HPP
#define DUCK_QUOTE_HPP

namespace duck {

/**
 * Metafunction creating a metafunction class from a metafunction.
 */
template <template <typename ...> class F>
struct quote {
    template <typename ...Args>
    struct apply : F<Args...> { };
};

} // end namespace duck

#endif // !DUCK_QUOTE_HPP
