/*!
 * @file
 * Defines `boost::mpl11::detail::variadic_at`.
 */

#ifndef BOOST_MPL11_DETAIL_VARIADIC_AT_HPP
#define BOOST_MPL11_DETAIL_VARIADIC_AT_HPP

#include <boost/mpl11/detail/dependent_on.hpp>


namespace boost { namespace mpl11 {
namespace variadic_at_detail {
    template <bool HasRandomAccess, unsigned long I, typename ...An>
    struct at_impl {
        static_assert(detail::dependent_on<char[I+1]>::template
                      value<bool, false>(),
        "trying to access a parameter pack at an out-of-bounds index");

        struct type;
    };

    // Script generating specializations for random access to variadic
    // parameter packs. You should not touch this! This is only of
    // importance to the maintainer of the library.

/*****************************************************************************

#!/usr/bin/env ruby

def decl_params(n)
    (0..n).collect { |i| "typename A#{i}" }.join(', ')
end

def spec_params(n)
    (0..n).collect { |i| "A#{i}" }.join(', ')
end

def generate_specializations(max_spec)
    declarations = <<-END
template <unsigned long I, typename ...An>
using variadic_at_c = at_impl<(I < #{max_spec}), I, An...>;

template <
    unsigned long I, #{decl_params max_spec-1}, typename ...Rest
>
struct at_impl<false, I, #{spec_params max_spec-1}, Rest...>
    : variadic_at_c<I - #{max_spec}, Rest...>
{ };

    END

    specializations = (0..max_spec).collect { |n|
        <<-END
template <#{decl_params n}, typename ...Rest> \
struct at_impl<true, #{n}, #{spec_params n}, Rest...> { \
    using type = A#{n}; \
};
        END
    }
    puts [declarations, specializations]
end

def generate_unit_tests(max_spec)
    puts "template <int> struct a;"
    (0..max_spec*3).each { |narg|
        args = (0..narg).collect { |index| ", a<#{index}>" }
        (0..narg).each { |index|
            # If we're within 5 indices of the begining or end of the
            # number of arguments, we generate a static_assert because
            # we'd like to test border cases.
            #
            # We also generate a static_assert if the parity of this index
            # does not match that of the current number of arguments. This
            # allows us to save half the static_asserts in average making
            # the test lighter to compile, but we still test even AND odd
            # indexing because the parity of narg is alternating.
            if [index, narg - index].min <= 5 or index.even? == narg.even? then
                puts <<-END
static_assert(is_same< \
    variadic_at_c<#{index} #{args}>::type, a<#{index}> \
>::value, "");
                END
            end
        }
    }
end


# Maximum number of specializations
MAX_SPEC = 40

# Whenever you regenerate the specializations, also regenerate the unit
# tests to make sure both stay in sync. The generated unit test should
# be pasted in <test/detail/variadic_at.cpp>.

# generate_specializations(MAX_SPEC)
# generate_unit_tests(MAX_SPEC)

*****************************************************************************/

    //////////////////////////////////////////////////////////////////////////
    // BEGIN GENERATED OUTPUT. DO NOT EDIT!
    //////////////////////////////////////////////////////////////////////////
    template <unsigned long I, typename ...An>
    using variadic_at_c = at_impl<(I < 40), I, An...>;

    template <
        unsigned long I, typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14, typename A15, typename A16, typename A17, typename A18, typename A19, typename A20, typename A21, typename A22, typename A23, typename A24, typename A25, typename A26, typename A27, typename A28, typename A29, typename A30, typename A31, typename A32, typename A33, typename A34, typename A35, typename A36, typename A37, typename A38, typename A39, typename ...Rest
    >
    struct at_impl<false, I, A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13, A14, A15, A16, A17, A18, A19, A20, A21, A22, A23, A24, A25, A26, A27, A28, A29, A30, A31, A32, A33, A34, A35, A36, A37, A38, A39, Rest...>
        : variadic_at_c<I - 40, Rest...>
    { };

    template <typename A0, typename ...Rest> struct at_impl<true, 0, A0, Rest...> {     using type = A0; };
    template <typename A0, typename A1, typename ...Rest> struct at_impl<true, 1, A0, A1, Rest...> {     using type = A1; };
    template <typename A0, typename A1, typename A2, typename ...Rest> struct at_impl<true, 2, A0, A1, A2, Rest...> {     using type = A2; };
    template <typename A0, typename A1, typename A2, typename A3, typename ...Rest> struct at_impl<true, 3, A0, A1, A2, A3, Rest...> {     using type = A3; };
    template <typename A0, typename A1, typename A2, typename A3, typename A4, typename ...Rest> struct at_impl<true, 4, A0, A1, A2, A3, A4, Rest...> {     using type = A4; };
    template <typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename ...Rest> struct at_impl<true, 5, A0, A1, A2, A3, A4, A5, Rest...> {     using type = A5; };
    template <typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename ...Rest> struct at_impl<true, 6, A0, A1, A2, A3, A4, A5, A6, Rest...> {     using type = A6; };
    template <typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename ...Rest> struct at_impl<true, 7, A0, A1, A2, A3, A4, A5, A6, A7, Rest...> {     using type = A7; };
    template <typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename ...Rest> struct at_impl<true, 8, A0, A1, A2, A3, A4, A5, A6, A7, A8, Rest...> {     using type = A8; };
    template <typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename ...Rest> struct at_impl<true, 9, A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, Rest...> {     using type = A9; };
    template <typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename ...Rest> struct at_impl<true, 10, A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, Rest...> {     using type = A10; };
    template <typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename ...Rest> struct at_impl<true, 11, A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, Rest...> {     using type = A11; };
    template <typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename ...Rest> struct at_impl<true, 12, A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, Rest...> {     using type = A12; };
    template <typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename ...Rest> struct at_impl<true, 13, A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13, Rest...> {     using type = A13; };
    template <typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14, typename ...Rest> struct at_impl<true, 14, A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13, A14, Rest...> {     using type = A14; };
    template <typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14, typename A15, typename ...Rest> struct at_impl<true, 15, A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13, A14, A15, Rest...> {     using type = A15; };
    template <typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14, typename A15, typename A16, typename ...Rest> struct at_impl<true, 16, A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13, A14, A15, A16, Rest...> {     using type = A16; };
    template <typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14, typename A15, typename A16, typename A17, typename ...Rest> struct at_impl<true, 17, A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13, A14, A15, A16, A17, Rest...> {     using type = A17; };
    template <typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14, typename A15, typename A16, typename A17, typename A18, typename ...Rest> struct at_impl<true, 18, A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13, A14, A15, A16, A17, A18, Rest...> {     using type = A18; };
    template <typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14, typename A15, typename A16, typename A17, typename A18, typename A19, typename ...Rest> struct at_impl<true, 19, A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13, A14, A15, A16, A17, A18, A19, Rest...> {     using type = A19; };
    template <typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14, typename A15, typename A16, typename A17, typename A18, typename A19, typename A20, typename ...Rest> struct at_impl<true, 20, A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13, A14, A15, A16, A17, A18, A19, A20, Rest...> {     using type = A20; };
    template <typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14, typename A15, typename A16, typename A17, typename A18, typename A19, typename A20, typename A21, typename ...Rest> struct at_impl<true, 21, A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13, A14, A15, A16, A17, A18, A19, A20, A21, Rest...> {     using type = A21; };
    template <typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14, typename A15, typename A16, typename A17, typename A18, typename A19, typename A20, typename A21, typename A22, typename ...Rest> struct at_impl<true, 22, A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13, A14, A15, A16, A17, A18, A19, A20, A21, A22, Rest...> {     using type = A22; };
    template <typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14, typename A15, typename A16, typename A17, typename A18, typename A19, typename A20, typename A21, typename A22, typename A23, typename ...Rest> struct at_impl<true, 23, A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13, A14, A15, A16, A17, A18, A19, A20, A21, A22, A23, Rest...> {     using type = A23; };
    template <typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14, typename A15, typename A16, typename A17, typename A18, typename A19, typename A20, typename A21, typename A22, typename A23, typename A24, typename ...Rest> struct at_impl<true, 24, A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13, A14, A15, A16, A17, A18, A19, A20, A21, A22, A23, A24, Rest...> {     using type = A24; };
    template <typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14, typename A15, typename A16, typename A17, typename A18, typename A19, typename A20, typename A21, typename A22, typename A23, typename A24, typename A25, typename ...Rest> struct at_impl<true, 25, A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13, A14, A15, A16, A17, A18, A19, A20, A21, A22, A23, A24, A25, Rest...> {     using type = A25; };
    template <typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14, typename A15, typename A16, typename A17, typename A18, typename A19, typename A20, typename A21, typename A22, typename A23, typename A24, typename A25, typename A26, typename ...Rest> struct at_impl<true, 26, A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13, A14, A15, A16, A17, A18, A19, A20, A21, A22, A23, A24, A25, A26, Rest...> {     using type = A26; };
    template <typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14, typename A15, typename A16, typename A17, typename A18, typename A19, typename A20, typename A21, typename A22, typename A23, typename A24, typename A25, typename A26, typename A27, typename ...Rest> struct at_impl<true, 27, A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13, A14, A15, A16, A17, A18, A19, A20, A21, A22, A23, A24, A25, A26, A27, Rest...> {     using type = A27; };
    template <typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14, typename A15, typename A16, typename A17, typename A18, typename A19, typename A20, typename A21, typename A22, typename A23, typename A24, typename A25, typename A26, typename A27, typename A28, typename ...Rest> struct at_impl<true, 28, A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13, A14, A15, A16, A17, A18, A19, A20, A21, A22, A23, A24, A25, A26, A27, A28, Rest...> {     using type = A28; };
    template <typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14, typename A15, typename A16, typename A17, typename A18, typename A19, typename A20, typename A21, typename A22, typename A23, typename A24, typename A25, typename A26, typename A27, typename A28, typename A29, typename ...Rest> struct at_impl<true, 29, A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13, A14, A15, A16, A17, A18, A19, A20, A21, A22, A23, A24, A25, A26, A27, A28, A29, Rest...> {     using type = A29; };
    template <typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14, typename A15, typename A16, typename A17, typename A18, typename A19, typename A20, typename A21, typename A22, typename A23, typename A24, typename A25, typename A26, typename A27, typename A28, typename A29, typename A30, typename ...Rest> struct at_impl<true, 30, A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13, A14, A15, A16, A17, A18, A19, A20, A21, A22, A23, A24, A25, A26, A27, A28, A29, A30, Rest...> {     using type = A30; };
    template <typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14, typename A15, typename A16, typename A17, typename A18, typename A19, typename A20, typename A21, typename A22, typename A23, typename A24, typename A25, typename A26, typename A27, typename A28, typename A29, typename A30, typename A31, typename ...Rest> struct at_impl<true, 31, A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13, A14, A15, A16, A17, A18, A19, A20, A21, A22, A23, A24, A25, A26, A27, A28, A29, A30, A31, Rest...> {     using type = A31; };
    template <typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14, typename A15, typename A16, typename A17, typename A18, typename A19, typename A20, typename A21, typename A22, typename A23, typename A24, typename A25, typename A26, typename A27, typename A28, typename A29, typename A30, typename A31, typename A32, typename ...Rest> struct at_impl<true, 32, A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13, A14, A15, A16, A17, A18, A19, A20, A21, A22, A23, A24, A25, A26, A27, A28, A29, A30, A31, A32, Rest...> {     using type = A32; };
    template <typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14, typename A15, typename A16, typename A17, typename A18, typename A19, typename A20, typename A21, typename A22, typename A23, typename A24, typename A25, typename A26, typename A27, typename A28, typename A29, typename A30, typename A31, typename A32, typename A33, typename ...Rest> struct at_impl<true, 33, A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13, A14, A15, A16, A17, A18, A19, A20, A21, A22, A23, A24, A25, A26, A27, A28, A29, A30, A31, A32, A33, Rest...> {     using type = A33; };
    template <typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14, typename A15, typename A16, typename A17, typename A18, typename A19, typename A20, typename A21, typename A22, typename A23, typename A24, typename A25, typename A26, typename A27, typename A28, typename A29, typename A30, typename A31, typename A32, typename A33, typename A34, typename ...Rest> struct at_impl<true, 34, A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13, A14, A15, A16, A17, A18, A19, A20, A21, A22, A23, A24, A25, A26, A27, A28, A29, A30, A31, A32, A33, A34, Rest...> {     using type = A34; };
    template <typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14, typename A15, typename A16, typename A17, typename A18, typename A19, typename A20, typename A21, typename A22, typename A23, typename A24, typename A25, typename A26, typename A27, typename A28, typename A29, typename A30, typename A31, typename A32, typename A33, typename A34, typename A35, typename ...Rest> struct at_impl<true, 35, A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13, A14, A15, A16, A17, A18, A19, A20, A21, A22, A23, A24, A25, A26, A27, A28, A29, A30, A31, A32, A33, A34, A35, Rest...> {     using type = A35; };
    template <typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14, typename A15, typename A16, typename A17, typename A18, typename A19, typename A20, typename A21, typename A22, typename A23, typename A24, typename A25, typename A26, typename A27, typename A28, typename A29, typename A30, typename A31, typename A32, typename A33, typename A34, typename A35, typename A36, typename ...Rest> struct at_impl<true, 36, A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13, A14, A15, A16, A17, A18, A19, A20, A21, A22, A23, A24, A25, A26, A27, A28, A29, A30, A31, A32, A33, A34, A35, A36, Rest...> {     using type = A36; };
    template <typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14, typename A15, typename A16, typename A17, typename A18, typename A19, typename A20, typename A21, typename A22, typename A23, typename A24, typename A25, typename A26, typename A27, typename A28, typename A29, typename A30, typename A31, typename A32, typename A33, typename A34, typename A35, typename A36, typename A37, typename ...Rest> struct at_impl<true, 37, A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13, A14, A15, A16, A17, A18, A19, A20, A21, A22, A23, A24, A25, A26, A27, A28, A29, A30, A31, A32, A33, A34, A35, A36, A37, Rest...> {     using type = A37; };
    template <typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14, typename A15, typename A16, typename A17, typename A18, typename A19, typename A20, typename A21, typename A22, typename A23, typename A24, typename A25, typename A26, typename A27, typename A28, typename A29, typename A30, typename A31, typename A32, typename A33, typename A34, typename A35, typename A36, typename A37, typename A38, typename ...Rest> struct at_impl<true, 38, A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13, A14, A15, A16, A17, A18, A19, A20, A21, A22, A23, A24, A25, A26, A27, A28, A29, A30, A31, A32, A33, A34, A35, A36, A37, A38, Rest...> {     using type = A38; };
    template <typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14, typename A15, typename A16, typename A17, typename A18, typename A19, typename A20, typename A21, typename A22, typename A23, typename A24, typename A25, typename A26, typename A27, typename A28, typename A29, typename A30, typename A31, typename A32, typename A33, typename A34, typename A35, typename A36, typename A37, typename A38, typename A39, typename ...Rest> struct at_impl<true, 39, A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13, A14, A15, A16, A17, A18, A19, A20, A21, A22, A23, A24, A25, A26, A27, A28, A29, A30, A31, A32, A33, A34, A35, A36, A37, A38, A39, Rest...> {     using type = A39; };
    template <typename A0, typename A1, typename A2, typename A3, typename A4, typename A5, typename A6, typename A7, typename A8, typename A9, typename A10, typename A11, typename A12, typename A13, typename A14, typename A15, typename A16, typename A17, typename A18, typename A19, typename A20, typename A21, typename A22, typename A23, typename A24, typename A25, typename A26, typename A27, typename A28, typename A29, typename A30, typename A31, typename A32, typename A33, typename A34, typename A35, typename A36, typename A37, typename A38, typename A39, typename A40, typename ...Rest> struct at_impl<true, 40, A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13, A14, A15, A16, A17, A18, A19, A20, A21, A22, A23, A24, A25, A26, A27, A28, A29, A30, A31, A32, A33, A34, A35, A36, A37, A38, A39, A40, Rest...> {     using type = A40; };
    //////////////////////////////////////////////////////////////////////////
    // END GENERATED OUTPUT
    //////////////////////////////////////////////////////////////////////////
} // end namespace variadic_at_detail

namespace detail {
    /*!
     * @ingroup details
     *
     * Retrieve the `N`th argument from a parameter pack.
     *
     * The complexity is O(n)/k, where k is a large constant.
     */
    template <unsigned long N, typename ...Pack>
    using variadic_at_c = variadic_at_detail::variadic_at_c<N, Pack...>;

    /*!
     * @ingroup details
     * Equivalent to `variadic_at_c<N::value, Pack...>`; provided
     * for convenience.
     */
    template <typename N, typename ...Pack>
    struct variadic_at
        : variadic_at_c<N::value, Pack...>
    { };
} // end namespace detail
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_DETAIL_VARIADIC_AT_HPP
