# Define Student structure
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

students = []

student_count = 0
MAX_STUDENTS = 100


def add_student():
    global student_count

    if student_count >= MAX_STUDENTS:
        print("Maximum student limit reached.")
        return

    print("Enter first name:")
    first_name = input()

    print("Enter last name:")
    last_name = input()

    print("Enter date of birth (DD/MM/YY):")
    dob = input()

    print("Enter gender:")
    gender = input()

    print("Enter GPA:")
    gpa = float(input())

    print("Enter semester:")
    semester = int(input())

    print("Enter program:")
    program = input()

    print("Enter number of courses:")
    num_courses = int(input())

    new_student = Student(
    first_name,
    last_name,
    dob,
    gender,
    gpa,
    semester,
    program,
    num_courses
    )

    students.append(new_student)
    student_count += 1

    print("Student added successfully.")