#!/usr/bin/env ruby

require "benchcc"


suite = Benchcc::BenchmarkSuite.new do
  benchmark(:foldl) do
    name "Left fold"
    description "Comparison between different implementations "\
                "of a left fold algorithm."
    file "src/foldl.erb.cpp"
    time 1..100

    technique(:mpl) do
      name "MPL"
      description "Left fold on an MPL vector."
      requires -> (env) { env[:input] <= 50 }
    end

    technique(:mpl11) do
      name "MPL11"
      description "Left fold on an MPL11 list."
      requires -> (env) { env[:input] <= 100 }
    end

    technique(:aliases) do
      description "Left fold on a variadic parameter pack using "\
                    "lightweight aliases to iterate."
    end

    technique(:standard_recursion) do
      description "Left fold on a variadic parameter pack using "\
                  "standard recursive structs."
    end
  end

  benchmark(:at) do
    description "Comparison of techniques implementing access to "\
                "parameter packs."
    file "src/at.erb.cpp"
    time 1..100

    technique :multiple_inheritance
    technique :overload
  end

  benchmark(:include_all) do
    description "Comparison of the compilation time for "\
                "including all a library."
    file "src/include_all.erb.cpp"

    technique :mpl
    technique :mpl11
  end

  benchmark(:instantiations) do
    description "Comparison between different ways of instantiating "\
                "the same number of templates"
    file "src/instantiations.erb.cpp"
    time (0..10_000).step 1_000

    technique :flat
    technique :recursive
  end

  benchmark(:list_at) do
    file "src/list_at.erb.cpp"
    time 0..50
    technique :mpl11
    technique :mpl
  end

  benchmark(:map) do
    description "Comparison of techniques to implement lookup "\
                "in compile-time maps."
    file "src/map.erb.cpp"
    time 0..200
    technique :single_inheritance
    technique :multiple_inheritance
  end

  benchmark(:max) do
    description "Comparison of techniques to implement "\
                "compile-time extrema computations."
    file "src/max.erb.cpp"
    technique :union
    technique :standard_recursion
    technique :argwise
    time 0..200
    # TODO: generate dataset with redundancy. look at src/max.erb.cpp
  end

  benchmark(:mention) do
    description "Comparison of the cost of mentioning a template "
                "versus instantiating it."
    file "src/mention.erb.cpp"
    technique :mention
    technique :instantiate
    time (0..20_000).step 100
  end

  benchmark(:metafunction_forwarding) do
    description "Comparison between metafunction forwarding and "\
                "nested type propagation."
    file "src/metafunction_forwarding.erb.cpp"
    technique :forwarding
    technique :nested_type
    time (0..300).step 5
  end

  benchmark(:metafunction_specialization) do
    description "Benchmark the cost of implementing metafunctions "\
                "via specialization."
    file "src/metafunction_specialization.erb.cpp"

    technique :full_specialization do
      description "The metafunction is specialized for different arguments"
    end

    technique :nested_type do
      description "The metafunction uses a nested type of the argument "\
                  "to customize its behavior"
    end

    time (0..5_000).step(100)
  end

  benchmark(:or) do
    description "Comparison of techniques to implement compile-time "\
                "logical conjunction."
    file "src/or.erb.cpp"
    technique :overload
    technique :noexcept
    technique :linear_constexpr
    technique :structs
    technique :specialization
    technique :aliases
    technique :short_circuit_structs
    time 0..100
  end

  benchmark(:pair_reuse) do
    description "Comparison of reusing a template versus using a new one "\
                "more specialized for the task at hand."
    file "src/pair_reuse.erb.cpp"
    technique :reuse
    technique :specialized
    time (0..20_000).step(100)
  end

  benchmark(:plus) do
    file "src/plus.erb.cpp"
    time 0..100
    technique :accumulating_constexpr
    technique :mpl
    technique :mpl11
    technique :recursive_constexpr
    technique :recursive_struct
    technique :sizeof_trick
  end

  benchmark(:while) do
    description "Comparison between using aliases and normal templates "\
                "for a `while_` implementation."
    file "src/while.erb.cpp"
    time 0..200
    technique :aliases
    technique :standard_recursion
  end
end

suite.run_from_cli(ARGV)
