#include "System.h"
#include <fstream>

using namespace std;

void System::menu(){
  loadData();
  printMenu();
  int option;
  bool save = false;
  cin >> option;
  while(option != 6){
    switch (option){
      case 1:
        teacherLogin();
        save = false;
        break;
      case 2:
        teacherSignup();
        save = false;
        break;
      case 3:
        studentLogin();
        save = false;
        break;
      case 4:
        studentSignup();
        save = false;
        break;
      case 5:
        cout << "*Saving...       ";
        saveData();
        cout << "Saved Successfully!!! *" << endl;
        save = true;
        break;
      default:
        cout << "#Please enter a number between 0 ~ 9!!!#" << endl;
        break;
    }
    printMenu();
    cin >> option;
  }
  if(!save){
    cout << "#Exit without saving modified data?    #" << endl;
    cout << "#Enter Y/y to exit , N/n to save data. #" << endl;
    char opt;
    while(getchar() != '\n');
    cin >> opt;
    while(getchar() != '\n');
    switch (opt){
      case 'y':
      case 'Y':
        cout << "#Exit without saving!!!                #" << endl;
        break;
      case 'n':
      case 'N':
        cout << "#Saving...       ";
        saveData();
        cout << "Saved Successfully!!!#" << endl;
        break;
      default:
        cout << "#You entered an invalid character!     #" << endl;
        cout << "#Default option(save) will be excuted  #" << endl;
        cout << "#Saving...       ";
        saveData();
        cout << "Saved Successfully!!! #" << endl;
        break;
    }
  }
  cout << "#Thank you for your using,good-bye :-) #" << endl;
  cout << "#    --designed by Wu Chenkang-16337247#" << endl;
}

void System::printMenu(){
  cout << "****************************************" << endl;
  cout << "*Welcome to the Course selection system*" << endl;
  cout << "****************************************" << endl;
  cout << "* 1)Teacher log in   2)Teacher sign up *" << endl;
  cout << "* 3)Student log in   4)Student sign up *" << endl;
  cout << "* 5)Save data        6)Exit            *" << endl;
  cout << "****************************************" << endl;
}

void System::teacherLogin(){
  cout << "*            Teacher Log in            *" << endl;
  cout << "*        Please enter your name        *" << endl;
  string teacherName;
 	cin >> teacherName;
  int teacherIndex = findTeacherIndex(teacherName);
  if(teacherIndex == -1){
    cout << "# Log in fail, no such teacher called  #" << endl;
    cout << left << "#" << setw(38) << teacherName << "#" << endl;
    cout << "# Return to Main menu..........        #" << endl;
  }else{
  	int option;
		string courseName;
		int maxStudent;
    do{
			teacherGroup[teacherIndex].getOption(option,courseName,maxStudent);
			switch (option){
				case 1:
					{
					if(openCourse(courseName,teacherGroup[teacherIndex],maxStudent)){
						cout << "* Course open successfully             *" << endl;
					}else{
						cout << "# Course already exists, open failed...#" << endl;
					}
					break;
					}
				case 2:
					{
					int cancleResult = cancleCourse(courseName,teacherGroup[teacherIndex]);
					if(cancleResult == 1){
						cout << "* Course cancle successfully           *" << endl;
					}else if(cancleResult == 0){
						cout << "# Not your course, cancle denied...    #" << endl;
					}else{
						cout << "# Course not found, cancle failed...   #" << endl;
					}
					break;
					}
				case 3:
					{
					if(courseName == "All"){
						for(int i = 0; i < teacherGroup[teacherIndex].courseList.size(); i++){
							int courseIndex = findCourseIndex(teacherGroup[teacherIndex].courseList[i]);
							courseGroup[courseIndex].printInfo(true);
						}
					}else{
						int courseIndex = findCourseIndex(courseName);
						if(courseIndex != -1){
							int inList = teacherGroup[teacherIndex].findCourseIndex(courseName);
							if(inList != -1){
								courseGroup[courseIndex].printInfo(true);
							}else{
								cout << "# The course is not in your courseList #" << endl;
								cout << "# Only part of its info will be shown  #" << endl;
								courseGroup[courseIndex].printInfo(false);
							}
						}else{
							cout << "# Course not found...                  #" << endl;
							cout << "# Check if you enter the wrong name    #" << endl;
						}
					}
					break;
					}
				default:
					break;
			}
    }while(option != 4);
    cout << "* Log out successfully!!!              *" << endl;
  }
}

void System::teacherSignup(){
  cout << "*           Teacher Sign up            *" << endl;
  cout << "*        Please enter your name        *" << endl;
  string name;
  cin >> name;
  if(findTeacherIndex(name) != -1){
    cout << "# Such teacher already exists!!!       #" << endl;
    cout << "# Sign up fail, return to main menu... #" << endl;
    return;
  }else{
  	Teacher newTeacher(name);
		teacherGroup.push_back(newTeacher);
		cout << "* Teacher sign up successfully         *" << endl;
		return;
  }
}

void System::studentLogin(){
  cout << "*            Student Log in            *" << endl;
  cout << "*        Please enter your name        *" << endl;
  string studentName;
 	cin >> studentName;
  int studentIndex = findStudentIndex(studentName);
  if(studentIndex == -1){
    cout << "# Log in fail, no such student called  #" << endl;
    cout << left << "#" << setw(38) << studentName << "#" << endl;
    cout << "# Return to Main menu..........        #" << endl;
  }else{
  	int option;
		string courseName;
    do{
			studentGroup[studentIndex].getOption(option,courseName);
			switch(option){
			case 1:
					{
					int chooseResult = chooseCourse(courseName,studentGroup[studentIndex]);
					if(chooseResult == 1){
						cout << "* Course choose successfully           *" << endl;
					}else if(chooseResult == 2){
						cout << "# You have chosen this course...       #" << endl;
						cout << "# Choose fail!!!                       #" << endl;
					}else if(chooseResult == 0){
						cout << "# The course is full, choose fail!!!   #" << endl;	
					}else{
						cout << "# No such course, choose fail!!!       #" << endl;
					}
					break;
					}
				case 2:
					{
					int quitResult = quitCourse(courseName,studentGroup[studentIndex]);
					if(quitResult == 1){
						cout << "* Course quit successfully             *" << endl;
					}else if(quitResult == 0){
						cout << "# You haven not chosen this course...  #" << endl;
						cout << "# Quit fail!!!                         #" << endl;
					}else{
						cout << "Nn such course, quit fail!!!           #" << endl;
					}
					break;
					}
				case 3:
					{
					if(courseName == "All"){
						for(int i = 0; i < studentGroup[studentIndex].courseList.size(); i++){
							courseName = studentGroup[studentIndex].courseList[i];
							int courseIndex = findCourseIndex(courseName);
							if(courseIndex == -1){
								studentGroup[studentIndex].courseList.erase(studentGroup[studentIndex].courseList.begin() + i);
								cout << "# The course \"" << left << setw(14) << courseName << "\" has been #" << endl << "# delete by the teacher                #"<< endl;
							}else{
								courseGroup[courseIndex].printInfo(false);
							}
						}
					}else{
						int studentCourseIndex = studentGroup[studentIndex].findCourseIndex(courseName);
						int courseIndex = findCourseIndex(courseName);
						if(courseIndex != -1){
							if(studentCourseIndex == -1){
								cout << "* You have not chosen this course      *" << endl;
							}else{
								cout << "* You have chosen this course          *" << endl;
							}
							courseGroup[courseIndex].printInfo(false);
						}else{
							if(studentCourseIndex != -1){
								studentGroup[studentIndex].courseList.erase(studentGroup[studentIndex].courseList.begin() + studentCourseIndex);
								cout << "# The course \"" << left << setw(14) << courseName << "\" has been #" << endl << "# delete by the teacher                #"<< endl;
							}else{
								cout << "# Course not found...                  #" << endl;
								cout << "# Check if you enter the wrong name    #" << endl;
							}
						}
					}
					break;
					}
				default:
					break;
			}
    }while(option != 4);
    cout << "* Log out successfully!!!              *" << endl;
  }
}

void System::studentSignup(){
  cout << "*           Student Sign up            *" << endl;
  cout << "*        Please enter your name        *" << endl;
  string name;
  cin >> name;
  if(findTeacherIndex(name) != -1){
    cout << "# Such student already exists!!!       #" << endl;
    cout << "# Sign up fail, return to main menu... #" << endl;
    return;
  }else{
  	Student newStudent(name);
		studentGroup.push_back(newStudent);
		cout << "* Student sign up successfully         *" << endl;
		return;
  }
}

bool System::openCourse(string courseName, Teacher& teacher, int maxStudent){
	if(findCourseIndex(courseName) == -1){
		Course newCourse(courseName, teacher.getName(),maxStudent);
		courseGroup.push_back(newCourse);
		teacher.courseList.push_back(courseName);
		return true;
	}else{
		return false;
	}	
}

int System::cancleCourse(string courseName, Teacher& teacher){
	int courseIndex = findCourseIndex(courseName);
	if(courseIndex == -1){
		return -1;
	}else{ 
		int teacherCourseIndex = teacher.findCourseIndex(courseName);
		if(teacherCourseIndex != -1){
			courseGroup.erase(courseGroup.begin()+courseIndex);
			teacher.courseList.erase(teacher.courseList.begin()+teacherCourseIndex);
			return 1;
		}else{
			return 0;
		}
	}
	
}

int System::chooseCourse(string courseName,Student& student){
	if(student.findCourseIndex(courseName) != -1){
		return 2;
	}else{ 
		int courseIndex = findCourseIndex(courseName);
		if(courseIndex != -1){
			if(courseGroup[courseIndex].studentList.size() != courseGroup[courseIndex].getMaxStudent()){
				courseGroup[courseIndex].studentList.push_back(student.getName());
				student.courseList.push_back(courseName);
				return 1;
			}else{
				return 0;
			}
		}else{
			return -1;
		}
	}
}

int System::quitCourse(string courseName,Student& student){
	int courseIndex = findCourseIndex(courseName);
	if(courseIndex == -1){
		return -1;
	}else{
		int studentCourseIndex = student.findCourseIndex(courseName);
		if(studentCourseIndex == -1){
			return 0;
		}else{
			courseGroup[courseIndex].studentList.erase(courseGroup[courseIndex].studentList.begin() + courseGroup[courseIndex].findStudentIndex(student.getName()));
			student.courseList.erase(student.courseList.begin() + studentCourseIndex);
			return 1;
		}
	}
}
int System::findTeacherIndex(string teacherName){
  for(int i = 0; i < teacherGroup.size(); i++){
    if(teacherName == teacherGroup[i].getName()){
      return i;
    }
  }
  return -1;
}

int System::findStudentIndex(string studentName){
	for(int i = 0; i < studentGroup.size(); i++){
    if(studentName == studentGroup[i].getName()){
      return i;
    }
  }
  return -1;
}

int System::findCourseIndex(string courseName){
	for(int i = 0; i < courseGroup.size(); i++){
    if(courseName == courseGroup[i].getName()){
      return i;
    }
  }
  return -1;
}

bool System::saveData(){
	ofstream file;
	file.open("data.txt");
	file << teacherGroup.size() << endl;
	for(int i = 0; i < teacherGroup.size(); i++){
		file << teacherGroup[i].name << endl;
		file << teacherGroup[i].courseList.size() << endl;
		for(int j = 0; j < teacherGroup[i].courseList.size(); j++){
			file << teacherGroup[i].courseList[j] << endl;
		}
	}
	file << studentGroup.size() << endl;
	for(int i = 0; i < studentGroup.size(); i++){
		file << studentGroup[i].name << endl;
		file << studentGroup[i].courseList.size() << endl;
		for(int j = 0; j < studentGroup[i].courseList.size(); j++){
			file << studentGroup[i].courseList[j] << endl;
		}
	}
	file << courseGroup.size() << endl;
	for(int i = 0; i < courseGroup.size(); i++){
		file << courseGroup[i].name << endl;
		file << courseGroup[i].teacherName << endl;
		file << courseGroup[i].maxStudent << endl;
		file << courseGroup[i].studentList.size() << endl;
		for(int j = 0; j < courseGroup[i].studentList.size(); j++){
			file << courseGroup[i].studentList[j] << endl;
		}
	}
	file.close();
	return true;				
}
bool System::loadData(){
	ifstream file;
	file.open("data.txt");
	if(!file.tellg()){
		{
		int teacherNum;
		int courseNum;
		string teacherName;
		string courseName;
		file >> teacherNum;
		for(int i = 0; i < teacherNum; i++){
			file >> teacherName;
			Teacher newTeacher(teacherName);
			file >> courseNum;
			for(int j = 0; j < courseNum; j++){
				file >> courseName;
				newTeacher.courseList.push_back(courseName);
			}
			teacherGroup.push_back(newTeacher);
		}
		}
	
		{
		int studentNum;
		int courseNum;
		string studentName;
		string courseName;
		file >> studentNum;
		for(int i = 0; i < studentNum; i++){
			file >> studentName;
			Student newStudent(studentName);
			file >> courseNum;
			for(int j = 0; j < courseNum; j++){
				file >> courseName;
				newStudent.courseList.push_back(courseName);
			}
			studentGroup.push_back(newStudent);
		}
		}
	
		{
		int courseNum;
		int maxStudent;
		int studentNum;
		string courseName;
		string teacherName;
		string studentName;
		file >> courseNum;
		for(int i = 0; i < courseNum; i++){
			file >> courseName;
			file >> teacherName;
			file >> maxStudent;
			file >> studentNum;
			Course newCourse(courseName, teacherName, maxStudent);
			for(int j = 0; j < studentNum; j++){
				file >> studentName;
				newCourse.studentList.push_back(studentName);
			}
			courseGroup.push_back(newCourse);
		}
		}
	}	
	file.close();
	return true;
}
