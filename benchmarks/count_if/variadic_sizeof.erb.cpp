#include <boost/mpl11/detail/count_if/variadic_sizeof.hpp>


template <template <typename ...> class pred, typename ...xs>
using count_if = boost::mpl11::detail::count_if::variadic_sizeof<pred, xs...>;

<%= render('_main.erb') %>