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


mpl11_add_test(comparable                   comparable.cpp)
mpl11_add_test(core_box                     core/box.cpp)
mpl11_add_test(core_datatype                core/datatype.cpp)
mpl11_add_test(detail_std_conditional       detail/std_conditional.cpp)
mpl11_add_test(detail_std_is_same           detail/std_is_same.cpp)
mpl11_add_test(detail_strict_variadic_foldl detail/strict_variadic_foldl.cpp)
mpl11_add_test(enumerable                   enumerable.cpp)
mpl11_add_test(functional_always            functional/always.cpp)
mpl11_add_test(functional_apply             functional/apply.cpp)
mpl11_add_test(functional_argmap            functional/argmap.cpp)
mpl11_add_test(functional_bind              functional/bind.cpp)
mpl11_add_test(functional_compose           functional/compose.cpp)
mpl11_add_test(functional_fix               functional/fix.cpp)
mpl11_add_test(functional_flip              functional/flip.cpp)
mpl11_add_test(functional_id                functional/id.cpp)
mpl11_add_test(functional_into              functional/into.cpp)
mpl11_add_test(functional_on                functional/on.cpp)
mpl11_add_test(functional_partial           functional/partial.cpp)
mpl11_add_test(functional_quote             functional/quote.cpp)
mpl11_add_test(functor                      functor.cpp)
mpl11_add_test(integral_c                   integral_c.cpp)
mpl11_add_test(logical_and_or               logical/and_or.cpp)
mpl11_add_test(logical_if                   logical/if.cpp)
mpl11_add_test(logical_not                  logical/not.cpp)
mpl11_add_test(master_header                master_header.cpp)
mpl11_add_test(orderable                    orderable.cpp)
