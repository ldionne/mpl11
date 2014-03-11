#!/usr/bin/env ruby

##############################################################################
# Comparison of the compilation time for including all the mpl
# and all the mpl11
##############################################################################


BENCHMARK_CODE=<<-END_OF_BENCHMARK

<% if opts[:mpl11] %>

    #include <boost/mpl11.hpp>

<% elsif opts[:mpl] %>

    #include <boost/mpl/accumulate.hpp>
    #include <boost/mpl/advance.hpp>
    #include <boost/mpl/advance_fwd.hpp>
    #include <boost/mpl/alias.hpp>
    #include <boost/mpl/always.hpp>
    #include <boost/mpl/and.hpp>
    #include <boost/mpl/apply.hpp>
    #include <boost/mpl/apply_fwd.hpp>
    #include <boost/mpl/apply_wrap.hpp>
    #include <boost/mpl/arg.hpp>
    #include <boost/mpl/arg_fwd.hpp>
    #include <boost/mpl/arithmetic.hpp>
    #include <boost/mpl/as_sequence.hpp>
    #include <boost/mpl/assert.hpp>
    #include <boost/mpl/at.hpp>
    #include <boost/mpl/at_fwd.hpp>
    #include <boost/mpl/back.hpp>
    #include <boost/mpl/back_fwd.hpp>
    #include <boost/mpl/back_inserter.hpp>
    #include <boost/mpl/base.hpp>
    #include <boost/mpl/begin.hpp>
    #include <boost/mpl/begin_end.hpp>
    #include <boost/mpl/begin_end_fwd.hpp>
    #include <boost/mpl/bind.hpp>
    #include <boost/mpl/bind_fwd.hpp>
    #include <boost/mpl/bitand.hpp>
    #include <boost/mpl/bitor.hpp>
    #include <boost/mpl/bitwise.hpp>
    #include <boost/mpl/bitxor.hpp>
    #include <boost/mpl/bool.hpp>
    #include <boost/mpl/bool_fwd.hpp>
    #include <boost/mpl/char.hpp>
    #include <boost/mpl/char_fwd.hpp>
    #include <boost/mpl/clear.hpp>
    #include <boost/mpl/clear_fwd.hpp>
    #include <boost/mpl/comparison.hpp>
    #include <boost/mpl/contains.hpp>
    #include <boost/mpl/contains_fwd.hpp>
    #include <boost/mpl/copy.hpp>
    #include <boost/mpl/copy_if.hpp>
    #include <boost/mpl/count.hpp>
    #include <boost/mpl/count_fwd.hpp>
    #include <boost/mpl/count_if.hpp>
    #include <boost/mpl/deque.hpp>
    #include <boost/mpl/deref.hpp>
    #include <boost/mpl/distance.hpp>
    #include <boost/mpl/distance_fwd.hpp>
    #include <boost/mpl/divides.hpp>
    #include <boost/mpl/empty.hpp>
    #include <boost/mpl/empty_base.hpp>
    #include <boost/mpl/empty_fwd.hpp>
    #include <boost/mpl/empty_sequence.hpp>
    #include <boost/mpl/end.hpp>
    #include <boost/mpl/equal.hpp>
    #include <boost/mpl/equal_to.hpp>
    #include <boost/mpl/erase.hpp>
    #include <boost/mpl/erase_fwd.hpp>
    #include <boost/mpl/erase_key.hpp>
    #include <boost/mpl/erase_key_fwd.hpp>
    #include <boost/mpl/eval_if.hpp>
    #include <boost/mpl/filter_view.hpp>
    #include <boost/mpl/find.hpp>
    #include <boost/mpl/find_if.hpp>
    #include <boost/mpl/fold.hpp>
    #include <boost/mpl/for_each.hpp>
    #include <boost/mpl/front.hpp>
    #include <boost/mpl/front_fwd.hpp>
    #include <boost/mpl/front_inserter.hpp>
    #include <boost/mpl/greater.hpp>
    #include <boost/mpl/greater_equal.hpp>
    #include <boost/mpl/has_key.hpp>
    #include <boost/mpl/has_key_fwd.hpp>
    #include <boost/mpl/has_xxx.hpp>
    #include <boost/mpl/identity.hpp>
    #include <boost/mpl/if.hpp>
    #include <boost/mpl/index_if.hpp>
    #include <boost/mpl/index_of.hpp>
    #include <boost/mpl/inherit.hpp>
    #include <boost/mpl/inherit_linearly.hpp>
    #include <boost/mpl/insert.hpp>
    #include <boost/mpl/insert_fwd.hpp>
    #include <boost/mpl/insert_range.hpp>
    #include <boost/mpl/insert_range_fwd.hpp>
    #include <boost/mpl/inserter.hpp>
    #include <boost/mpl/int.hpp>
    #include <boost/mpl/int_fwd.hpp>
    #include <boost/mpl/integral_c.hpp>
    #include <boost/mpl/integral_c_fwd.hpp>
    #include <boost/mpl/integral_c_tag.hpp>
    #include <boost/mpl/is_placeholder.hpp>
    #include <boost/mpl/is_sequence.hpp>
    #include <boost/mpl/iter_fold.hpp>
    #include <boost/mpl/iter_fold_if.hpp>
    #include <boost/mpl/iterator_category.hpp>
    #include <boost/mpl/iterator_range.hpp>
    #include <boost/mpl/iterator_tags.hpp>
    #include <boost/mpl/joint_view.hpp>
    #include <boost/mpl/key_type.hpp>
    #include <boost/mpl/key_type_fwd.hpp>
    #include <boost/mpl/lambda.hpp>
    #include <boost/mpl/lambda_fwd.hpp>
    #include <boost/mpl/less.hpp>
    #include <boost/mpl/less_equal.hpp>
    #include <boost/mpl/list.hpp>
    #include <boost/mpl/list_c.hpp>
    #include <boost/mpl/logical.hpp>
    #include <boost/mpl/long.hpp>
    #include <boost/mpl/long_fwd.hpp>
    #include <boost/mpl/lower_bound.hpp>
    #include <boost/mpl/map.hpp>
    #include <boost/mpl/max.hpp>
    #include <boost/mpl/max_element.hpp>
    #include <boost/mpl/min.hpp>
    #include <boost/mpl/min_element.hpp>
    #include <boost/mpl/min_max.hpp>
    #include <boost/mpl/minus.hpp>
    #include <boost/mpl/modulus.hpp>
    #include <boost/mpl/multiplies.hpp>
    #include <boost/mpl/negate.hpp>
    #include <boost/mpl/next.hpp>
    #include <boost/mpl/next_prior.hpp>
    #include <boost/mpl/not.hpp>
    #include <boost/mpl/not_equal_to.hpp>
    #include <boost/mpl/numeric_cast.hpp>
    #include <boost/mpl/O1_size.hpp>
    #include <boost/mpl/O1_size_fwd.hpp>
    #include <boost/mpl/or.hpp>
    #include <boost/mpl/order.hpp>
    #include <boost/mpl/order_fwd.hpp>
    #include <boost/mpl/pair.hpp>
    #include <boost/mpl/pair_view.hpp>
    #include <boost/mpl/partition.hpp>
    #include <boost/mpl/placeholders.hpp>
    #include <boost/mpl/plus.hpp>
    #include <boost/mpl/pop_back.hpp>
    #include <boost/mpl/pop_back_fwd.hpp>
    #include <boost/mpl/pop_front.hpp>
    #include <boost/mpl/pop_front_fwd.hpp>
    #include <boost/mpl/print.hpp>
    #include <boost/mpl/prior.hpp>
    #include <boost/mpl/protect.hpp>
    #include <boost/mpl/push_back.hpp>
    #include <boost/mpl/push_back_fwd.hpp>
    #include <boost/mpl/push_front.hpp>
    #include <boost/mpl/push_front_fwd.hpp>
    #include <boost/mpl/quote.hpp>
    #include <boost/mpl/range_c.hpp>
    #include <boost/mpl/remove.hpp>
    #include <boost/mpl/remove_if.hpp>
    #include <boost/mpl/replace.hpp>
    #include <boost/mpl/replace_if.hpp>
    #include <boost/mpl/reverse.hpp>
    #include <boost/mpl/reverse_fold.hpp>
    #include <boost/mpl/reverse_iter_fold.hpp>
    #include <boost/mpl/same_as.hpp>
    #include <boost/mpl/sequence_tag.hpp>
    #include <boost/mpl/sequence_tag_fwd.hpp>
    #include <boost/mpl/set.hpp>
    #include <boost/mpl/set_c.hpp>
    #include <boost/mpl/shift_left.hpp>
    #include <boost/mpl/shift_right.hpp>
    #include <boost/mpl/single_view.hpp>
    #include <boost/mpl/size.hpp>
    #include <boost/mpl/size_fwd.hpp>
    #include <boost/mpl/size_t.hpp>
    #include <boost/mpl/size_t_fwd.hpp>
    #include <boost/mpl/sizeof.hpp>
    #include <boost/mpl/sort.hpp>
    #include <boost/mpl/stable_partition.hpp>
    #include <boost/mpl/string.hpp>
    #include <boost/mpl/switch.hpp>
    #include <boost/mpl/tag.hpp>
    #include <boost/mpl/times.hpp>
    #include <boost/mpl/transform.hpp>
    #include <boost/mpl/transform_view.hpp>
    #include <boost/mpl/unique.hpp>
    #include <boost/mpl/unpack_args.hpp>
    #include <boost/mpl/upper_bound.hpp>
    #include <boost/mpl/value_type.hpp>
    #include <boost/mpl/value_type_fwd.hpp>
    #include <boost/mpl/vector.hpp>
    #include <boost/mpl/vector_c.hpp>
    #include <boost/mpl/void.hpp>
    #include <boost/mpl/void_fwd.hpp>
    #include <boost/mpl/zip_view.hpp>

<% end %>


int main() { }

END_OF_BENCHMARK


require_relative 'bench'


class Main < Benchmarker
    def make_plot(compiler, _, opts)
        opts[:mpl] = true
        mpl = compiler.compile_template_string(BENCHMARK_CODE, binding).real

        opts[:mpl] = false
        opts[:mpl11] = true
        mpl11 = compiler.compile_template_string(BENCHMARK_CODE, binding).real

        puts "including all the mpl11: #{mpl11} s"
        puts "including all the mpl: #{mpl} s"
    end
end

Main.new(ARGV).run
