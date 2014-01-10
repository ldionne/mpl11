/*!
 * @file
 * Defines the methods of the @ref Iterable typeclass.
 */

#ifndef BOOST_MPL11_ITERABLE_ITERABLE_HPP
#define BOOST_MPL11_ITERABLE_ITERABLE_HPP

#include <boost/mpl11/fwd/iterable.hpp>

#include <boost/mpl11/apply.hpp>
#include <boost/mpl11/comparable.hpp>
#include <boost/mpl11/detail/box.hpp>
#include <boost/mpl11/detail/default_unpack.hpp>
#include <boost/mpl11/detail/lexicographical_compare.hpp>
#include <boost/mpl11/detail/std_equal.hpp>
#include <boost/mpl11/foldable.hpp>
#include <boost/mpl11/functor.hpp>
#include <boost/mpl11/if.hpp>
#include <boost/mpl11/integral_c.hpp> // required by rules
#include <boost/mpl11/orderable.hpp>
#include <boost/mpl11/sequence_traits.hpp>
#include <boost/mpl11/tag_of.hpp>


namespace boost { namespace mpl11 {
    namespace rules {
        template <typename Iter, typename>
        struct head_impl
            : Iterable<typename tag_of<typename Iter::type>::type>::
              template head_impl<typename Iter::type>
        { };

        template <typename Iter, typename>
        struct tail_impl
            : Iterable<typename tag_of<typename Iter::type>::type>::
              template tail_impl<typename Iter::type>
        { };

        template <typename Iter, typename>
        struct init_impl
            : Iterable<typename tag_of<typename Iter::type>::type>::
              template init_impl<typename Iter::type>
        { };

        template <typename Iter, typename>
        struct last_impl
            : Iterable<typename tag_of<typename Iter::type>::type>::
              template last_impl<typename Iter::type>
        { };

        template <typename Iter, typename>
        struct is_empty_impl
            : Iterable<typename tag_of<typename Iter::type>::type>::
              template is_empty_impl<typename Iter::type>
        { };

        template <typename Iter, typename>
        struct length_impl
            : Iterable<typename tag_of<typename Iter::type>::type>::
              template length_impl<typename Iter::type>
        { };

        template <typename Iter, typename Index, typename>
        struct at_impl
            : Iterable<typename tag_of<typename Iter::type>::type>::
              template at_impl<typename Iter::type, typename Index::type>
        { };

        template <typename Iter, typename F, typename>
        struct unpack_impl
            : Iterable<typename tag_of<typename Iter::type>::type>::
              template unpack_impl<typename Iter::type, typename F::type>
        { };
    } // end namespace rules

#if defined(BOOST_MPL11_ENABLE_ASSERTIONS)
    template <typename Iter>
    struct head {
        static_assert(!is_empty<Iter>::value,
        "Invalid usage of `head` on an empty iterable.");
        using type = typename rules::head_impl<Iter>::type;
    };

    template <typename Iter>
    struct tail {
        static_assert(!is_empty<Iter>::value,
        "Invalid usage of `tail` on an empty iterable.");
        using type = typename rules::tail_impl<Iter>::type;
    };

    template <typename Iter>
    struct init {
        static_assert(!is_empty<Iter>::value,
        "Invalid usage of `init` on an empty iterable.");
        using type = typename rules::init_impl<Iter>::type;
    };

    template <typename Iter>
    struct last {
        static_assert(!is_empty<Iter>::value,
        "Invalid usage of `last` on an empty iterable.");
        using type = typename rules::last_impl<Iter>::type;
    };

    template <typename Iter, typename Index_>
    struct at {
    private:
        static constexpr auto Index = Index_::type::value;
        static_assert(Index >= 0,
        "Invalid usage of `at` with a negative index.");

        using Length = if_c<sequence_traits<typename Iter::type>::is_finite,
            length<Iter>,
            size_t<Index + 1>
        >;

        static_assert(Index < Length::value,
        "Invalid usage of `at` with an out-of-bounds index.");

    public:
        using type = typename rules::at_impl<Iter, Index_>::type;
    };
#endif

    //////////////////////
    // Instantiations
    //////////////////////
    namespace detail { template <typename> struct lazy_init; }

    template <>
    struct Iterable<iterable_tag> {
        template <typename Iter>
        using last_impl = if_c<is_empty<tail<detail::box<Iter>>>::value,
            head<detail::box<Iter>>,
            last<tail<detail::box<Iter>>>
        >;

        template <typename Iter>
        using init_impl = detail::lazy_init<detail::box<Iter>>;

        template <typename Iter, typename Index>
        struct at_impl
            : if_c<Index::value == 0,
                head<detail::box<Iter>>,
                at<tail<detail::box<Iter>>, pred<detail::box<Index>>>
            >
        { };

    private:
        //! @todo Remove this ad-hoc implementation.
        struct succ {
            using type = succ;
            template <typename N, typename>
            using apply = size_t<N::type::value + 1>;
        };

    public:
        template <typename Iter>
        using length_impl = typename foldl<
            succ, size_t<0>, detail::box<Iter>
        >::type;

        template <typename Iter, typename F>
        using unpack_impl = detail::default_unpack<
            detail::box<Iter>, detail::box<F>
        >;
    };

    template <>
    struct Comparable<iterable_tag, iterable_tag>
        : Comparable<comparable_tag>
    {
        template <typename S1, typename S2>
        using equal_impl = detail::std_equal<detail::box<S1>, detail::box<S2>>;
    };

    template <typename Tag>
    struct Comparable<iterable_tag, Tag>
        : detail::flip_Comparable<iterable_tag, Tag>
    { };

    template <>
    struct Orderable<iterable_tag, iterable_tag>
        : Orderable<orderable_tag>
    {
        template <typename S1, typename S2>
        using less_impl = detail::lexicographical_compare<S1, S2>;
    };

    template <typename Tag>
    struct Orderable<iterable_tag, Tag>
        : detail::flip_Orderable<iterable_tag, Tag>
    { };

    template <>
    struct Foldable<iterable_tag> {
        template <typename F, typename State, typename Iter>
        struct foldl_impl
            : if_<is_empty<detail::box<Iter>>,
                detail::box<State>,
                foldl<
                    detail::box<F>,
                    apply<
                        detail::box<F>,
                        detail::box<State>,
                        head<detail::box<Iter>>
                    >,
                    tail<detail::box<Iter>>
                >
            >
        { };

        template <typename F, typename State, typename Iter>
        struct foldr_impl
            : if_<is_empty<detail::box<Iter>>,
                detail::box<State>,
                apply<
                    detail::box<F>,
                    head<detail::box<Iter>>,
                    foldr<
                        detail::box<F>,
                        detail::box<State>,
                        tail<detail::box<Iter>>
                    >
                >
            >
        { };
    };

    namespace detail { template <typename, typename> struct lazy_fmap; }

    template <>
    struct Functor<iterable_tag> {
        template <typename F, typename Iter>
        using fmap_impl = detail::lazy_fmap<detail::box<F>, detail::box<Iter>>;
    };
}} // end namespace boost::mpl11

#include <boost/mpl11/detail/lazy_fmap.hpp>
#include <boost/mpl11/detail/lazy_init.hpp>

#endif // !BOOST_MPL11_ITERABLE_ITERABLE_HPP
