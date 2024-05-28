static tList removeElemRec(tList l, elemType elem, int *removed) {
  if (l == NULL)
    return l;
  int compare = l->cmp(l->head, elem);
  if (compare > 0){
    l->tail = removeElemRec(l->tail, elem, removed);
    return l;
  }
  if (compare < 0) {
    *removed = 0;
    return l;
  }
  tList next = l->tail;
  *removed = 1;
  free(l);
  return next;

}

int removeElem(listADT l, elemType elem) {
  int removed = 0;
  l-list = removeElemRec(l->list, elemType elem, &removed);
  return removed;
}

elemType getElementAtIndexRec(tList l, int idx) {
  if(idx == 0)
    return l->head;
  return getElementAtIndexRec(l->tail, idx-1);
}
elemType getElementAtIndex(const listADT l, int idx) {
  assert(l->size > idx && idx >= 0);
  return getElementAtIndexRec(l->list, idx);
}
