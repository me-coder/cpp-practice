#include <string>

#include "UnitTests.hpp"

/**
 *  See SensibleLessThan.hpp for instructions on for the
 *  exercise. This file is the main program which executes
 *  the test suite twice - once for each string type.
 */

int main(int argc, char* argv[])
{
  test_suite<std::string>();
  test_suite<const char*>();

  return 0;
}
