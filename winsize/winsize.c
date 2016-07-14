#include <stdio.h>
#include <unistd.h>

#include <sys/ioctl.h>


int getWindowSize(int *rows, int *cols)
{
  struct winsize ws;

  if (ioctl(1, TIOCGWINSZ, &ws) == -1 || ws.ws_col == 0) {
    printf("get window size by ioctl failed\n");

    return -1;
  }

  *cols = ws.ws_col;
  *rows = ws.ws_row;

  return 0;
}

int main(int argc, char *argv[])
{
  int rows, cols;
  if (getWindowSize(&rows, &cols) == -1) {
    printf("query terminal size failed\n");
    return 1;
  }
  else {
    printf("terminal size is %dx%d (cols / rows)\n", cols, rows);
    return 0;
  }
}
