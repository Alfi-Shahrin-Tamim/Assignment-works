#include <stdio.h>

float cgpa(float course1[],float course2[],float course3[],
                float course4[],float course5[],float course6[],float course7[], int i){
           float total = course1[i]+course2[i]+course3[i]+course4[i]+course5[i]+ course6[i]+ course7[i];
           total = total / 7;
           return total;         
}

int main(){
    int i, j;
    float cg[5], course1[5], course2[5], course3[5], course4[5], course5[5], course6[5], course7[5], total[5];

    for (i = 0; i < 5; i++){
        printf("Marks for Roll %d in course 1: ", i+1);
        scanf("%f", &course1[i]);
    }

    for (i = 0; i < 5; i++){
        printf("Marks for Roll %d in course 2: ", i+1);
        scanf("%f", &course2[i]);
    }

    for (i = 0; i < 5; i++){
        printf("Marks for Roll %d in course 3: ", i+1);
        scanf("%f", &course3[i]);
    }

    for (i = 0; i < 5; i++){
        printf("Marks for Roll %d in course 4: ", i+1);
        scanf("%f", &course4[i]);
    }

    for (i = 0; i < 5; i++){
        printf("Marks for Roll %d in course 5: ", i+1);
        scanf("%f", &course5[i]);
    }

    for (i = 0; i < 5; i++){
        printf("Marks for Roll %d in course 6: ", i+1);
        scanf("%f", &course6[i]);
    }    

    for (i = 0; i < 5; i++){
        printf("Marks for Roll %d in course 7: ", i+1);
        scanf("%f", &course7[i]);
    }
       
    cg[0] = cgpa(course1, course2, course3, course4, course5, course6, course7, 0);
    cg[1] = cgpa(course1, course2, course3, course4, course5, course6, course7, 1);
    cg[2] = cgpa(course1, course2, course3, course4, course5, course6, course7, 2);
    cg[3] = cgpa(course1, course2, course3, course4, course5, course6, course7, 3);
    cg[4] = cgpa(course1, course2, course3, course4, course5, course6, course7, 4);

    int rolls[5] = {1, 2, 3, 4, 5};
    
    for(i = 0; i < 4; i ++){
        for(j = 0; j < 4 - i; j ++){
            if (cg[j] < cg[j + 1]){
                float temp = cg[j];
                cg[j] = cg[j +1];
                cg[j+1] = temp;
                
                int temp1 = rolls[j];
                rolls[j] = rolls[j+1];
                rolls[j+1] = temp1;
            }
        }
    }   
    for(i = 0; i < 5; i++){
        printf("Roll %d with CGPA %0.2f has merit %d\n", rolls[i], cg[i], i + 1);
    }
}
 
