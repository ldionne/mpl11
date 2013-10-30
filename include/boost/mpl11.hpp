/*!
 * @file
 * Includes the whole _mpl11_ library.
 */

#ifndef BOOST_MPL11_HPP
#define BOOST_MPL11_HPP

/*!
 * @defgroup details Details
 *
 * Implementation details.
 *
 *
 * @todo
 * Fix the note below: some metafunctions in `detail` do return
 * `IntegralConstant`s.
 *
 * @note
 * In order to reduce dependencies to the maximum, boolean metafunctions in
 * this category are not real boolean metafunctions as they do not return
 * `IntegralConstant`s. Instead, they have a nested boolean `value` which
 * carries the result.
 */

/*!
 * @defgroup datatypes Data types
 *
 * Constructs for manipulating data at compile-time.
 */

/*!
 * @defgroup sequences Sequences
 * @ingroup datatypes
 *
 * Types representing collections of other types.
 */

/*!
 * @defgroup containers Containers
 * @ingroup sequences
 *
 * Mutable sequences.
 */

/*!
 * @defgroup views Views
 * @ingroup sequences
 *
 * Immutable sequences providing a lazily-altered presentation of one or more
 * underlying sequences.
 */

/*!
 * @defgroup metafunctions Metafunctions
 *
 * Compile-time functions operating on types.
 */

/*!
 * @defgroup algorithms Algorithms
 * @ingroup metafunctions
 *
 * Generic algorithms manipulating @ref datatypes through their intrinsics.
 */

/*!
 * @defgroup intrinsics Intrinsics
 * @ingroup metafunctions
 *
 * Metafunctions forming the essential interface of @ref datatypes.
 *
 * Intrinsics use a special dispatching system to allow their behavior to
 * be customized easily.
 *
 *
 * @todo Document the dispatching system.
 */

/*!
 * @defgroup mixins Mixins
 *
 * Classes providing some operations based on other operations provided
 * by the user.
 *
 *
 * @todo
 * Document the usage and composition of mixins, and their
 * relation to concepts.
 */

#include <boost/mpl11/add.hpp>
#include <boost/mpl11/advance.hpp>
#include <boost/mpl11/always.hpp>
#include <boost/mpl11/and.hpp>
#include <boost/mpl11/apply_wrap.hpp>
#include <boost/mpl11/arithmetic.hpp>
#include <boost/mpl11/associative_sequence.hpp>
#include <boost/mpl11/at.hpp>
#include <boost/mpl11/back.hpp>
#include <boost/mpl11/begin.hpp>
#include <boost/mpl11/bidirectional_iterator.hpp>
#include <boost/mpl11/bidirectional_sequence.hpp>
#include <boost/mpl11/bitand.hpp>
#include <boost/mpl11/bitor.hpp>
#include <boost/mpl11/bitwise.hpp>
#include <boost/mpl11/bitxor.hpp>
#include <boost/mpl11/class_of.hpp>
#include <boost/mpl11/comparable.hpp>
#include <boost/mpl11/couple.hpp>
#include <boost/mpl11/deref.hpp>
#include <boost/mpl11/distance.hpp>
#include <boost/mpl11/divide.hpp>
#include <boost/mpl11/empty_base.hpp>
#include <boost/mpl11/end.hpp>
#include <boost/mpl11/equal.hpp>
#include <boost/mpl11/first.hpp>
#include <boost/mpl11/forward_iterator.hpp>
#include <boost/mpl11/forward_sequence.hpp>
#include <boost/mpl11/front.hpp>
#include <boost/mpl11/greater.hpp>
#include <boost/mpl11/greater_equal.hpp>
#include <boost/mpl11/has_key.hpp>
#include <boost/mpl11/hash.hpp>
#include <boost/mpl11/hashable.hpp>
#include <boost/mpl11/identity.hpp>
#include <boost/mpl11/if.hpp>
#include <boost/mpl11/inherit.hpp>
#include <boost/mpl11/integral_c.hpp>
#include <boost/mpl11/integral_constant.hpp>
#include <boost/mpl11/is_empty.hpp>
#include <boost/mpl11/key_of.hpp>
#include <boost/mpl11/less.hpp>
#include <boost/mpl11/less_equal.hpp>
#include <boost/mpl11/logical.hpp>
#include <boost/mpl11/modulo.hpp>
#include <boost/mpl11/multiply.hpp>
#include <boost/mpl11/next.hpp>
#include <boost/mpl11/not.hpp>
#include <boost/mpl11/not_equal.hpp>
#include <boost/mpl11/or.hpp>
#include <boost/mpl11/orderable.hpp>
#include <boost/mpl11/pair.hpp>
#include <boost/mpl11/prev.hpp>
#include <boost/mpl11/quote.hpp>
#include <boost/mpl11/random_access_iterator.hpp>
#include <boost/mpl11/random_access_sequence.hpp>
#include <boost/mpl11/second.hpp>
#include <boost/mpl11/shift_left.hpp>
#include <boost/mpl11/shift_right.hpp>
#include <boost/mpl11/size.hpp>
#include <boost/mpl11/substract.hpp>
#include <boost/mpl11/value_of.hpp>

#endif // !BOOST_MPL11_HPP
