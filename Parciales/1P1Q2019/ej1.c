void resta(int v1[], int v2[], int resta[]) {
  int z = 0;
  for (int i = 0; v1[i] != -1; i++) {
    char encontrado = 0;
    for (int j = 0; v2[j] != -1 && !encontrado; j++)
      if (v1[i] == v2[j])
        encontrado = 1;
    if (!encontrado)
      resta[z++] = v1[i];
  }
  resta[z] = -1;
}
