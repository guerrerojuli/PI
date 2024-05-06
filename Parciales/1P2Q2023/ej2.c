#define M 6

int sumaBorde(int mat[][M], int index) {
  int suma = 0;
  for (int i = index + 1; i < M - index; i++){
    suma += mat[i][index]; 
    suma += mat[index][i];
    suma += mat[M - i][M - index -1];
    suma += mat[M - index - 1][M - i];
  }
  return suma;
}

void bordes(int mat[][M], int sumas[]) {
  for (int i = 0; i < M / 2; i++)
    sumas[i] = sumaBorde(mat, i);
}

int main(void){
  int m1[][M] = {
    {1, 1, 1, 1, 1, 1},
    {1, 2, 2, 2, 2, 1},
    {1, 2, 3, 3, 2, 1},
    {1, 2, 3, 3, 2, 1},
    {1, 2, 2, 2, 2, 1},
    {1, 1, 1, 1, 1, 1}
  };
  int sumas1[M/2];
  bordes(m1, sumas1);
  return 0;

}
