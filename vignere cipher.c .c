#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char key[] = "KEY";
    char plaintext[] = "HELLO"; 
    char ciphertext[strlen(plaintext) + 1]; 
    int keyLength = strlen(key);
    for (int i = 0; key[i]; i++) {
        key[i] = toupper(key[i]);
    }

    for (int i = 0, j = 0; plaintext[i]; i++) {
        char currentChar = plaintext[i];

        if (isalpha(currentChar)) {
            char keyChar = key[j % keyLength]; 
            keyChar = toupper(keyChar);

            int shift = keyChar - 'A'; 
            char base = islower(currentChar) ? 'a' : 'A';

            ciphertext[i] = (currentChar - base + shift) % 26 + base;
            j++;
        } else {
            ciphertext[i] = currentChar;
        }
    }
    
    ciphertext[strlen(plaintext)] = '\0';

    printf("Plaintext: %s\n", plaintext);
    printf("Ciphertext: %s\n", ciphertext);

    return 0;
}
