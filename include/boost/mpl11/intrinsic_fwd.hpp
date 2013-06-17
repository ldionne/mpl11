/*!
 * @file
 * This header contains the forward declaration of all the intrinsics.
 */

#ifndef BOOST_MPL11_INTRINSIC_FWD_HPP
#define BOOST_MPL11_INTRINSIC_FWD_HPP

#include <cstddef>


namespace boost { namespace mpl11 { inline namespace v2 {
namespace intrinsic {
    struct at;
    struct back;
    struct begin;
    struct clear;
    struct deref;
    struct empty;
    struct end;
    struct erase;
    struct erase_key;
    struct first;
    struct front;
    struct has_key;
    struct insert;
    struct insert_range;
    struct key;
    struct next;
    struct pop_back;
    struct pop_front;
    struct prior;
    struct push_back;
    struct push_front;
    struct second;
    struct size;
    struct value;
}

template <typename, typename ...> struct at;
template <typename, std::size_t>  struct at_c;
template <typename, typename ...> struct back;
template <typename, typename ...> struct begin;
template <typename, typename ...> struct clear;
template <typename, typename ...> struct deref;
template <typename, typename ...> struct empty;
template <typename, typename ...> struct end;
template <typename, typename ...> struct erase;
template <typename, typename ...> struct erase_key;
template <typename, typename ...> struct first;
template <typename, typename ...> struct front;
template <typename, typename ...> struct has_key;
template <typename, typename ...> struct insert;
template <typename, typename ...> struct insert_range;
template <typename, typename ...> struct key;
template <typename, typename ...> struct next;
template <typename, typename ...> struct pop_back;
template <typename, typename ...> struct pop_front;
template <typename, typename ...> struct prior;
template <typename, typename ...> struct push_back;
template <typename, typename ...> struct push_front;
template <typename, typename ...> struct second;
template <typename, typename ...> struct size;
template <typename, typename ...> struct value;
}}}

#endif // !BOOST_MPL11_INTRINSIC_FWD_HPP
