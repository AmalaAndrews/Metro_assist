#ifndef LOCATION_H
#define LOCATION_H

void get_location(ticket *tick, const char *people);
int compare(const char*str1, const char*str2);
int check_purple(char *src,char *dest);
int check_green(char *src,char *dest);
void cal_ticket_cost(void);
extern int print_flag;
void time_validity(ticket *tick);
void display(ticket *tick);
#endif
