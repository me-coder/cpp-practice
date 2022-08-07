#ifndef UNITTESTS_HPP
#define UNITTESTS_HPP

#include <vector>
#include <set>
#include <algorithm>

#include "TestMacros.hpp"

#include "SensibleLessThan.hpp"

template <typename String>
void test_letters()
{
  SensibleLessThan<String> comparer;
  String lhs = "Aadvark";
  String rhs = "Zygote";
  CHECK_EQUAL(comparer(lhs, rhs), true);
  CHECK_EQUAL(comparer(rhs, lhs), false);
  CHECK_EQUAL(comparer(rhs, rhs), false);
  CHECK_EQUAL(comparer(lhs, lhs), false);
}

template <typename String>
void test_numbers()
{
  SensibleLessThan<String> comparer;
  String lhs = "423";
  String rhs = "1259";
  CHECK_EQUAL(comparer(lhs, rhs), true);
  CHECK_EQUAL(comparer(rhs, lhs), false);
  CHECK_EQUAL(comparer(rhs, rhs), false);
  CHECK_EQUAL(comparer(lhs, lhs), false);
}

template <typename String>
void test_different()
{
  SensibleLessThan<String> comparer;
  String lhs = "54";
  String rhs = "Well";
  CHECK_EQUAL(comparer(lhs, rhs), true);
  CHECK_EQUAL(comparer(rhs, lhs), false);
  CHECK_EQUAL(comparer(rhs, rhs), false);
  CHECK_EQUAL(comparer(lhs, lhs), false);
}

template <typename String>
void test_mixed()
{
  SensibleLessThan<String> comparer;
  String lhs = "Well7";
  String rhs = "Well23";
  CHECK_EQUAL(comparer(lhs, rhs), true);
  CHECK_EQUAL(comparer(rhs, lhs), false);
  CHECK_EQUAL(comparer(rhs, rhs), false);
  CHECK_EQUAL(comparer(lhs, lhs), false);
}

template <typename String>
void test_separated()
{
  SensibleLessThan<String> comparer;
  String lhs = "Well54/7";
  String rhs = "Well054/76";
  CHECK_EQUAL(comparer(lhs, rhs), true);
  CHECK_EQUAL(comparer(rhs, lhs), false);
  CHECK_EQUAL(comparer(rhs, rhs), false);
  CHECK_EQUAL(comparer(lhs, lhs), false);
}

template <typename String>
void test_separated2()
{
  SensibleLessThan<String> comparer;
  String lhs = "Well 12/2";
  String rhs = "Well 12/11";
  CHECK_EQUAL(comparer(lhs, rhs), true);
  CHECK_EQUAL(comparer(rhs, lhs), false);
  CHECK_EQUAL(comparer(rhs, rhs), false);
  CHECK_EQUAL(comparer(lhs, lhs), false);
}

template <typename String>
void test_whitespace_separated_numbers()
{
  SensibleLessThan<String> comparer;
  String lhs = "Well 12 2";
  String rhs = "Well 12 11";
  CHECK_EQUAL(comparer(lhs, rhs), true);
  CHECK_EQUAL(comparer(rhs, lhs), false);
  CHECK_EQUAL(comparer(rhs, rhs), false);
  CHECK_EQUAL(comparer(lhs, lhs), false);
}

template <typename String>
void test_dates()
{
  SensibleLessThan<String> comparer;
  String lhs = "1974-1-12";
  String rhs = "1974-02-15";
  CHECK_EQUAL(comparer(lhs, rhs), true);
  CHECK_EQUAL(comparer(rhs, lhs), false);
  CHECK_EQUAL(comparer(rhs, rhs), false);
  CHECK_EQUAL(comparer(lhs, lhs), false);
}

template <typename String>
void test_leading_zeros()
{
  SensibleLessThan<String> comparer;
  String lhs = "Well0324";
  String rhs = "Well003421";
  CHECK_EQUAL(comparer(lhs, rhs), true);
  CHECK_EQUAL(comparer(rhs, lhs), false);
  CHECK_EQUAL(comparer(rhs, rhs), false);
  CHECK_EQUAL(comparer(lhs, lhs), false);
}

template <typename String>
void test_ignore_whitespace()
{
  SensibleLessThan<String> comparer;
  String lhs = "Well 1";
  String rhs = "Well  2";
  CHECK_EQUAL(comparer(lhs, rhs), true);
  CHECK_EQUAL(comparer(rhs, lhs), false);
  CHECK_EQUAL(comparer(rhs, rhs), false);
  CHECK_EQUAL(comparer(lhs, lhs), false);
}

template <typename String>
void test_empty()
{
  SensibleLessThan<String> comparer;
  String lhs = "";
  String rhs = "something";
  CHECK_EQUAL(comparer(lhs, rhs), true);
  CHECK_EQUAL(comparer(rhs, lhs), false);
  CHECK_EQUAL(comparer(rhs, rhs), false);
  CHECK_EQUAL(comparer(lhs, lhs), false);
}

template <typename String>
void test_case()
{
  SensibleLessThan<String> comparer;
  String lhs = "abc";
  String rhs = "DEF";
  CHECK_EQUAL(comparer(lhs, rhs), true);
  CHECK_EQUAL(comparer(rhs, lhs), false);
  CHECK_EQUAL(comparer(rhs, rhs), false);
  CHECK_EQUAL(comparer(lhs, lhs), false);
}

template <typename String>
void test_decimals()
{
  SensibleLessThan<String> comparer;
  String lhs = "1.212";
  String rhs = "1.234";
  CHECK_EQUAL(comparer(lhs, rhs), true);
  CHECK_EQUAL(comparer(rhs, lhs), false);
  CHECK_EQUAL(comparer(rhs, rhs), false);
  CHECK_EQUAL(comparer(lhs, lhs), false);
}

template <typename String>
void test_checkered()
{
  SensibleLessThan<String> comparer;
  String lhs = "123abc456";
  String rhs = "abc123def";
  CHECK_EQUAL(comparer(lhs, rhs), true);
  CHECK_EQUAL(comparer(rhs, lhs), false);
  CHECK_EQUAL(comparer(rhs, rhs), false);
  CHECK_EQUAL(comparer(lhs, lhs), false);
}

template <typename String>
void test_eirigk_failure()
{
  SensibleLessThan<String> comparer;
  String lhs = "Kali Well ";
  String rhs = "wMal_1";
  CHECK_EQUAL(comparer(lhs, rhs), true);
  CHECK_EQUAL(comparer(rhs, lhs), false);
  CHECK_EQUAL(comparer(rhs, rhs), false);
  CHECK_EQUAL(comparer(lhs, lhs), false);
}

template <typename String>
void test_well_11_failure()
{
  SensibleLessThan<String> comparer;
  String lhs = "Well 11";
  String rhs = "Well 11/1";
  CHECK_EQUAL(comparer(lhs, rhs), true);
  CHECK_EQUAL(comparer(rhs, lhs), false);
  CHECK_EQUAL(comparer(rhs, rhs), false);
  CHECK_EQUAL(comparer(lhs, lhs), false);
}

template <typename String>
void test_sort_vector()
{
  // Here we provide a manually sorted array. We copy it,
  // shuffle it, and sort it using the SensibleLessThan
  // comparator.  We then check that the sorted array is
  // equal to what we started with.
  const int num = 8;
  String s[num] = { "Well 1",
                    "Well 2",
                    "Well 11",
                    "Well 11/1",
                    "Well 23/1",
                    "Well  23/2",
                    "Well 23/11a",
                    "Well 23/11B" };

  std::vector<String> v(s, s + num);
  std::vector<String> w = v;
  std::random_shuffle(w.begin(), w.end());
  std::sort(w.begin(), w.end(), SensibleLessThan<String>());
  CHECK_EQUAL(std::equal(w.begin(), w.end(), v.begin()), true);
}

template <typename String>
void test_set_comparator()
{
  // Since these three strings are 'equal' according to the
  // SensibleLessThan comparison, only one of them should be
  // inserted into the std::set
  std::set<String, SensibleLessThan<String> > s;
  s.insert("Well 23/11a");
  s.insert("well 023/11A");
  s.insert("WELL  23/011a");
  CHECK_EQUAL(s.size(), 1U);
}

template <typename String>
void test_suite()
{
  test_letters<String>();
  test_numbers<String>();
  test_different<String>();
  test_mixed<String>();
  test_separated<String>();
  test_separated2<String>();
  test_dates<String>();
  test_leading_zeros<String>();
  test_ignore_whitespace<String>();
  test_whitespace_separated_numbers<String>();
  test_empty<String>();
  test_decimals<String>();
  test_checkered<String>();
  test_eirigk_failure<String>();
  test_well_11_failure<String>();
  test_sort_vector<String>();
  test_set_comparator<String>();
}

#endif
