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

mpl11_add_test(test_container_map       container/map.cpp)
mpl11_add_test(test_container_pair      container/pair.cpp)
mpl11_add_test(test_container_vector    container/vector.cpp)
mpl11_add_test(test_detail_basic_map    detail/basic_map.cpp)
mpl11_add_test(test_detail_nested_apply detail/nested_apply.cpp)
mpl11_add_test(test_has_xxx             has_xxx.cpp)
mpl11_add_test(test_if                  if.cpp)
