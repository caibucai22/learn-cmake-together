#include <cstdlib>
#include <iostream>
#include <string>

std::string say_hello() { return std::string("hello CMake world!"); }

int main()
{
  std::cout << say_hello() << std::endl;
  return EXIT_SUCCESS;
}