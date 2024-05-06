#define COLS 5

void difSimFil(const int v1[], const int v2[], int v3[]){
  for(int i = 0, j = 0, z = 0; v1[i] != -1  || v2[j] != -1;){
    if (v1[i] == -1)
      v3[z++] = v2[j++]; 
    else if (v2[j] == -1)
      v3[z++] = v1[i++]; 
    else if(v1[i] < v2[j])
      v3[z++] = v1[i++]; 
    else if (v1[i] > v2[j])
      v3[z++] = v2[j++]; 
    else {
      i++;
      j++;
    }
  }
  return;
}

void difSim(const int m1[][COLS], const int m2[][COLS], int m3[][COLS], int filas){
  for(int i = 0; i < filas; i++)
    difSimFil(m1[i], m2[i], m3[i]);
  return;
}
