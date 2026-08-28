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
typedef struct {
    char name[50];
    int roll;
    float cg;
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
    FILE *bin = fopen("bin_result.bin", "wb");
    if(bin == NULL) {
        perror("Error opening binary file");
        for(int i = 0; i < 7; i++) fclose(fp[i]);
        return 1;
    }
    char buffer[7][100];
    for (int i = 0; i < 7; i++) fgets(buffer[i], sizeof(buffer[i]), fp[i]);
  
    int count = 0, read = 0;
    float marks[5], total;
    while(1){
            for(int i = 0; i < 7; i++){
                if(fgets(buffer[i], sizeof(buffer[i]), fp[i]) == NULL) {
                    read = -1;
                    break;
                }
            }
            if (read == -1) break;
            float course[7] = {0};    
            total = 0; 
            for(int i = 0; i < 7; i++){
                sscanf(buffer[i], "%[^,], %d, %f, %f, %f, %f, %f", students[count].name, &students[count].roll, &marks[0], &marks[1], &marks[2], &marks[3], &marks[4]);
                for (int j = 0; j < 5; j++) course[i] += marks[j];
                course[i] = calc(course[i]);
                total += course[i];    
            } 
            students[count].cg = total / 7 ;
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
    fwrite(students, sizeof(Student), count, bin);
    fclose(bin); 
    for(int j = 0; j < 7; j++) fclose(fp[j]);
    bin = fopen("bin_result.bin", "rb");
    if(bin == NULL){
        perror("Error opening binary file");
        return 1;
    }
    FILE *out = fopen("output.txt", "w");
    if(out == NULL){
        perror("Error opening output file");
        fclose(bin);
        return 1;
    }
    Student read_students[50];
    size_t read_count = fread(read_students, sizeof(Student), count, bin);
    if(read_count != count) printf("Warning: Expected students: %d, Read students: %zu", count, read_count);
    fprintf(out,"%-15s | %-6s | %s\n", "Name", "Roll", "CGPA");
    fprintf(out,"----------------|--------|------\n");
    for(int i = 0; i < read_count; i++){
    fprintf(out,"%-15s | %-6d | %.2f\n", read_students[i].name, read_students[i].roll, read_students[i].cg);    
    }
    fclose(bin);
    fclose(out);
    return 0;
}
