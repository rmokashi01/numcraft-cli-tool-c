#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "twos_complement.h"

void print_twos_banner() {
    printf("\n===========================================\n");
    printf("   ➕ Two's Complement Arithmetic Simulator\n");
    printf("===========================================\n");
    printf(" Understand how signed binary arithmetic\n");
    printf(" works using two's complement logic.\n");
    printf("-------------------------------------------\n");
}

int detect_overflow(int a, int b, int result) {
    if ((a > 0 && b > 0 && result < 0) ||
        (a < 0 && b < 0 && result > 0)) {
        return 1;
    }
    return 0;
}


void int_to_twos_complement(int value, int bits, char *binary) {
    unsigned int mask = (1 << bits) - 1; // mask to clip extra bits
    unsigned int twos = (unsigned int)value & mask;

    for (int i = bits - 1; i >= 0; i--) {
        binary[bits - 1 - i] = ((twos >> i) & 1) + '0';
    }
    binary[bits] = '\0';
}


int binary_to_signed_decimal(const char *binary, int bits) {
    int result = 0;

    // If MSB (sign bit) is 1 → negative number
    if (binary[0] == '1') {
        // Invert bits
        char inverted[33];
        for (int i = 0; i < bits; i++) {
            inverted[i] = (binary[i] == '0') ? '1' : '0';
        }
        inverted[bits] = '\0';

        // Convert inverted binary to decimal
        for (int i = 0; i < bits; i++) {
            result = result * 2 + (inverted[i] - '0');
        }
        result = -(result + 1);
    } else {
        // Positive number
        for (int i = 0; i < bits; i++) {
            result = result * 2 + (binary[i] - '0');
        }
    }

    return result;
}


void add_twos_complement(const char *bin_a, const char *bin_b, char *result, int bits, char *carry_out) {
    int carry = 0;
    for (int i = bits - 1; i >= 0; i--) {
        int bit1 = bin_a[i] - '0';
        int bit2 = bin_b[i] - '0';
        int sum = bit1 + bit2 + carry;

        result[i] = (sum % 2) + '0';
        carry_out[i] = carry + '0';
        carry = sum / 2;
    }
    result[bits] = '\0';
    carry_out[bits] = '\0';
}


void run_twos_complement_module() {
    int bit_size, a, b, choice;
    char cont;
    char bin_a[33], bin_b[33], result[33], carry_bits[33];

    print_twos_banner();

    do {
        printf("\nChoose operation:\n");
        printf("1. Addition (a + b)\n");
        printf("2. Subtraction (a - b)\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        printf("Enter bit size (e.g. 4, 8, 16): ");
        scanf("%d", &bit_size);

        int max_val = (1 << (bit_size - 1)) - 1;
        int min_val = -(1 << (bit_size - 1));

        printf("Enter first number (a): ");
        scanf("%d", &a);

        printf("Enter second number (b): ");
        scanf("%d", &b);

        // Range check
        if (a < min_val || a > max_val || b < min_val || b > max_val) {
            printf("⚠️  Error: Numbers must be within %d to %d for %d-bit signed integers.\n", min_val, max_val, bit_size);
        } else {
            int_to_twos_complement(a, bit_size, bin_a);

            if (choice == 1) {
                int_to_twos_complement(b, bit_size, bin_b);
                add_twos_complement(bin_a, bin_b, result, bit_size, carry_bits);
            } else if (choice == 2) {
                int neg_b = -b;
                int_to_twos_complement(neg_b, bit_size, bin_b);
                printf("Binary of -b (%d): %s\n", neg_b, bin_b);
                add_twos_complement(bin_a, bin_b, result, bit_size, carry_bits);
            } else {
                printf("⚠️  Invalid operation choice.\n");
                continue;
            }

            // Print bit-by-bit view
            printf("\nBit-by-bit Addition:\n");
            printf("  A      : %s\n", bin_a);
            printf("  B      : %s\n", bin_b);
            printf("  --------\n");
            printf("  Result : %s\n", result);
            printf("  Carry  : %s\n", carry_bits);

            // Summary and overflow check
            int signed_result = binary_to_signed_decimal(result, bit_size);
            int dec_result = (choice == 1) ? (a + b) : (a - b);
            int overflow = detect_overflow(a, (choice == 1 ? b : -b), dec_result);

            printf("\nSummary:\n");
            printf("----------------------------------\n");
            printf("  Decimal:    %d %c %d = %d\n", a, (choice == 1 ? '+' : '-'), b, signed_result);
            printf("  Binary A:   %s\n", bin_a);
            printf("  Binary B:   %s\n", bin_b);
            printf("  Result:     %s (Decimal: %d)\n", result, signed_result);
            printf("  Carry Bits: %s\n", carry_bits);
            if (overflow) {
                printf("⚠️  Overflow Detected! Result is outside %d-bit signed range.\n", bit_size);
            }
            printf("----------------------------------\n");
        }

        printf("\nDo you want to try another operation? (y/n): ");
        scanf(" %c", &cont);
    } while (cont == 'y' || cont == 'Y');
}
