#include <stdio.h>
#include <assert.h>
#include <limits.h>

#define MAX_ITERATIONS (100000000 + 1)
//#define MAX_ITERATIONS (10000 + 1)

unsigned long collatz_seqlen(unsigned long n);


int main(void)
{
    unsigned long i;
    unsigned long max_len = 0;
    unsigned long imax = 0;
    
    for (i = 1; i < MAX_ITERATIONS; i++) {  // https://oeis.org/A006577
        unsigned long len = collatz_seqlen(i);
        printf("%lu", len);
        printf("\n");
        if (len > max_len) {
            max_len = len;
            imax = i;
        }
    }

    fprintf(stderr, "Max len = %lu (from %lu)\n", max_len, imax);
    return 0;
}

unsigned long collatz_seqlen(unsigned long n)
{
    unsigned long seq_len = 0;
    
    assert(n > 0);   // pre-condition
    
    while (n != 1) {
        if (n & 1) // if odd
            n = 3 * n + 1;
        else
            n /= 2;
        seq_len++;
    }
    
    return seq_len;
}

