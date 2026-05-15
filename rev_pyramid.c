 #include <stdio.h>

int main()
{
    int n,i,j,x;
    printf("Give a value for n: ");
    scanf("%d", &n);    
    for(i=1;i<=n;i++){
      for(x=1;x<i;x++){
        printf(" ");
      }
      for(j=1;j<=n-i+1;j++){
          printf(" *");
      }
      printf("\n");
    }
}  
