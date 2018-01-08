# correct_cpp_is_perfect

Branch|[Travis CI](https://travis-ci.org)|[Codecov](https://www.codecov.io)
---|---|---
master|[![Build Status](https://travis-ci.org/CarmenIJsebaart/correct_cpp_is_perfect.svg?branch=master)](https://travis-ci.org/CarmenIJsebaart/correct_cpp_is_perfect)|[![codecov.io](https://codecov.io/github/CarmenIJsebaart/correct_cpp_is_perfect/coverage.svg?branch=master)](https://codecov.io/github/CarmenIJsebaart/correct_cpp_is_perfect/branch/master)

[Correct C++](https://github.com/richelbilderbeek/correct_cpp) chapter 'is_perfect'.

## Goal

 * Refactor an application to lower cyclomatic complexity

## Prerequisites

 * Understand [how this course works](https://github.com/richelbilderbeek/correct_cpp/blob/master/how_this_course_works.md)
 * Have some experience [how to lower cyclomatic complexity](https://github.com/richelbilderbeek/correct_cpp/blob/master/lower_cyclomatic_complexity.md)
 * Have written [a correct 'is_prime' program](https://github.com/richelbilderbeek/correct_is_prime)

## Exercise

Write a command-line interface (CLI) program that determines if a number is a perfect number (see 'What is a perfect number?').

Here are the outputs and exit statuses the program should give:

Call to `is_perfect`|Output|Exit status
---|---|---
`./is_perfect`|Any|1
`./is_perfect X`, where X is a number that is not perfect|`false` (with newline)|0
`./is_perfect Y`, where Y is a number that is perfect|`true` (with newline)|0
`./is_perfect nonsense`|Any|1
`./is_perfect 6 28`|Any|1

In this exercise, you start with the code below. Yes, that code works perfectly. 

```c++
#include <cassert>
#include <iostream>
#include <string>
#include <vector>

int main(int argc, char* argv[])
{
  if (argc != 2) return 1;
  try
  {
    const int value{std::stoi(argv[1])};

    // Is this a perfect number?
    // -1: unknown
    //  0: false
    //  1: true
    int is_perfect{-1};

    // Negative values are not perfect
    if (value < 0) is_perfect = 0;

    // Zero is not perfect
    if (is_perfect == -1 && value == 0) is_perfect = 0;

    //Collect the proper divisors
    std::vector<int> proper_divisors;
    
    if (is_perfect == -1 && value == 2)
    {
      proper_divisors.push_back(1);
    }
    else if (is_perfect == -1 && value > 2)
    {
      for (int denominator=1; denominator!=value-1; ++denominator)
      {
        if (value % denominator == 0)
        {
          proper_divisors.push_back(denominator);
        }
      }
    }

    //sum the proper divisors, if not known if number is perfect
    int sum{0};
    if (is_perfect == -1)
    {
      for (const int proper_divisor: proper_divisors) { sum += proper_divisor; }
    }
    if (is_perfect == -1 && sum == value) is_perfect = 1;
    if (is_perfect == -1) is_perfect = 0;

    //show
    assert(is_perfect != -1); //Must be known now
    if (is_perfect == 1)
    {
      std::cout << "true\n";
    }
    else
    {
      std::cout << "false\n";
    }
  }
  catch (const std::exception&)
  {
    return 1;
  }
}
```


 * You may start from scratch if you think that is simpler
 * The code has a too high cyclomatic complexity. Simplify it. See [how to lower cyclomatic complexity](https://github.com/richelbilderbeek/correct_cpp/blob/master/lower_cyclomatic_complexity.md). 
   Tips:
     * the comments tell what is happening, create functions with those names
     * a possible function prototype: `std::vector<int> collect_proper_divisors(const int i) noexcept`
     * a possible function prototype: `int sum(const std::vector<int>& v) noexcept`
     * a possible function prototype: `bool is_perfect(const int i) noexcept`
 * Your code needs to have 100% code coverage, regardless how it is called (that is, with zero, one or more arguments), 
   see [how to get 100 percent code coverage](https://github.com/richelbilderbeek/correct_cpp/blob/master/get_100_percent_code_coverage.md)

## What is a perfect number?

Any number is a perfect number if the sum of its proper divisors equals itself.
A number's divisors are those value the number can be divided by without leaving a remainer.
A number's proper divisors are those divisors different from the number itself.

For example:
 * 6 has divisors 1,2,3 and 6
 * 6 has proper divisors 1,2 and 3
 * 6 is perfect, as 1+2+3=6

Number|Is perfect?
Less than 6|No
6|Yes
7 to an including 27|No
28|Yes

## External links

 * [Wikipedia's page about perfect numbers](https://en.wikipedia.org/wiki/Perfect_number)
 * [Download the Qt Creator file `main.pro`](https://raw.githubusercontent.com/richelbilderbeek/correct_cpp/master/shared/main.pro)

