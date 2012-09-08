/**
 * This file defines placeholders for bind and lambda expressions.
 */

#ifndef DUCK_PLACEHOLDERS_HPP
#define DUCK_PLACEHOLDERS_HPP

#include <cstddef>


namespace duck {

template <std::size_t> struct placeholder { };

using _1 = placeholder<1>;
using _2 = placeholder<2>;
using _3 = placeholder<3>;
using _4 = placeholder<4>;
using _5 = placeholder<5>;
using _6 = placeholder<6>;
using _7 = placeholder<7>;
using _8 = placeholder<8>;
using _9 = placeholder<9>;

} // end namespace duck

#endif // !DUCK_PLACEHOLDERS_HPP
