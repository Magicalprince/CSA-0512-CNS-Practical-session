#include <stdio.h>
#include <stdint.h>
#include <math.h>
int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int mod_exp(int a, int b, int n) {
    int result = 1;
    a = a % n;
    while (b > 0) {
        if (b % 2 == 1)
            result = (result * a) % n;
        b = b >> 1;
        a = (a * a) % n;
    }
    return result;
}

int main() {
    int p = 61;     
    int q = 53;     
    int n = p * q;  
    int e = 17;     
    int d = 2753;

    int phi = (p - 1) * (q - 1);
    while ((d * e) % phi != 1) {
        d++;
    }

    int plaintext = 42;

    int ciphertext = mod_exp(plaintext, e, n);

    int decrypted_message = mod_exp(ciphertext, d, n);

    printf("Original Message: %d\n", plaintext);
    printf("Encrypted Message: %d\n", ciphertext);
    printf("Decrypted Message: %d\n", decrypted_message);

    return 0;
}
