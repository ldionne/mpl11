/*!
 * @file
 * Defines `boost::mpl11::insert`.
 */

#ifndef BOOST_MPL11_ALGORITHM_INSERT_HPP
#define BOOST_MPL11_ALGORITHM_INSERT_HPP

#include <boost/mpl11/algorithm/erase_key.hpp>
#include <boost/mpl11/algorithm/insert_fwd.hpp>
#include <boost/mpl11/dispatch.hpp>
#include <boost/mpl11/functional/arg.hpp>
#include <boost/mpl11/functional/lambda.hpp>
#include <boost/mpl11/intrinsic/key_of.hpp>
#include <boost/mpl11/intrinsic/value_of.hpp>
#include <boost/mpl11/view/indexed_by.hpp>
#include <boost/mpl11/view/joined.hpp>
#include <boost/mpl11/view/single_element.hpp>


namespace boost { namespace mpl11 {
    template <typename Sequence, typename Position, typename Element>
    struct dispatch<tag::default_<tag::insert>, Sequence, Position, Element>
        : insert_range<
            Sequence, Position, view::single_element<Element>
        >
    { };

    template <typename Sequence, typename Element>
    struct dispatch<tag::default_<tag::insert>, Sequence, Element> {
    private:
        using Filtered = typename erase_key<
            Sequence, typename key_of<Sequence, Element>::type
        >::type;

        using GetKey = typename lambda<key_of<Filtered, _1>>::type;
        using GetValue = typename lambda<value_of<Filtered, _1>>::type;

    public:
        using type = view::indexed_by<
            view::joined<
                Filtered,
                view::indexed_by<
                    view::single_element<Element>, GetKey, GetValue
                >
            >,
            GetKey,
            GetValue
        >;
    };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_ALGORITHM_INSERT_HPP
