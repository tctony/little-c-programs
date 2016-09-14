#include <stdio.h>
#include "indirect_symbol.h"
#include "foo.h"

extern void private_foo();
extern void static_foo();

 int main(int argc, char *argv[])
 {
   print_all_indirect_symbols();

   putchar('\n');

   foo();
   private_foo();

   return 0;
 }
