char *strcat(char *s, char *t) {
  char *origen = s;
  for (; *s; s++);
  for (; (*s = *t); s++);
  return origen;
}
