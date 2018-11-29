#pragma once
#include<iostream>
#include<iomanip>
#include<string>
using namespace std;
enum Status {
	��,��
};

ostream& operator << (ostream& out, Status status);

struct ActiveTime {
	int minute;
	int hour;
	ActiveTime():minute(0),hour(0){}
	ActiveTime(int hour, int minute):minute(minute), hour(hour){}
};

ostream& operator << (ostream& out, const ActiveTime AT);


class People {//�ṩ��Ա��������
private:
	string name;
	int CardID;
	Status status;//��or��
	ActiveTime AT;
	//ActiveTime LastEnterTime;
	//ActiveTime LastLeaveTime;
public:
	People(string name, int CardID) :name(name), CardID(CardID) {}
	People(string name, int CardID, int hour, int minute, Status status):name(name),CardID(CardID),AT(hour, minute),status(status){}
	const int getCardID();
	const string getName();
	const ActiveTime getActiveTime();
	const Status getStatus();
	void ShowInfo2();
	virtual void ShowInfo() = 0;

};
