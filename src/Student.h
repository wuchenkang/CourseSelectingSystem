#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

class Student{
  friend class System;	//系统类作为学生的友元类，具有学生的访问和修改权限
public:
  Student(string name);	//学生类的构造函数
  
  //用于让系统获得学生发出的请求
  void getOption(int& option,string& courseName);
  
  //返回学生的姓名
  string getName()const;
private:
  string name;	//学生的姓名
  vector<string> courseList;	//学生选择的课程列表
  
  //服务函数，用于在学生的选择的课程列表中以课程名寻找课程索引
  int findCourseIndex(string courseName);
  
  //设置学生的姓名
  bool setName(string name);
};

#endif
