from datetime import datetime


class Student:
    def __init__(self, first_name, last_name, dob, gender, gpa, semester, program, num_courses):
        self.first_name = first_name
        self.last_name = last_name
        self.dob = dob
        self.gender = gender
        self.gpa = gpa
        self.semester = semester
        self.program = program
        self.num_courses = num_courses


Students = [
    Student("Alice", "Johnson", "2001-05-14", "Female", 3.8, 5, "Computer Science", 6),
    Student("Brian", "Smith", "2000-11-22", "Male", 3.2, 4, "Information Technology", 5),
    Student("Clara", "Ndiaye", "2002-03-09", "Female", 3.9, 6, "Software Engineering", 7)
]


# -------------------------
# Helper validation functions
# -------------------------

def get_non_empty_string(prompt):
    while True:
        value = input(prompt).strip()
        if value:
            return value
        else:
            print("Input cannot be empty. Please try again.")


def get_valid_int(prompt, min_value=None, max_value=None):
    while True:
        try:
            value = int(input(prompt))
            if min_value is not None and value < min_value:
                print(f"Value must be at least {min_value}.")
            elif max_value is not None and value > max_value:
                print(f"Value must be at most {max_value}.")
            else:
                return value
        except ValueError:
            print("Invalid input. Please enter a valid integer.")


def get_valid_float(prompt, min_value=None, max_value=None):
    while True:
        try:
            value = float(input(prompt))
            if min_value is not None and value < min_value:
                print(f"Value must be at least {min_value}.")
            elif max_value is not None and value > max_value:
                print(f"Value must be at most {max_value}.")
            else:
                return value
        except ValueError:
            print("Invalid input. Please enter a valid number.")


def get_valid_dob(prompt):
    """
    Validates date of birth in YYYY-MM-DD format
    and ensures it's a real date.
    """
    while True:
        dob = input(prompt).strip()
        try:
            # Try to parse the date
            parsed_date = datetime.strptime(dob, "%Y-%m-%d")

            # Get today's date (without time)
            today = datetime.now().date()

            # Allow only dates strictly before today
            if parsed_date.date() < today:
                return dob
            else:
                print("Date of birth must be before today.")
        except ValueError:
            print("Invalid date format. Please use YYYY-MM-DD.")


def get_valid_gender(prompt):
    """
    Validates gender input against allowed values.
    """
    valid_genders = ["male", "female", "other"]

    while True:
        gender = input(prompt).strip().lower()

        if gender in valid_genders:
            # Capitalize first letter for consistency
            return gender.capitalize()
        else:
            print("Invalid gender. Please enter Male, Female, or Other.")


# -------------------------
# Core functions
# -------------------------

def display_students():
    if not Students:
        print("No student records available.")
    else:
        print(f"List of students:")
        for i, student in enumerate(Students):
            print(f"Student id: {i + 1}")
            print(f"First Name: {student.first_name}")
            print(f"Last Name: {student.last_name}")
            print(f"Date of birth: {student.dob}")
            print(f"Gender: {student.gender}")
            print(f"GPA: {student.gpa}")
            print(f"Semester: {student.semester}")
            print(f"Program: {student.program}")
            print(f"Number of Courses: {student.num_courses}")
            print()


def add_student():
    first_name = get_non_empty_string("Enter first name: ")
    last_name = get_non_empty_string("Enter last name: ")
    dob = get_valid_dob("Enter date of birth (YYYY-MM-DD): ")
    gender = get_valid_gender("Enter gender (Male/Female/Other): ")

    # GPA must be between 0.0 and 4.0
    gpa = get_valid_float("Enter GPA (0.0 - 4.0): ", 0.0, 4.0)

    semester = get_valid_int("Enter semester: ", 1)
    program = get_non_empty_string("Enter program: ")
    num_courses = get_valid_int("Enter number of courses: ", 0)

    student = Student(first_name, last_name, dob, gender, gpa, semester, program, num_courses)
    Students.append(student)

    print("Student added successfully.")


def remove_student():
    if not Students:
        print("No student records to remove.")
    else:
        display_students()

        index = get_valid_int("Enter the id of the student to remove: ", 1, len(Students))
        Students.pop(index - 1)

        print("Student removed successfully.")


def modify_student():
    if not Students:
        print("No student records to modify.")
    else:
        display_students()

        index = get_valid_int("Enter the id of the student to modify: ", 1, len(Students))
        student = Students[index - 1]

        student.first_name = get_non_empty_string("Enter new first name: ")
        student.last_name = get_non_empty_string("Enter new last name: ")
        student.gpa = get_valid_float("Enter new GPA (0.0 - 4.0): ", 0.0, 4.0)
        student.program = get_non_empty_string("Enter new program: ")

        print("Student record updated successfully.")


# -------------------------
# Main program
# -------------------------

def main():
    print(f"Welcome to the Student Management Program!")
    while True:
        print("\nStudent Enrollment Menu")
        print("1. Display Students")
        print("2. Add Student")
        print("3. Remove Student")
        print("4. Modify Student")
        print("5. Exit")

        choice = get_valid_int("Enter your choice: ")

        if choice == 1:
            display_students()
        elif choice == 2:
            add_student()
        elif choice == 3:
            remove_student()
        elif choice == 4:
            modify_student()
        elif choice == 5:
            print("Exiting program...\nBye bye!")
            break
        else:
            print("Invalid option. Please try again.")


if __name__ == "__main__":
    main()