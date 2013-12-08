#=============================================================================
# Setup examples
#=============================================================================
add_custom_target(example COMMENT "Build all the examples.")

function(mpl11_add_example name sources)
    add_executable(${name} ${sources})
    add_dependencies(example ${name})
endfunction()


#=============================================================================
# Setup examples requiring Boost
#=============================================================================
find_package(Boost QUIET)
if (NOT Boost_FOUND)
    message(STATUS "Boost headers were not found. Some examples won't be available.")
else()

endif()
