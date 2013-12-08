#=============================================================================
# Setup benchmarks
#=============================================================================
add_custom_target(benchmarks COMMENT "Build all the benchmarks.")

function(mpl11_add_benchmark name source)
    add_executable(benchmark_${name} EXCLUDE_FROM_ALL ${source})
    add_dependencies(benchmarks benchmark_${name})
endfunction()

mpl11_add_benchmark(vector_at       vector/at.cpp)
mpl11_add_benchmark(vector_foldl    vector/foldl.cpp)
mpl11_add_benchmark(vector_pop_back vector/pop_back.cpp)
