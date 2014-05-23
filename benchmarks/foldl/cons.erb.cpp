#define BOOST_MPL11_NO_ASSERTIONS
#include <boost/mpl11/list.hpp>


<%= render('_main.erb') do |f, state, xs|
    cons = xs.foldr("boost::mpl11::list<>") { |x, tail|
      "boost::mpl11::cons<#{x}, #{tail}>"
    }
    "boost::mpl11::foldl<#{f}, #{state}, #{cons}>"
end %>