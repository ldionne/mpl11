/*!
 * @file
 * Forward declares categories for sequences, iterators and integral constants.
 */

#ifndef BOOST_MPL11_FWD_CATEGORIES_HPP
#define BOOST_MPL11_FWD_CATEGORIES_HPP

namespace boost { namespace mpl11 { namespace category {
    struct none { };
    struct integral_constant { };

    // Sequence categories
    struct forward_sequence { };
    struct bidirectional_sequence : forward_sequence { };
    struct random_access_sequence : bidirectional_sequence { };
    struct associative_sequence   : forward_sequence { };

    // Iterator categories
    struct forward_iterator { };
    struct bidirectional_iterator : forward_iterator { };
    struct random_access_iterator : bidirectional_iterator { };
}}} // end namespace boost::mpl11::category

#endif // !BOOST_MPL11_FWD_CATEGORIES_HPP
