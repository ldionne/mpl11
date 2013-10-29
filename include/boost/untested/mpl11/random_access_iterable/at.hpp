/*!
 * @file
 * Defines `boost::mpl11::RandomAccessSequence::at`.
 */

#ifndef BOOST_MPL11_RANDOM_ACCESS_SEQUENCE_AT_HPP
#define BOOST_MPL11_RANDOM_ACCESS_SEQUENCE_AT_HPP

#include <boost/mpl11/advance.hpp>
#include <boost/mpl11/begin.hpp>
#include <boost/mpl11/deref.hpp>
#include <boost/mpl11/random_access_sequence/random_access_sequence.hpp>
#include <boost/mpl11/size.hpp>


namespace boost { namespace mpl11 {
    template <typename Sequence, typename N>
    struct RandomAccessSequence::at {
        static_assert(N::value >= 0,
        "Trying to access a sequence at a negative index.");
        static_assert(N::value < size<Sequence>::type::value,
        "Trying to access a sequence at an index beyond the last element.");

        // Can't inherit from `deref` because we want the `static_assert`s
        // above to be triggered before we do anything.
        using type = typename deref<
            typename advance<typename begin<Sequence>::type, N>::type
        >::type;
    };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_RANDOM_ACCESS_SEQUENCE_AT_HPP
