#define DIM 256

int depura(unsigned char v[], unsigned int dim){
  char apariciones[DIM] = {0};
  char nuevaDim = 0;
  for (int i = 0; i < dim; i++)
    apariciones[v[i]]++;
  for (int i = 0; i < DIM; i++)
    if (apariciones[i])
      v[nuevaDim++] = i;
  return nuevaDim;
}
