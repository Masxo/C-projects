#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//#region TAIL FACTORIAL
/**
 * Factorial function with tail impementation
 * @param n number entered
 * @param tail tail init value
 * @return factorial of n
 */
unsigned long long factorialTail(unsigned long long n, unsigned long long tail) {
    return n == 0 ? tail : factorialTail(n-1, n * tail);
}
//#endregion

//#region NEXT PRIME
/**
 * Finds the next prime after n
 * @param n number entered
 * @return next prime number
 */
unsigned long long nextPrime(unsigned long long n) {
    // quantity of divisors
    int div = 0;
    // only breaks when div = 1, which means  only was divided by 1
    while(div != 1) {
        // resets div every run
        div = 0;
        // increments number
        n++;
        // see quantity of divisors in n
        for (unsigned long long i = 1; i < n; i++) {
            if (n % i == 0) {
                div++;
            }
        }
    }
    return n;
}
//#endregion

//#region PRIME OMEGA FUNCTION
/**
 * prime omega function in math
 * @param n
 * @return number of different prime divisors
 */
unsigned long long primeOmegaFunction(unsigned long long n) {
    // sets the size of the primediv array, and second n for verification
    unsigned long long size = 0,nlast = n;
    // array of prime numbers
    unsigned long long *primediv;
    // executes until n is fully factored
    while(n != 1) {
        // verifies if size is 0, first case
        if(size == 0) {
            // sets size of primediv to 1, and first primediv[0] first prime number
            primediv = (unsigned long long *) calloc(++size, sizeof(unsigned long long));
            primediv[0] = 2;
        // verifies if n is divisible by current prime number
        }else if(n % primediv[size - 1] == 0) {
            // divides n
            n /= primediv[size - 1];
        // if n is not divisible then verifies if n was actually divided or not
        } else if(nlast != n){
            // resizes primediv for next number
            primediv = (unsigned long long *) realloc(primediv, ++size * sizeof(unsigned long long));
            // adds next prime number in the next element
            primediv[size - 1] = nextPrime(primediv[size - 2]);
            nlast = n;
        // case n wasn't divided means n is not factorable by current number
        } else {
            // updates prime number without changing size
            primediv[size - 1] = nextPrime(primediv[size - 1]);
        }
    }
    // frees the memory used
    free(primediv);
    return size;
}
//#endregion

//#region FIND DIVISORS FUNCTION
/**
 * Function to find number of divisors or particullar divisor,
 * in decremental order,
 * ex.: if n = 6 returns 6 when n_div = 1,3 when n_div = 2,...
 * @param n number
 * @param n_div number of divisor, 0 equals to find all divisors
 * @return number of divisors of n or particullar divisor of n
 */
unsigned long long findDivisorsFunction(unsigned long long n, int n_div) {
    // number of divisors of n
    unsigned long long div = 0;
    for(int i = 1; i <= n; i++) {
        // verifies if n is divisible by i
        if(n % i == 0) {
            // increments divisor
            div++;
            // what n_div == 0 means is to find all divisors
            if(n_div == 0)
                continue;
            // if n_div != 0 means to find n_div divisor
            else if(n_div == div)
                return i;
        }
    }
    return div;
}
//#endregion

//#region SUMMATORY SPECIAL FUNCTION
unsigned long long summatorySpecialFunction(unsigned long long n) {
    unsigned long long sum = 0;
    for (int i = 1; i <= n; i++) {
        for (unsigned long long j = findDivisorsFunction(i, 0); j > 0; j--) {
            sum += pow(findDivisorsFunction(i, j), 2);
        }
    }
    return sum;
}
//#endregion

//#region SUMMATORY FUNCTION
/**
 * summatory function with max, min and summatory method defined
 * @param n start number
 * @param summatory_function
 * @param max number max
 * @return the sum of n to max based on the function
 */
unsigned long long summatoryFunction(unsigned long long n,
                                     long long (*summatory_function)(void *),
                                     unsigned long long max) {
    unsigned long long sum = 0;
    for(unsigned long long i = n; i < max; i++) {
        sum += (*summatory_function)(&i);
    }
    return sum;
}
//#endregion


int main() {
    for(int i = 1; i < 16; i++)
    printf("%lld\n",summatorySpecialFunction(pow(10,i)));
    return 0;
}
