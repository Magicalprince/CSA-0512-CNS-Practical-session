#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char key[] = "KEYWORD";
    char plaintext[] = "HELLO";
    char playfairMatrix[5][5];
    char ciphertext[255];
    int i, j, k;
    char keyMatrix[26] = {0};
    k = 0;
    for (i = 0; i < strlen(key); i++) {
        char c = toupper(key[i]);
        if (keyMatrix[c - 'A'] == 0) {
            if (c != 'J') {
                keyMatrix[c - 'A'] = 1;
                playfairMatrix[k / 5][k % 5] = c;
                k++;
            }
        }
    }
    
    for (i = 0; i < 26; i++) {
        char c = 'A' + i;
        if (keyMatrix[i] == 0) {
            if (c != 'J') {
                playfairMatrix[k / 5][k % 5] = c;
                k++;
            }
        }
    }

    for (i = 0; plaintext[i] != '\0'; i++) {
        if (plaintext[i] == ' ')
            continue;
        plaintext[i] = toupper(plaintext[i]);
        if (plaintext[i] == 'J')
            plaintext[i] = 'I';
    }

    k = 0;
    for (i = 0; i < strlen(plaintext); i += 2) {
        char a = plaintext[i];
        char b = (i + 1 < strlen(plaintext)) ? plaintext[i + 1] : 'X';

        int row1, col1, row2, col2;

        for (j = 0; j < 5; j++) {
            for (k = 0; k < 5; k++) {
                if (playfairMatrix[j][k] == a) {
                    row1 = j;
                    col1 = k;
                }
                if (playfairMatrix[j][k] == b) {
                    row2 = j;
                    col2 = k;
                }
            }
        }

        if (row1 == row2) {
            a = playfairMatrix[row1][(col1 + 1) % 5];
            b = playfairMatrix[row2][(col2 + 1) % 5];
        } else if (col1 == col2) {
            a = playfairMatrix[(row1 + 1) % 5][col1];
            b = playfairMatrix[(row2 + 1) % 5][col2];
        } else {
            a = playfairMatrix[row1][col2];
            b = playfairMatrix[row2][col1];
        }

        ciphertext[i] = a;
        ciphertext[i + 1] = b;
    }

    printf("Plaintext: %s\n", plaintext);
    printf("Ciphertext: %s\n", ciphertext);

    return 0;
}
