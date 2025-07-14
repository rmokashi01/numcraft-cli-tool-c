#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "bit_byte_ops.h"


void print_unit_banner() {
    printf("\n==========================================\n");
    printf("       📐 Bit / Byte Unit Converter\n");
    printf("==========================================\n");
    printf(" Converts between bits, bytes, KB, MB, GB.\n");
    printf("------------------------------------------\n");
}

void run_bitbyte_converter() {
    double value;
    char unit[10];

    print_unit_banner();

    printf("Enter the value (numeric): ");
    scanf("%lf", &value);

    printf("Enter the unit (bit/byte/kb/mb/gb): ");
    scanf("%s", unit);

    // Convert unit to lowercase (optional)
    for (int i = 0; unit[i]; i++) unit[i] = tolower(unit[i]);

    // Convert input to bits first
    double bits = 0;
    if (strcmp(unit, "bit") == 0)
        bits = value;
    else if (strcmp(unit, "byte") == 0)
        bits = value * 8;
    else if (strcmp(unit, "kb") == 0)
        bits = value * 1024 * 8;
    else if (strcmp(unit, "mb") == 0)
        bits = value * 1024 * 1024 * 8;
    else if (strcmp(unit, "gb") == 0)
        bits = value * 1024 * 1024 * 1024 * 8;
    else {
        printf("⚠️  Invalid unit entered.\n");
        return;
    }

    // Output all conversions
    printf("\n🔁 Conversion Results:\n");
    printf("Bits   : %.0lf\n", bits);
    printf("Bytes  : %.3lf\n", bits / 8);
    printf("KB     : %.6lf\n", bits / (8 * 1024));
    printf("MB     : %.6lf\n", bits / (8 * 1024 * 1024));
    printf("GB     : %.6lf\n", bits / (8.0 * 1024 * 1024 * 1024));
}

void run_bit_byte_module() {
    int choice;
    do {
        printf("\n============================================\n");
        printf("     🧮 Bit/Byte & Bitwise Operations\n");
        printf("============================================\n");
        printf("1. Bit/Byte/Kilobyte Converter\n");
        printf("2. Bitwise Operation Visualizer (AND, OR, etc.)\n");
        printf("3. Back to Main Menu\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: run_bitbyte_converter(); break;
            case 2: run_bitwise_simulator(); break;
            case 3: printf("Returning to main menu...\n"); break;
            default: printf("⚠️  Invalid choice. Try again.\n");
        }
    } while (choice != 3);
}


void print_bitwise_banner() {
    printf("\n===========================================\n");
    printf("      🔎 Bitwise Operation Visualizer\n");
    printf("===========================================\n");
    printf(" Try AND, OR, XOR, NOT, <<, >> in binary\n");
    printf("-------------------------------------------\n");
}

void print_binary(int num, int bits, char *bin_str) {
    for (int i = bits - 1; i >= 0; i--) {
        bin_str[bits - 1 - i] = ((num >> i) & 1) + '0';
    }
    bin_str[bits] = '\0';
}

void run_bitwise_simulator() {
    int a, b, bits = 8, op;
    char cont;
    char bin_a[33], bin_b[33], result_bin[33];
    int result;

    print_bitwise_banner();

    do {
        printf("Enter number A: ");
        scanf("%d", &a);
        printf("Enter number B: ");
        scanf("%d", &b);

        print_binary(a, bits, bin_a);
        print_binary(b, bits, bin_b);

        printf("\nChoose operation:\n");
        printf("1. AND (a & b)\n");
        printf("2. OR  (a | b)\n");
        printf("3. XOR (a ^ b)\n");
        printf("4. NOT (~a)\n");
        printf("5. Left Shift  (a << 1)\n");
        printf("6. Right Shift (a >> 1)\n");
        printf("Enter choice: ");
        scanf("%d", &op);

        switch (op) {
            case 1:
                result = a & b;
                print_binary(result, bits, result_bin);
                printf("\n  %s (A)\n", bin_a);
                printf("& %s (B)\n", bin_b);
                printf("= %s → %d\n", result_bin, result);
                break;
            case 2:
                result = a | b;
                print_binary(result, bits, result_bin);
                printf("\n  %s (A)\n", bin_a);
                printf("| %s (B)\n", bin_b);
                printf("= %s → %d\n", result_bin, result);
                break;
            case 3:
                result = a ^ b;
                print_binary(result, bits, result_bin);
                printf("\n  %s (A)\n", bin_a);
                printf("^ %s (B)\n", bin_b);
                printf("= %s → %d\n", result_bin, result);
                break;
            case 4:
                result = ~a;
                print_binary(result, bits, result_bin);
                printf("\n~ %s (A)\n", bin_a);
                printf("= %s → %d\n", result_bin, result);
                break;
            case 5:
                result = a << 1;
                print_binary(result, bits, result_bin);
                printf("\n%s << 1 = %s → %d\n", bin_a, result_bin, result);
                break;
            case 6:
                result = a >> 1;
                print_binary(result, bits, result_bin);
                printf("\n%s >> 1 = %s → %d\n", bin_a, result_bin, result);
                break;
            default:
                printf("⚠️  Invalid choice.\n");
        }

        printf("\nDo you want to try another? (y/n): ");
        scanf(" %c", &cont);
    } while (cont == 'y' || cont == 'Y');
}