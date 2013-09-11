#ifndef BOOST_MPL11_TEST_FUNCTIONAL_METAFUNCTION_CLASSES_HPP
#define BOOST_MPL11_TEST_FUNCTIONAL_METAFUNCTION_CLASSES_HPP

struct with_nested_type {
    struct non_template { struct apply { struct type; }; };
    struct variadic { template <typename ...> struct apply { struct type; }; };
    struct unary { template <typename> struct apply { struct type; }; };
    struct binary
    { template <typename, typename> struct apply { struct type; }; };
};

struct without_nested_type {
    struct non_template { struct apply { }; };
    struct variadic { template <typename ...> struct apply { }; };
    struct unary { template <typename> struct apply { }; };
    struct binary { template <typename, typename> struct apply { }; };
};

struct with_incomplete_apply {
    struct non_template { struct apply; };
    struct variadic { template <typename ...> struct apply; };
    struct unary { template <typename> struct apply; };
    struct binary { template <typename, typename> struct apply; };
};

#endif // !BOOST_MPL11_TEST_FUNCTIONAL_METAFUNCTION_CLASSES_HPP
