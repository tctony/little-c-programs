#include <stdio.h>

// 16 times cmp, 
int count_bits_0(unsigned int n) {
  int c = 0;
  while (n != 0) {
    n = (n & n-1);
    ++c;
  }
  return c;
}

int t[256] = { -1 };
int count_bits_1(unsigned int n) {
  if (t[0] == -1) {
    for (int i=0; i<256; ++i) {
      t[i] = count_bits_0(i);
    }
  }

  int c = 0;
  for (int i=0; i<4; ++i) {
    c += t[(n>>(i*8)) & 0xff];
  }
  return c;
}

int count_bits_2(unsigned int n) {
  int mask[] = {
    0x55555555,
    0x33333333,
    0x0f0f0f0f,
    0x00ff00ff,
    0x0000ffff
  };

  for (int i=0, shift=1; i<5; ++i, shift*=2) { 
    n = (n&mask[i]) + ((n>>shift)&mask[i]);
  }

  return (int)n;
}


int main(int argc, char *argv[])
{
#define STR(_V) _STR(_V)
#define _STR(_V) #_V
#define INTEGER 0b10010100010111010110010

  char *s = STR(INTEGER);
  unsigned int i = INTEGER;
  unsigned int c = __builtin_popcount(i);

  printf("integer i: %u (%s)\n", i, s);
  printf("has %u bits of one\n\n", c);

  printf("count_bits_0: %d\n", count_bits_0(i));
  printf("count_bits_1: %d\n", count_bits_1(i));
  printf("count_bits_2: %d\n", count_bits_2(i));

  return 0;
}
