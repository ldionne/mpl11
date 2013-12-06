#=============================================================================
# Setup benchmarks
#=============================================================================
add_custom_target(benchmark COMMENT "Build all the benchmarks.")

function(mpl11_add_benchmark name)
    add_executable(benchmark_${name} EXCLUDE_FROM_ALL ${name}.cpp)
    add_dependencies(benchmark benchmark_${name})
endfunction()

mpl11_add_benchmark(at)
mpl11_add_benchmark(foldl)
mpl11_add_benchmark(instantiations)
mpl11_add_benchmark(map)
mpl11_add_benchmark(max_c)
mpl11_add_benchmark(or_c)
mpl11_add_benchmark(sum_c)
mpl11_add_benchmark(while)
