#include "header.h"

#include "view_ticket.h"
void display_ticket() {
    char username[15];
    printf("\033[94mEnter your registered phone number:\033[0m");
    scanf("%s", username);
    FILE *file = fopen("tickets.txt", "r");
    if (file == NULL) {
        printf("Error: Could not open tickets file.\n");
        return;
    }

    char buffer[1024];
    int found = 0;

     while (fgets(buffer, sizeof(buffer), file)) {
        // Remove the newline character from the buffer
        buffer[strcspn(buffer, "\n")] = 0;
	// Check if the line matches the username (phone number)
        if (strcmp(buffer, username) == 0) {
            found = 1;
            printf("\nTickets for %s:\n", username);

            // Print associated ticket details (until next username or EOF)
            while (fgets(buffer, sizeof(buffer), file)) {
                buffer[strcspn(buffer, "\n")] = 0;
                if (isdigit(buffer[0])) break; // Stop at the next username (phone number)
                printf("%s\n", buffer);
            }

            // Move file pointer back by one line so that the next username check works correctly
            fseek(file, -strlen(buffer) - 1, SEEK_CUR);
        }
    }

    if (!found) {
        printf("No tickets found for this user.\n");
    }

    fclose(file);
}
