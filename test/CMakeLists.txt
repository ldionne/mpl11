#=============================================================================
# Setup unit tests
#=============================================================================
add_custom_target(unit COMMENT "build all the unit tests")
add_custom_target(check
    DEPENDS unit
    COMMAND ${CMAKE_CTEST_COMMAND}
    COMMENT "build and then run all the unit tests"
)

function(mpl11_add_test name sources)
    add_executable(${name} EXCLUDE_FROM_ALL ${sources})
    add_test(NAME ${name} COMMAND ${name})
    add_dependencies(unit ${name})
endfunction()


mpl11_add_test(algorithm_advance         algorithm/advance.cpp)
mpl11_add_test(always                    always.cpp)
mpl11_add_test(apply_wrap                apply_wrap.cpp)
mpl11_add_test(arg                       arg.cpp)
mpl11_add_test(as_placeholder            as_placeholder.cpp)
mpl11_add_test(bind                      bind.cpp)
mpl11_add_test(container_vector          container/vector.cpp)
mpl11_add_test(detail_best_category_for  detail/best_category_for.cpp)
mpl11_add_test(detail_either             detail/either.cpp)
mpl11_add_test(detail_has_xxx            detail/has_xxx.cpp)
mpl11_add_test(detail_is_same            detail/is_same.cpp)
mpl11_add_test(detail_nested_apply       detail/nested_apply.cpp)
mpl11_add_test(detail_tag_dispatched     detail/tag_dispatched.cpp)
mpl11_add_test(detail_variadic_at        detail/variadic_at.cpp)
mpl11_add_test(if                        if.cpp)
mpl11_add_test(integral_c                integral_c.cpp)
mpl11_add_test(intrinsic_and             intrinsic/and.cpp)
mpl11_add_test(intrinsic_not             intrinsic/not.cpp)
mpl11_add_test(intrinsic_or              intrinsic/or.cpp)
mpl11_add_test(is_placeholder_expression is_placeholder_expression.cpp)
mpl11_add_test(lambda                    lambda.cpp)
mpl11_add_test(pair                      pair.cpp)
mpl11_add_test(quote                     quote.cpp)
