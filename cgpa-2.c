#include <stdio.h>
#include <string.h>
float calc(float i){      
      if (i >= 80) return 4.00;
      else if (i >= 75) return 3.75;
      else if (i >= 70) return 3.5;
      else if (i >= 65) return 3.25;
      else if (i >= 60) return 3.00;
      else if (i >= 55) return 2.75;
      else if (i >= 50) return 2.5;
      else if (i >= 45) return 2.25;
      else if (i >= 40) return 2.00;
      else return 0.00;   
}
typedef struct Student {
    char name[50];
    int roll;
    float cg;
    float total;
    struct Student *next;
} Student;

int main(int argc, char *argv[]){
    if(argc != 8){
        printf("Invalid amount of command line arguments.\n");
        return 1;
    }
    FILE *fp[7];
    for(int i = 0; i < 7; i++){
        fp[i] = fopen(argv[i+1], "r");
        if(fp[i] == NULL){
            printf("Error opening file %d", (i + 1));
            perror("");
            for(int j = 0; j < i; j++) fclose(fp[j]);
            return 1;
        }
    }     
    Student students[50];
    char buffer[7][100];
    for (int i = 0; i < 7; i++) fgets(buffer[i], sizeof(buffer[i]), fp[i]);
    int count = 0, read = 0;
    float marks[5], total_grade, mark_total;
    while(1){
            for(int i = 0; i < 7; i++){
                if(fgets(buffer[i], sizeof(buffer[i]), fp[i]) == NULL) {
                    read = -1;
                    break;
                }
            }
            if (read == -1) break;
            float course[7] = {0};    
            total_grade = 0;
            mark_total = 0; 
            for(int i = 0; i < 7; i++){
                sscanf(buffer[i], "%[^,], %d, %f, %f, %f, %f, %f", students[count].name, &students[count].roll, &marks[0], &marks[1], &marks[2], &marks[3], &marks[4]);
                for (int j = 0; j < 5; j++) course[i] += marks[j];
                mark_total += course[i]; 
                course[i] = calc(course[i]);
                total_grade += course[i];    
            } 
            students[count].total = mark_total;
            students[count].cg = total_grade / 7 ;
            count++;                  
    } 
    for(int i = 0; i < count - 1; i++){
        for(int j = 0; j < count - 1 - i; j++){
            if(students[j].cg < students[j+1].cg) {
                Student temp;
                temp = students[j];
                students[j] = students[j+1];
                students[j+1] = temp;
            }
        }
    }
    for(int i = 0; i < count - 1; i++) students[i].next = &students[i+1];
    students[count - 1].next = NULL;
    FILE *out = fopen("output.txt", "w");
    if(out == NULL){
        perror("Error opening output file");
        for(int j = 0; j < 7; j++) fclose(fp[j]);
        return 1;
    }
    int roll, x = -1;
    printf("Pick Roll of student: ");
    scanf("%d", &roll);
    for(int i = 0; i < count; i++){
        if(students[i].roll == roll){
            x = i;
            break;
        }
    }
    if(x == -1) {
        printf("Roll not found.\n");
        fclose(out);
        for(int j = 0; j < 7; j++) fclose(fp[j]);
        return 1;
    }
    fprintf(out,"%-15s | %-6s | %s\n", "Name", "Roll", "Marks of Next Person");
    fprintf(out,"----------------|--------|----------------------\n");
    for(int i = x; i < count - 1; i++){
    fprintf(out,"%-15s | %-6d | %.2f\n", students[i].name, students[i].roll, students[i].next->total);    
    }
    for(int j = 0; j < 7; j++) fclose(fp[j]);
    fclose(out);
    return 0;
}
