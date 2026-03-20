#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    int id;
    char first_name[25];
    char last_name[25];
    char dob[11];
    char gender[15];
    float gpa;
    int semester;
    char program[20];
    int num_courses;
} Student;

Student students[100];
int student_count = 0;
// Function declaration
void add_student();
int delete_student();
void display_students();
int isValidDate(int, int, int);
int isLeap(int);

void main()
{
   int choice;
   do
   {
      printf("\n1. Add Student");
      printf("\n2. View Student");
      printf("\n3. Delete Student");
      printf("\n4. Exit");
      printf("\nEnter your choice:");
      scanf("%d", &choice);

      // Contol flow statement to execute based on choice
      switch (choice)
      {
      case 1:
         add_student();
         break;
      case 2:
         display_students();
         break;
      case 3:
         if (delete_student() == 0)
         {
            printf("Invalid student Id. Please check it again");
         }
         else
         {
            printf("\nDeleted student succesfully.");
         }
         break;
      case 4:
         break;
      default:
         printf("Invalid entry");
      }
   } while (choice != 4);
}

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


// Function for deleting student from array
int delete_student()
{
   int i, index = -1, student_id;
   printf("\nEnter student id tobe deleted:");
   scanf("%d", &student_id);
   for (i = 0; i < student_count; i++)
   {
      // Stop searching the elements as soon it found id in array
      if (students[i].id == student_id)
      {
         index = i;
         i = student_count;
         break;
      }
   }

   if (index == -1)
   {
      return 0;
   }
   else
   {
      // Shift the next element to current location.
      for (i = index; i < student_count; i++)
      {
         if ((i + 1) <= student_count)
         {
            students[i] = students[i + 1];
         }
      }

      student_count--;
      return 1;
   }
}

// Function for displaying all students in student array
void display_students()
{
   int i;
   if (student_count == -1)
   {
      printf("Student list is empty. Please add new student and try this option.");
   }
   for (i = 0; i < student_count; i++)
   {
      printf("\nStudent Id is:%d", students[i].id);
      printf("\nStudent First Name is:%s", students[i].first_name);
      printf("\nStudent last name is:%s", students[i].last_name);
      printf("\nStudent Date of birth is:%s", students[i].dob);
      printf("\nStudent gender is:%s", students[i].gender);
      printf("\nStudent GPA is:%f", students[i].gpa);
      printf("\nStudent current semester is:%d", students[i].semester);
      printf("\nStudent program is:%s", students[i].program);
      printf("\nNumber of courses are:%d", students[i].num_courses);
   }
}

// Function to check if a year is a leap year
int isLeap(int year)
{
   return (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0));
}

// Function to validate the date
int isValidDate(int date, int month, int year)
{
   if (year > 9999 || year < 1800)
      return 0; // Range check
   if (month < 1 || month > 12)
      return 0;
   if (date < 1 || date > 31)
      return 0;

   // Handle February and months with 30 days
   if (month == 2)
      return isLeap(year) ? (date <= 29) : (date <= 28);
   if (month == 4 || month == 6 || month == 9 || month == 11)
      return (date <= 30);
   printf("%d", date);
   return 1;
}
