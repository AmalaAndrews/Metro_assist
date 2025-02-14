#include "header.h"
#include "metro_ticket.h"
#include "adding_station.h"
#include "location.h"
#include "ticket_fare.h"
#include "storing.h"
int print_flag = 0;
int dis_flag = 0;
void get_location(ticket *tick, const char *people)
{
    int tick_count = 0;
    char src[50];
    char dest[50];
    int num_of_pass;
    int opt;
    float amnt = 0.0;
    int route_flag = 0;
    
    do{
        printf("\033[94mEnter route you want: \033[0m\n");
        printf("\033[36m1. Purple Line\n2. Green Line\033[0m\n");
        printf("\033[94mEnter your choice: \033[0m");
        scanf("%d", &opt);
        printf("\n");
        switch(opt)
        {
            case 1:
            // purple line
            route_flag = 0;
            do {
                initial(&opt);
                printf("\033[105;97mPURPLE LINE ROUTE: \033[0m\n");
               for (int i = 0; i < V_N; i++)
               {
                  printf("%s ", purple_line[i]); 
                  if(i != 0 && i % 6 == 0)
                  {
                    printf("\n");
                  }
                  if (i != (V_N - 1))
                  {
                    printf("\033[95m -> \033[0m");
                  }
                }
                printf("\n\n\033[94mSource Station      : \033[0m");
                scanf(" %[^\n]", src);
                printf("\033[94mDestination Station : \033[0m");
                scanf(" %[^\n]", dest);
                printf("\n");
               }while(check_purple(src, dest));
               strcpy(tick->source, src);
               strcpy(tick->destination, dest);
	       // strcpy(tick->phone, people);
               break;
               case 2:
               // green line
               route_flag = 0;
               do {
               initial(&opt);
               // show which all stations
               printf("\033[42;97mGREEN LINE ROUTE: \033[0m\n");
               for (int i = 0; i < G_N; i++)
               {
                  printf("%s ", green_line[i]);
                  if(i != 0 && i % 6 == 0)
                  {
                      printf("\n");
                  }
                  if (i != (G_N - 1))
                  {
                      printf("\033[32m -> \033[0m");
                  }
                }
                printf("\n\n\033[94mSource Station      : \033[0m");
                scanf(" %[^\n]s", src);
                printf("\033[94mDestination Station : \033[0m");
                scanf(" %[^\n]s", dest);
                printf("\n");
            }while(check_green(src, dest));
            strcpy(tick->source, src);
            strcpy(tick->destination, dest);
	    // strcpy(tick->phone, people);
            break;
            default:
            printf("\033[31mPlease enter a valid option\nUsage: Enter 1 or 2\033[0m\n\n");
            route_flag = 1;
            break;
        }
    }while(opt != 1 && opt != 2);    
    
    do{
        printf("\033[94mNumber of Passengers: \033[0m\n");
        printf("\033[36m1\n2\n3\n4\n5\n6\n\033[0m");
        printf("\033[94mEnter your choice   : \033[0m");
        scanf("%d", &num_of_pass);
        if(num_of_pass < 1 || num_of_pass > 6)
        {
            printf("\n\033[31mPlease enter a valid option\nUsage: Enter 1\n2\n3\n4\n5\n6\n\033[0m");
        }
    }while(num_of_pass < 1 || num_of_pass > 6);
    tick->num_pass = num_of_pass;
    time_validity(tick);
    ticket_fare(tick, src, dest, opt);
    int pay_flag = 0;
    do{
        if(pay_flag == 0 && amnt != 0)
        {
            printf("\n\n\033[31mPLEASE PAY THE CORRECT AMOUNT!!!\033[0m\n");
        }
        print_flag = 1;
        display(tick);
        printf("\n\n\033[32mGreat! Please pay the amount to complete the payment\033[0m\n");
        for(long int wait = 1000000000; wait--; );
        printf("\n\033[94mEnter the amount you paid: \033[0m");
        scanf("%f", &amnt);
        if (amnt != tick->total_cost)
        {
            pay_flag = 0;
        }
        else {
                pay_flag = 1;
        }
    }while(amnt != tick->total_cost);
    printf("\n\033[32mStatus: Order complete\033[0m\n");
    // tick_count++;
    srand(time(0));
    tick_count = rand() % 100;
    tick->tick_num = tick_count;
    printf("\033[32mThank you, fetching your ticket details.\033[0m\n");
    for(long int wait = 1000000000; wait--; );
    dis_flag = 1;
    // printf("HUMBOOO %s\n", people);
    store_ticket(tick,people);
    display(tick);
    loc_flag = 1;
}

int compare(const char*str1, const char*str2)
{
    while(*str1 && *str2)
    {
        if(tolower((unsigned char)*str1) != tolower((unsigned char)*str2))
        {
            return 0;
        }
        str1++;
        str2++;
    }
    return *str1 == *str2;
}

int check_purple(char *src,char *dest)
{
    // check if the given both is in corresponding line
    int flag = 0;
    for (int i = 0; i < V_N; i++)
    {
        if (compare(src, purple_line[i]))
        {
            flag++;
        }
        if (compare(dest, purple_line[i]))
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
        if (compare(src, green_line[i]))
        {
            flag++;
        }
        if (compare(dest, green_line[i]))
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
 
void time_validity(ticket *tick)
{
    time_t t;
    struct tm *tm_info;
    time(&t);
    tm_info = localtime(&t);
    char buff[20];
    snprintf(buff, sizeof(buff), "%02d/%02d/%04d", tm_info->tm_mday, tm_info->tm_mon + 1, tm_info->tm_year + 1900);
    strcpy(tick->cur_date, buff);
    tm_info->tm_hour += 6;
    t = mktime(tm_info);
    tm_info = localtime(&t);
    char *am_pm = (tm_info->tm_hour >= 12) ? "PM" : "AM";
    char new_buff[60];
    snprintf(new_buff, sizeof(new_buff), "%02d/%02d/%04d %02d:%02d:%02d %s", tm_info->tm_mday, tm_info->tm_mon + 1, tm_info->tm_year + 1900,
             tm_info->tm_hour, tm_info->tm_min, tm_info->tm_sec, am_pm);
    strcpy(tick->validity, new_buff);
}

void display(ticket *tick)
{
    if (dis_flag)
    {
        // dis_flag = 0;
        printf("\n\n\033[32mYour transaction is successfully completed\033[0m\n");
        
    }
    if (print_flag == 2)
    {
        printf("\033[35mTICKET DETAILS\033[0m\n\n");
    }
    else if(print_flag == 1)
    {
        printf("\n\033[94mTHANKS! PLEASE CHECK AND VERIFY THE BELOW BOOKING DETAILS: \033[0m\n");
    }
    if(dis_flag)
    {
	dis_flag = 0;
        printf("        Ticket Number : %d\n", tick->tick_num);
    }
    printf("===============================================\n");
    printf("No of Passengers      | %d                     \n", tick->num_pass);
    //printf("==============================================\n");
    printf("Source Station        | %s               \n", tick->source);
    //printf("==============================================\n");
    printf("Destination Station   | %s                 \n", tick->destination);
    //printf("==============================================\n");
    printf("Travel Date           | %s            \n", tick->cur_date);
    //printf("==============================================\n");
    printf("Cost per ticket       | ₹%.2f               \n", tick->cost_per_tick);
    //printf("==============================================\n");
    printf("Travel amount         | ₹%.2f               \n", tick ->total_cost);
    //printf("==============================================\n");
    printf("Ticket validity until | %s\n", tick->validity);
    printf("===============================================\n");
}
