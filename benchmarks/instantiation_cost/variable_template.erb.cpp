template <int>
constexpr int x{};


int main() {
    <%= 1.upto(breadth).map { |n| "(void)x<#{n}>;" }.join("\n") %>
}
