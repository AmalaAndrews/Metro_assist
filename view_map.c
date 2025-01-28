#include "header.h"
#include "adding_station.h"
#include "view_map.h"

void view_map()
{
    // initial(&opt);
    printf("------------------------METRO MAP------------------------\n");
    fflush(stdout);
    printf("%-30s%-20s%-30s\n\n", "PURPLE LINE", " ", "GREEN LINE");

    int max_size = (V_N > G_N) ? V_N : G_N;
    for(int i = 0; i < max_size; i++)
    {
       if (i < V_N)
       {
          if (i == 14)
          {
               printf("%-20s", purple_line[i]);
          }
          else{
               printf("%-30s", purple_line[i]);
          }
        
       }
       else{
        printf("%-30s", " ");
       }

       if (i == 14)
       {
         printf("<--- Intersection --->        ");
       }
       else if (i < max_size -1 || (1 == V_N - 1 && i == G_N - 1))
       {
          printf("                    ");
       }
       else{
          printf("                            ");
       }
       if (i < G_N)
       {
          printf("%s", green_line[i]);
       }
       printf("\n");
       if (i < max_size - 1)
       {
       if (i + 1 < V_N)
       {
          printf("   ");
         printf("%-30s", "|");
       }
       else{
         printf("%-30s", " ");
       }
       // printf("|");
       if (i + 1 < G_N)
       {
          printf("                      ");
         printf("%-30s", "|");
       }
       else{
         printf("%-30s", " ");
       }
       printf("\n\n");
       }
    }

}
