#=============================================================================
# Setup unit tests
#=============================================================================
add_custom_target(unit COMMENT "Build all the unit tests.")

function(mpl11_add_test name sources)
    # We compile each unit test with the possible combinations of options
    # found in boost/mpl11/detail/config.hpp.
    #
    # For lack of a better solution, I currently create different targets for
    # each configuration.
    # A - BOOST_MPL11_NO_ASSERTIONS
    # R - BOOST_MPL11_NO_RULES
    add_executable(${name}_AR ${sources})
    add_executable(${name}_A ${sources})
    add_executable(${name}_R ${sources})
    add_executable(${name} ${sources})

    set_target_properties(${name}_R PROPERTIES
        COMPILE_DEFINITIONS BOOST_MPL11_NO_RULES)
    set_target_properties(${name}_A PROPERTIES
            COMPILE_DEFINITIONS BOOST_MPL11_NO_ASSERTIONS)
    set_target_properties(${name}_AR PROPERTIES
        COMPILE_DEFINITIONS BOOST_MPL11_NO_RULES
        COMPILE_DEFINITIONS BOOST_MPL11_NO_ASSERTIONS)

    add_custom_target(${name}_all_cfgs)
    add_dependencies(${name}_all_cfgs
        ${name} ${name}_A ${name}_R ${name}_AR)
    add_dependencies(unit ${name}_all_cfgs)
endfunction()


mpl11_add_test(comparable                   comparable.cpp)
mpl11_add_test(core_box                     core/box.cpp)
mpl11_add_test(core_cast                    core/cast.cpp)
mpl11_add_test(core_common_datatype         core/common_datatype.cpp)
mpl11_add_test(core_datatype                core/datatype.cpp)
mpl11_add_test(core_foreign                 core/foreign.cpp)
mpl11_add_test(detail_std_conditional       detail/std_conditional.cpp)
mpl11_add_test(detail_std_equal             detail/std_equal.cpp)
mpl11_add_test(detail_std_is_same           detail/std_is_same.cpp)
mpl11_add_test(detail_strict_variadic_foldl detail/strict_variadic_foldl.cpp)
mpl11_add_test(enumerable                   enumerable.cpp)
mpl11_add_test(field                        field.cpp)
mpl11_add_test(foldable                     foldable.cpp)
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
mpl11_add_test(group                        group.cpp)
mpl11_add_test(integer                      integer.cpp)
mpl11_add_test(integral_domain              integral_domain.cpp)
mpl11_add_test(iterable                     iterable.cpp)
mpl11_add_test(list                         list.cpp)
mpl11_add_test(logical_and_or               logical/and_or.cpp)
mpl11_add_test(logical_if                   logical/if.cpp)
mpl11_add_test(logical_not                  logical/not.cpp)
mpl11_add_test(master_header                master_header.cpp)
mpl11_add_test(monoid                       monoid.cpp)
mpl11_add_test(orderable                    orderable.cpp)
mpl11_add_test(ring                         ring.cpp)
