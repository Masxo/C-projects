#include <stdio.h>

// include nodes
int main() {
    long long largest = 0,largn = 0;
    for(int i = 1000000; i > 0; i--) {
        int larg = 0;
        long long n = i;
        while(n > 1) {
            if(n % 2 != 0) {
                n = (3 * n + 1) / 2;
                larg += 2;
            } else {
                n = n / 2;
                larg++;
            }
        }
        if(larg > largest) {
            largest = larg;
            largn = i;
        }
    }
    printf("%d",largn);

    return 0;
}
