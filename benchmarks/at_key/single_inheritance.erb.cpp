#include <boost/mpl11/detail/at_key/single_inheritance.hpp>


template <typename key, typename ...pairs>
using at_key = boost::mpl11::detail::at_key::single_inheritance<key, pairs...>;

<%= render('_main.erb') %>