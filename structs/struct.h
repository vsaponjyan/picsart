#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

struct StudentData
{
    char first_names[50];
    char last_names[50];
    int grades[10];
    double avg;
};

int random_int(int min, int max) {
    return min + rand() % (max - min + 1);
}

void addStudent(struct StudentData *students, const char *first_name, const char *last_name)
{
    static int count = 0;
    
   
    strcpy(students->first_names, first_name);
    strcpy(students->last_names, last_name);
    
    printf("Student %d: %s %s", count + 1, students->first_names, students->last_names);
    double average = 0;
    for (int i = 0; i < 5; i++) {
        students->grades[i] = random_int(1, 100);
        average = average + students->grades[i];
        printf(" Grade: %d", students->grades[i]);
        
    }
        printf(" Average: %.2lf \n", average/5);
        students->avg = average/5;
    
    count = count + 1;
}

void max_grade(struct StudentData *arr, size_t size) {
    double max_avg = arr[0].avg;
    char max_student[100];
    strcpy(max_student, arr[0].first_names); 
    
    for (size_t i = 1; i < size; i++) {
        if (arr[i].avg > max_avg) {
            max_avg = arr[i].avg;
            strcpy(max_student, arr[i].first_names);
        }
    }
    
    printf("\033[32m Student with highest average: %s, Average is \033[0m%.2lf\n", max_student, max_avg);
}


