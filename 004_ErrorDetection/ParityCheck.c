#include <stdio.h>
#include <string.h>

// This function converts a character into its binary representation
void charToBinary(char c, char *binary) {
    for (int i = 7; i >= 0; --i) {
        binary[7 - i] = (c & (1 << i)) ? '1' : '0';
    }
    binary[8] = '\0';
}

// This function calculates the parity bit for a group of bits
char calculateParity(char *bits, int count) {
    int ones = 0;
    for (int i = 0; i < count; ++i) {
        if (bits[i] == '1') {
            ++ones;
        }
    }
    return (ones % 2 == 0) ? '0' : '1';
}

int main() {
    char text[100];
    char binary[9];

    printf("Enter a text: ");
    fgets(text, sizeof(text), stdin);

    printf("Binary representation: ");
    for (int i = 0; i < strlen(text) - 1; ++i) { // -1 to exclude the newline character
        charToBinary(text[i], binary);
        printf("%s ", binary);
    }
    printf("\n");

    // More code will go here to implement encoding and error checking...

    return 0;
}