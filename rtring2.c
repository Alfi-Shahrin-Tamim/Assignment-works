#include <stdio.h>
int main()
{
    int n,i,j;
    printf("Give a value for n: ");
    scanf("%d", &n);
    for(i=1;i<=n;i++){
      for(j=n-i+1;j>=1;j--){
        printf("* ");
      }
      printf("\n");
    }
}   