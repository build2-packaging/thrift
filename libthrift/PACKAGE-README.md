# libthrift

Apache Thrift C++ library.

Thrift is a lightweight, language-independent software stack for
point-to-point RPC implementation.
Thrift provides clean abstractions and implementations for data transport,
data serialization, and application level processing. The code generation
system takes a simple definition language as input and generates code
across programming languages that uses the abstracted stack to build
interoperable RPC clients and servers.

This package contains the C++ runtime library that needs to be linked to any
application that wishes to use the Thrift-generated C++ code.


## Usage

The package provides the following libraries (see the documentation for
background):

```
lib{thrift}    (depends on openssl for SSL support)
lib{thriftnb}  (depends on libevent, on openssl for SSL support)
lib{thriftz}   (depends on zlib)
```

The libraries except `lib{thrift}` are optional and are disabled by default.
Additionally, SSL support in `lib{thrift}` and `lib{thriftnb}` is optional and
is disabled by default. These optional features can be enabled with the
following configuration variables:

```
config [bool] config.libthrift.openssl  ?= false
config [bool] config.libthrift.libevent ?= false
config [bool] config.libthrift.zlib     ?= false
```

For example, if you wish to use both `lib{thrift}` and `lib{thriftz}` in your
application with SSL support, then you can add the following to your
`manifest`:

```
depends:
\
libthrift ^0.17.0
{
  require
  {
    config.libthrift.openssl = true
    config.libthrift.zlib = true
  }
}
\
```

And the following to your `buildfile`:

```
import libs = libthrift%lib{thrift thriftz}
```
