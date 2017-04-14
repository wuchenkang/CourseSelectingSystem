#include "Student.h"

using namespace std;

Student::Student(string name){
	setName(name);
}

void Student::getOption(int& option,string& courseName){
  cout << "****************************************" << endl;
  cout << "* User: "<< left<< setw(30) <<  name << " *" << endl;
  cout << "****************************************" << endl;
  cout << "*          Available options           *" << endl;
  cout << "****************************************" << endl;
  cout << "* 1)Choose course   2)Quit course      *" << endl;
  cout << "* 3)Show courses    4)Log out          *" << endl;
  cout << "****************************************" << endl;
  cin >> option;
  while(option < 1 || option > 4){
    cout << "# Invalid option,please try again!     #" << endl;
  }
  switch(option){
    case 1:
      cout << "* Please enter the name of the course  *" << endl;
      cin >> courseName;
      break;
    case 2:
			cout << "* Please enter the name of the course  *" << endl;
      cin >> courseName;
      break;
    case 3:
			cout << "* Please enter the name of the course  *" << endl;
			cout << "* Enter \"All\" to show all your courses *" << endl;
      cin >> courseName;
      break;
    default:
      break;
  }
  return;
}

string Student::getName()const{
	return name;
}

int Student::findCourseIndex(string courseName){
	for(int i = 0; i < courseList.size(); i++){
		if(courseList[i] == courseName){
			return i;
		}
	}
	return -1;
}

bool Student::setName(string name){
	this->name = name;
}
