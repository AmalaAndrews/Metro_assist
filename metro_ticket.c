#include "metro_ticket.h"
#include "location.h"
#include "header.h"
#include "adding_station.h"
#include "view_map.h"

void main()
{
    ticket tick;
    int option, flag = 0;
    int opt = 1;
    initial(&opt);
    opt = 2;
    initial(&opt);
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
         case 3:
        // view map
        view_map();
        // break;
        case 4:
        // exit
        printf("\n\nThank you for using the Metro Reservation System.\n");
        flag = 1; // then put this whole code in while(1) and if exit is pressing then only go out if flag == 1 then break from while(1)
        break;
        default:
        printf("\nPlease enter a valid option\nUsage: Enter 1 or 2 or 3.\n");
    }
}
