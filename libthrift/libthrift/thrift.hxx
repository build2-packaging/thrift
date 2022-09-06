#pragma once

#include <iosfwd>
#include <string>

#include <libthrift/export.hxx>

namespace thrift
{
  // Print a greeting for the specified name into the specified
  // stream. Throw std::invalid_argument if the name is empty.
  //
  LIBTHRIFT_SYMEXPORT void
  say_hello (std::ostream&, const std::string& name);
}
