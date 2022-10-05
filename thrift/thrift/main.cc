#include <cstring> // strncmp()
#include <cstdio>  // printf()

#define main xmain
#include "src/thrift/main.cc"
#undef main

int main (int argc, /*const*/ char** argv)
{
  if (argc == 2 && strncmp(argv[1], "--build2-metadata=", 18) == 0) {
    printf("# build2 buildfile thrift\n");
    printf("export.metadata = 1 thrift\n");
    printf("thrift.name = [string] thrift\n");
    printf("thrift.version = [string] '%s'\n", THRIFT_VERSION_BUILD2);
    printf("thrift.checksum = [string] '%s'\n", THRIFT_VERSION_BUILD2);
    return 0;
  }

  return xmain(argc, argv);
}
