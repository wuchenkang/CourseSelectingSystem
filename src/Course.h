#ifndef COURSE_H
#define COURSE_H

#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

class Course{
  friend class System;	//系统具有课程的访问和修改权限
public:
  //以课程名，教师名和课程容量初始化课程
  Course(string name,string teacherName,int maxStudent);
  
  //部分课程信息的get函数
  string getName()const;
  string getTeacherName()const;
  int getMaxStudent()const;
  
  //打印课程信息
  void printInfo(bool type)const;
private:
  string name;	//课程名
  string teacherName;	//教师名
  int maxStudent;	//课程容量
  vector<string> studentList;	//课程的学生花名册
  
  //服务函数，用于在课程的花名册中以名字寻找学生索引
  int findStudentIndex(string studentName);
  
  //部分课程信息的set函数
  void setName(string name);
  void setTeacherName(string teacherName);
  void setMaxStudent(int maxStudent);
};

#endif
