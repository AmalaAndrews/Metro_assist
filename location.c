#include "metro_ticket.h"
#include "location.h"
#include "header.h"
#include "adding_station.h"

void get_location(ticket *tick)
{
    char src[50];
    char dest[50];
    int num_of_pass;
    int opt;
    printf("1. Purple Line\n2. Green Line\n");
    scanf("%d", &opt);
    switch(opt)
    {
        case 1:
        // purple line
        do {
            initial(&opt);
            // show which all stations
            printf("PURPLE LINE ROUTE: \n");
            for (int i = 0; i < V_N; i++)
            {
                printf("%s ", route_line[i]);
                if(i != 0 && i % 6 == 0)
                {
                    printf("\n");
                }
                if (i != (V_N - 1))
                {
                    printf("-> ");
                }
            }
            printf("\nSource Station: ");
            scanf("%s", src);
            printf("\nDestination Station: ");
            scanf("%s", dest);
        }while(check_valid(src, dest));
        strcpy(tick->source, src);
        strcpy(tick->destination, dest);
        break;
        case 2:
        // green line
        do {
            // show which all stations
            printf("GREEN LINE ROUTE: \n");
            for (int i = 0; i < G_N; i++)
            {
                printf("%s ", route_line[i]);
                if(i != 0 && i % 6 == 0)
                {
                    printf("\n");
                }
                if (i != (G_N - 1))
                {
                    printf("-> ");
                }
            }
            printf("\nSource Station: ");
            scanf("%s", src);
            printf("\nDestination Station: ");
            scanf("%s", dest);
        }while(check_valid(src, dest));
        strcpy(tick->source, src);
        strcpy(tick->destination, dest);
        break;
        default:
        printf("Please enter a valid option\nUsage: Enter 1 or 2\n");
    }    
    printf("\n Number of Passengers: \n");
    printf("1\n2\n3\n4\n5\n6\n");
    scanf("%d", &num_of_pass);
    if(num_of_pass == 1 || num_of_pass == 2 || num_of_pass == 3 || num_of_pass == 4 || num_of_pass == 5 || num_of_pass == 6)
    {
        printf("Please enter a valid option\nUsage: Enter 1\n2\n3\n4\n5\n6\n");
    }
    tick->num_pass = num_of_pass;
    printf("Thanks! Please check and verify the below booking details: \n");
    printf("No of Passengers : %d\n", tick->num_pass);
    printf("Source Station: %s\n", tick->source);
    printf("Destination Station: %s\n", tick->destination);
    // printf("Travel Date: \n");
    // printf("Cost per ticket: ₹%.2f\n");
    // printf("Travel amount: ₹%.2f\n");
    // printf("Valid till: \n")
}

int check_valid(char *src,char *dest)
{
    // check if the given both is in corresponding line
    int flag = 0;
    for (int i = 0; i < V_N; i++)
    {
        if (!strcmp(src, route_line[i]))
        {
            flag++;
        }
        if (!strcmp(dest, route_line[i]))
        {
            flag++;
        }
    }
    if(flag == 2)
    {
        return 0;
    }
    return 1;
}