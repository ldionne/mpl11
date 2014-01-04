#=============================================================================
# Setup unit tests
#=============================================================================
add_custom_target(unit COMMENT "Build all the unit tests.")

function(mpl11_add_test name sources)
    # For each unit test, we compile with and without the assertions.
    # Since I'm not a CMake pro, I currently create two different targets.
    add_executable(${name}_without_assertions ${sources})

    add_executable(${name}_with_assertions ${sources})
    set_target_properties(
        ${name}_with_assertions PROPERTIES
            COMPILE_DEFINITIONS BOOST_MPL11_ENABLE_ASSERTIONS
    )

    add_custom_target(${name})
    add_dependencies(${name}
        ${name}_with_assertions
        ${name}_without_assertions
    )
    add_dependencies(unit ${name})
endfunction()


mpl11_add_test(always                   always.cpp)
mpl11_add_test(and_or                   and_or.cpp)
mpl11_add_test(apply                    apply.cpp)
mpl11_add_test(arg                      arg.cpp)
mpl11_add_test(arithmetic               arithmetic.cpp)
mpl11_add_test(bitwise                  bitwise.cpp)
mpl11_add_test(comparable               comparable.cpp)
mpl11_add_test(compose                  compose.cpp)
mpl11_add_test(cons                     cons.cpp)
mpl11_add_test(detail_conditional       detail/conditional.cpp)
mpl11_add_test(detail_index_sequence    detail/index_sequence.cpp)
mpl11_add_test(detail_is_same           detail/is_same.cpp)
mpl11_add_test(detail_is_specialization detail/is_specialization.cpp)
mpl11_add_test(detail_variadic_last     detail/variadic_last.cpp)
mpl11_add_test(drop                     drop.cpp)
mpl11_add_test(empty_base               empty_base.cpp)
mpl11_add_test(empty_sequence           empty_sequence.cpp)
mpl11_add_test(enumerable               enumerable.cpp)
mpl11_add_test(flip                     flip.cpp)
mpl11_add_test(foldl                    foldl.cpp)
mpl11_add_test(identity                 identity.cpp)
mpl11_add_test(if                       if.cpp)
mpl11_add_test(inherit                  inherit.cpp)
mpl11_add_test(integral                 integral.cpp)
mpl11_add_test(integral_c               integral_c.cpp)
mpl11_add_test(into                     into.cpp)
mpl11_add_test(iterate                  iterate.cpp)
mpl11_add_test(list                     list.cpp)
mpl11_add_test(master_header            master_header.cpp)
mpl11_add_test(not                      not.cpp)
mpl11_add_test(orderable                orderable.cpp)
mpl11_add_test(partial                  partial.cpp)
mpl11_add_test(quote                    quote.cpp)
mpl11_add_test(repeat                   repeat.cpp)
mpl11_add_test(scanl                    scanl.cpp)
mpl11_add_test(sequence                 sequence.cpp)
mpl11_add_test(tag_of                   tag_of.cpp)
mpl11_add_test(take                     take.cpp)
mpl11_add_test(take_while               take_while.cpp)
