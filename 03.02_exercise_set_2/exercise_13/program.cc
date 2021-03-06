#include <iostream>
#include <bitset>

int main(int agrc, char* argv[])
{
  int const value = std::stoi(argv[1]);// Convert input to signed int

                                       // Print value and binary representation
  std::cout << value << " = " << std::bitset<8*sizeof(value)>(value) << " = ";  

  size_t bitsInVal = sizeof(value)*8;
                                       // If value is neg, print negative value
  if (value < 0)
    std::cout << (1 << (bitsInVal - 1)) << " + ";

  std::string powSum;
                                       // Loop over remaining bits and print
									   // value if its a 1.
  for (int i = 1 << (bitsInVal - 2); i != 0; i >>= 1)
  {
    if (value & i)
      powSum += std::to_string(i) + " + ";
  }

  powSum = powSum.substr(0, powSum.length() - 3);
  std::cout << powSum << '\n';
}
