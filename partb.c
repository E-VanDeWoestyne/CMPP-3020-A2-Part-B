#include <stdio.h>
#include <string.h>

typedef struct {
    char first_name[15];
    char last_name[15];
    char dob[8];
    char gender[15];
    float gpa;
    int semester;
    char program[20];
    int num_courses;
} Student;

Student students[100];
int student_count = 0;

void add_student() {
    if (student_count >= 100) {
        printf("Maximum student limit reached.\n");
        return;
    }
    
    Student new_student;
    
    printf("Enter first name: ");
    scanf("%s", new_student.first_name);
    
    printf("Enter last name: ");
    scanf("%s", new_student.last_name);
    
    printf("Enter date of birth (DD/MM/YY): ");
    scanf("%s", new_student.dob);
    
    printf("Enter gender: ");
    scanf("%s", new_student.gender);

    printf("Enter GPA: ");
    scanf("%f", &new_student.gpa);

    printf("Enter semester: ");
    scanf("%d", &new_student.semester);

    printf("Enter program: ");
    scanf("%s", new_student.program);

    printf("Enter number of courses: ");
    scanf("%d", &new_student.num_courses);

    students[student_count++] = new_student;
    printf("Student added successfully.\n");
}
