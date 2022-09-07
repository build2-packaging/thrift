#undef NDEBUG
#include <cassert>
#include <memory>
#include <string>

#include <thrift/config.h>
#include <thrift/TOutput.h>

std::string res;
void print_func(const char* arg)
{
  res = arg;
}

int main ()
{
  assert(std::string(PACKAGE_NAME) == "thrift");

  apache::thrift::TOutput out;
  out.setOutputFunction(print_func);
  res = "";
  out.printf("test");

  assert(res == "test");

  return 0;
}
