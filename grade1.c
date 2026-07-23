#include <stdio.h>
#include <string.h>

float calc(int i){     
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
float cgpa(float course[5][7], int student){
           float total = 0;
           for (int i = 0; i < 7; i ++) total += course[student][i];
           total = total / 7;
           return total;         
}

int main(){
    int i, j, roll, mark;
    float course[5][7], cg[5];

    for(i = 0; i < 5; i++){
        for(j = 0; j < 7; j++){
            printf("Marks for Roll: %d in course %d: ", i + 1, j + 1);
            scanf("%d", &mark);
            course[i][j] = calc(mark);
        }
    }
       
    for (j = 0; j < 5; j++)cg[j] = cgpa(course, j);

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
    while(1){
        char grade[10];
        printf("Press -1 to exit or,\nSee result of Roll: ");
        scanf("%d", &roll);
        
        if (roll == -1 || roll < 1 || roll > 5) break;
        for(i = 0; i < 5; i++){
            if(rolls[i] == roll) break;
        }
        if (cg[i] == 4.00) strcpy(grade, "A+");
        else if (cg[i] >= 3.75) strcpy(grade, "A");
        else if (cg[i] >= 3.50) strcpy(grade, "A-");
        else if (cg[i] >= 3.25) strcpy(grade, "B+");
        else if (cg[i] >= 3.00) strcpy(grade, "B");
        else if (cg[i] >= 2.75) strcpy(grade, "B-");
        else if (cg[i] >= 2.50) strcpy(grade, "C+");
        else if (cg[i] >= 2.25) strcpy(grade, "C");
        else if (cg[i] >= 2.00) strcpy(grade, "D");
        else strcpy(grade, "F");
          
        printf("Roll %d has CGPA: %0.2f, Grade: %s and merit %d\n", rolls[i], cg[i],grade, i + 1);
    }
    return 0;
}
 
