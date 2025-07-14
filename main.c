#include <stdio.h>
#include <stdlib.h>
#include "quiz.h"
#include "twos_complement.h"
#include "visualizer.h"
#include "bit_byte_ops.h"

void show_banner() {
    printf("=======================================\n");
    printf("     Number System Learning Project    \n");
    printf("=======================================\n");
}

int main() {
    int choice;

    while (1) {
        show_banner();
        printf("\nMain Menu:\n");
        printf("1. Number Conversion Quiz Game\n");
        printf("2. Two's Complement Arithmetic Simulator\n");
        printf("3. Number Conversion Visualizer\n");
        printf("4. Bit/Byte Conversion & Bitwise Operations\n");
        printf("5. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                run_quiz_module();
                break;
            case 2:
                run_twos_complement_module();
                break;
            case 3:
                run_visualizer_module();
                break;
            case 4:
                run_bit_byte_module();
                break;
            case 5:
                printf("Exiting program. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Try again.\n");
        }

        printf("\nPress Enter to continue...\n");
        getchar(); // consume newline left by scanf
        getchar(); // wait for enter
    }

    return 0;
}
