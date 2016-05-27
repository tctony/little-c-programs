#include <stdio.h>

int main(int argc, char *argv[])
{
  unsigned short word = 0x1234; // assume sizeof(unsigned short) == 2
  unsigned char *p = (unsigned char *) &word;
  printf((p[0] == 0x12 ? "Big Endian Machine\n" : "Little Endian Machine\n"));

  return 0;
}
