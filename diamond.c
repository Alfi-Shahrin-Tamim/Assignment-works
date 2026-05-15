 #include <stdio.h>
int main()
{
    int n,i,j,x;
    printf("Give a value for n: ");
    scanf("%d", &n);
    for(i=1;i<=n;i++){
      for(j=1;j<=n;j++){
        if(j >= n-i+1){
        printf(" *");
        }
        else{
          printf(" ");
        }
      }
      printf("\n");
    }    
    for(i=2;i<=n;i++){
      for(x=1;x<i;x++){
        printf(" ");
      }
      for(j=1;j<=n-i+1;j++){
          printf(" *");
      }
      printf("\n");
    }
}  
