#include <stdio.h>
#include <stdlib.h>
#include "visualizer.h"
#include <unistd.h> // For usleep (animation)
#include <math.h>   // for pow()
#include <string.h>


char hex_map[] = "0123456789ABCDEF";

void decimal_to_hex_visual(int num) {
    int quotients[32], remainders[32];
    char hex_digits[32];
    int count = 0;
    int original = num;

    // Step 1: Division by 16
    while (num > 0) {
        quotients[count] = num;
        remainders[count] = num % 16;
        hex_digits[count] = hex_map[num % 16];
        num /= 16;
        count++;
    }

    // Final row
    quotients[count] = 0;
    remainders[count] = -1;
    hex_digits[count] = '-';
    count++;

    // Banner
    printf("\n============================================\n");
    printf("   🧮 Decimal to Hexadecimal - Visualizer\n");
    printf("============================================\n");
    printf("  Shows how repeated /16 gives hex digits.\n");
    printf("--------------------------------------------\n");

    printf("\nDecimal Input: %d\n", original);
    printf("\nStep | Quotient | Remainder | Hex Digit\n");
    printf("----------------------------------------\n");

    for (int i = 0; i < count; i++) {
        if (remainders[i] == -1)
            printf(" %2d  |   %3d    |     -     |    -\n", i + 1, quotients[i]);
        else
            printf(" %2d  |   %3d    |    %2d     |    %c\n", i + 1, quotients[i], remainders[i], hex_digits[i]);
        usleep(200000);
    }

    // Final Hex (MSB to LSB)
    printf("\n🧠 Hexadecimal (MSB ← LSB): ");
    for (int i = count - 2; i >= 0; i--) {
        printf("%c", hex_digits[i]);
    }
    printf(" ✅\n");
}


void print_decimal_to_binary_banner() {
    printf("\n=========================================\n");
    printf("   🔄 Decimal to Binary - Visualizer\n");
    printf("=========================================\n");
    printf("  This shows how decimal numbers convert\n");
    printf("  step-by-step into binary using division.\n");
    printf("-----------------------------------------\n");
}

void decimal_to_binary_visual(int num) {
    int quotients[32];
    int remainders[32];
    int count = 0;
    int original = num;

    // Step 1: Build table (quotient, remainder)
    while (num > 0) {
        quotients[count] = num;
        remainders[count] = num % 2;
        num /= 2;
        count++;
    }

    // Append last row
    quotients[count] = 0;
    remainders[count] = -1;
    count++;

    // Print banner
    print_decimal_to_binary_banner();

    // Step 2: Table printing with optional animation
    printf("\n🧮 Step-by-Step Division Table:\n");
    printf("┌────────────┬─────────────┐\n");
    printf("│  Quotient  │  Remainder  │\n");
    printf("├────────────┼─────────────┤\n");
    for (int i = 0; i < count; i++) {
        if (remainders[i] == -1)
            printf("│     %3d    │      -      │\n", quotients[i]);
        else
            printf("│     %3d    │     %d       │\n", quotients[i], remainders[i]);

        usleep(250000);  // optional delay (250ms)
    }
    printf("└────────────┴─────────────┘\n");

    // Step 3: Final binary (MSB to LSB)
    printf("\n🧠 Final Binary for Decimal %d (MSB ← LSB): ", original);
    for (int i = count - 2; i >= 0; i--) {
        printf("%d", remainders[i]);
    }
    printf(" ✅\n");
}



void run_visualizer_module() {
    int choice, num;
    char binary_input[33];

    do {
        printf("\n=======================================\n");
        printf("     🔍 Number Conversion Visualizer\n");
        printf("=======================================\n");
        printf("1. Decimal → Binary\n");
        printf("2. Binary → Decimal\n");
        printf("3. Decimal → Hexadecimal\n");
        printf("4. Hexadecimal → Decimal\n");
        printf("5. Decimal → Octal\n");
        printf("6. Octal → Decimal\n");
        printf("7. Back to Main Menu\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter a decimal number: ");
                scanf("%d", &num);
                if (num < 0)
                    printf("⚠️  Please enter a positive number.\n");
                else
                    decimal_to_binary_visual(num);
                break;

            case 2:
                printf("Enter a binary number: ");
                scanf("%s", binary_input);
                binary_to_decimal_visual(binary_input);
                break;
            
            case 3:
                printf("Enter a decimal number: ");
                scanf("%d", &num);
                if (num < 0)
                    printf("⚠️  Please enter a positive number.\n");
                else
                    decimal_to_hex_visual(num);
                break;
            
            case 4:
                printf("Enter a hexadecimal number: ");
                scanf("%s", binary_input); // reuse buffer
                hex_to_decimal_visual(binary_input);
                break;

            case 5:
                printf("Enter a decimal number: ");
                scanf("%d", &num);
                if (num < 0)
                    printf("⚠️  Please enter a positive number.\n");
                else
                    decimal_to_octal_visual(num);
                break;

            case 6:
                printf("Enter an octal number: ");
                scanf("%s", binary_input);  // reuse buffer
                octal_to_decimal_visual(binary_input);
                break;

            case 7:
                printf("Returning to main menu...\n");
                break;

            default:
                printf("⚠️  Invalid choice. Try again.\n");
        }
    } while (choice != 7);
}




void binary_to_decimal_visual(const char *binary) {
    int length = strlen(binary);
    int result = 0;

    // Step 1: Validate binary string
    for (int i = 0; i < length; i++) {
        if (binary[i] != '0' && binary[i] != '1') {
            printf("⚠️  Invalid binary digit '%c'. Please enter only 0 or 1.\n", binary[i]);
            return;
        }
    }

    // Banner
    printf("\n=============================================\n");
    printf("   🧮 Binary to Decimal - Visualizer\n");
    printf("=============================================\n");
    printf("  Shows how each bit contributes to the total.\n");
    printf("---------------------------------------------\n");

    printf("\nBinary Input: %s\n\n", binary);

    // Print headers
    printf("Position (2^n):  ");
    for (int i = 0; i < length; i++) {
        printf("2^%d  ", length - 1 - i);
    }

    printf("\nBit Value     :  ");
    for (int i = 0; i < length; i++) {
        printf(" %c   ", binary[i]);
    }

    printf("\n---------------------------------------------\n");

    // Compute total with breakdown
    printf("Calculation   :  ");
    for (int i = 0; i < length; i++) {
        int bit = binary[i] - '0';
        int power = length - 1 - i;
        result += bit * (1 << power);

        printf("(%d×%d)", bit, (1 << power));
        if (i != length - 1) printf(" + ");
    }

    printf(" = %d ✅\n", result);
}


int hex_char_to_int(char c) {
    if (c >= '0' && c <= '9') return c - '0';
    if (c >= 'A' && c <= 'F') return 10 + (c - 'A');
    if (c >= 'a' && c <= 'f') return 10 + (c - 'a');
    return -1;
}

void hex_to_decimal_visual(const char *hex) {
    int length = strlen(hex);
    int total = 0;

    // Step 1: Validate input
    for (int i = 0; i < length; i++) {
        if (hex_char_to_int(hex[i]) == -1) {
            printf("⚠️  Invalid hex digit '%c'. Use 0-9, A-F.\n", hex[i]);
            return;
        }
    }

    // Banner
    printf("\n=============================================\n");
    printf("   🧮 Hexadecimal to Decimal - Visualizer\n");
    printf("=============================================\n");
    printf("  Shows place value of each hex digit (16ⁿ).\n");
    printf("---------------------------------------------\n");

    printf("\nHex Input: %s\n\n", hex);

    // Print headers
    printf("Position (16^n):   ");
    for (int i = 0; i < length; i++) {
        printf("16^%d  ", length - 1 - i);
    }

    printf("\nHex Digit      :   ");
    for (int i = 0; i < length; i++) {
        printf(" %c    ", hex[i]);
    }

    printf("\nDecimal Value  :   ");
    for (int i = 0; i < length; i++) {
        int digit = hex_char_to_int(hex[i]);
        int power = 1 << 4 * (length - 1 - i);  // 16^n
        int value = digit * power;
        printf("%4d ", value);
        total += value;
    }

    printf("\n---------------------------------------------\n");

    // Final breakdown
    printf("Total Decimal  = ");
    for (int i = 0; i < length; i++) {
        int digit = hex_char_to_int(hex[i]);
        int power = 1 << 4 * (length - 1 - i);
        printf("(%d×%d)", digit, power);
        if (i != length - 1) printf(" + ");
    }
    printf(" = %d ✅\n", total);
}


void decimal_to_octal_visual(int num) {
    int quotients[32], remainders[32];
    char octal_digits[32];
    int count = 0;
    int original = num;

    while (num > 0) {
        quotients[count] = num;
        remainders[count] = num % 8;
        octal_digits[count] = '0' + (num % 8);
        num /= 8;
        count++;
    }

    // Final row
    quotients[count] = 0;
    remainders[count] = -1;
    octal_digits[count] = '-';
    count++;

    // Banner
    printf("\n===========================================\n");
    printf("   🧮 Decimal to Octal - Visualizer\n");
    printf("===========================================\n");
    printf("  Shows how repeated /8 gives octal digits.\n");
    printf("-------------------------------------------\n");

    printf("\nDecimal Input: %d\n", original);
    printf("\nStep | Quotient | Remainder | Octal Digit\n");
    printf("------------------------------------------\n");

    for (int i = 0; i < count; i++) {
        if (remainders[i] == -1)
            printf(" %2d  |   %3d    |     -     |    -\n", i + 1, quotients[i]);
        else
            printf(" %2d  |   %3d    |    %2d     |    %c\n", i + 1, quotients[i], remainders[i], octal_digits[i]);
        usleep(200000);  // optional animation delay
    }

    // Final Octal (MSB to LSB)
    printf("\n🧠 Octal (MSB ← LSB): ");
    for (int i = count - 2; i >= 0; i--) {
        printf("%c", octal_digits[i]);
    }
    printf(" ✅\n");
}


int octal_char_to_int(char c) {
    if (c >= '0' && c <= '7') return c - '0';
    return -1;
}

void octal_to_decimal_visual(const char *octal) {
    int length = strlen(octal);
    int total = 0;

    // Step 1: Validate
    for (int i = 0; i < length; i++) {
        if (octal_char_to_int(octal[i]) == -1) {
            printf("⚠️  Invalid octal digit '%c'. Use 0–7 only.\n", octal[i]);
            return;
        }
    }

    // Banner
    printf("\n=============================================\n");
    printf("   🧮 Octal to Decimal - Visualizer\n");
    printf("=============================================\n");
    printf("  Shows how each digit contributes (8ⁿ).\n");
    printf("---------------------------------------------\n");

    printf("\nOctal Input: %s\n\n", octal);

    // Headers
    printf("Position (8^n):     ");
    for (int i = 0; i < length; i++)
        printf("8^%d   ", length - 1 - i);

    printf("\nOctal Digit   :     ");
    for (int i = 0; i < length; i++)
        printf(" %c    ", octal[i]);

    printf("\nDecimal Value :     ");
    for (int i = 0; i < length; i++) {
        int digit = octal_char_to_int(octal[i]);
        int power = 1;
        for (int j = 0; j < length - 1 - i; j++) power *= 8;
        int value = digit * power;
        printf("%4d  ", value);
        total += value;
    }

    // Summary
    printf("\n---------------------------------------------\n");
    printf("Total Decimal = ");
    for (int i = 0; i < length; i++) {
        int digit = octal_char_to_int(octal[i]);
        int power = 1;
        for (int j = 0; j < length - 1 - i; j++) power *= 8;
        printf("(%d×%d)", digit, power);
        if (i != length - 1) printf(" + ");
    }
    printf(" = %d ✅\n", total);
}
