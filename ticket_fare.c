#include "metro_ticket.h"
#include "ticket_fare.h"
#include "header.h"
#include "adding_station.h"
void ticket_fare(ticket *tick, char *src, char *dest, int opt)
{
    // function
    float times = 0;
    int found_src = 0, found_dest = 0;;
    int dest_val, src_val;
    if (opt == 1)
    {
        for (int i = 0; i < V_N; i++)
        {
	     //printf("Checking: %s with %s\n", purple_line[i], src);
            if (!strcasecmp (purple_line[i], src))
            {
                found_src = 1;
		src_val = i;
            }
            
            if (!strcasecmp (purple_line[i], dest))
            {
		dest_val = i;
		found_dest = 1;
                // break;
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
	    // printf("Checking: %s with %s\n", green_line[i], src);
            if (!strcasecmp (green_line[i], src))
            {
		src_val = i;
                found_src = 1;
            }
            
            if (!strcasecmp (green_line[i], dest))
            {
		dest_val = i;
		found_dest = 1;
                // break;
            }

            if (found_src)
            {
                times++;
            }
        }
    }
    // printf("src = %d, dest = %d\n", src_val, dest_val);
    float index_diff = (float) abs(src_val - dest_val);
    // printf("DIFFERENCE = %f\n", index_diff);
    times = index_diff;  // Set times to number of stations between source and destination
    //printf(" tyme = %f\n", times);
//printf("PRRRICEEEE = %lf\n", PRICE);
    // Now calculate cost
    tick->cost_per_tick = PRICE * times;  // Price per ticket
  //  printf("ONE PERSONNN = %lf\n", PRICE * times);
    tick->total_cost = (float) tick->cost_per_tick * (tick->num_pass);
}
