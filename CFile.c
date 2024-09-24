#include <stdio.h>

int square(int n){
    if (n>=0 && n<=9) return n*n;
    return square(n/10) + (n%10)*(n%10);
}

int main(){
    float n;
    scanf("%f",&n);
    n = n/1;
    int result = square(n);
    printf("The sum of squares of digits = %d\n",result);
    return 0;
}