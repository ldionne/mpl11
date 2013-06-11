/*!
 * @file
 * This file defines `boost::mpl11::detail::basic_map`.
 */

#ifndef BOOST_MPL11_DETAIL_BASIC_MAP_HPP
#define BOOST_MPL11_DETAIL_BASIC_MAP_HPP

#include <boost/type_traits/is_same.hpp>


namespace boost { namespace mpl11 { inline namespace v2 { namespace detail {
namespace basic_map_detail {
    template <typename I, I N>
    struct bootstrap_integral_c {
        static constexpr I value = N;
        using type = bootstrap_integral_c;
    };
    using yes_type = bootstrap_integral_c<bool, true>;
    using no_type = bootstrap_integral_c<bool, false>;

    template <typename T> struct allow_incomplete { using type = T; };

    template <typename Owner, typename ...Pairs>
    struct lookup_cell;

    template <typename Owner, typename Element, typename ...Rest>
    struct lookup_cell<Owner, Element, Rest...> : lookup_cell<Owner, Rest...> {
    private:
        using Next = lookup_cell<Owner, Rest...>;
        using Key = typename Owner::template key_type<Element>::type;
        using Value = typename Owner::template value_type<Element>::type;

    public:
        using this_element = Element;
        using next_cell = Next;

        using Next::has_key;
        static yes_type has_key(allow_incomplete<Key>);

        using Next::at;
        template <typename Default>
        static allow_incomplete<Value> at(allow_incomplete<Key>, Default);
    };

    template <typename Owner>
    struct lookup_cell<Owner> {
        template <typename Key>
        static no_type has_key(Key);

        template <typename Key, typename Default>
        static Default at(Key, Default);
    };
}

/*!
 *
 * @internal
 * This map is used to bootstrap the argument binding facilities and other
 * fundamentals of the library. For this reason, it must be pretty much
 * self-contained.
 *
 * @note
 * The pairs must have nested members named `first` and `second`.
 */
template <typename ...Elements>
class basic_map {
    using lookup_begin = basic_map_detail::lookup_cell<basic_map, Elements...>;
    using lookup_end = basic_map_detail::lookup_cell<basic_map>;

    template <typename Cell>
    struct iterator {
        struct deref { using type = typename Cell::this_element; };
        struct next { using type = iterator<typename Cell::next_cell>; };
    };

    template <typename I, I N>
    using bootstrap_integral_c = basic_map_detail::bootstrap_integral_c<I, N>;

    template <typename T>
    using wrap = basic_map_detail::allow_incomplete<T>;

    template <typename T>
    using unwrap = typename T::type;

    struct fail;

public:
    using type = basic_map;

    template <typename Key>
    struct has_key {
        using type = decltype(lookup_begin::has_key(wrap<Key>{}));
    };

    template <typename Key, typename Default = fail>
    struct at {
        using type = unwrap<
            decltype(lookup_begin::at(wrap<Key>{}, wrap<Default>{}))
        >;

        static_assert(!is_same<type, fail>::value,
            "the requested key could not be found in the map");
    };

    struct begin {
        using type = iterator<lookup_begin>;
    };

    struct end {
        using type = iterator<lookup_end>;
    };

    struct size {
        using type = bootstrap_integral_c<unsigned long, sizeof...(Elements)>;
    };

    struct empty {
        using type = bootstrap_integral_c<bool, size::type::value == 0>;
    };

    struct front {
        using type = typename begin::type::deref;
    };

    template <typename Element>
    struct key_type {
        using type = typename Element::first;
    };

    template <typename Element>
    struct value_type {
        using type = typename Element::second;
    };

    struct clear {
        using type = basic_map<>;
    };

    template <typename Element>
    struct push_front {
        using type = basic_map<Element, Elements...>;
    };

    template <typename Element>
    struct push_back {
        using type = basic_map<Elements..., Element>;
    };
};
}}}}

#endif // !BOOST_MPL11_DETAIL_BASIC_MAP_HPP
