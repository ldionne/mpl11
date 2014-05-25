#include <boost/mpl11/detail/at_key/multiple_inheritance2.hpp>


template <typename key, typename ...pairs>
using at_key = boost::mpl11::detail::at_key::multiple_inheritance2<key, pairs...>;

<%= render('_main.erb') %>