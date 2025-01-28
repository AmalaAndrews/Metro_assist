#include "metro_ticket.h"
#include "ticket_fare.h"
#include "header.h"
#include "adding_station.h"
void ticket_fare(ticket *tick, char *src, char *dest, int opt)
{
    // function
    float times = 0;
    int found_src = 0;
    if (opt == 1)
    {
        for (int i = 0; i < V_N; i++)
        {
            if (!strcasecmp (purple_line[i], src))
            {
                found_src = 1;
            }
            
            if (!strcasecmp (purple_line[i], dest))
            {
                break;
            }

            if (found_src)
            {
                times++;
            }
        }
 
    }
    else if(opt == 2)
    {
        for (int i = 0; i < G_N; i++)
        {
            if (!strcasecmp (green_line[i], src))
            {
                found_src = 1;
            }
            
            if (!strcasecmp (green_line[i], dest))
            {
                break;
            }

            if (found_src)
            {
                times++;
            }
        }
    }
    times *= PRICE;
    tick->cost_per_tick = times;
    tick->total_cost = (float) times * (tick->num_pass);
}