#include <stdio.h>

#include "foo.h"

void foo() {
  printf("foo\n");
}

void private_foo() {
  printf("private foo\n");
}

static void static_foo() __attribute__((unused));
static void static_foo() __attribute__((noinline));
static void static_foo() {
  printf("static foo\n");
}

