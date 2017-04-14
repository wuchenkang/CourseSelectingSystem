#include "Course.h"

using namespace std;

Course::Course(string name,string teacherName,int maxStudent){
	setName(name);
	setTeacherName(teacherName);
	setMaxStudent(maxStudent);
}
string Course::getName()const{
	return name;
}
string Course::getTeacherName()const{
	return teacherName;
}
int Course::getMaxStudent()const{
	return maxStudent;
}

int Course::findStudentIndex(string studentName){
	for(int i = 0; i < studentList.size(); i++){
		if(studentList[i] == studentName){
			return i;
		}
	}
	return -1;
}

void Course::setName(string name){
	this->name = name;
}

void Course::setTeacherName(string teacherName){
	this->teacherName = teacherName;
}

void Course::setMaxStudent(int maxStudent){
	this->maxStudent = maxStudent;
}

void Course::printInfo(bool type)const{
	cout << "****************************************" << endl;
	cout << "* Course name:	" << left <<setw(23) << name << "*" << endl;
	cout << "* Teacher:  " << left << setw(27) << teacherName << "*" << endl;
	cout << "* Students condition:" << right << setw(3) << studentList.size() << "/" << left <<setw(3) << maxStudent << "           *" <<endl;
	if(type && studentList.size() != 0){
		cout << "****************************************" << endl;
		cout << "* Student list:                        *" << endl;
		for(int i = 0; i < studentList.size() ; i++){
			if(i % 3 == 0){
				cout << "* ";
			}
			cout << left << setw(12) << studentList[i];
			if(i % 3 == 2){
				cout << " *" << endl;
			}
		}
		if(studentList.size() % 3 != 0){
			int extra = 3 - studentList.size();
			cout << string(extra * 12, ' ');
			cout << " *" << endl;
		}
	}
	cout << "****************************************" << endl;
}
