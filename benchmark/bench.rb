#!/usr/bin/env ruby

##############################################################################
# Utilities to gather compilation statistics and plot the results
##############################################################################
require 'benchmark'
require 'erb'
require 'tempfile'
require_relative 'ruby_gnuplot/lib/gnuplot'


# Returns the basename of a file without the extension.
def File.basename_we(fname)
    File.basename(fname, File.extname(fname))
end

def average(xs)
    (xs.reduce :+) / xs.size
end

def quote(str)
    "\"#{str}\""
end

def round_up(n, ndigits)
    k = 10 ** ndigits
    if n % k == 0
        n
    else
        (1 + n/k) * k
    end
end

def round_down(n, ndigits)
    k = 10 ** ndigits
    (n / k) * k
end

class FailedCompilation < RuntimeError

end

class BenchmarkingCompiler
    attr_reader :name

    def initialize(name, compile)
        @name = name
        @_compile = compile
    end

    def to_s
        @name
    end

    def _compile(filename)
        @_compile.call(filename)
        raise FailedCompilation.new unless $?.success?
    end

    def compile_string(str)
        tmp = Tempfile.new(['', '.cpp'])
        tmp.write(str)
        tmp.close
        self.compile_file(tmp.path)
    end

    def compile_template_string(str, b=binding)
        erb = ERB.new(str)
        code = erb.result(b)
        self.compile_string(code)
    end

    def compile_template_file(filename, b=binding)
        self.compile_template_string(File.read(filename), b)
    end

    def compile_file(filename)
        self._compile(filename) # Rehearse once before benchmarking.
        avg = average 2.times.collect {
            Benchmark.measure { self._compile(filename) }
        }
        avg.instance_variable_set(:@label, @name); avg
    end
end

# Generates `[xs, ys]` points for graphing. `ys` is a list containing
# `gen_y(x)` for each `x` in `xs`. Whenever a call to `gen_y` raises
# a `FailedCompilation` error, the (`nil, `nil`) point is added instead,
# which makes a hole in the generated graph.
def generate_points(xs, &gen_y)
    points = [[], []]
    for x in xs
        begin
            y = gen_y.call(x)
            points[0] << x
            points[1] << y
        rescue FailedCompilation
            $stderr.puts("skipping point (#{x}, ?); y-axis generation failed")
            points[0] << nil
            points[1] << nil
        end
    end
    points
end

class Benchmarker
    def _usage(s=nil)
        msg = <<-EOS
Usage:
    #{File.basename_we($0)} [options]
        --fair      When available, benchmarks will be more fair. For example,
                    all headers will always be included at the beginning of
                    the benchmark to eliminate any difference in header
                    parsing time.
EOS

        $stderr.puts(s) if s
        $stderr.puts(msg)
        exit(2)
    end

    def initialize(argv)
        @opts = {:fair => false}
        @compilers = {
            :gcc49 => BenchmarkingCompiler.new("GCC 4.9",
                -> (filename) {
                    `g++-4.9 -std=c++11 -o /dev/null -I ~/code/mpl11/include -c #{filename}`
                }
            ),
            :clang35 => BenchmarkingCompiler.new("Clang 3.5",
                -> (filename) {
                    `clang++-3.5 -std=c++11 -o /dev/null -I ~/code/mpl11/include -c #{filename}`
                }
            )
        }

        until argv.empty?
            case argv[0]
            when '--fair'   then @opts[:fair] = true; argv.shift
            else _usage("Unknown option: #{argv[0].inspect}")
            end
        end
    end

    def run
        Gnuplot.open do |gnuplot_process|
            self.make_plot(@compilers[:clang35], gnuplot_process, @opts)
        end
    end
end
