TList sortedList(TList l) {
  if (l == NULL || l->tail == NULL)
    return l;
  TList next = sortedList(l->tail);
  if (l->elem < next->elem) {
    l->tail = next;
    return l;
  }
  free(l);
  return next;
}
