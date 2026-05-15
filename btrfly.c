 #include <stdio.h>

int main()

{

    int n,i,j,x,y,lines,stars;

    printf("Number of lines: ");
    scanf("%d", &n);
    lines = 2 * (n-2) + 1;
    stars = n - 2;
    x = (lines - 1) / 2;
    y = (lines - 1) - x;
    for(i=1;i<=x;i++){
        if(i % 2 == 0){
            for(j=1;j<=stars;j++){
                printf("-");
            }
            printf("\\ /");
            for(j=1;j<=stars;j++){
                printf("-");
            }
            printf("\n");
        }
        else{
            for(j=1;j<=stars;j++){
                printf("*");
            }
            printf("\\ /");
            for(j=1;j<=stars;j++){
                printf("*");
            }
            printf("\n");
        }
 
    }
    for(j=1;j<=stars + 1;j++){
        printf(" ");
    }
    printf("@\n");
    for(i=1;i<=y;i++){
        if(i % 2 == 0){
            for(j=1;j<=stars;j++){
                printf("-");
            }
            printf("\\ /");
            for(j=1;j<=stars;j++){
                printf("-");
            }
            printf("\n");
        }
        else{
            for(j=1;j<=stars;j++){
                printf("*");
            }
            printf("\\ /");
            for(j=1;j<=stars;j++){
                printf("*");
            }
            printf("\n");
        }
 
    }
        
    
}  
