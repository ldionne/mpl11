#define BOOST_MPL11_NO_ASSERTIONS
#include <boost/mpl11/detail/left_folds/bounded.hpp>
#include <boost/mpl11/list.hpp>


<%= render('_main.erb') do |f, state, xs|
    list = "boost::mpl11::list<#{xs.join(', ')}>"
    <<-EOS
    boost::mpl11::detail::left_folds::bounded<
        #{xs.size}, #{f}::type::apply, #{state}, #{list}
    >
    EOS
end %>