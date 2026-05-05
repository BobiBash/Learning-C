#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[256];
    double grade;
} Student;

int main() {

    int num_students;
    printf("Input number of students: ");
    scanf("%d", &num_students);
    while(getchar() != '\n');

    Student *students_ptr = malloc(sizeof(Student) * num_students);
    
    for(int i = 0; i < num_students; i++) {
        printf("Student name: ");
        fgets(students_ptr[i].name, sizeof(students_ptr[i].name), stdin);
        students_ptr[i].name[strcspn(students_ptr[i].name, "\n")] = 0;
        
        printf("Student grade: ");
        scanf(" %lf", &students_ptr[i].grade);
        while(getchar() != '\n');
    }

    for(int i = 0; i < num_students; i++) {
        printf("Student name: %s, Student grade: %.2lf\n", students_ptr[i].name, students_ptr[i].grade);
    }

    free(students_ptr);
    return 0;
}