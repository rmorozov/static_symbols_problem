#pragma once

#include <cassert>

using Payload = int;

inline int val = {};

class __attribute__((visibility("default"))) Foo
{
  public:
  Foo() = default;
  ~Foo() { assert( inner == &val ); }
  int* inner = &val;
  private:

};



