typedef struct palabraCDT *palabraADT;

palabraADT crearVacia();

palabraADT crearDesde(char *s);

void destruirPalabra(palabraADT palabra);

void mostrarPalabra(palabraADT palabra);

palabraADT agregarLetra(palabraADT palabra, char letra);



