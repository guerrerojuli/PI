#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N_DIRS 4
#define MAX_RADIUS 30
#define IN_RADIUS(x, y, r) ((x) * (x) + (y) * (y) < (r) * (r))

typedef struct {
  int x;
  int y;
} tParticle;

typedef struct {
  int x;
  int y;
} tDirection;

void moveRandomly(tParticle *p) {
  static tDirection dirs[] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
  int random = rand() % N_DIRS;
  p->x += dirs[random].x;
  p->y += dirs[random].y;
}

void printTable(int times[], int dim) {
  printf("%10s\t|%10s\t|%10s\n", "RADIUS", "TIME", "RADIUS/TIME");
  for (int i = 0; i < dim; i++)
    printf("%10d\t|%10d\t|%7.3f\n", i + 1, times[i], (float)(i + 1) / times[i]);
}

int main(void) {
  int r, times[MAX_RADIUS] = {0};
  srand(time(NULL));

  for (r = 1; r <= MAX_RADIUS; r++) {
    tParticle p = {0, 0};
    while (IN_RADIUS(p.x, p.y, r)) {
      times[r - 1]++;
      moveRandomly(&p);
    }
  }

  printTable(times, MAX_RADIUS);

  return 0;
}
