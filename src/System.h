#ifndef SYSTEM_H
#define SYSTEM_H

#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include "Student.h"
#include "Teacher.h"
#include "Course.h"

class System{
public:
  void menu();	//菜单函数，用于进行系统的菜单操作
private:
  vector<Student> studentGroup;	//系统中已注册的学生组
  vector<Teacher> teacherGroup;	//系统中已注册的教师组
  vector<Course> courseGroup;	//系统中已开设的课程组
  
  void teacherLogin();	//教师登录模块
  void teacherSignup();	//教师注册模块
  void studentLogin();	//学生登录模块
  void studentSignup();	//学生注册模块
  bool saveData();	//储存数据模块
  
  //系统开始运行时自动调用的服务，在数据文件存在的情况下将数据导入系统
  bool loadData();
  void printMenu();	//被菜单函数调用的服务，用于打印系统菜单
  
  //教师登录模块的开设课程子功能，用于教师开设课程
  bool openCourse(string courseName, Teacher& teacher, int maxStudent);
  //教师登录模块的取消课程子功能，用于教师取消课程
  int cancleCourse(string courseName, Teacher& teacher);
  
  //学生登录模块的选择课程子功能，用于学生选择课程
  int chooseCourse(string courseName,Student& student);
  //学生登录模块的退出课程子功能，用于学生退出课程
  int quitCourse(string courseName,Student& student);
  
  //辅助服务，用于在教师组中寻找教师索引
  int findTeacherIndex(string teacherName);
  //辅助服务，用于在学生组中寻找学生索引
  int findStudentIndex(string studentName);
  //辅助服务，用于在课程组中寻找课程索引
  int findCourseIndex(string courseName);
};


#endif
