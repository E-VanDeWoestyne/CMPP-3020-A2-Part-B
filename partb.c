#include <stdio.h>

/*
 * Simple student management program.
 */

typedef struct {
  char first_name[25];
  char last_name[25];
  char dob[11];
  char gender[15];
  float gpa;
  int semester;
  char program[50];
  int num_courses;
} Student;

// Initialize a fixed-size array to store student records and counters for
// tracking the number of students and assigning unique IDs.
Student students[100];
int student_count = 0;
int next_student_id = 1;

// Function declaration
void add_student();
int delete_student();
void display_students();
int isValidDate(int, int, int);
void isLeap(int *);
void clear_input_buffer(void);

int main(void) {
  int choice;
  // Keep showing the menu until user chooses to exit.
  do {
    printf("\n1. Add Student");
    printf("\n2. View Student");
    printf("\n3. Delete Student");
    printf("\n4. Exit");
    printf("\nEnter your choice: ");
    scanf("%d", &choice);

    // Contol flow statement to execute based on choice
    switch (choice) {
    case 1:
      add_student();
      break;
    case 2:
      display_students();
      break;
    case 3:
      if (delete_student() == 0) {
        printf("\nInvalid student ID. Please check it again.\n");
      } else {
        printf("\nDeleted student succesfully.\n");
      }
      break;
    case 4:
      break;
    default:
      printf("\nInvalid entry. Please enter a valid choice.\n");
    }
  } while (choice != 4);
  return 0;
}

void add_student() {
  // Prevent overflow of fixed-size storage.
  if (student_count >= 100) {
    printf("Maximum student limit reached.\n");
    return;
  }

  Student new_student;
  int day, month, year;

  while (1) {
    printf("\nEnter first name: ");
    if (scanf(" %24[^\n]", new_student.first_name) == 1) {
      clear_input_buffer();
      break;
    }
    printf("Invalid input. Please enter text.\n");
    clear_input_buffer();
  }

  while (1) {
    printf("Enter last name: ");
    if (scanf(" %24[^\n]", new_student.last_name) == 1) {
      clear_input_buffer();
      break;
    }
    printf("Invalid input. Please enter text.\n");
    clear_input_buffer();
  }

  // Read DOB inputted, then parse and validate DD/MM/YYYY. Loop if format was
  // incorrect. AI assisted with 'sscanf' line syntax for implementing the date
  // validator.
  while (1) {
    printf("Enter date of birth (DD/MM/YYYY): ");
    scanf("%10s", new_student.dob);

    if (sscanf(new_student.dob, "%d/%d/%d", &day, &month, &year) == 3 &&
        isValidDate(day, month, year)) {
      break;
    }

    printf("Invalid date. Please enter a valid date in DD/MM/YYYY format.\n");
    clear_input_buffer();
  }

  while (1) {
    printf("Enter gender: ");
    if (scanf("%14s", new_student.gender) == 1) {
      clear_input_buffer();
      break;
    }
    printf("Invalid input. Please enter text.\n");
    clear_input_buffer();
  }

  while (1) {
    printf("Enter GPA: ");
    if (scanf("%f", &new_student.gpa) == 1) {
      clear_input_buffer();
      break;
    }
    printf("Invalid input. Please enter a number.\n");
    clear_input_buffer();
  }

  while (1) {
    printf("Enter semester: ");
    if (scanf("%d", &new_student.semester) == 1) {
      clear_input_buffer();
      break;
    }
    printf("Invalid input. Please enter an integer.\n");
    clear_input_buffer();
  }

  while (1) {
    printf("Enter program: ");
    if (scanf(" %49[^\n]", new_student.program) == 1) {
      clear_input_buffer();
      break;
    }
    printf("Invalid input. Please enter text.\n");
    clear_input_buffer();
  }

  while (1) {
    printf("Enter number of courses: ");
    if (scanf("%d", &new_student.num_courses) == 1) {
      clear_input_buffer();
      break;
    }
    printf("Invalid input. Please enter an integer.\n");
    clear_input_buffer();
  }

  students[student_count++] = new_student;
  printf("\nStudent added successfully.\n");
}

// Function for deleting student from array
int delete_student() {
  int i, index;
  printf("\nEnter the index of the student to remove: ");
  scanf("%d", &index);
  if (index > student_count) {
    printf("Invalid student index.");
    return 0;
  }
  // Shift the next element to current location.
  for (i = index - 1; i < student_count; i++) {
    if ((i + 1) <= student_count) {
      students[i] = students[i + 1];
    }
  }

  student_count--;
  return 1;
}

// Function for displaying all students in student array
void display_students() {
  int i;
  if (student_count == 0) {
    printf(
        "\nStudent list is empty. Please add new student and try this option.");
  }

  // Print every student's info currently stored in the array.
  for (i = 0; i < student_count; i++) {
    printf("\nStudent ID: %d", i + 1);
    printf("\nFirst name: %s", students[i].first_name);
    printf("\nLast name: %s", students[i].last_name);
    printf("\nDate of birth: %s", students[i].dob);
    printf("\nGender: %s", students[i].gender);
    printf("\nGPA: %f", students[i].gpa);
    printf("\nCurrent semester: %d", students[i].semester);
    printf("\nProgram: %s", students[i].program);
    printf("\nNumber of courses: %d\n", students[i].num_courses);
  }
}

// Function to check if a year is a leap year
void isLeap(int *year) {
  *year = (((*year % 4 == 0) && (*year % 100 != 0)) || (*year % 400 == 0));
}

// Function to validate the date
int isValidDate(int date, int month, int year) {
  if (year > 9999 || year < 1800) {
    return 0; // Range check
  }
  if (month < 1 || month > 12) {
    return 0;
  }
  if (date < 1 || date > 31) {
    return 0;
  }

  // Handle February and months with 30 days
  if (month == 2) {
    isLeap(&year);
    return year ? (date <= 29) : (date <= 28);
  }
  if (month == 4 || month == 6 || month == 9 || month == 11) {
    return (date <= 30);
  }
  return 1;
}

// Function to clean input buffer after reading input to prevent issues with
// subsequent input calls. Used after reading input (like in add_student) to
// ensure that any leftover characters do not interfere with the next input.
void clear_input_buffer(void) {
  int ch;
  while ((ch = getchar()) != '\n' && ch != EOF) {
  }
}