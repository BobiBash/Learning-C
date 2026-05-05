#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[256];
    double grade;
} Student;

int compare_names(const void *name1, const void *name2);

int main() {

    int num_students;
    int Student_size = sizeof(Student);
    printf("Input number of students: ");
    scanf("%d", &num_students);
    while(getchar() != '\n');

    Student *students_ptr = malloc(Student_size * num_students);
    
    for(int i = 0; i < num_students; i++) {
        printf("Student name: ");
        fgets(students_ptr[i].name, sizeof(students_ptr[i].name), stdin);
        students_ptr[i].name[strcspn(students_ptr[i].name, "\n")] = 0;
        
        printf("Student grade: ");
        scanf(" %lf", &students_ptr[i].grade);
        while(getchar() != '\n');
    }

    qsort(students_ptr, num_students, Student_size, compare_names);

    for(int i = 0; i < num_students; i++) {
        printf("Student name: %s, Student grade: %.2lf\n", students_ptr[i].name, students_ptr[i].grade);
    }

    free(students_ptr);
    return 0;
}

int compare_names(const void *name1, const void *name2) {
    Student *s1 = (Student *)name1;
    Student *s2 = (Student *)name2;

    int name_cmp = strcmp(s1->name, s2->name);
    if (name_cmp != 0)
        return name_cmp;

    if(s1->grade > s2->grade) return -1;
    if(s1->grade < s2->grade) return 1;
    return 0;
}