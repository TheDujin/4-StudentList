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


int main() {
  vector<Student> sList;
  char add[4] = {'A', 'D', 'D', '\0'};
  char print[6] = {'P', 'R', 'I', 'N', 'T', '\0'};
  char del[7] = {'D', 'E', 'L', 'E', 'T', 'E', '\0'};

  
  Student george;
  cin >> george.name;
  george.id = 1234;
  george.gpa = 3.0;
  cout << george.name << " ID: " << george.id << " GPA: " << george.gpa << endl;









}
