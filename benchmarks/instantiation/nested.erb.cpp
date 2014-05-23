template <unsigned i>
struct metafunction {
    using type = typename metafunction<i - 1>::type;
};

template <>
struct metafunction<0> { using type = metafunction; };

using go = metafunction<    <%= n %>      >::type;