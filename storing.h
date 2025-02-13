#ifndef STORING_H
#define STORING_H
#include "metro_ticket.h"
int is_user_registered(const char *username);
void store_ticket(ticket *tick, const char*username);
#endif
