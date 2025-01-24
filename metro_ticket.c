#include "metro_ticket.h"
#include "location.h"
#include "header.h"
#include "adding_station.h"

void main()
{
    ticket tick;
    int option;
    printf("\n------------------WELCOME TO METRO RESERVATION SYSTEM------------------\n");
    printf("\n1. Book Ticket\n2. View Ticket\n3. View Map\n4. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &option);
    printf("\n");
    switch(option)
    {
        case 1:
        // book ticket
        get_location(&tick);
        break;
        // case 2:
        // cancel ticket
        // break;
        // case 3:
        // view map
        // break;
        case 4:
        // exit
        printf("Thank you for using the Metro Reservation System.\n");
        break;
        default:
        printf("Please enter a valid option\nUsage: Enter 1 or 2 or 3.\n");
    }
}
