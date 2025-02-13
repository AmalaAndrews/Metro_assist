#ifndef LOCATION_H
#define LOCATION_H

void get_location(ticket *tick);
int check_purple(char *src,char *dest);
int check_green(char *src,char *dest);
void cal_ticket_cost(void);
// void ticketvalidity(char *validity);
void display(ticket *tick);
#endif
