template <unsigned i>
struct metafunction
    : metafunction<i - 1>
{ };

template <>
struct metafunction<0> { using type = metafunction; };

using go = metafunction<    <%= n %>    >::type;