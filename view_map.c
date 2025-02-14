#include "header.h"
#include "adding_station.h"
#include "view_map.h"

void view_map()
{
    // initial(&opt);
    printf("\033[41;97m========================METRO MAP===========================\033[0m\n\n");
    fflush(stdout);
    printf("\033[45;97m   PURPLE LINE   \033[0m");
	    // %-20s\033[42;97m%-30s\033[0m\n\n", "PURPLE LINE", " ", "GREEN LINE");
    printf("                                 ");
    printf("\033[102;97m   GREEN LINE   \033[0m\n\n");

    int max_size = (V_N > G_N) ? V_N : G_N;
    for(int i = 0; i < max_size; i++)
    {
       if (i < V_N)
       {
          if (i == 14)
          {
               printf("\033[107;35m%-20s\033[0m", purple_line[i]);
          }
          else{
               printf("\033[107;35m%-30s\033[0m", purple_line[i]);
          }
        
       }
       else{
        printf("%-30s", " ");
       }

       if (i == 14)
       {
	   printf("   ");
         printf("\033[107;33m<--- Intersection --->\033[0m");
	 printf("        ");
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
          printf("\033[107;32m%s\033[0m", green_line[i]);
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
