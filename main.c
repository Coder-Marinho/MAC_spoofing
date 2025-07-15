//
// Created by marinho on 7/15/25.
//
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>


void clearScreen();

int generate();

int main() {
    clearScreen();
    int choice = 0;

    printf("enunciado\n");
    printf("Select your choice:\n");
    printf("Press 1 to generate random MAC address \n");
    printf("Press 2 to auto change MAC address\n");
    scanf("%d", &choice);

    while (choice < 1 || choice > 2){
        printf("Invalid input. Try again:\n");
        printf("Press 1 to generate random MAC address \n");
        printf("Press 2 to auto change MAC address\n");
        scanf("%d", &choice);
    }

    if (choice == 1) {
        generate();
    }
    else if (choice == 2) {
        printf("Feature coming soon...\n");
    }

    return 0;
}

void clearScreen() {
    const char *CLEAR_SCREEN_ANSI = "\e[1;1H\e[2J";
    write(STDOUT_FILENO, CLEAR_SCREEN_ANSI, 12);
}

//This function are responsible to generate a random MAC address
//ever it is called allowing auto or manual option
int generate() {
    int choice = 0;
    srand(time(0));
    int joint[6];

    for (int i = 0; i < 6; i++) {
        joint[i] = rand() %256;

        if (i == 0) {
            joint[i] = 0x02;
        }

        printf("%.2X", joint[i]);

        if (i < 5) {
            printf(":");
        }
    }
    printf("\n");

    printf("Press 1 for back to menu or 2 for new generate\n");
    scanf("%d", &choice);

    while (choice < 1 || choice > 2) {
        printf("Invalid input. Try again:\n");
        printf("Press 1 for back to menu or 2 for new generate\n");
        scanf("%d", &choice);
    }

    if (choice == 1) {
        main();
    }
    if (choice == 2) {
        generate();
    }
}