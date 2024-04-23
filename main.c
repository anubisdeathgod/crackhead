#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main() {
    printf("                            __   .__                       .___\n");
    printf("  ________________    ____ |  | _|  |__   ____ _____     __| _/\n");
    printf("_/ ___\\_  __ \\__  \\ _/ ___\\|  |/ /  |  \\_/ __ \\\\__  \\   / __ | \n");
    printf("\\  \\___|  | \\// __ \\\\  \\___|    <|   Y  \\  ___/ / __ \\_/ /_/ | \n");
    printf(" \\___  >__|  (____  /\\___  >__|_ \\___|  /\\___  >____  /\\____ | \n");
    printf("     \\/           \\/     \\/     \\/    \\/     \\/     \\/      \\/ \n");
    printf("\n");

    char archive[256]; 
    char password_list[256];

    printf("Archive name: ");
    fgets(archive, sizeof(archive), stdin);
    archive[strcspn(archive, "\n")] = 0; // Remove trailing newline if present

    if (strlen(archive) == 0) {
        printf("Archive name not provided.\n");
        exit(0);
    }

    printf("Password list: ");
    fgets(password_list, sizeof(password_list), stdin);
    password_list[strcspn(password_list, "\n")] = 0; // Remove trailing newline if present

    if (strlen(password_list) == 0) {
        printf("Password list not provided.\n");
        exit(0);
    }

    // Open the password list file
    FILE *file = fopen(password_list, "r");
    
    if (file == NULL) {
        printf("Failed to open password list file.\n");
        exit(0);
    }
    
    char pass[100000];
    while (fscanf(file, "%s", pass) == 1) {
        // Attempt to extract the archive with the current password
        char command[200];
        chdir("C:\\Program Files\\7-Zip\\");
        sprintf(command, "7z.exe x -p%s \"%s\" -o\"cracked\" -y > nul", pass, archive);
        int result = system(command);
        if (result == 0) {
            printf("Cracking with the password:%s\n", archive, pass); // Display cracking status
            printf("Archive cracked! Password is: %s\n", pass);
            break; // Break out of the loop if the password is found
        } else {
            printf("Failed attempt with password: %s\n", pass);
        }
    }

    fclose(file);
    return 0;
}
