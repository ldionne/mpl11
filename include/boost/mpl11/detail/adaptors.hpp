/*!
 * @file
 * Defines adaptors for several concepts.
 */

#ifndef BOOST_MPL11_DETAIL_ADAPTORS_HPP
#define BOOST_MPL11_DETAIL_ADAPTORS_HPP

#include <boost/mpl11/fwd/advance.hpp>
#include <boost/mpl11/fwd/at.hpp>
#include <boost/mpl11/fwd/at_key.hpp>
#include <boost/mpl11/fwd/back.hpp>
#include <boost/mpl11/fwd/begin.hpp>
#include <boost/mpl11/fwd/class_of.hpp>
#include <boost/mpl11/fwd/deref.hpp>
#include <boost/mpl11/fwd/distance.hpp>
#include <boost/mpl11/fwd/end.hpp>
#include <boost/mpl11/fwd/equal.hpp>
#include <boost/mpl11/fwd/front.hpp>
#include <boost/mpl11/fwd/greater.hpp>
#include <boost/mpl11/fwd/greater_equal.hpp>
#include <boost/mpl11/fwd/has_key.hpp>
#include <boost/mpl11/fwd/is_empty.hpp>
#include <boost/mpl11/fwd/key_of.hpp>
#include <boost/mpl11/fwd/less.hpp>
#include <boost/mpl11/fwd/less_equal.hpp>
#include <boost/mpl11/fwd/next.hpp>
#include <boost/mpl11/fwd/not_equal.hpp>
#include <boost/mpl11/fwd/prev.hpp>
#include <boost/mpl11/fwd/size.hpp>
#include <boost/mpl11/fwd/value_of.hpp>


namespace boost { namespace mpl11 { namespace detail {
    template <typename Adaptor>
    struct adapted
        : class_of<Adaptor>::type::template adapted_impl<Adaptor>
    { };

    template <typename Adaptor>
    using adapted_t = typename adapted<Adaptor>::type;

    template <typename Adaptor, typename Adapted>
    struct adapt
        : class_of<Adaptor>::type::template adapt_impl<Adaptor, Adapted>
    { };

    template <typename Adaptor, typename Adapted>
    using adapt_t = typename adapt<Adaptor, Adapted>::type;

    struct comparable_adaptor {
        template <typename Self, typename Other>
        using equal_impl = equal<adapted_t<Self>, adapted_t<Other>>;

        template <typename Self, typename Other>
        using not_equal_impl = not_equal<adapted_t<Self>, adapted_t<Other>>;
    };

    struct orderable_adaptor {
        template <typename Self, typename Other>
        using less_impl = less<adapted_t<Self>, adapted_t<Other>>;

        template <typename Self, typename Other>
        using less_equal_impl = less_equal<adapted_t<Self>, adapted_t<Other>>;

        template <typename Self, typename Other>
        using greater_impl = greater<adapted_t<Self>, adapted_t<Other>>;

        template <typename Self, typename Other>
        using greater_equal_impl = greater_equal<
            adapted_t<Self>, adapted_t<Other>
        >;
    };

    struct forward_iterator_adaptor : comparable_adaptor {
        template <typename Iterator>
        using next_impl = adapt<Iterator, next_t<adapted_t<Iterator>>>;

        template <typename Iterator>
        using deref_impl = deref<adapted_t<Iterator>>;

        template <typename Iterator, typename N>
        using advance_impl = adapt<
            Iterator, advance_t<adapted_t<Iterator>, N>
        >;

        template <typename First, typename Last>
        using distance_impl = distance<adapted_t<First>, adapted_t<Last>>;
    };

    struct bidirectional_iterator_adaptor : forward_iterator_adaptor {
        template <typename Iterator>
        using prev_impl = adapt<Iterator, prev_t<adapted_t<Iterator>>>;

        template <typename Iterator, typename N>
        using advance_impl = adapt<
            Iterator, advance_t<adapted_t<Iterator>, N>
        >;
    };

    struct random_access_iterator_adaptor
        : bidirectional_iterator_adaptor,
          orderable_adaptor
    {
        template <typename Iterator, typename N>
        using advance_impl = adapt<
            Iterator, advance_t<adapted_t<Iterator>, N>
        >;

        template <typename First, typename Last>
        using distance_impl = distance<adapted_t<First>, adapted_t<Last>>;
    };

    struct sequence_adaptor {
        template <typename Sequence>
        using begin_impl = begin<adapted_t<Sequence>>;

        template <typename Sequence>
        using end_impl = end<adapted_t<Sequence>>;

        template <typename Sequence>
        using size_impl = size<adapted_t<Sequence>>;

        template <typename Sequence>
        using is_empty_impl = is_empty<adapted_t<Sequence>>;
    };

    struct directional_sequence_adaptor
        : sequence_adaptor,
          comparable_adaptor,
          orderable_adaptor
    {
        template <typename Sequence>
        using front_impl = front<adapted_t<Sequence>>;
    };

    struct bidirectional_sequence_adaptor : directional_sequence_adaptor {
        template <typename Sequence>
        using begin_impl = begin<adapted_t<Sequence>>;

        template <typename Sequence>
        using end_impl = end<adapted_t<Sequence>>;

        template <typename Sequence>
        using back_impl = back<adapted_t<Sequence>>;
    };

    struct random_access_sequence_adaptor : bidirectional_sequence_adaptor {
        template <typename Sequence>
        using begin_impl = begin<adapted_t<Sequence>>;

        template <typename Sequence>
        using end_impl = end<adapted_t<Sequence>>;

        template <typename Sequence, typename N>
        using at_impl = at<adapted_t<Sequence>, N>;
    };

    struct associative_sequence_adaptor
        : sequence_adaptor,
          comparable_adaptor
    {
        template <typename Sequence, typename Key, typename Default>
        using at_key_def_impl = at_key<adapted_t<Sequence>, Key, Default>;

        template <typename Sequence, typename Key>
        using at_key_impl = at_key<adapted_t<Sequence>, Key>;

        template <typename Sequence, typename Key>
        using has_key_impl = has_key<adapted_t<Sequence>, Key>;

        template <typename Sequence, typename Element>
        using value_of_impl = value_of<adapted_t<Sequence>, Element>;

        template <typename Sequence, typename Element>
        using key_of_impl = key_of<adapted_t<Sequence>, Element>;
    };
}}} // end namespace boost::mpl11::detail


#include <boost/mpl11/class_of.hpp>


#endif // !BOOST_MPL11_DETAIL_ADAPTORS_HPP
