#include "LMS.h"
using namespace std;
LMS::LMS(string lmsName){
    name=lmsName;
}

void LMS::addStudent(Student& student) {
    students.push_back(student);
//    cout << "Student " << student.getName() << " added to LMS." << endl;
}

void LMS::addCourse(Course& course) {
    courses.push_back(course);
//    cout << "Course " << course.getName() << " added to LMS." << endl;
}

bool LMS::addStudentToCourse(int studentId, int courseId) {
    
    bool studentFound = false;
    Student* studentPtr = nullptr;
    for (Student& s : students) {
        if (s.getId() == studentId) {
            studentPtr = &s;  // Store reference to student
            studentFound = true;
            break;
        }
    }
    
    // Check if course exists
    bool courseFound = false;
    Course* coursePtr = nullptr;
    for (Course& c : courses) {
        if (c.getId() == courseId) {
            coursePtr = &c;  // Store reference to course
            courseFound = true;
            break;
        }
    }
    
    // Try to enroll the student in the course
    if (studentPtr->takeCourse(*coursePtr)) {
        coursePtr->addStudent(studentId);
    }
    return true;
}


void LMS::printDetails() {
    cout << "LMS Name: " << name << endl;
    
    // Print students
    cout << "Students:" << endl;
    for (auto& student : students) {
        student.printDetails();
    }

    // Print courses
    cout << "Courses:" << endl;
    for (auto& course : courses) {
        course.printDetails();
    }
}
