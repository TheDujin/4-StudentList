#include <iostream>
#include <vector>
#include <string.h>
#include <cstdlib>
#include <iomanip>

using namespace std;

struct Student {
  char firstName[80];
  char lastName[80];
  int id;
  float gpa;
};
Student addStudent(vector<Student> * listPtr);
void printOut(vector<Student> * listPtr);
void deleteStudent(vector<Student> * listPtr);

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
  return newStudent;
}

void printOut(vector<Student> * listPtr) {
  vector<Student>::iterator itr;
  int i = 0;
  if (listPtr->empty()) {
    cout << "There are no students registered. You can add some with the \"ADD\" command." << endl;
    return;
  }
  for (itr = listPtr->begin(); itr != listPtr->end(); itr++) {
    Student student = * itr;
    cout << "Name: " << student.lastName << ", " << student.firstName << "   ID: " << student.id << "   GPA: " << student.gpa << endl;
    i++;
  }
}

void deleteStudent(vector<Student> * listPtr) {
  int idTarget;
  cout << "Please enter the ID of the student you would like to delete." << endl << "ID: ";
  cin >> idTarget;

}



int main() {
  char input[81];
  vector<Student> sList;
  vector<Student> * listPtr = & sList;
  char add[4] = {'A', 'D', 'D', '\0'};
  char print[6] = {'P', 'R', 'I', 'N', 'T', '\0'};
  char del[7] = {'D', 'E', 'L', 'E', 'T', 'E', '\0'};
  char quit[5] = {'Q', 'U', 'I', 'T', '\0'};
  bool running = true;
  
  while (running) {
    cout << "Please type \"ADD\", \"PRINT\", \"DELETE\", or \"QUIT\" as commands then press Enter." << endl << "Input: ";
    cout << setprecision(2) << fixed;
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
  
  
  //Student george;
  //cin >> george.name;
  //george.id = 1234;
  //george.gpa = 3.0;
  //cout << george.name << " ID: " << george.id << " GPA: " << george.gpa << endl;









}
