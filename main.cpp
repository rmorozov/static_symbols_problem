#include "lib_a.h"
#include "lib_b.h"

int main()
{
  Bar1 bar1;
  Bar2 bar2;

  bar2.OperateFoo(bar1.GetFoo());

  return 0;

}

