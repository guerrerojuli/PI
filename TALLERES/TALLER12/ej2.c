#include "ej2.h"
#include <stdlib.h>
#include <string.h>
#include <strings.h>

#define BLOCK 20

typedef struct contactNode {
  tContact contact;
  struct contactNode *next;
} tContactNode;

typedef tContactNode *tContactList;

typedef struct group {
  char *groupName;
  tContactList contacts;
  struct group *next;
} tGroup;

typedef tGroup *tGroupList;

struct addressBookCDT {
  tGroupList groups; 
  tGroup *currentGroup;
  tContactNode *currentContact;
};


tGroupList addGroupRec(tGroupList groupList, const char* groupName, int *added){
  *added = 0;
  int cmp = 0;
  if (groupList == NULL || (cmp = strcasecmp(groupList->groupName, groupName)) > 0) {
    tGroup *newGroup = calloc(1, sizeof(*newGroup)); 
    newGroup->next = groupList;
    newGroup->groupName = malloc(strlen(groupName) + 1);
    strcpy(newGroup->groupName, groupName);
    *added = 1;
    return newGroup;
  }
  if (cmp < 0)
    groupList->next = addGroupRec(groupList->next, groupName, added);
  return groupList;
}

tContactList addContactRec(tContactList contactList, const tContact contact, int *added){
  *added = 0;
  int cmp = 0;
  if (contactList == NULL || (cmp = strcasecmp(contactList->contact.name, contact.name)) > 0) {
    tContactNode *newContact = calloc(1, sizeof(*newContact)); 
    newContact->next = contactList;
    newContact->contact = contact;
    *added = 1;
    return newContact;
  }
  if (cmp < 0)
    contactList->next = addContactRec(contactList->next, contact, added);
  return contactList;
}

addressBookADT newAddressBook() {
  return calloc(1, sizeof(struct addressBookCDT));
}

tGroup *searchGroup(tGroupList groupList, const char* groupName) {
  int cmp = 0;
  if (groupList == NULL || (cmp = strcasecmp(groupList->groupName, groupName)) > 0) {
    return NULL;
  }
  if (cmp < 0)
    return searchGroup(groupList->next, groupName);
  return groupList;
}

int addGroup(addressBookADT addressBook, const char * groupName) {
  int added = 0;
  addressBook->groups = addGroupRec(addressBook->groups, groupName, &added);
  return added;
}

int addContact(addressBookADT addressBook, const char * groupName, tContact contact) {
  int added = 0;
  tGroup *group = searchGroup(addressBook->groups, groupName);
  if (group != NULL)
    group->contacts = addContactRec(group->contacts, contact, &added);
  return added;
}

/*
** Permite iterar por todos los contactos de la agenda
** QUE PERTENEZCAN AL GRUPO INDICADO por parámetro en toBegin
** El orden es alfabético por nombre del contacto.
*/
void toBeginForGroup(addressBookADT addressBook, const char * groupName) {
  tGroup *group = searchGroup(addressBook->groups, groupName);
  if (group == NULL)
    return;
  addressBook->currentContact = group->contacts;
}

int hasNextForGroup(addressBookADT addressBook) {
  return addressBook->currentContact != NULL;
}

/* Retorna un contacto, aborta si no hay siguiente */
tContact nextForGroup(addressBookADT addressBook) {
  if (!hasNextForGroup(addressBook))
    abort();
  tContact toReturn = addressBook->currentContact->contact;
  addressBook->currentContact = addressBook->currentContact->next;
  return toReturn;
}

/*
** Permite iterar por todos los grupos de la agenda
** El orden es alfabético por nombre del grupo.
*/
void toBegin(addressBookADT addressBook) {
  addressBook->currentGroup = addressBook->groups;
}

int hasNext(addressBookADT addressBook) {
  return addressBook->currentGroup != NULL;
}

/* Retorna una copia del grupo, aborta si no hay siguiente */
char * next(addressBookADT addressBook) {
  if (!hasNext(addressBook))
    abort();
  char *toReturn = malloc(strlen(addressBook->currentGroup->groupName) + 1);
  strcpy(toReturn, addressBook->currentGroup->groupName);
  addressBook->currentGroup = addressBook->currentGroup->next;
  return toReturn;
}
