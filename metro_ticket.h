#ifndef METRO_TICKET_H
#define METRO_TICKET_H


#define MAX_LENGTH 5

typedef struct ticket{
    char source[50];
    char destination[50];
    int num_pass;
    int tick_num;
    float cost_per_tick;
    float total_cost;
    char cur_date[20];
char validity[50];
// char phone[15];
 struct tickets *link;
}ticket;
typedef struct{
    char phn_numb[15];
    char og_pass[6];
    char old_pass[6];
    ticket *link;
}members;
extern int loc_flag;

extern members mem[MAX_LENGTH];

#endif
