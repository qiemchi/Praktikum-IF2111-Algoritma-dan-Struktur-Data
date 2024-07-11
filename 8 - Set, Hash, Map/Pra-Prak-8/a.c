#include <stdio.h>
#include <string.h>
#define S_(x) #x
#define S(x) S_(x)
#define PBWIDTH 64
#define PBCHAR '#'

static void progressbar(unsigned percent) {
  char pbstr[PBWIDTH];
  memset(pbstr, PBCHAR, PBWIDTH);
  fprintf(stderr, "\r[%-" S(PBWIDTH) ".*s] %u%%",
      percent * PBWIDTH / 100, pbstr, percent);
}
int main(void) {
  progressbar(70);
  fprintf(stderr, "\n");
}