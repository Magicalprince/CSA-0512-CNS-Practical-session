#include <stdio.h>
#include <math.h>

int mod_pow(int base, int exponent, int modulus) {
    if (exponent == 0)
        return 1;

    long long result = 1;
    while (exponent > 0) {
        if (exponent % 2 == 1)
            result = (result * base) % modulus;
        base = (base * base) % modulus;
        exponent /= 2;
    }
    return (int)result;
}

int main() {
    int prime, primitive_root, alice_private, bob_private;
    int alice_public, bob_public;
    printf("Enter the prime number (p): ");
    scanf("%d", &prime);
    printf("Enter the primitive root (g): ");
    scanf("%d", &primitive_root);
    printf("Alice, enter your private key (a): ");
    scanf("%d", &alice_private);
    alice_public = mod_pow(primitive_root, alice_private, prime);
    printf("Bob, enter your private key (b): ");
    scanf("%d", &bob_private);
    bob_public = mod_pow(primitive_root, bob_private, prime);
    int alice_secret = mod_pow(bob_public, alice_private, prime);
    int bob_secret = mod_pow(alice_public, bob_private, prime);
    printf("Alice's Secret Key: %d\n", alice_secret);
    printf("Bob's Secret Key: %d\n", bob_secret);

    return 0;
}
