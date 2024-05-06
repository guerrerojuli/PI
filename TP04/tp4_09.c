#define ENT_HORA 6
#define ENT_MINUTOS 30

int llegaTemprano(const int hora, const int minutos) {
  return (hora < ENT_HORA || (hora == ENT_HORA && minutos <= ENT_MINUTOS));
}
