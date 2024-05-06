#define DIM 5

int esAscendente(int m[][DIM], int v[]) {
  char esAscendente = 1;
  v[0] = m[0][0];
  for (int i = 1, j = 1; i < DIM * DIM && esAscendente; i++) {
    if (*(m + i - 1) > *(m + i))
      esAscendente = 0;
    else
      v[j++] = *(m + i);
  }
}
