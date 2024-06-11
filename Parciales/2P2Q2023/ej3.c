int contarGrupos(char *s, char c) {
  if (!*s)
    return 0;
  return ((*s == c) && (*(s + 1) !=  c)) + contarGrupos(s + 1, c);
}

int countGroups(TList l, char c) {
  if (l == NULL)
    return 0;
  return ((l->head == c) && ((l->tail == NULL) || (l->tail->head != c))) + countGroups(l->tail, c);
}
