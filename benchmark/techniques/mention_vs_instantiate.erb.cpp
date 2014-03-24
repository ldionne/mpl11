<%
    xs = (0..env[:input]).map { |i|
        case env[:config]
        when :mention
            "using Go#{i} = x<#{i}>;"
        when :instantiate
            "using Go#{i} = x<#{i}>::type;"
        end
    }
%>

template <int>
struct x { using type = x; };

<%= xs.join("\n") %>


int main() { }
