#include <stdio.h>
#include <stdlib.h>
#include <cxxabi.h>

int main(int argc, char *argv[]) {
  if (argc < 2) {
    printf("usage: %s mangled_symbol ...\n", argv[0]);
    return -1;
  }

  char *demangled_name;
  int status = -1;
  demangled_name = abi::__cxa_demangle(argv[1], NULL, NULL, &status);
  printf("%s -> %s\n", argv[1], demangled_name);
  free(demangled_name);

  return 0;
}
/*
  clang++ demangle.cpp
  ./a.out _ZN2CA11Transaction17observer_callbackEP19__CFRunLoopObservermPv
  _ZN2CA11Transaction17observer_callbackEP19__CFRunLoopObservermPv -> CA::Transaction::observer_callback(__CFRunLoopObserver*, unsigned long, void*)
 */
