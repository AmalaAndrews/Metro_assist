#include "metro_ticket.h"
#include "location.h"
#include "header.h"
#include "adding_station.h"
#include "view_map.h"
#include "view_ticket.h"
//#include "delete_ticket.h"

int loc_flag = 0;
members mem[MAX_LENGTH] = {0};

int mem_count = 0;

// Function to load users from a file
void load_users()
{
    FILE *file = fopen("users.txt", "r");
    if (!file)
    {
        return; // No file exists yet
    }

    while (fscanf(file, "%s %s %s", mem[mem_count].phn_numb, mem[mem_count].og_pass, mem[mem_count].old_pass) == 3)
    {
        mem[mem_count].link = NULL; // Initialize ticket pointer
        mem_count++;
        if (mem_count >= MAX_LENGTH) break; // Prevent overflow
    }

    fclose(file);
}

// Function to save a new user to the file
void save_user(members *user)
{
    FILE *file = fopen("users.txt", "a"); // Append mode
    if (!file)
    {
        printf("Error opening file.\n");
        return;
    }

    fprintf(file, "%s %s %s\n", user->phn_numb, user->og_pass, user->old_pass);
    // printf("USER NUMBER: %s\n", user->phn_numb);
    fclose(file);
}

int main()
{
    ticket tick;
    members people;
    int option, flag = 0;
    char pass[6] = {0}, re_pass[6] = {0};
    char temp[20], temp_phn[20];
    int opt = 1;
    initial(&opt);
    opt = 2;
    initial(&opt);
    int login;

    load_users();

    printf("\033[45;97m                     WELCOME TO METRO TRAVEL ASSISTANT                      \033[0m\n");
    while (1)  // Loop until successful sign-up or login
    {
        printf("\n\033[36m1. Sign Up\n    or\n2. Sign In\033[0m\n");
	printf("\033[94mEnter your option: \033[0m");
        scanf(" %d", &login);

        if (login == 1)  // Sign-Up
        {
            printf("\n\033[94mEnter phone number: \033[0m");
            scanf("%s", temp_phn);

            // Check if the phone number already exists
            int exists = 0;
            for (int i = 0; i < mem_count; i++)
            {
                if (strcmp(temp_phn, mem[i].phn_numb) == 0)
                {
                    exists = 1;
                    break;
                }
            }

            if (exists)
            {
                printf("\033[31m!!!User already exists. Try signing in.\033[0m\n");
                continue;  // Go back to login choice
            }

            if (mem_count >= MAX_LENGTH)
            {
                printf("\033[31m!!!No space for more users.\033[0m\n");
                return 1;
            }

            while (1)  // Password entry loop
            {
                printf("\n\033[94mEnter password: (Upto 5 characters)\033[0m\n");
                scanf("%5s", pass);
                printf("\033[94mRe-enter password: \033[0m");
                scanf("%5s", re_pass);

                if (!strcmp(pass, re_pass))
                {
                    strcpy(mem[mem_count].phn_numb, temp_phn);
                    strcpy(mem[mem_count].og_pass, pass);
                    strcpy(mem[mem_count].old_pass, pass);
                    mem[mem_count].link = NULL;  // No tickets initially
                    mem_count++;

                    // Save to file
                    save_user(&mem[mem_count - 1]);

                    printf("\033[32mAccount created successfully!!!\033[0m\n");
                    break;  // Exit password loop
                }
                else
                {
                    printf("\033[31mOOPs!!!Passwords do not match. Try again.\033[0m\n");
                }
            }
        }
        else if (login == 2)  // Sign-In
        {
            printf("\033[94mEnter phone number: \033[0m");
            scanf("%s", temp);
            printf("\033[94mEnter password: \033[0m");
            scanf("%5s", pass);

            int found = 0;
            for (int i = 0; i < mem_count; i++)
            {
                if (strcmp(temp, mem[i].phn_numb) == 0 && strcmp(pass, mem[i].og_pass) == 0)
                {
                    found = 1;
		    mem_count = i;
                    break;
                }
            }

            if (!found)
            {
                printf("\033[31mInvalid phone number or password. Try again.\033[0m\n");
                continue;  // Go back to login choice
            }

            printf("\033[32mLogin successful!\033[0m\n");
            break;  // Exit login loop
        }
        else
        {
            printf("\033[31mInvalid option. Please enter 1 or 2.\033[0m\n");
        }
    }

    // menu loop
    while (1)
    {
	sleep(2);
        printf("\n\n\033[36m1. Book Ticket\n2. View Ticket\n3. View Map\n4. Exit\033[0m\n");
        printf("\033[94mEnter your choice: \033[0m");
	getchar();
        scanf("%d", &option);
        printf("\n");
        switch(option)
        {
            case 1:
            // book ticket
            get_location(&tick,mem[mem_count].phn_numb);
            break;
            case 2:
            //view ticket
	    display_ticket();
            break;
            //case 3:
            // cancel ticket
	    //cancel_ticket(mem[mem_count].phn_numb);
            break;
            case 3:
            // view map
            view_map();
            break;
            case 4:
            // exit
            printf("\n\n\033[45;97m              THANK YOU FOR USING THE METRO TRAVEL ASSISTANT.              \033[0m\n\n");
            flag = 1; // then put this whole code in while(1) and if exit is pressing then only go out if flag == 1 then break from while(1)
            break;
            default:
            printf("\n\033[31mPlease enter a valid option\nUsage: Enter 1 or 2 or 3.\033[0m\n");
        }
        if (flag)
        {
            break;
        }
    }
}
