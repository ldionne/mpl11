/**
 * This file contains the unit tests for the @em fail_on helper.
 */

#include <mpl11/fail_on.hpp>


using namespace mpl11;

using yes = char (&)[1];
using no = char (&)[2];

template <typename T> no failed(fail_on<T>);

yes failed(...);

static_assert(sizeof(failed(int())) == sizeof(yes), "");
