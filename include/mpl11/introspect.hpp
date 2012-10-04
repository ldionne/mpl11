/**
 * This file defines the @em introspect metafunction.
 */

#ifndef MPL11_INTROSPECT_HPP
#define MPL11_INTROSPECT_HPP

#include <mpl11/apply.hpp>
#include <mpl11/arg.hpp>
#include <mpl11/if.hpp>

#include <cstddef>
#include <type_traits>


namespace mpl11 {

namespace types {
    struct primitive { };
    struct pointer { };
    struct lvalue_reference { };
    struct rvalue_reference { };
    struct array { };
    struct member_function_pointer { };
    struct member_object_pointer { };
    struct function { };
    struct enumeration { };
    struct union_ { };
    struct class_or_struct { };
    struct constant { };
    struct volatile_ { };
    struct constant_volatile { };
}

namespace detail {
    // Enumeration
    template <typename T>
    struct introspect_enum {
        using type = types::enumeration;
        using self = T;
    };

    // Union
    template <typename T>
    struct introspect_union {
        using type = types::union_;
        using self = T;
    };

    // Class or struct
    template <typename T>
    struct introspect_class_or_struct {
        static_assert(std::is_class<T>::value,
                      "invalid fall through for introspect's dispatcher");
        using type = types::class_or_struct;
        using self = T;
    };
} // end namespace detail

// Dispatch yet unknown types
template <typename T>
struct introspect
    :        if_<typename std::is_enum<T>::type, detail::introspect_enum<T>,
    typename if_<typename std::is_union<T>::type, detail::introspect_union<T>,
          /* else */                    detail::introspect_class_or_struct<T>
    >::type>::type
{ };


// Primitive
namespace detail {
    template <typename T>
    struct primitive_base {
        using type = types::primitive;
        using self = T;
    };
}
#define MPL11_I_DECLARE_PRIMITIVE(T) \
    template <> struct introspect<T> : detail::primitive_base<T> { }
MPL11_I_DECLARE_PRIMITIVE(bool);
MPL11_I_DECLARE_PRIMITIVE(char);
MPL11_I_DECLARE_PRIMITIVE(short);
MPL11_I_DECLARE_PRIMITIVE(int);
MPL11_I_DECLARE_PRIMITIVE(long);
MPL11_I_DECLARE_PRIMITIVE(float);
MPL11_I_DECLARE_PRIMITIVE(double);
MPL11_I_DECLARE_PRIMITIVE(void);
#undef MPL11_I_DECLARE_PRIMITIVE


// Pointer
template <typename T>
struct introspect<T*> {
    using type = types::pointer;
    using self = T*;
    using pointee = introspect<T>;
};


// Lvalue reference
template <typename T>
struct introspect<T&> {
    using type = types::lvalue_reference;
    using self = T&;
    using referee = introspect<T>;
};


// Rvalue reference
template <typename T>
struct introspect<T&&> {
    using type = types::rvalue_reference;
    using self = T&&;
    using referee = introspect<T>;
};


// Array
template <typename T>
struct introspect<T[]> {
    using type = types::array;
    using self = T[];
    using value = introspect<T>;
};

template <typename T, std::size_t n>
struct introspect<T[n]> {
    using type = types::array;
    using self = T[n];
    using value = introspect<T>;
};


// Constant
template <typename T>
struct introspect<T const> {
    using type = types::constant;
    using self = T const;
    using raw = introspect<T>;
};


// Volatile
template <typename T>
struct introspect<T volatile> {
    using type = types::volatile_;
    using self = T volatile;
    using raw = introspect<T>;
};


// Constant volatile
template <typename T>
struct introspect<T const volatile> {
    using type = types::constant_volatile;
    using self = T const volatile;
    using constant = introspect<T const>;
    using volatile_ = introspect<T volatile>;
    using raw = introspect<T>;
};


namespace detail {
    /**
     * Return the (i-1)th argument after introspecting it.
     */
    template <std::size_t i, typename ...Args>
    using introspect_at = introspect<typename apply<arg<i>, Args...>::type>;
}


// Member function pointer
template <typename Tag, typename Result, typename ...Args>
struct introspect<Result (Tag::*)(Args...)> {
    using type = types::member_function_pointer;
    using self = Result (Tag::*)(Args...);
    using result = introspect<Result>;
    using tag = introspect<Tag>;
    template <std::size_t i> using arg = detail::introspect_at<i, Args...>;
};


// Member object pointer
template <typename Tag, typename T>
struct introspect<T Tag::*> {
    using type = types::member_object_pointer;
    using self = T Tag::*;
    using member = introspect<T>;
    using tag = introspect<Tag>;
};


// Function
template <typename Result, typename ...Args>
struct introspect<Result (Args...)> {
    using type = types::function;
    using self = Result (Args...);
    using result = introspect<Result>;
    template <std::size_t i> using arg = detail::introspect_at<i, Args...>;
};

} // end namespace mpl11

#endif // !MPL11_INTROSPECT_HPP
