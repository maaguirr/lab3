#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

const size_t MAX_SIZE = 100;

int theArray[10] = {1,2,3,4,5,6,7,8,9,10};

typedef struct student{
    int ID;
    char firstName[30];
    char lastName[30];
    float GPA;
} Student;

void reverseArray(void){
    int theArrSize = sizeof(theArray)/sizeof(theArray[0]);
    for(int i = 1 ; i < (theArrSize + 1); i++){
        printf("%d ", (theArray[10-i]));
    }
    printf("\n");
}


Student* createStudentInfo(){
    Student* stdnt = (Student*) malloc(sizeof(Student));
    printf("Please enter Student ID: ");
    scanf("%d", &stdnt->ID);
    printf("Please enter Student's first name: ");
    scanf("%s", stdnt->firstName);
    printf("Please enter Student's last name: ");
    scanf("%s", stdnt->lastName);
    printf("Please enter Student's GPA: ");
    scanf("%f", &stdnt->GPA);
    return stdnt;
}

void sortByGPA(Student** stdntArr, int stdnts){
    for(int i = 0; i < stdnts; i++){
        for(int j = 0; j < (stdnts-1-i); j++){
            if (stdntArr[j]->GPA < stdntArr[j+1]->GPA){
                Student* p = stdntArr[j];
                stdntArr[j] = stdntArr[j+1];
                stdntArr[j+1] = p;
            }
        }
    }
}

void openFile(Student** stdntArr, int stdnts){
    FILE *pq;
    char buff[255];
    pq = fopen("student_info.txt","r");
    printf("\n");
    for(int n=0;n<=(stdnts*4);n++){
        fgets(buff,255,(FILE*)pq);
        printf("%s",buff);
    }
}

void gpaAvg(float sum, int stdnts){
    printf("\n");
    float avg = sum/stdnts;
    printf("Average GPA of students is: %0.1f", avg);
    printf("\n");
}

char menu(){
    char choice;
    printf("A) Count the number of vowels in the string\nB) Count the number of consonants in the string\nC) Convert the string to uppercase\nD) Convert the string to lowercase\nE) Display the current string\nF) Enter new string\nM) Display this menu\nR) Reverse string\nX) Exit the program\n");
    printf("Make a selection: \n");
    scanf(" %c", &choice);
    return(choice);
}

int main(){
reverseArray();
    float sum = 0;
    int stdnts;
    printf("Please enter # of students: ");
    scanf("%d", &stdnts);
    Student** stdntArr = (Student**)malloc(sizeof(Student*) *stdnts);
    for(int i = 0; i < stdnts; i++){
        stdntArr[i] = createStudentInfo();
    }
    sortByGPA(stdntArr, stdnts);
    FILE *fp = fopen("student_info.txt","w");
    fprintf(fp, "The number of students is: %d\n", stdnts);
    for(int i = 0; i < stdnts; i++){
        fprintf(fp, "%d\n", stdntArr[i]->ID);
        fprintf(fp, "%s\n", stdntArr[i]->firstName);
        fprintf(fp, "%s\n", stdntArr[i]->lastName);
        fprintf(fp, "%.1f\n", stdntArr[i]->GPA);
        sum += stdntArr[i]->GPA;
    }
    fclose(fp);
    for(int k = 0; k < stdnts; k++){
        free(stdntArr[k]);
    }
    free(stdntArr);
    openFile(stdntArr, stdnts);
    gpaAvg(sum, stdnts);
    
    
    char s[MAX_SIZE];
    printf("Please Input text: ");
    gets(s);
    bool run = 1;
    while(run){
        int c = 0, count = 0;
        int x = 0, counter = 0;
        int i;
        int vowels;
        char menuSelection = menu();
        if (menuSelection == 'a' || menuSelection == 'A'){
            while (s[c] != '\0') {
                if (s[c] == 'a' || s[c] == 'A' || s[c] == 'e' || s[c] == 'E' || s[c] == 'i' || s[c] == 'I' || s[c] =='o' || s[c]=='O' || s[c] == 'u' || s[c] == 'U'){
                    count++;
                }
            c++;
            }
            printf("\nNumber of vowels: %i\n\n", count);
        }
        else if (menuSelection == 'b' || menuSelection == 'B'){
            while (s[x] != '\0') {
                if (s[x] == 'a' || s[x] == 'A' || s[x] == 'e' || s[x] == 'E' || s[x] == 'i' || s[x] == 'I' || s[x] =='o' || s[x]=='O' || s[x] == 'u' || s[x] == 'U'){
                    vowels++;
                }
                else{
                    counter++;
                }
            x++;
            }
            vowels = 0;
            printf("\nNumber of consonants: %i\n\n", counter);
        }
        else if(menuSelection == 'c' || menuSelection == 'C'){
            for (i = 0; s[i]!='\0'; i++) {
                if(s[i] >= 'a' && s[i] <= 'z') {
                    s[i] = s[i] -32;
                }
            }
            printf("\nString in Upper Case = %s\n", s);
        }
        else if(menuSelection == 'd' || menuSelection == 'D'){
            for (i = 0; s[i]!='\0'; i++) {
                if(s[i] >= 'A' && s[i] <= 'Z') {
                    s[i] = s[i] +32;
                }
            }
            printf("\nString in Lower Case = %s\n", s);
        }
        else if(menuSelection == 'e' || menuSelection == 'E'){
            printf("The current string is '%s'\n",s);
        }
        else if(menuSelection == 'f' || menuSelection == 'F'){
            fflush(stdin);
            memset(s, 0, sizeof MAX_SIZE);
            printf("Please Input text: ");
            gets(s);
        }
        else if(menuSelection == 'm' || menuSelection == 'M'){
            
        }
        else if(menuSelection == 'r' || menuSelection == 'R'){
            printf("reversed string is %s\n",strrev(s));
        }
        else if(menuSelection == 'x' || menuSelection == 'X'){
            exit(1);
        }
        else{
            printf("please pick a valid choice");
        }
    }
}