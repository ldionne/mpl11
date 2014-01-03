/*!
 * @file
 * Defines the `boost::mpl11::methods` namespace and related namespaces.
 */

#ifndef BOOST_MPL11_DETAIL_METHODS_HPP
#define BOOST_MPL11_DETAIL_METHODS_HPP

namespace boost { namespace mpl11 {
    /*!
     * Contains the version of methods that do not perform sanity
     * checks on their input.
     *
     * When specializing methods directly, i.e. without using the
     * typeclass system, always specialize the methods in this namespace.
     */
    namespace unchecked { }

    /*!
     * Contains the version of methods that perform sanity checks
     * on their input before forwarding to their unchecked counterpart.
     *
     * When creating a new method that has no checks to perform, simply
     * import the name of the method from the `unchecked` namespace.
     * If the method has checks to perform, they must be done in the
     * version of the method living in this namespace.
     */
    namespace checked { }

    /*!
     * Contains the methods of all the typeclasses in the library.
     *
     *
     * @todo
     * Make this customizable in the future.
     */
    namespace methods = checked;
}} // end namespace boost::mpl11

#endif // !BOOST_MPL11_DETAIL_METHODS_HPP
