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

    add_dependencies(${name} ${name}_A ${name}_R ${name}_AR)
    add_dependencies(unit ${name})
endfunction()


mpl11_add_test(bitwise                      bitwise.cpp)
mpl11_add_test(comparable                   comparable.cpp)
mpl11_add_test(core-box                     core/box.cpp)
mpl11_add_test(core-cast                    core/cast.cpp)
mpl11_add_test(core-common_datatype         core/common_datatype.cpp)
mpl11_add_test(core-datatype                core/datatype.cpp)
mpl11_add_test(core-foreign                 core/foreign.cpp)
mpl11_add_test(detail-std_conditional       detail/std_conditional.cpp)
mpl11_add_test(detail-std_index_sequence    detail/std_index_sequence.cpp)
mpl11_add_test(detail-std_is_same           detail/std_is_same.cpp)
mpl11_add_test(detail-strict_variadic_foldl detail/strict_variadic_foldl.cpp)
mpl11_add_test(enumerable                   enumerable.cpp)
mpl11_add_test(field                        field.cpp)
mpl11_add_test(foldable                     foldable.cpp)
mpl11_add_test(functional-always            functional/always.cpp)
mpl11_add_test(functional-apply             functional/apply.cpp)
mpl11_add_test(functional-arg               functional/arg.cpp)
mpl11_add_test(functional-argmap            functional/argmap.cpp)
mpl11_add_test(functional-bind              functional/bind.cpp)
mpl11_add_test(functional-compose           functional/compose.cpp)
mpl11_add_test(functional-fix               functional/fix.cpp)
mpl11_add_test(functional-flip              functional/flip.cpp)
mpl11_add_test(functional-id                functional/id.cpp)
mpl11_add_test(functional-into              functional/into.cpp)
mpl11_add_test(functional-on                functional/on.cpp)
mpl11_add_test(functional-partial           functional/partial.cpp)
mpl11_add_test(functional-quote             functional/quote.cpp)
mpl11_add_test(functor                      functor.cpp)
mpl11_add_test(group                        group.cpp)
mpl11_add_test(integer                      integer.cpp)
mpl11_add_test(integral_domain              integral_domain.cpp)
mpl11_add_test(iterable                     iterable.cpp)
mpl11_add_test(list                         list.cpp)
mpl11_add_test(logical-and_or               logical/and_or.cpp)
mpl11_add_test(logical-if                   logical/if.cpp)
mpl11_add_test(logical-not                  logical/not.cpp)
mpl11_add_test(master_header                master_header.cpp)
mpl11_add_test(minimal_foldable             minimal_foldable.cpp)
mpl11_add_test(monoid                       monoid.cpp)
mpl11_add_test(orderable                    orderable.cpp)
mpl11_add_test(ring                         ring.cpp)
