#include <stdio.h>
#include <string.h>

int main() {
    // Define the key matrix and plaintext
    int key[2][2] = {{7, 8}, {11, 11};
    char plaintext[] = "SHORTERMESSAGE";
    char ciphertext[strlen(plaintext)];
    int i, j, k;

    // Ensure the length of the plaintext is a multiple of 2
    int len = strlen(plaintext);
    while (len % 2 != 0) {
        plaintext[len] = 'X';
        len++;
    }

    // Encrypt the message
    k = 0;
    for (i = 0; i < len; i += 2) {
        for (j = 0; j < 2; j++) {
            ciphertext[k] = ((key[j][0] * (plaintext[i] - 'A') + key[j][1] * (plaintext[i + 1] - 'A')) % 26) + 'A';
            k++;
        }
    }

    // Print the ciphertext
    printf("Plaintext: %s\n", plaintext);
    printf("Ciphertext: %s\n", ciphertext);

    return 0;
}
