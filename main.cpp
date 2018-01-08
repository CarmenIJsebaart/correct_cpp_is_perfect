#include <cassert>
#include <iostream>
#include <string>
#include <vector>

std::vector<int> collect_proper_devisors(const int value, const int is_perfect)
{
  std::vector<int> proper_divisors;
  if (is_perfect == -1 && value == 2)
  {
    proper_divisors.push_back(1);
  }
  else if (is_perfect == -1 && value > 2)
  {
    for (int denominator = 1; denominator != value - 1; ++denominator)
    {
      if (value % denominator == 0)
      {
        proper_divisors.push_back(denominator);
      }
    }
  }
  return proper_divisors;
}

int sum_proper_devisors(std::vector<int> proper_divisors, int is_perfect)
{
  int sum = 0;
  if (is_perfect == -1)
  {
    for (const int proper_divisor: proper_divisors) { sum += proper_divisor; }
  }
  return sum;
}

int is_perfect_number(const int value)
{
  // Is this a perfect number?
  // -1: unknown
  //  0: false
  //  1: true
  int is_perfect = -1;

  // Negative values are not perfect
  if (value < 0) is_perfect = 0;

  // Zero is not perfect
  if (is_perfect == -1 && value == 0) is_perfect = 0;

  //Collect the proper divisors
  std::vector<int> proper_divisors = collect_proper_devisors(value, is_perfect);

  //sum the proper divisors, if not known if number is perfect
  int sum = sum_proper_devisors(proper_divisors, is_perfect);
  if (is_perfect == -1 && sum == value) is_perfect = 1;
  if (is_perfect == -1) is_perfect = 0;

  //show
  assert(is_perfect != -1); //Must be known now
  return is_perfect;
}

int do_main(const std::vector<std::string> &args)
{
  if (args.size() != 2) return 1;
  try
  {
    const int value{std::stoi(args[1])};
    int is_perfect = is_perfect_number(value);
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
  return 0;
}

int main(int argc, char* argv[])
{
  assert(do_main( { "is_perfect" } ) == 1);
  assert(do_main( { "is_perfect", "12" } ) == 1);
  assert(do_main( { "is_perfect", "6" } ) == 1);
  assert(do_main( { "is_perfect", "nonsense" } ) == 1);
  assert(do_main( { "is_perfect", "6", "28" } ) == 1);
  assert(do_main( { "is_perfect", "6413654546542121312" } ) == 1);

  const std::vector<std::string> args(argv, argv + argc);
  return do_main(args);
}
