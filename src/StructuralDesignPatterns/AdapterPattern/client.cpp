#include "Adapter.h"

#include <iostream>

#define divide Toolkit::MathsV1::divide   //case:1
//#define divide Toolkit::MathsV2::divide //case:2
//#define divide Toolkit::Adapter::divide //case:3

auto divider(double param1, double param2)
  -> double
  {
  return divide(param1, param2);
  }

int main() 
  {
  std::cout << "\nAPI using, result: "     << divider(374, 4);   //case:1
  //std::cout << "\nNew API using, result: " << divider(374, 4); //case:2
  //std::cout << "\nClient: I don't understand this result:\n";  //case:2
  //std::cout << "\nNew API using, result: " << divider(374, 4); //case:3
  std::cout << "\n";
  return 0;
  }