#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

struct Student {
  char firstName[80];
  char lastName[80];
  float id;
  float gpa;
};
Student addStudent();

Student addStudent() {
  Student newStudent;
  char input[81];
  cout << "Please enter the first name of the student." << endl << "First name: ";
  cin >> newStudent.firstName;
  cout << "Please enter the last name of the student." << endl << "Last name: ";
  cin >> newStudent.lastName;
  cout << "Please enter the student ID." << endl << "Student ID: ";
  cin >> newStudent.id;


  return newStudent;
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
    cin.getline(input, 80);
    if (strcmp(input, add) == 0) {
      cout << "Adding..." << endl;
      addStudent();
    }
    else if (strcmp(input, print) == 0) {
      cout << "Printing..." << endl;
    }
    else if (strcmp(input, del) == 0) {
      cout << "Deleting..." << endl;
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
