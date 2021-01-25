#include <stdio.h>
#include <string.h>
#include <stdbool.h>

unsigned long place(int n) {
    unsigned long res = 1;
    for (int i = 0; i < n-1; res*= 10, i++);
    return res;
}

void main() {
    printf("generate primes upto: ");
    char input[16];
    fgets(input, 16, stdin);

    unsigned long len = 0;
    int s_length = strlen(input) - 1;
    for (int i = 0; i < s_length; i++) len += place(s_length-i) * (int)(input[i] - 48);

    // sieve of eratosthenes
    bool primes[len+1];
    for (unsigned long i = 2; i <= len; i++) primes[i] = true;
    for (unsigned long i = 2; i*i <= len; i++)
        if (primes[i])
            for (long j = i*i; j <= len; j+=i)
                primes[j] = false;

    char filename[32];
    sprintf(filename, "upto%ldprimes.txt", len);
    printf("generated %ld primes\nsaving result to \"%s\"\n", len, filename);
    FILE *file = fopen(filename, "w");
    for (unsigned long i = 0; i < len; i++) if (primes[i]) fprintf(file, "%ld\n", i);
    fflush(file);
    fclose(file);
}
