#include <stdio.h>
#include <string.h>

int main() {
    int railCount = 3; // Number of rails
    char plaintext[] = "HELLO";
    int len = strlen(plaintext);
    char rails[railCount][len];
    int direction = 1; // 1 for down, -1 for up
    int row = 0;
    
    for (int i = 0; i < railCount; i++) {
        for (int j = 0; j < len; j++) {
            rails[i][j] = ' ';
        }
    }
    
    for (int i = 0; i < len; i++) {
        rails[row][i] = plaintext[i];
        row += direction;
        
        if (row == railCount - 1 || row == 0) {
            direction = -direction;
        }
    }
    
    char ciphertext[len];
    int index = 0;
    
    for (int i = 0; i < railCount; i++) {
        for (int j = 0; j < len; j++) {
            if (rails[i][j] != ' ') {
                ciphertext[index] = rails[i][j];
                index++;
            }
        }
    }
    
    // Print the plaintext and ciphertext
    printf("Plaintext: %s\n", plaintext);
    printf("Ciphertext: %s\n", ciphertext);
    
    return 0;
}
