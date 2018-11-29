#pragma once
#include"People.h"
class Student :public People {
public:
	Student(string name, int ID) :People(name, ID) {}
	Student(string name, int CardID, int hour, int minute, Status status):
		People(name, CardID, hour, minute, status){}
	void ShowInfo();
	//提供面向学生的扩展功能
	//目前暂无扩展内容
};