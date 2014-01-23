/*!
 * @file
 * Defines the @ref Core module.
 */

#ifndef BOOST_MPL11_CORE_HPP
#define BOOST_MPL11_CORE_HPP

namespace boost { namespace mpl11 {
    template <typename x>
    struct box {
        using type = x;
    };

    namespace core_detail {
        template <typename T>
        auto pick_datatype(T*)  -> typename T::mpl_datatype;
        auto pick_datatype(...) -> Foreign;
    }

    template <typename ctor>
    struct datatype {
        using type = decltype(core_detail::pick_datatype((ctor*)nullptr));
    };
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_CORE_HPP
