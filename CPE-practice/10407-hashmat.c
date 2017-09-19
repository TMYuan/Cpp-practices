#include <stdlib.h>
#include <stdio.h>

int main(){
    long long int x, y;
    while(scanf("%lld %lld", &x, &y) == 2){
        printf("%lld\n", x>y ? x-y : y-x);
    }

    return 0;
}