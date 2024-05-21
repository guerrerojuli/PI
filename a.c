void push(stackADT s, int elem) {
  if (s->size == s->cantElem) {
    s->size += BLOQUE;
    s->v = realloc(s->v, s->size * sizeof(*s->v));
  }
  s->v[s->cantElem++] = elem;
}

