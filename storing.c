#include "header.h"
#include "storing.h"


void store_ticket(ticket *tick, const char *username) 
{
    if (!is_user_registered(username)) {
        printf("\033[31mError: User '%s' is not registered. Please register first.\n\033[0m", username);
        return;
    }

    FILE *file = fopen("tickets.txt", "a"); // Append mode
    if (file == NULL) {
        return;
    }

    fprintf(file, "%s\n", username);
    fprintf(file, "    Ticket Number:%d, Source: %s, Destination: %s, Passengers: %d, Cost: ₹%.2f, Valid Until: %s\n",
            tick->tick_num, tick->source, tick->destination, tick->num_pass, tick->total_cost, tick->validity);

    fclose(file);
}

int is_user_registered(const char *username) {
    FILE *file = fopen("users.txt", "r");
    if (file == NULL) {
        printf("\033[31mError: Could not open users file.\033[31m\n");
        return 0;
    }

    char buffer[100], og_username[11];
    while (fgets(buffer, sizeof(buffer), file)) {
        buffer[strcspn(buffer, "\n")] = 0; // Remove newline
        if (sscanf(buffer, "%11s", og_username) != 1) {
            continue; // Skip if extraction fails
        }

        if (strcmp(og_username, username) == 0) {
            fclose(file);
            return 1; // User found
        }
    }

    fclose(file);
    return 0; // User not found
}
