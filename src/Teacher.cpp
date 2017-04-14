#include "Teacher.h"

using namespace std;

Teacher::Teacher(string name){
  setName(name);
}

void Teacher::getOption(int& option,string& courseName, int& maxStudent){
  cout << "****************************************" << endl;
  cout << "* User: "<< left<< setw(30) <<  name << " *" << endl;
  cout << "****************************************" << endl;
  cout << "*          Available options           *" << endl;
  cout << "****************************************" << endl;
  cout << "* 1)Open course     2)Cancle course    *" << endl;
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
      cout << "Please enter the max number of studnets*" << endl;
      cin >> maxStudent;
      while(maxStudent <= 0){
      	cout << "#Invalid amount of students, try again!#" << endl;
      	cin >> maxStudent;
      }
      break;
    case 2:
			cout << "* Please enter the name of the course  *" << endl;
      cin >> courseName;
      break;
    case 3:
			cout << "* Please enter the name of the course  *" << endl;
			cout << "* Enter \"All\" to show all your course  *" << endl;
      cin >> courseName;
      break;
    default:
      break;
  }
  return;
}

string Teacher::getName()const{
	return name;
}

int Teacher::findCourseIndex(string courseName){
	for(int i = 0; i < courseList.size(); i++){
		if(courseList[i] == courseName){
			return i;
		}
	}
	return -1;
}

void Teacher::setName(string name){
	this->name = name;
}
