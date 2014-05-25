#include <boost/mpl11/detail/count_if/variadic_sum.hpp>


template <template <typename ...> class pred, typename ...xs>
using count_if = boost::mpl11::detail::count_if::variadic_sum<pred, xs...>;

<%= render('_main.erb') %>