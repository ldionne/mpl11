#define BOOST_MPL11_NO_ASSERTIONS
#include <boost/mpl11/detail/right_folds/until_naive.hpp>
#include <boost/mpl11/list.hpp>


<%= render('_main.erb') do |f, state, xs|
  <<-EOS
  boost::mpl11::detail::right_folds::until_naive<
      boost::mpl11::is_empty,
      #{f}::type::apply,
      #{state},
      boost::mpl11::list<#{xs.join(', ')}>
  >
  EOS
end %>