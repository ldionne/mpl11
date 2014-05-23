#include <boost/mpl11/detail/at_index/multiple_inheritance2.hpp>


using size_t = decltype(sizeof(int));

template <size_t n, typename ...xs>
using at_index = boost::mpl11::detail::at_index::multiple_inheritance2<n, xs...>;

<%= render('_main.erb') %>