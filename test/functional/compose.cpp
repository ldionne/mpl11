/*!
 * @file
 * Contains unit tests for `boost::mpl11::compose`.
 */

#include <boost/mpl11/functional.hpp>

#include <boost/mpl11/detail/std_is_same.hpp>


using namespace boost::mpl11;
using detail::std_is_same;

struct w { using type = w; };
struct x { using type = x; };
struct y { using type = y; };
template <typename ...xs> struct f { using type = f<typename xs::type...>; };
template <typename ...xs> struct g { using type = g<typename xs::type...>; };
template <typename ...xs> struct h { using type = h<typename xs::type...>; };

template <template <typename ...> class ...fs>
struct composing {
    template <typename ...args>
    struct with {
        template <typename result>
        struct is : composing {
            static_assert(std_is_same<
                typename compose<quote<fs>...>::type::
                template apply<args...>::type,
                result
            >::value, "");
        };
    };
};

struct tests
    : composing<f>
        ::with<>::is<f<>>
        ::with<w>::is<f<w>>
        ::with<w, x>::is<f<w, x>>
        ::with<w, x, y>::is<f<w, x, y>>

    , composing<f, g>
        ::with<>::is<f<g<>>>
        ::with<w>::is<f<g<w>>>
        ::with<w, x>::is<f<g<w>, x>>
        ::with<w, x, y>::is<f<g<w>, x, y>>

    , composing<f, g, h>
        ::with<>::is<f<g<h<>>>>
        ::with<w>::is<f<g<h<w>>>>
        ::with<w, x>::is<f<g<h<w>>, x>>
        ::with<w, x, y>::is<f<g<h<w>>, x, y>>
{ };


int main() { }
