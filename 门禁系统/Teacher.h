#pragma once
#include"People.h"
class Teacher :public People {//�̳���People���ṩ�����ʦ����չ����
private:
	int FaceID;
public:
	
	Teacher(string name, int FaceID, int CardID) :
		People(name, CardID),FaceID(FaceID) {}
	Teacher(string name, int FaceID, int CardID, int hour, int minute, Status status) :
		People(name, CardID, hour, minute, status), FaceID(FaceID){}
	const int getFaceID();
	void ShowInfo();
};