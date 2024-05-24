void push(stackADT s, int elem) {
  TNode *node = malloc(sizeof(*node));
  node->elem = elem;
  node->tail = s->first;
  s->first = node;
  s->elemCount++;
}

int pop(stackADT s) {
  assert(isEmpty(s) == 0)
  TNode *aux = s->first;
  int res = aux->elem;
  s->first = aux->tail;
  s->elemCount--;
  free(aux);
  return res;
}

tList addRec(tList l, elemType elem, int (*cmp) (elemType, elemType), int *flag){
  int c;
  if(l == NULL || 0 < (c = cmp(elem, l->head))) {
    tNode *node = malloc(sizeof(*node));
    node->head = elem;
    node->tail = l;
    *flag= 1;
    return node;
  }
  if(c == 0)
    return l;
  l->tail = add(l->tail, elem);
  return l;
}

int add(listADT l, elemType elem) {
  int added = 0;
  l->first = addRec(l->first, elem, l->cmp, &added);
  l->elemCount += added;
  return added;
}
