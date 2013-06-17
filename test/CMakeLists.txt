#=============================================================================
# Setup unit tests
#=============================================================================
find_package(Boost 1.53 REQUIRED)

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

mpl11_add_test(test_and                             and.cpp)
mpl11_add_test(test_container_map                   container/map.cpp)
mpl11_add_test(test_container_pair                  container/pair.cpp)
mpl11_add_test(test_container_set                   container/set.cpp)
mpl11_add_test(test_container_variadic              container/variadic.cpp)
mpl11_add_test(test_container_vector                container/vector.cpp)
mpl11_add_test(test_detail_basic_map                detail/basic_map.cpp)
mpl11_add_test(test_detail_nested_apply             detail/nested_apply.cpp)
mpl11_add_test(test_detail_wrap_with                detail/wrap_with.cpp)
mpl11_add_test(test_eval                            eval.cpp)
mpl11_add_test(test_has_xxx                         has_xxx.cpp)
mpl11_add_test(test_if                              if.cpp)
mpl11_add_test(test_integral_c                      integral_c.cpp)
mpl11_add_test(test_is_same                         is_same.cpp)
mpl11_add_test(test_lambda                          lambda.cpp)
mpl11_add_test(test_not                             not.cpp)
mpl11_add_test(test_or                              or.cpp)
mpl11_add_test(test_trait_dispatcher_of             trait/dispatcher_of.cpp)
mpl11_add_test(test_trait_is_inplace_transformation trait/is_inplace_transformation.cpp)
mpl11_add_test(test_trait_is_placeholder            trait/is_placeholder.cpp)
