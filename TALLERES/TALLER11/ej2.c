#include <stdlib.h>
#include "ej2.h"

typedef struct node {
  elementType value;
  struct node *next;
} tNode;

// first -> node -> node -> last -> new
struct queueCDT {
  tNode *first;
  tNode *last;
};

queueADT newQueue(void) {
  return calloc(1, sizeof(struct queueCDT));
}
 
// Agrega un elemento al final de la cola
void queue(queueADT q, elementType n) {
  tNode *node = malloc(sizeof(*node));
  node->value = n;
  node->next = NULL;
  if (!isEmpty(q))
    q->last->next = node;
  else 
    q->first = node;
  q->last = node;
  
}
 
// Remueve un elemento del principio de la cola y lo deja en out
void dequeue(queueADT q, elementType * out) {
  if (isEmpty(q))
    return;
  tNode *first = q->first;
  *out = first->value;
  q->first = first->next;
  free(first);
}
 
int isEmpty(queueADT q) {
  return (q->first == NULL);
}
 
void freeQueue(queueADT q) {
  tNode *next;
  for (tNode *node = q->first; node != NULL; node = next) {
    next = node->next;
    free(node);
  }
  free(q);
}
