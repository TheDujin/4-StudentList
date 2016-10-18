#include <iostream>
#include <vector>
#include <string.h>
#include <cstdlib>
#include <iomanip>

using namespace std;
/* StudentList by Kevin Jin. A storage system for a list of students.
 * Takes in the inputs "ADD", "DELETE", "PRINT", or "QUIT".
 * "ADD" allows one to enter the parameters for a new student.
 * "DELETE" allows one to delete a student using their ID.
 * "PRINT" allows one to print the current list of students.
 * "QUIT" works as generally advertised.
 * Please enter valid inputs or the code may crash unexpectedly!
 */

//The Student class. Each Student object stores the parameters for a student.
struct Student {
  //These arrays and variables store values for the student.
  char firstName[80];
  char lastName[80];
  int id;
  float gpa;
};

//Declare functions.
Student addStudent(vector<Student> * listPtr);
void printOut(vector<Student> * listPtr);
void deleteStudent(vector<Student> * listPtr);

//Adds a student by prompting for first/last names, ID, and GPA.
Student addStudent(vector<Student> * listPtr) {
  Student newStudent;
  cout << "Please enter the first name of the student." << endl << "First name: ";
  cin >> newStudent.firstName;
  cout << "Please enter the last name of the student." << endl << "Last name: ";
  cin >> newStudent.lastName;
  cout << "Please enter the student ID." << endl << "Student ID: ";
  cin >> newStudent.id;
  cout << "Please enter the student\'s GPA (between 0 and 10, exclusive)." << endl << "Student\'s GPA: ";
  cin >> newStudent.gpa;
  cin.ignore();
  cout << setprecision(2) << fixed << endl;
  //Retursn this student so it can be added to the vector of Students in the main class.
  return newStudent;
}

//Iterates through the vector of students (if there is at least one student) and prints them out.
void printOut(vector<Student> * listPtr) {
  vector<Student>::iterator itr;
  int i = 1;
  if (listPtr->empty()) {
    cout << "There are no students registered. You can add some with the \"ADD\" command." << endl << endl;
    return;
  }
  for (itr = listPtr->begin(); itr != listPtr->end(); itr++) {
    Student student = * itr;
    cout << i << ". Name: " << student.lastName << ", " << student.firstName << "   ID: " << student.id << "   GPA: " << student.gpa << endl;
    i++;
  }
  cout << endl;
}

//Delete a student by finding the Student corresponding to the given ID and erasing it.
void deleteStudent(vector<Student> * listPtr) {
  int idTarget;
  cout << "Please enter the ID of the student you would like to delete." << endl << "ID: ";
  cin >> idTarget;
  vector<Student>::iterator itr;
  int i = 0;
  for (itr = listPtr->begin(); itr != listPtr->end(); itr++) {
    Student student = * itr;
    if (student.id == idTarget) {
      listPtr->erase(listPtr->begin() + i);
      cout << "Student deleted." << endl << endl;
      cin.ignore();
      return;
    }
    i++;
  }
  cout << "That ID could not be found." << endl << endl;
  cin.ignore();
}


//Main class. Takes in inputs and does stuff with it.
int main() {
  char input[81];
  vector<Student> sList;
  vector<Student> * listPtr = & sList;
  //By comparing input with these arrays, which input is being called can be determined.
  char add[4] = {'A', 'D', 'D', '\0'};
  char print[6] = {'P', 'R', 'I', 'N', 'T', '\0'};
  char del[7] = {'D', 'E', 'L', 'E', 'T', 'E', '\0'};
  char quit[5] = {'Q', 'U', 'I', 'T', '\0'};
  bool running = true;

  //While quit has not been called:
  while (running) {
    cout << "Please type \"ADD\", \"PRINT\", \"DELETE\", or \"QUIT\" as commands then press Enter." << endl << "Input: ";
    cout << setprecision(2) << fixed;
    //Takes in input then determines what the input was and calls the corresponding function.
    cin.getline(input, 80);
    if (strcmp(input, add) == 0) {
      cout << "Adding..." << endl;
      sList.push_back(addStudent(listPtr));
    }
    else if (strcmp(input, print) == 0) {
      cout << "Printing..." << endl;
      printOut(listPtr);
    }
    else if (strcmp(input, del) == 0) {
      cout << "Deleting..." << endl;
      deleteStudent(listPtr);
    }
    else if (strcmp(input, quit) == 0) {
      cout << "Quitting..." << endl << "Program terminated. Thank you for your time.";
      running = false;
    }
    else {
      cout << "That input isn't valid. Please check your spelling and ensure that all letters are capitalized." << endl;
    }
    
    
  }
}
