#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "quiz.h"

int score = 0, total_questions = 0;

// Helper: Binary to Decimal
int binary_to_decimal(const char *binary) {
    int decimal = 0;
    while (*binary) {
        decimal = decimal * 2 + (*binary++ - '0');
    }
    return decimal;
}

// Helper: Decimal to Binary
void decimal_to_binary(int n, char *binary) {
    binary[0] = '\0';
    char temp[32];
    int i = 0;
    do {
        temp[i++] = (n % 2) + '0';
        n /= 2;
    } while (n > 0);
    temp[i] = '\0';

    // reverse temp into binary
    for (int j = 0; j < i; j++) {
        binary[j] = temp[i - j - 1];
    }
    binary[i] = '\0';
}

// Ask one random question
void ask_question() {
    int type = rand() % 4;
    char user_input[100];
    int user_ans_int;
    int correct = 0;

    switch (type) {
        case 0: {
            // Binary → Decimal
            int num = rand() % 64; // 0–63
            char binary[32];
            decimal_to_binary(num, binary);

            printf("Q: What is %s (binary) in decimal? ", binary);
            scanf("%d", &user_ans_int);

            if (user_ans_int == num) correct = 1;
            break;
        }

        case 1: {
            // Decimal → Binary
            int num = rand() % 64;
            char correct_bin[32], input_bin[100];
            decimal_to_binary(num, correct_bin);

            printf("Q: What is %d (decimal) in binary? ", num);
            scanf("%s", input_bin);

            if (strcmp(input_bin, correct_bin) == 0) correct = 1;
            break;
        }

        case 2: {
            // Hex → Decimal
            int num = rand() % 256;
            printf("Q: What is %X (hex) in decimal? ", num);
            scanf("%d", &user_ans_int);

            if (user_ans_int == num) correct = 1;
            break;
        }

        case 3: {
            // Binary Addition
            int a = rand() % 16;
            int b = rand() % 16;
            char bin_a[16], bin_b[16];
            decimal_to_binary(a, bin_a);
            decimal_to_binary(b, bin_b);

            printf("Q: What is %s + %s (binary)? ", bin_a, bin_b);
            scanf("%s", user_input);

            char correct_sum[32];
            decimal_to_binary(a + b, correct_sum);

            if (strcmp(user_input, correct_sum) == 0) correct = 1;
            break;
        }
    }

    total_questions++;
    if (correct) {
        printf("✅ Correct!\n");
        score++;
    } else {
        printf("❌ Incorrect.\n");
    }
}

void print_quiz_banner() {
    printf("\n");
    printf("===========================================\n");
    printf("   🔢 Number Conversion Quiz Game 🔢\n");
    printf("===========================================\n");
    printf(" Test your skills on binary, decimal, hex\n");
    printf(" conversions and arithmetic operations!\n");
    printf("-------------------------------------------\n");
}



void run_quiz_module() {
    print_quiz_banner();
    srand(time(0));  // Seed random once
    char choice;

    do {
        ask_question();

        printf("Score: %d/%d\n", score, total_questions);
        do {
        printf("Do you want to continue? (y/n): ");
        scanf(" %c", &choice);

        if (choice != 'y' && choice != 'Y' && choice != 'n' && choice != 'N') {
            printf("⚠️  Invalid input. Please enter 'y' or 'n'.\n");
        }
    } while (choice != 'y' && choice != 'Y' && choice != 'n' && choice != 'N');


    } while (choice == 'y' || choice == 'Y');

    printf("\nFinal Score: %d/%d\n", score, total_questions);
}
