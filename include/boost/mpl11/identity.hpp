/*!
 * @file
 * Defines `boost::mpl11::identity`.
 */

#ifndef BOOST_MPL11_IDENTITY_HPP
#define BOOST_MPL11_IDENTITY_HPP

namespace boost { namespace mpl11 {
    //! Returns `T` unchanged.
    template <typename T>
    struct identity {
        using type = T;
    };
}}

#endif // !BOOST_MPL11_IDENTITY_HPP