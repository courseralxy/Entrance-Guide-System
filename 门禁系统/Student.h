#pragma once
#include"People.h"
class Student :public People {
public:
	Student(string name, int ID) :People(name, ID) {}
	Student(string name, int CardID, int hour, int minute, Status status):
		People(name, CardID, hour, minute, status){}
	void ShowInfo();
	//�ṩ����ѧ������չ����
	//Ŀǰ������չ����
};