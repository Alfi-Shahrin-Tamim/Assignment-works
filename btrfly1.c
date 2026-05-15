#include <stdio.h>
void func_print(int call1){
    if(call1 == 1) printf("\\ /");
    else printf("/ \\");
}
void half_print(int line, int call ){
    int stars;
    stars = line - 2;
    for(int b = 1;b <=stars;b++){
        if(b % 2 == 0){        
        for(int a = 1;a <= stars;a++) printf("-");                  
        func_print(call);
        for(int a = 1;a <= stars;a++) printf("-");
        }            
    else{
        for(int a = 1;a <= stars;a++) printf("*");
        func_print(call);
        for(int a = 1;a <= stars;a++) printf("*");
    }
    printf("\n");
  }  
}
int main(){
    int n,i,stars;
    printf("Give a value for n: ");
    scanf("%d", &n);
    stars = n - 2;
    half_print(n, 1);
    for(i = 1; i<= n-1; i++) printf(" ");
    printf("@\n");
    half_print(n, 2);
}     
