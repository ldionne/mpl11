<%
    @env = env
    n = @env.input
    xs = (0...n).collect{ |i| "x<#{i}>" }.join(", ")

    @headers = {
        "mpl11::list" => "<boost/mpl11/list.hpp>",
        "mpl::vector" => "<boost/mpl/vector/vector#{n.round_up(1)}.hpp>",
        "mpl::list"   => "<boost/mpl/list/list#{n.round_up(1)}.hpp>"
    }

    @datasets = {
        "mpl11::list" => "boost::mpl11::list_<#{xs}>",
        "mpl::vector" => "boost::mpl::vector#{n}<#{xs}>",
        "mpl::list"   => "boost::mpl::list#{n}<#{xs}>"
    }

    def rules
        "#define BOOST_MPL11_NO_REWRITE_RULES" unless @env.rules
    end

    def headers
        @headers.select { |config, hdrs| @env.fair || @env.config === config }
                .values
                .flatten
                .map(&"#include ".method(:+))
                .join("\n")
    end

    def dataset
        "using dataset = #{@datasets[@env.config]};"
    end

    def mpl_include header
        "#include #{header}" if @env.fair || @env.config =~ /^mpl::/
    end
%>

template <unsigned> struct x;

struct f {
    using type = f;
    template <typename ...>
    struct apply { struct type; };
};

struct g {
    using type = g;
    template <typename ...>
    struct apply { struct type; };
};

<%= rules %>
<%= headers %>
<%= dataset %>

<%
case env.operation
    when :fmap, :fmap_nested
%>


    <%= mpl_include("<boost/mpl/transform.hpp>") %>
    <% if env.config =~ /^mpl::/ %>
        template <typename f, typename dataset>
        using fmap = typename boost::mpl::transform<dataset, f>::type;
    <% else %>
        using boost::mpl11::fmap;
    <% end %>

    <% if env.operation == :fmap %>
        using Go = fmap<f, dataset>::type;
    <% elsif env.operation == :fmap_nested %>
        using Go = fmap<f, fmap<g, dataset>>::type;
    <% end %>


<% when :at %>


    <%= mpl_include("<boost/mpl/at.hpp>") %>
    <% if env.config =~ /^mpl::/ %>
        using boost::mpl::at_c;
    <% else %>
        template <typename xs, unsigned long n>
        using at_c = boost::mpl11::at_c<n, xs>;
    <% end %>

    using Go = at_c<dataset,   <%= n-1 %>      >::type;


<% when :foldl %>


    struct state { struct type; };

    <%= mpl_include("<boost/mpl/fold.hpp>") %>
    <% if env.config =~ /^mpl::/ %>
        template <typename f, typename state, typename xs>
        using foldl = boost::mpl::fold<xs, state, f>;
    <% else %>
        using boost::mpl11::foldl;
    <% end %>

    using Go = foldl<f, state, dataset>::type;


<% end %>
