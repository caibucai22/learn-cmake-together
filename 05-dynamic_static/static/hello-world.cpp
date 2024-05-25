#include "Message.hpp"
#include <cstdlib>
#include <iostream>

int main()
{
  Message say_hello("hello, cmake world!");
  std::cout << say_hello << std::endl;

  Message say_goodbye("goodbye, cmake world!");
  std::cout << say_goodbye << std::endl;

  return EXIT_SUCCESS;
}