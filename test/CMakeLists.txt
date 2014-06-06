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
    # norules  - BOOST_MPL11_NO_REWRITE_RULES
    add_custom_target(${test})

    macro(helper suffix)
        add_executable(${test}-${suffix} ${source})
        add_dependencies(${test} ${test}-${suffix})

        foreach(def IN ITEMS ${ARGN})
            set_property(TARGET ${test}-${suffix}
                         APPEND PROPERTY COMPILE_DEFINITIONS ${def})
        endforeach()
    endmacro()
    helper(normal)
    helper(noassert         BOOST_MPL11_NO_ASSERTIONS)
    helper(norules          BOOST_MPL11_NO_REWRITE_RULES)
    helper(noassert-norules BOOST_MPL11_NO_ASSERTIONS
                            BOOST_MPL11_NO_REWRITE_RULES)
endfunction()

function(mpl11_add_tests module)
    if(NOT TARGET ${module})
        mpl11_add_module(${module})
    endif()

    foreach(test IN ITEMS ${ARGN})
        mpl11_add_standalone_test(${module}.${test} ${module}/${test}.cpp)
        add_dependencies(${module} ${module}.${test})
    endforeach()
endfunction()

mpl11_add_tests(
    detail
    ######
    at_index
    at_key
    count_if
    dependent
    inherit
    left_folds
    logical_or
    right_folds
    std_conditional
    std_index_sequence
    std_is_same
)

mpl11_add_tests(
    ext
    ###
    std_tuple
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
    infix
    into
    lift
    namespace
    on
    partial
    sections
)

mpl11_add_tests(
    core
    ####
    box
    cast
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

mpl11_add_tests(
    typeclass
    #########
    bitwise
    comparable
    enumerable
    field
    foldable
    functor
    group
    integral_domain
    iterable
    monad
    monoid
    orderable
    ring
)

mpl11_add_tests(
    list
    ####
    list
    rules
)

mpl11_add_standalone_test(integer integer.cpp)
mpl11_add_standalone_test(master_header master_header.cpp)
mpl11_add_standalone_test(maybe maybe.cpp)
mpl11_add_standalone_test(minified_master minified_master.cpp)
