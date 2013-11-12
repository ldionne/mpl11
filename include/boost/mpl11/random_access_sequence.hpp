/*!
 * @file
 * Defines `boost::mpl11::RandomAccessSequence`.
 */

#ifndef BOOST_MPL11_RANDOM_ACCESS_SEQUENCE_HPP
#define BOOST_MPL11_RANDOM_ACCESS_SEQUENCE_HPP

#include <boost/mpl11/fwd/random_access_sequence.hpp>

#include <boost/mpl11/advance.hpp>
#include <boost/mpl11/begin.hpp>
#include <boost/mpl11/bidirectional_sequence.hpp> // required by fwd decl
#include <boost/mpl11/deref.hpp>
#include <boost/mpl11/size.hpp>


namespace boost { namespace mpl11 {
    template <typename S, typename N>
    struct RandomAccessSequence::at_impl {
        static_assert(N::value >= 0,
        "Trying to access a sequence at a negative index.");
        static_assert(N::value < size<S>::value,
        "Trying to access a sequence at an index beyond the last element.");

        using type = typename deref<
            typename advance<typename begin<S>::type, N>::type
        >::type;
    };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_RANDOM_ACCESS_SEQUENCE_HPP
