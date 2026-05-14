#include <stdio.h>
void name()
{
    char c1,c2,c3,c4,c5,c6;
    printf("What is your name? ");
    scanf("%c%c%c%c%c%c", &c1,&c2,&c3,&c4,&c5,&c6);
    printf("This program has been created by %c%c%c%c%c%c(~_~)\n" , c1,c2,c3,c4,c5,c6);
}
float add(float a,float b)
{
    return (a+b);
}

float subtract(float a,float b)
{
    return (a-b);
}

float multiply(float a,float b)
{
    return (a * b);
}
float divide(float a,float b)
{
    return (a/b);
}
int main()
{   
    name();    
    float x, y, sum, subtrc, multiple, div;
    printf("Give value for x: ");
    scanf("%f", &x);
    printf("Give value for y: ");
    scanf("%f", &y);
    sum = add(x,y);
    subtrc = subtract(x,y);
    multiple = multiply(x,y);
    div = divide(x,y);
    printf("Sum is %.2f\n", sum);
    printf("Subtraction is %.2f\n", subtrc);
    printf("Multiplication is %.2f\n", multiple);
    printf("Division is %.2f", div);
    
    return 0;
}