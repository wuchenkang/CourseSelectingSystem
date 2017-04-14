#ifndef TEACHER_H
#define TEACHER_H

#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

class Teacher{
  friend class System;	//系统类作为教师的友元类，具有教师的访问和修改权限
public:
  Teacher(string name);	//教师类的构造函数
  
  //用于让系统获得教师发出的请求
  void getOption(int& option,string& CourseName, int& maxStudent);
  
  string getName()const;	//返回教师的姓名
private:
  string name;	//教师的姓名
  vector<string> courseList;	//教师开设的课程列表
  
  //服务函数，用于在教师开设的课程列表中以课程名寻找课程索引
  int findCourseIndex(string courseName);
  
  //设置教师的姓名
  void setName(string name);
};

#endif

