#include <stdio.h>
#include <assert.h>
#include <limits.h>

#define MAX_ITERATIONS (100000000 + 1)
//#define MAX_ITERATIONS (10000 + 1)
//#define MAX_ITERATIONS (200 + 1)

unsigned long collatz_seqlen(unsigned long n);

// http://oeis.org/A153330

int main(void)
{
    unsigned long i;
    long min_delta, max_delta;
    unsigned long min_delta_at, max_delta_at;
    
    unsigned long prev_len = collatz_seqlen(1);
    
    min_delta    = LONG_MAX;
    min_delta_at = 1;
    max_delta    = LONG_MIN;
    max_delta_at = 1;
    
    for (i = 2; i < MAX_ITERATIONS; i++) {
        unsigned long len = collatz_seqlen(i);
        long delta = len - prev_len;
        //printf("len %4lu (delta %4ld)", len, delta);
        printf("%ld", delta);
        printf("\n");
        
        if (delta < min_delta) {
            min_delta = delta;
            min_delta_at = i;
        }
        if (delta > max_delta) {
            max_delta = delta;
            max_delta_at = i;
        }
        
        prev_len = len;
    }
    fprintf(stderr, "Min delta = %ld (first at %lu)   Max delta = %ld (first at %lu)\n", min_delta, min_delta_at, max_delta, max_delta_at);
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

