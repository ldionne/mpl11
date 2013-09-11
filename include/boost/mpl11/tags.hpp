/*!
 * @file
 * Defines all the tags of the library.
 */

#ifndef BOOST_MPL11_TAGS_HPP
#define BOOST_MPL11_TAGS_HPP

namespace boost { namespace mpl11 { namespace tag {
    // Algorithm tags
    struct advance;
    struct all_of;
    struct any_of;
    struct contains;
    struct copy;
    struct count;
    struct count_if;
    struct distance;
    struct equal;
    struct find;
    struct find_if;
    struct foldl;
    struct foldr;
    struct is_permutation;
    struct max;
    struct min;
    struct none_of;

    // Intrinsic tags
    struct at;
    struct back;
    struct begin;
    struct category_of;
    struct clear;
    struct deref;
    struct end;
    struct erase;
    struct erase_key;
    struct first;
    struct front;
    struct has_key;
    struct insert;
    struct insert_range;
    struct is_empty;
    struct key_of;
    struct next;
    struct pop_back;
    struct pop_front;
    struct prior;
    struct push_back;
    struct push_front;
    struct second;
    struct size;
    struct value_of;

    // Operator tags
    struct and_;
    struct equal_to;
    struct greater;
    struct greater_equal;
    struct less;
    struct less_equal;
    struct not_;
    struct not_equal_to;
    struct or_;
}}} // end namespace boost::mpl11::tag

#endif // !BOOST_MPL11_TAGS_HPP
