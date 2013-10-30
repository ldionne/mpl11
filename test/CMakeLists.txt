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


mpl11_add_test(always                   always.cpp)
mpl11_add_test(apply_wrap               apply_wrap.cpp)
mpl11_add_test(bidirectional_iterator   bidirectional_iterator.cpp)
mpl11_add_test(class_of                 class_of.cpp)
mpl11_add_test(detail_conditional       detail/conditional.cpp)
mpl11_add_test(detail_either            detail/either.cpp)
mpl11_add_test(detail_is_same           detail/is_same.cpp)
mpl11_add_test(detail_is_specialization detail/is_specialization.cpp)
mpl11_add_test(detail_move              detail/move.cpp)
mpl11_add_test(empty_base               empty_base.cpp)
mpl11_add_test(forward_iterator         forward_iterator.cpp)
mpl11_add_test(identity                 identity.cpp)
mpl11_add_test(if                       if.cpp)
mpl11_add_test(integral_c               integral_c.cpp)
mpl11_add_test(master_header            master_header.cpp)
mpl11_add_test(pair                     pair.cpp)
mpl11_add_test(quote                    quote.cpp)
