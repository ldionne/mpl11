#=============================================================================
# Setup benchmarks
#=============================================================================
add_custom_target(benchmarks COMMENT "Build all the benchmarks.")

function(mpl11_add_benchmark name source)
    add_executable(benchmark_${name} EXCLUDE_FROM_ALL ${source})
    add_dependencies(benchmarks benchmark_${name})
endfunction()

mpl11_add_benchmark(partial_specializations partial_specializations.cpp)
mpl11_add_benchmark(vector                  vector.cpp)
