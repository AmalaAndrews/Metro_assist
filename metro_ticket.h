#ifndef METRO_TICKET_H
#define METRO_TICKET_H


// #define MAX_LENGTH 20
typedef struct{
    char source[50];
    char destination[50];
    int num_pass;
    float cost_per_tick;
    float total_cost;
char validity[20];
}ticket;


#endif