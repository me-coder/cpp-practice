#ifndef TESTMACROS_HPP
#define TESTMACROS_HPP

#include <iostream>
#include <iomanip>

// These macros are used for unit testing.

#define CHECK_EQUAL(actual, expected) CHECK_EQUAL_IMPL(actual, expected, __LINE__)

#define CHECK_EQUAL_IMPL(actual, expected, line)  \
  if ((actual) != (expected)) {                   \
    std::cerr << "Failed at line "                \
              << __FILE__ << ":" << line          \
              << ' ' << std::boolalpha            \
              << (actual) << " != " << (expected) \
              << std::noboolalpha << std::endl;   \
  } else {                                        \
    std::cout << "Passed at line "                \
              << __FILE__ << ":" << line          \
              << ' ' << std::boolalpha            \
              << (actual) << " == " << (expected) \
              << std::noboolalpha << std::endl;   \
  }

#endif
