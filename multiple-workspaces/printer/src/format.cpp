#include "format.h"
#include <iostream>
#include <sstream>

std::string format_int(int input)
{
  std::stringstream temp;
  temp << "~~" <<  input << "~~";

  return temp.str();
}
