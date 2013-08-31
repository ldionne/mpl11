/*!
 * @file
 * Defines categories for sequences, iterators and integral constants.
 */

#ifndef BOOST_MPL11_CATEGORIES_HPP
#define BOOST_MPL11_CATEGORIES_HPP

namespace boost { namespace mpl11 { namespace category {
    struct integral_constant { };

    // Sequence categories
    struct forward_sequence { };
    struct bidirectional_sequence : forward_sequence { };
    struct random_access_sequence : bidirectional_sequence { };

    struct extensible_sequence { };
    struct front_extensible_sequence : extensible_sequence { };
    struct back_extensible_sequence : extensible_sequence { };

    struct associative_sequence : forward_sequence { };
    struct extensible_associative_sequence : associative_sequence { };

    // Iterator categories
    struct forward_iterator { };
    struct bidirectional_iterator : forward_iterator { };
    struct random_access_iterator : bidirectional_iterator { };
}}} // end namespace boost::mpl11::category

#endif // !BOOST_MPL11_CATEGORIES_HPP
