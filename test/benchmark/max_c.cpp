/*!
 * @file
 * Comparison of techniques to implement compile-time extrema computations.
 */


#define USE_UNION
// #define USE_RECURSIVE_STRUCTS

#if defined(USE_UNION) || defined(USE_RECURSIVE_STRUCTS)

    template <long a0, long a1, long ...aN>
    struct max_c
        : max_c<a0, max_c<a1, aN...>::value>
    { };

    template <long a0, long a1>
    struct max_c<a0, a1> {
        static constexpr long value = a0 < a1 ? a1 : a0;
    };

    #if defined(USE_UNION)

        template <long a0, long a1, long a2, long a3, long a4, long a5, long a6>
        union alignas(char) batch_max_impl {
            char _a0[a0+1];
            char _a1[a1+1];
            char _a2[a2+1];
            char _a3[a3+1];
            char _a4[a4+1];
            char _a5[a5+1];
            char _a6[a6+1];
        };

        template <long ...ai>
        using batch_max = max_c<
            // The maximum of all the positive integers.
            sizeof(batch_max_impl<(ai < 0 ? 0 : ai)...>) - 1,

            // The minimum of all the negative integers.
            -(sizeof(batch_max_impl<(ai < 0 ? -ai : 0)...>) - 1)
        >;

        template <long a0, long a1, long a2, long a3, long a4, long a5, long a6>
        struct max_c<a0, a1, a2, a3, a4, a5, a6>
            : batch_max<a0, a1, a2, a3, a4, a5, a6>
        { };

        template <
            long a0, long a1, long a2, long a3, long a4, long a5, long a6,
            long a7, long ...aN
        >
        struct max_c<a0, a1, a2, a3, a4, a5, a6, a7, aN...>
            : max_c<max_c<a0, a1, a2, a3, a4, a5, a6>::value, a7, aN...>
        { };

    #endif

#endif

static_assert(max_c<-1, 0>::value == 0, "");
static_assert(max_c<-1, 1>::value == 1, "");
static_assert(max_c<-1, -4>::value == -1, "");

static_assert(max_c<0, 0>::value == 0, "");
static_assert(max_c<0, 1>::value == 1, "");
static_assert(max_c<1, 0>::value == 1, "");
static_assert(max_c<1, 1>::value == 1, "");

static_assert(max_c<0, 1, 2>::value == 2, "");
static_assert(max_c<0, 1, 2, 3>::value == 3, "");
static_assert(max_c<0, 4, 2, 3>::value == 4, "");
static_assert(max_c<0, 1, 2, 3, 2, 3>::value == 3, "");


/*

The reported times are the "user" part when running
time clang-3.4 -std=c++11 -Wall -Wextra -pedantic -o /dev/null max_c.cpp -ftemplate-depth=500 -fconstexpr-depth=500
time clang++   -std=c++11 -Wall -Wextra -pedantic -o /dev/null max_c.cpp -ftemplate-depth=500 -fconstexpr-depth=500
time g++-4.9   -std=c++11 -Wall -Wextra -pedantic -o /dev/null max_c.cpp -ftemplate-depth=500 -fconstexpr-depth=500

Commands were ran 5 times and the average was taken.

Summing up to 1000         | clang v3.4  | Apple LLVM clang 5.0 | GCC 4.9.0 20131201 (experimental) |
-----------------------------------------------------------------------------------------------------
USE_UNION                  |    0.16s    |         0.07s        |               0.11s               |
USE_RECURSIVE_STRUCTS      |    0.33s[1] |         0.15s[1]     |               0.31s               |

[1] Constexpr / template depth modification is required to avoid hitting the limit.

*/

/*
#!/usr/bin/env ruby
ints = (0..500).collect.shuffle
puts "static_assert(max_c<#{ints.join(', ')}>::value == #{ints.max}, \"\");"
*/

static_assert(max_c<325, 444, 296, 218, 36, 383, 6, 85, 431, 369, 78, 26, 187, 87, 481, 279, 143, 7, 208, 45, 0, 219, 395, 9, 225, 470, 353, 144, 424, 259, 215, 466, 386, 18, 183, 440, 247, 281, 141, 323, 102, 420, 91, 461, 246, 330, 82, 136, 138, 71, 38, 129, 126, 207, 445, 74, 432, 198, 359, 97, 104, 67, 210, 389, 274, 298, 65, 262, 378, 151, 111, 188, 245, 156, 15, 127, 221, 460, 366, 270, 174, 393, 58, 23, 411, 360, 223, 63, 256, 13, 93, 314, 189, 329, 254, 477, 197, 114, 425, 465, 271, 364, 488, 134, 252, 331, 171, 248, 398, 166, 415, 200, 363, 137, 371, 202, 239, 309, 448, 358, 287, 406, 498, 4, 146, 487, 167, 474, 161, 95, 258, 401, 318, 128, 255, 345, 230, 496, 455, 251, 70, 184, 125, 272, 169, 81, 25, 228, 336, 103, 414, 482, 190, 497, 372, 253, 165, 158, 315, 3, 220, 213, 312, 76, 34, 160, 148, 54, 209, 437, 112, 162, 310, 399, 341, 307, 250, 429, 326, 327, 275, 57, 48, 233, 159, 28, 214, 400, 30, 382, 12, 121, 413, 227, 357, 365, 99, 10, 80, 31, 268, 384, 311, 379, 175, 283, 351, 33, 147, 204, 301, 441, 168, 47, 201, 199, 241, 354, 75, 265, 41, 356, 346, 347, 8, 321, 337, 412, 163, 417, 192, 423, 109, 69, 483, 404, 238, 118, 24, 186, 289, 231, 472, 416, 203, 20, 320, 86, 195, 49, 469, 237, 157, 263, 240, 324, 59, 288, 100, 402, 447, 55, 61, 459, 16, 338, 355, 385, 267, 291, 458, 66, 344, 475, 44, 224, 64, 370, 334, 302, 206, 478, 266, 257, 35, 457, 426, 176, 1, 374, 182, 115, 11, 322, 362, 236, 98, 177, 32, 181, 243, 94, 313, 428, 212, 479, 242, 191, 60, 333, 419, 295, 304, 284, 495, 335, 492, 72, 376, 339, 299, 450, 422, 135, 56, 328, 308, 484, 403, 116, 14, 107, 343, 50, 397, 142, 368, 446, 193, 249, 73, 388, 185, 21, 92, 436, 90, 234, 120, 132, 464, 124, 155, 196, 117, 390, 53, 410, 282, 194, 342, 350, 494, 408, 433, 244, 108, 476, 235, 173, 443, 285, 454, 493, 62, 300, 293, 154, 5, 303, 489, 471, 29, 452, 232, 438, 122, 277, 500, 133, 83, 348, 373, 211, 442, 486, 89, 77, 491, 205, 2, 229, 172, 164, 149, 110, 405, 178, 280, 394, 105, 96, 276, 421, 409, 273, 42, 434, 79, 222, 396, 106, 361, 462, 456, 217, 226, 463, 113, 451, 427, 19, 260, 367, 349, 152, 290, 68, 332, 278, 480, 449, 439, 387, 52, 37, 84, 473, 490, 305, 216, 119, 51, 130, 88, 17, 269, 468, 150, 46, 380, 145, 316, 297, 375, 180, 140, 286, 22, 40, 294, 170, 381, 317, 123, 319, 179, 139, 292, 101, 391, 340, 264, 418, 261, 131, 499, 435, 43, 485, 453, 377, 430, 407, 352, 392, 27, 39, 306, 153, 467>::value == 500, "");


int main() { }
