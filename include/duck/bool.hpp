/**
 * This file defines the bool_ metafunction and related boolean metatypes.
 */

#ifndef DUCK_BOOL_HPP
#define DUCK_BOOL_HPP

namespace duck {

template <bool expr>
struct bool_ {
    static bool const value = expr;
    using type = bool_;
};

struct true_ : bool_<true> { };

struct false_ : bool_<false> { };

} // end namespace duck

#endif // !DUCK_BOOL_HPP
