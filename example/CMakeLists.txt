#=============================================================================
# Setup examples
#=============================================================================
add_custom_target(examples COMMENT "Build all the examples.")

function(mpl11_add_example name sources)
    add_executable(${name} ${sources})
    add_dependencies(examples ${name})
endfunction()
