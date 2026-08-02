#include <stdio.h>
#include <stdlib.h>

int fib( int elements){
         if (elements == 0) return 0;
         else if(elements == 1) return 1;
         return fib(elements - 1) + fib(elements -2); 
}

int main(){
    int elements;
    printf("Number of terms: ");
    scanf("%d", &elements);

    printf("Fibonacci sequence: ");
    for(int i = 0; i < elements; i++) printf("%d ", fib(i));
    printf("\n");

}
