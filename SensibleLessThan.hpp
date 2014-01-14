#ifndef SENSIBLELESSTHAN_HPP
#define SENSIBLELESSTHAN_HPP

/**
 *  In this file you must provide code for implementing a sorting 'comparator'
 *  called SensibleLessThan, that is capable of sorting text strings in the
 *  same way a human would. For example, a lay-person would sort "A5" before "A11"
 *  since 5 is less than 11.
 *
 *  The comparison should,
 *   - treat positive integers embedded in the string as a human would
 *   - implement strict-weak ordering
 *   - ignore whitespace length differences within the string
 *   - be case insenstive
 *   - handle leading zeros on numbers
 *   - be usable as a stand-alone comparison for two strings
 *   - be usable as a sorting comparison for algorithms such as std::sort
 *   - be usable for ordering STL containers such as std::map or std::set
 *
 *  For example:
 *
 *    "a5" < "a11"        - because 5 is less than 11
 *    "6xxx < 007asdf"    - because 6 < 7
 *    "00042Q < 42s"      - because Q < s alphabetically
 *    "6   8" < "006 9"   - because 8 < 9
 *
 *  See UnitTests.hpp for more examples of how the comparison should behave.
 *
 *  Objective:
 *
 *  The unit tests in UnitTests.hpp #include *this* file and refer to the type
 *  SensibleLessThan which you must provide.  The comparator is parameterized
 *  on a string type. We require a solution that will work with both the C++
 *  string class std::string, and the C string const char*.
 *
 *  In order to achieve success you must provide code such that:
 *
 *    a) main.cpp can be compiled with a conforming Standard C++ compiler.
 *    b) When executed, the program reports that all tests have passed.
 *
 *  Rules:
 *    1) You may use C++ development tools of your choice. e.g. Visual C++
 *       on Windows, gcc on Linux or gcc on Mac OS X.
 *    2) You should restrict yourself to using the facilities provided by
 *       Standard C++ and the Standard C++ Library.  Use of third-party
 *       libraries or non-standard compiler extensions is not permitted.
 *    3) You may use as many additional source code or header files of
 *       your own devising as required to solve the problem.
 *    4) You should may not modify the main.cpp, TestMacros.hpp, or
 *       UnitTests.hpp files (unless you think _we_ have made a mistake,
 *       in which case we'd like to know about it!)
 */

// PROVIDE YOUR IMPLEMENTATION OF SensibleLessThan HERE
#include <string>

template <typename T>
class SensibleLessThan
{
public:
    bool operator()(T const & lhs, T const & rhs)
    {
        std::string str1(lhs), str2(rhs);
        return this->Comparer(str1.c_str(), str2.c_str());
    }
private:
    bool Comparer(const char * lhs, const char * rhs)
    {
        return true;
    }
};

#endif
