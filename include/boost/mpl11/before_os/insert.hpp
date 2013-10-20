/*!
 * @file
 * Defines `boost::mpl11::insert`.
 */

#ifndef BOOST_MPL11_INSERT_HPP
#define BOOST_MPL11_INSERT_HPP

#include <boost/mpl11/fwd/insert.hpp>

#include <boost/mpl11/arg.hpp>
#include <boost/mpl11/dispatch.hpp>
#include <boost/mpl11/erase_key.hpp>
#include <boost/mpl11/indexed_view.hpp>
#include <boost/mpl11/joined_view.hpp>
#include <boost/mpl11/key_of.hpp>
#include <boost/mpl11/lambda.hpp>
#include <boost/mpl11/single_view.hpp>
#include <boost/mpl11/value_of.hpp>


namespace boost { namespace mpl11 {
    template <typename Sequence, typename Position, typename Element>
    struct dispatch<tag::insert, Sequence, Position, Element>
        : insert_range<
            Sequence, Position, single_view<Element>
        >
    { };

    template <typename Sequence, typename Element>
    struct dispatch<tag::insert, Sequence, Element> {
    private:
        using Filtered = typename erase_key<
            Sequence, typename key_of<Sequence, Element>::type
        >::type;

        using GetKey = typename lambda<key_of<Filtered, _1>>::type;
        using GetValue = typename lambda<value_of<Filtered, _1>>::type;

    public:
        using type = indexed_view<
            joined_view<
                Filtered,
                indexed_view<
                    single_view<Element>, GetKey, GetValue
                >
            >,
            GetKey,
            GetValue
        >;
    };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_INSERT_HPP
