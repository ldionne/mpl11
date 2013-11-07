/**
 * This file defines a metafunction to parse arbitrary template expressions.
 */

#ifndef MPL11_SANDBOX_PARSE_HPP
#define MPL11_SANDBOX_PARSE_HPP

#include <mpl11/apply.hpp>
#include <mpl11/pack.hpp>


namespace mpl11 {
namespace sandbox {
    // Note: We reimplement several metafunctions to avoid circular
    //       dependencies with the rest of the library.

    namespace detail {
        template <bool b>
        struct return_ {
            template <typename ...>
            struct apply { static bool const value = b; };
        };
    }

    /**
     * Traits to customize the visit of an expression tree.
     * When a trait is not defined by a visitor, it defaults to a nop.
     */
    template <typename Visitor>
    struct visitor_traits {
    private:
        struct do_nothing {
            template <typename T>
            struct apply { using type = T; };
        };

        template <typename V> static typename V::pre_visit pre_type(int);
        template <typename> static do_nothing pre_type(...);

        template <typename V> static typename V::post_visit post_type(int);
        template <typename> static do_nothing post_type(...);

        template <typename V> static typename V::skip skip_type(int);
        template <typename> static detail::return_<false> skip_type(...);

        template <typename V> static typename V::discover discover_type(int);
        template <typename> static do_nothing discover_type(...);

    public:
        // Metafunction class to determine whether a vertex should be skipped.
        // Skipping a vertex implies that all its neighbors are skipped too.
        using skip = decltype(skip_type<Visitor>(0));

        // Metafunction class called before visiting the neighbors.
        using pre_visit = decltype(pre_type<Visitor>(0));

        // Metafunction class called after visiting the neighbors.
        using post_visit = decltype(post_type<Visitor>(0));

        // Metafunction called on a vertex when first discovered. This is
        // different from the `preorder` metafunction in that it is called
        // even if the visit of that vertex is skipped.
        using discover = decltype(discover_type<Visitor>(0));
    };

     /**
      * A null visitor that does not modify the expression tree.
      * Since it does nothing, it stops the visit as soon as possible.
      */
    struct null_visitor {
        using skip = detail::return_<true>;
    };

    namespace detail {
        template <bool cond, typename True, typename False>
        struct eval_if {
            using type = typename True::type;
        };

        template <typename True, typename False>
        struct eval_if<false, True, False> {
            using type = typename False::type;
        };

        template <typename T>
        struct identity { using type = T; };

        template <typename Result, typename Neighbors>
        struct unwrap_visitor_result;

        template <typename Result, typename ...Neighbors>
        struct unwrap_visitor_result<Result, pack<Neighbors...>>
            : pack<Result, Neighbors...>
        { };

        template <typename ...Results, typename ...Neighbors>
        struct unwrap_visitor_result<pack<Results...>, pack<Neighbors...>>
            : pack<Results..., Neighbors...>
        { };

        template <typename Vertex, typename Visitor> class parse_base;
    } // end namespace detail

    /**
     * Visit an expression tree, calling a visitor on each node.
     *
     * The visitor's return value can be in a variadic pack when performing
     * a postvisit. This allows the visitor to add vertices during the visit.
     * By convention, only the discovery and postvisit are done on leaves.
     *
     * Note: If the visitor wants to return a variadic pack as-is, then the
     *       pack should be wrapped in another pack, so the first one can be
     *       stripped safely.
     */
    template <typename Root_, typename Visitor=null_visitor>
    class parse {
        using Root =
            typename apply<
                typename visitor_traits<Visitor>::discover, Root_
            >::type;

    public:
        using type =
            typename detail::eval_if<
                apply<typename visitor_traits<Visitor>::skip, Root>::value,
                detail::identity<Root>,
                detail::parse_base<Root, Visitor>
            >::type;
    };

    namespace detail {
        template <typename Vertex, typename Visitor>
        class parse_base
            : public apply<
                typename visitor_traits<Visitor>::post_visit, Vertex
            >
        { };

        template <template <typename ...> class Vertex,
                  typename ...Neighbors, typename Visitor>
        class parse_base<Vertex<Neighbors...>, Visitor> {
            using VisitorTraits = visitor_traits<Visitor>;

            // Perform the preorder visit.
            using pre_visit =
                typename apply<
                    typename VisitorTraits::pre_visit, Vertex<Neighbors...>
                >::type;

            // Recursively visit the neighbors.
            template <typename> struct in_visit_impl;
            template <template <typename ...> class V, typename ...N>
            struct in_visit_impl<V<N...>> {
                // Fold the result of visiting each neighbor,
                // which is sometimes a pack.
                template <typename ...N_> struct impl : pack<> { };
                template <typename N_, typename ...Rest>
                struct impl<N_, Rest...>
                    : unwrap_visitor_result<
                        typename parse<N_, Visitor>::type,
                        typename impl<Rest...>::type
                    >
                { };

                // Recreate a vertex from a pack of types.
                template <typename ...> struct make_vertex;
                template <typename ...N_>
                struct make_vertex<pack<N_...>> {
                    using type = V<N_...>;
                };

                using type = typename make_vertex<
                                typename impl<N...>::type
                            >::type;
            };

            using in_visit = typename in_visit_impl<pre_visit>::type;

            // Perform postorder visit.
            using post_visit =
                typename apply<
                    typename VisitorTraits::post_visit, in_visit
                >::type;

        public:
            using type = post_visit;
        };
    } // end namespace detail

} // end namespace sandbox
} // end namespace mpl11

#endif // !MPL11_SANDBOX_PARSE_HPP
