#include <string.h>

#define DAYSOFYEAR  366
#define ISDAYVALID(day) (0 < (day) && (day) <= 366)

typedef struct visitor {
  char *name;
  struct visitor *next;
} tVisitor;

typedef tVisitor *tVisitorList;

typedef struct {
  size_t dayTickets;  //la cantidad de tickets es igual a la dimension de visitors
  tVisitorList visitors;
  tVisitor *current;
} tDay;


struct museumTicketCDT {
  size_t yearTickets;
  tDay daysOfYear[DAYSOFYEAR];
}


static tVisitorList addVisitor(tVisitorList visitors, const char* visitor, int *added) {
  *added = 0;
  if (visitors == NULL)
    return NULL;
  int cmp;
  if ((cmp = strcmp(visitors->name, visitor)) > 0) {
    tVisitor *newVisitor = malloc(sizeof(*newVisitor));
    newVisitor->name = visitor;
    newVisitor->next = visitors;
    *added = 1;
    return newVisitor;
  }
  if (cmp < 0)
    visitors->next = addVisitor(visitors->next, visitor, added);
  return visitors;
}


museumTicketADT newMuseumTicket() {
  return calloc(1, sizeof(struct museumTicketCDT));
}

int addTicket(museumTicketADT museumTicket, size_t dayOfYear, const char *visitor) {
  if (!ISDAYVALID(dayOfYear))
    return 0;
  int added = 0;
  museumTicket->dayOfYear[dayOfYear].visitors = addVisitor(museumTicket->dayOfYear[dayOfYear].visitors, visitor, &added);
  museumTicket->dayOfYear[dayOfYear].dayTickets += added;
  museumTicket->yearTickets += 1;
  return added;
}

int dayTickets(const museumTicketADT museumTicket, size_t dayOfYear) {
  if (!ISDAYVALID(dayOfYear))
    return -1;
  return museumTicket->daysOfYear[dayofYear].dayTickets;
}

void toBeginByDay(museumTicketADT museumTicket, size_t dayOfYear) {
  if (!ISDAYVALID(dayOfYear) || !hasNextByDay(museumTicket, dayOfYear))
    abort();
  museumTicket->daysOfYear[dayOfYear].current = museumTicket->daysOfYear[dayOfYear].visitors;
}
