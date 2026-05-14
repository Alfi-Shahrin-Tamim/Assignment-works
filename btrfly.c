 #include <stdio.h>

int main()

{

    int n,i,j,x,y;

    printf("Number of lines: ");
    scanf("%d", &n);
    x = n /2;
    y = n - x;
    for(i=1;i<=x;i++){
        printf("*****\\ /*****\n");
        printf("-----\\ /-----\n");
    }
    printf("      @\n");
    for(i=1;i<=y;i++){
        printf("*****\\ /*****\n");
        printf("-----\\ /-----\n");
    }    
    
}  
