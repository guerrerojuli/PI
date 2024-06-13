#include <stdlib.h>

void desordenar(int arreglo[], unsigned int dim){
  srand(time(NULL));
  for(int i = 0; i < dim; i++){
		randomIndex = rand()%dim;
		aux = arreglo[i];
    arreglo[i] = arreglo[randomIndex];
		arreglo[randomIndex] = aux;
	}
}
