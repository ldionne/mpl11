/*!
 * @file
 * Comparison of techniques to implement compile-time logical conjunction.
 */

template <bool Condition, typename Then, typename Else>
struct conditional { using type = Then; };

template <typename Then, typename Else>
struct conditional<false, Then, Else> { using type = Else; };


// #define USE_OVERLOAD
// #define USE_NOEXCEPT
// #define USE_LINEAR_CONSTEXPR
// #define USE_STRUCTS
#define USE_SPECIALIZATION

#if defined(USE_OVERLOAD)

    template <typename ...T>
    constexpr bool all_pointers(T*...) { return true; }

    template <typename ...T>
    constexpr bool all_pointers(T...) { return false; }

    template <typename ...T>
    struct or_ {
        static constexpr bool value = !all_pointers(
            ((typename conditional<T::value, int, void*>::type)0)...
        );
    };

    template <>
    struct or_<> {
        static constexpr bool value = false;
    };

#elif defined(USE_NOEXCEPT)

    void allow_expansion(...) noexcept;

    struct non_throwing { non_throwing() noexcept { } };
    struct throwing { throwing() { throw; } };

    template <typename ...T>
    struct or_ {
        static constexpr bool value = !noexcept(
            allow_expansion(
                typename conditional<
                    T::value, throwing, non_throwing
                >::type{}...
            )
        );
    };

#elif defined(USE_LINEAR_CONSTEXPR)

    // This has horrible performance and we sometimes hit the recursion
    // limit on Clang.
    constexpr bool or_impl() { return false; }

    template <typename ...Tail>
    constexpr bool or_impl(bool head, Tail... tail) {
        return head || or_impl(tail...);
    }

    template <typename ...T>
    struct or_ {
        static constexpr bool value = or_impl(T::value...);
    };

#elif defined(USE_STRUCTS)

    // Surprisingly (for me), this is better than the above solution using
    // constexpr functions, but it still sucks and we hit the recursion limit
    // on Clang quite easily.
    template <typename ...T>
    struct or_ {
        static constexpr bool value = false;
    };

    template <typename Head, typename ...Tail>
    struct or_<Head, Tail...> {
        static constexpr bool value = Head::value || or_<Tail...>::value;
    };

#elif defined(USE_SPECIALIZATION)

    // I don't know why I did not think of this earlier. This is clearly
    // the simplest method and it's also the fastest. lol
    template <typename ...T>
    struct or_ {
        static constexpr bool value = true;
    };

    template <template <bool> class ...Bool>
    struct or_<Bool<false>...> {
        static constexpr bool value = false;
    };

#endif

template <bool B>
struct bool_ { static constexpr bool value = B; };

using true_ = bool_<true>;
using false_ = bool_<false>;

static_assert(!or_<>::value, "");

static_assert( or_<true_>::value, "");
static_assert(!or_<false_>::value, "");

static_assert( or_<true_, true_>::value, "");
static_assert( or_<true_, false_>::value, "");
static_assert( or_<false_, true_>::value, "");
static_assert(!or_<false_, false_>::value, "");


/*

The reported times are the "user" part when running
time clang-3.4 -std=c++11 -Wall -Wextra -pedantic -o /dev/null or_c.cpp
time clang++   -std=c++11 -Wall -Wextra -pedantic -o /dev/null or_c.cpp -ftemplate-depth=500
time g++-4.9   -std=c++11 -Wall -Wextra -pedantic -o /dev/null or_c.cpp

Commands were ran 5 times and the average was taken.


                     | clang v3.4 | Apple LLVM clang 5.0 | GCC 4.9.0 20131110 (experimental) |
----------------------------------------------------------------------------------------------
USE_OVERLOAD         |    0.03s   |         0.02s        |               0.04s               |
USE_NOEXCEPT         |    0.04s   |         0.02s        |               0.03s               |
USE_LINEAR_CONSTEXPR |    0.17s   |         0.08s(*)     |               0.20s               |
USE_STRUCTS          |    0.09s   |         0.05s(*)     |               0.07s               |
USE_SPECIALIZATION   |    0.02s   |         0.02s        |               0.03s               |

(*) -ftemplate-depth=500 is required to avoid hitting the recursive template instantiation limit.

*/

// ruby -e "puts ((0..200).collect{'false_'} << 'true_').join(', ')" | pbcopy
static_assert(
    or_<
        false_, false_, false_, false_, false_, false_, false_, false_, false_, false_, false_, false_, false_, false_, false_, false_, false_, false_, false_, false_, false_, false_, false_, false_, false_, false_, false_, false_, false_, false_, false_, false_, false_, false_, false_, false_, false_, false_, false_, false_, false_, false_, false_, false_, false_, false_, false_, false_, false_, false_, false_, false_, false_, false_, false_, false_, false_, false_, false_, false_, false_, false_, false_, false_, false_, false_, false_, false_, false_, false_, false_, false_, false_, false_, false_, false_, false_, false_, false_, false_, false_, false_, false_, false_, false_, false_, false_, false_, false_, false_, false_, false_, false_, false_, false_, false_, false_, false_, false_, false_, false_, false_, false_, false_, false_, false_, false_, false_, false_, false_, false_, false_, false_, false_, false_, false_, false_, false_, false_, false_, false_, false_, false_, false_, false_, false_, false_, false_, false_, false_, false_, false_, false_, false_, false_, false_, false_, false_, false_, false_, false_, false_, false_, false_, false_, false_, false_, false_, false_, false_, false_, false_, false_, false_, false_, false_, false_, false_, false_, false_, false_, false_, false_, false_, false_, false_, false_, false_, false_, false_, false_, false_, false_, false_, false_, false_, false_, false_, false_, false_, false_, false_, false_, false_, false_, false_, false_, false_, false_, false_, false_, false_, false_, false_, false_, false_, false_, false_, false_, false_, false_, true_
    >::value
, "");


int main() { }
