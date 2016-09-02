#include <stdio.h>
#include <time.h>
#include <sys/time.h>
//#include <windows.h>

void timer1();
void timer2();
void timer3();

int main() {
  timer1();
  putchar('\n');
  timer2();
  putchar('\n');
  timer3();
  return 0;
}

void timer1() {
  // tranditional c
  clock_t t1, t2;
  t1 = t2 = clock();

  // loop until t2 gets a different value
  while(t1 == t2)
    t2 = clock();

  printf("%.6fms\n", (double)(t2 - t1) / CLOCKS_PER_SEC * 1000);
}

void timer2() {
  struct timeval t1, t2;
  double elapsedTime;

  gettimeofday(&t1, NULL);
  do {
    gettimeofday(&t2, NULL);
  } while (t1.tv_sec == t2.tv_sec
           && t1.tv_usec == t2.tv_usec);

  elapsedTime = (t2.tv_sec - t1.tv_sec) * 1000.0;        // sec to ms
  elapsedTime += (t2.tv_usec - t1.tv_usec) / 1000.0;     // us to ms
  printf("%.6fms\n", elapsedTime);
}

void timer3() {
  // on windows use QueryPerformanceCounter, QueryPerformanceFrequency
  /*
    LARGE_INTEGER frequency;        // ticks per second
    LARGE_INTEGER t1, t2;           // ticks
    double elapsedTime;

    // get ticks per second
    QueryPerformanceFrequency(&frequency);

    // start timer
    QueryPerformanceCounter(&t1);

    // do something
    ...

    // stop timer
    QueryPerformanceCounter(&t2);

    // compute and print the elapsed time in millisec
    elapsedTime = (t2.QuadPart - t1.QuadPart) * 1000.0 / frequency.QuadPart;
    cout << elapsedTime << " ms.\n";
  */
}
