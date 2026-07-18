#include <stdio.h>

int main(){
    
    char str1[50], str2[50];
    printf("Give your first word: ");
    scanf("%s", str1);
    printf("Give your second word: ");
    scanf("%s", str2);

    int i = 0;
    while (str1[i] != '\0' && str2[i] != '\0' && str1[i] == str2[i]) i = i + 1;

    printf("Orderd --> \n");
    if(str1[i] > str2[i]) printf("%s\n%s\n", str2, str1);
    else if(str1[i] < str2[i]) printf("%s\n%s\n", str1, str2);
    else printf("They are the same string =>\n%s\n%s\n", str1, str2);

}
