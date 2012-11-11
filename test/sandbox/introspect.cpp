/**
 * This file defines unit tests for the @em introspect metafunction.
 */

#include <mpl11/sandbox/introspect.hpp>

#include <type_traits>


using namespace mpl11;
using namespace mpl11::sandbox;

#define ASSERT_SAME(a, b) static_assert(std::is_same<a, b>::value,          \
                                        STRINGIZE(a is not the same as b))
#define STRINGIZE(x) #x


struct empty { };
using MemberFunction = int (empty::*)();
using MemberPointer = int empty::*;
using Function = int (char);
union Union { };
enum Enum { };
enum class EnumClass { };

// Make sure types are dispatched to the right specialization.
using namespace types;

template <typename T, typename Category>
struct check_for {
    // For function types, dum out the test for arrays because we can't make
    // arrays of functions.
    using T_for_array = typename std::conditional<
                                    std::is_function<T>::value, int, T>::type;
    template <typename U>
    using introspect_type = typename introspect<U>::type;
    ASSERT_SAME(introspect_type<T>, Category);
    ASSERT_SAME(introspect_type<T_for_array[]>, array);
    ASSERT_SAME(introspect_type<T_for_array[10]>, array);
    ASSERT_SAME(introspect_type<T*>, pointer);
    ASSERT_SAME(introspect_type<T&>, lvalue_reference);
    ASSERT_SAME(introspect_type<T&&>, rvalue_reference);
};

check_for<int, primitive> a;
check_for<MemberFunction, member_function_pointer> b;
check_for<MemberPointer, member_object_pointer> c;
check_for<Function, function> d;
check_for<Union, union_> e;
check_for<Enum, enumeration> f;
check_for<EnumClass, enumeration> g;
check_for<empty, class_or_struct> h;
ASSERT_SAME(introspect<int const>::type, constant);
ASSERT_SAME(introspect<int volatile>::type, volatile_);
ASSERT_SAME(introspect<int const volatile>::type, constant_volatile);
ASSERT_SAME(introspect<void>::type, primitive);

// Make sure type parsing nests correctly.
using Complicated = Function* (&&)(MemberPointer, MemberFunction&&);
using Introspected = introspect<Complicated>;
ASSERT_SAME(Introspected::self, Complicated);
ASSERT_SAME(Introspected::type, rvalue_reference);
ASSERT_SAME(Introspected::referee::result::self, Function*);
ASSERT_SAME(Introspected::referee::arg<2>::self, MemberFunction&&);
