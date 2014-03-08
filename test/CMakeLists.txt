#=============================================================================
# Setup unit tests
#=============================================================================
add_custom_target(tests COMMENT "Build all the unit tests.")

function(mpl11_add_module module)
    add_custom_target(${module}
        COMMENT "Build unit tests for the ${module} module.")
    add_dependencies(tests ${module})
endfunction()

function(mpl11_add_standalone_test test source)
    # We compile each unit test with the possible combinations of options
    # found in boost/mpl11/detail/config.hpp.
    #
    # For lack of a better solution, we currently create different targets
    # for each configuration.
    # noassert - BOOST_MPL11_NO_ASSERTIONS
    # norules  - BOOST_MPL11_NO_RULES
    add_custom_target(${test})

    macro(helper suffix)
        add_executable(${test}-${suffix} ${source})
        add_dependencies(${test} ${test}-${suffix})

        foreach(def IN ITEMS ${ARGN})
            set_property(
                TARGET ${test}-${suffix}
                APPEND PROPERTY COMPILE_DEFINITIONS ${def}
            )
        endforeach()
    endmacro()
    helper(normal)
    helper(noassert         BOOST_MPL11_NO_ASSERTIONS)
    helper(norules          BOOST_MPL11_NO_RULES)
    helper(noassert-norules BOOST_MPL11_NO_ASSERTIONS BOOST_MPL11_NO_RULES)
endfunction()

function(mpl11_add_tests module)
    if(NOT TARGET ${module})
        mpl11_add_module(${module})
    endif()

    foreach(test IN ITEMS ${ARGN})
        mpl11_add_standalone_test(${module}-${test} ${module}/${test}.cpp)
        add_dependencies(${module} ${module}-${test})
    endforeach()
endfunction()

mpl11_add_tests(
    detail
    ######
    std_conditional
    std_index_sequence
    std_is_same
    strict_variadic_foldl
)

mpl11_add_tests(
    functional
    ##########
    always
    apply
    arg
    argmap
    bind
    compose
    currying
    fix
    flip
    id
    into
    on
    partial
    quote
)

mpl11_add_tests(
    core
    ####
    box
    cast
    cast_to
    common_datatype
    datatype
    foreign
)

mpl11_add_tests(
    logical
    #######
    if
    and_or
    not
)

mpl11_add_standalone_test(bitwise bitwise.cpp)
mpl11_add_standalone_test(comparable comparable.cpp)
mpl11_add_standalone_test(enumerable enumerable.cpp)
mpl11_add_standalone_test(field field.cpp)
mpl11_add_standalone_test(foldable foldable.cpp)
mpl11_add_standalone_test(functor functor.cpp)
mpl11_add_standalone_test(group group.cpp)
mpl11_add_standalone_test(integer integer.cpp)
mpl11_add_standalone_test(integral_domain integral_domain.cpp)
mpl11_add_standalone_test(iterable iterable.cpp)
mpl11_add_standalone_test(list list.cpp)
mpl11_add_standalone_test(master_header master_header.cpp)
mpl11_add_standalone_test(minimal_foldable minimal_foldable.cpp)
mpl11_add_standalone_test(monoid monoid.cpp)
mpl11_add_standalone_test(orderable orderable.cpp)
mpl11_add_standalone_test(ring ring.cpp)
