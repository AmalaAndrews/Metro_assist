#include "header.h"
#include "metro_ticket.h"
#include "adding_station.h"
#include "location.h"
#include "ticket_fare.h"

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
            scanf("%49s", src);
            //printf("\n");
            printf("Destination Station : ");
            scanf("%49s", dest);
            printf("\n");
        }while(check_purple(src, dest));
        strcpy(tick->source, src);
        strcpy(tick->destination, dest);
        break;
        case 2:
        // green line
        do {
            initial(&opt);
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
            // printf("%s\n", green_line[G_N - 1]);
            printf("\n\nSource Station      : ");
            scanf("%49s", src);
            printf("Destination Station : ");
            scanf("%49s", dest);
            printf("\n");
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
    // printf("\nTHANKS! PLEASE CHECK AND VERIFY THE BELOW BOOKING DETAILS: \n");
    // printf("No of Passengers    : %d\n", tick->num_pass);
    // printf("Source Station      : %s\n", tick->source);
    // printf("Destination Station : %s\n", tick->destination);
    // printf("Travel Date: \n");
    // printf("Cost per ticket: ₹%.2f\n");
    // printf("Travel amount: ₹%.2f\n");
    // printf("Valid till: \n")
    //printf("HIII\n");
    //ticketvalidity(tick->validity);
    ticket_fare(tick, src, dest, opt);
    display(tick);
    printf("\n\nGreat! Which payment option do yoy want to go with?\n");
    //printf("Pay Using UPI\n");
    printf("Online payment\n");
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
     if(flag == 2)
    {
        return 0;
    }
    return 1;
}
    

/*void ticketvalidity(char *validity, ticket *tick)
{
    printf("Hi..1\n");
    time_t current = time(NULL);
 printf("Hi..2\n");
    struct tm *timeinfo = localtime(&current);
    printf("Hi..3\n");
    timeinfo->tm_hour += 6;
    printf("Hi..4\n");
    mktime(timeinfo);
    printf("Hi..5\n");
    strftime(validity, sizeof(tick->validity), "Valid until: %I:%M %p, %d-%m-%Y", timeinfo);
    
   /* if (!strftime(validity, 50, "Valid until: %I:%M %p, %d-%m-%Y", timeinfo)) {
        printf("Error formatting ticket validity!\n");
    }printf("Hi..6\n");
}*/
/*void ticketvalidity(char *validity) {
    time_t current = time(NULL);
    struct tm *timeinfo = localtime(&current);

    // Add 6 hours to the current time
    timeinfo->tm_hour += 6;
    mktime(timeinfo);

    // Write formatted string to validity with a size limit
    if (strftime(validity, 100, "Valid until: %I:%M %p, %d-%m-%Y", timeinfo) == 0) {
        printf("Failed to format validity string\n");
    } else {
        printf("Formatted validity: %s\n", validity);
    }*/
    /*void ticketvalidity(char *validity) {
    time_t current = time(NULL);
    struct tm *timeinfo = localtime(&current);

    // Add 6 hours to the current time
    timeinfo->tm_hour += 6;
    mktime(timeinfo); // Normalize time structure

    // Format the string manually using sprintf
    sprintf(validity, "Valid until: %02d:%02d %s, %02d-%02d-%04d",
            (timeinfo->tm_hour % 12 == 0 ? 12 : timeinfo->tm_hour % 12), // Hour in 12-hour format
            timeinfo->tm_min,                                          // Minutes
            (timeinfo->tm_hour >= 12 ? "PM" : "AM"),                   // AM/PM
            timeinfo->tm_mday,                                         // Day of the month
            timeinfo->tm_mon + 1,                                      // Month (0-11, so add 1)
            timeinfo->tm_year + 1900);                                 // Year (years since 1900)
}*/


void display(ticket *tick)
{
    printf("\nTHANKS! PLEASE CHECK AND VERIFY THE BELOW BOOKING DETAILS: \n");
    printf("No of Passengers    : %d\n", tick->num_pass);
    printf("Source Station      : %s\n", tick->source);
    printf("Destination Station : %s\n", tick->destination);
    // printf("Travel Date: \n");
    printf("Cost per ticket     : ₹%.2f\n", tick->cost_per_tick);
    printf("Travel amount       : ₹%.2f\n", tick ->total_cost);
    //printf("Debug: Validity size=%zu\n", sizeof(tick->validity));

    // printf("%s\n", tick->validity);
}
