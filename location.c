#include "header.h"
#include "metro_ticket.h"
#include "adding_station.h"
#include "location.h"

void get_location(ticket *tick)
{
    char src[50];
    char dest[50];
    int num_of_pass;
    int opt;
    printf("Which route you want: \n");
    printf("1. Purple Line\n2. Green Line\n");
    printf("Enter your choice: ");
    scanf("%d", &opt);
    printf("\n");
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
                printf("%s ", purple_line[i]);
                if(i != 0 && i % 6 == 0)
                {
                    printf("\n");
                }
                if (i != (V_N - 1))
                {
                    printf("-> ");
                }
            }
            printf("\n\nSource Station      : ");
            scanf("%s", src);
            //printf("\n");
            printf("Destination Station : ");
            scanf("%s", dest);
            printf("\n");
        }while(check_purple(src, dest));
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
                printf("%s ", green_line[i]);
                if(i != 0 && i % 6 == 0)
                {
                    printf("\n");
                }
                if (i != (G_N - 1))
                {
                    printf("-> ");
                }
            }
            printf("\nSource Station: \n");
            scanf("%s", src);
            printf("\nDestination Station: \n");
            scanf("%s", dest);
        }while(check_green(src, dest));
        strcpy(tick->source, src);
        strcpy(tick->destination, dest);
        break;
        default:
        printf("Please enter a valid option\nUsage: Enter 1 or 2\n");
    }    
    printf("Number of Passengers: \n");
    printf("1\n2\n3\n4\n5\n6\n");
    printf("Enter your choice   : ");
    scanf("%d", &num_of_pass);
    if(num_of_pass < 1 || num_of_pass > 6)
    {
        printf("\nPlease enter a valid option\nUsage: Enter 1\n2\n3\n4\n5\n6\n");
    }
    tick->num_pass = num_of_pass;
    printf("\nTHANKS! PLEASE CHECK AND VERIFY THE BELOW BOOKING DETAILS: \n");
    printf("No of Passengers    : %d\n", tick->num_pass);
    printf("Source Station      : %s\n", tick->source);
    printf("Destination Station : %s\n", tick->destination);
    // printf("Travel Date: \n");
    // printf("Cost per ticket: ₹%.2f\n");
    // printf("Travel amount: ₹%.2f\n");
    // printf("Valid till: \n")
}

int check_purple(char *src,char *dest)
{
    // check if the given both is in corresponding line
    int flag = 0;
    for (int i = 0; i < V_N; i++)
    {
        if (!strcasecmp(src, purple_line[i]))
        {
            flag++;
        }
        if (!strcasecmp(dest, purple_line[i]))
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
int check_green(char *src,char *dest)
{
    // check if the given both is in corresponding line
    int flag = 0;
    for (int i = 0; i < G_N; i++)
    {
        if (!strcasecmp(src, green_line[i]))
        {
            flag++;
        }
        if (!strcasecmp(dest, green_line[i]))
        {
            flag++;
        }
    }
    return (flag == 2) ? 0 : 1;
}