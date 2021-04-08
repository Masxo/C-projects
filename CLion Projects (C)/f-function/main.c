#include <stdio.h>
#include <stdlib.h>
#include <math.h>

unsigned long long factorialTail(unsigned long long n, unsigned long long tail) {
    return n == 0 ? tail : factorialTail(n-1, n * tail);
}

unsigned long long nextPrime(unsigned long long n) {
    int div = 0;
    while(div != 1) {
        div = 0;
        n++;
        for (unsigned long long i = 1; i < n; i++) {
            if (n % i == 0) {
                div++;
            }
        }
    }
    return n;
}

unsigned long long primeOmegaFunction(unsigned long long n) {
    unsigned long long size = 0,nlast = n;
    unsigned long long *primediv;
    while(n != 1) {
        if(size == 0) {
            primediv = (unsigned long long *) calloc(++size, sizeof(unsigned long long));
            primediv[0] = 2;
        }else if(n % primediv[size - 1] == 0) {
            n /= primediv[size - 1];
        } else if(nlast != n){
            primediv = (unsigned long long *) realloc(primediv, ++size * sizeof(unsigned long long));
            primediv[size - 1] = nextPrime(primediv[size - 2]);
            nlast = n;
        } else {
            primediv[size - 1] = nextPrime(primediv[size - 1]);
        }
    }
    free(primediv);
    return size;
}

unsigned long long findDivisorsFunction(unsigned long long n, int res) {
    unsigned long long div = 0;
    for(int i = 1; i <= n; i++) {
        if(n % i == 0) {
            div++;
            if(res == 0)
                continue;
            else if(res == div)
                return i;
        }
    }
    return div;
}

unsigned long long summatoryFunction(unsigned long long n) {
    unsigned long long sum = 0;
    //n *= n;
    for(unsigned long long i = findDivisorsFunction(n,0); i > 0; i--) {
        sum += pow(2,primeOmegaFunction(findDivisorsFunction(n,i)));
        //sum += pow(findDivisorsFunction(n,i),0);
    }
    return sum;
}

unsigned summatoryFactorialFunction(unsigned long long n) {
    unsigned long long sum = 0;
    for(unsigned long long i = 2; i <= n; i++) {
        sum += summatoryFunction(factorialTail(i,1));
        printf("%d\n",i);
    }
    return sum;
}

int main() {
    for(int i = 2; i < 10000000; i++)
        printf("%d -> %lld\n",i,factorialTail(i,1));//summatoryFactorialFunction(10000000) % 1000000087);
    return 0;
}
