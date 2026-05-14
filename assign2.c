#include <stdio.h>
int main()
{
    int n,i,j;
    printf("Give a value for n: ");
    scanf("%d", &n);
    for(i=1;i<=n;i++){
      printf("* ");
      if (i == n){
        printf("\n");
      }
    }
      for(i=1;i<=(n-2);i++){
      for(j=1;j<=2*n;j++){
        if(j ==1 || j == 2*n - 1){
          printf("*");
        }
        else{
        printf(" ");
        }
      }
      printf("\n");
    }
    for(i=1;i<=n;i++){
      printf("* ");
    }
    
}   