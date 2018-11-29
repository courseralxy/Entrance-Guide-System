#pragma once
#include<vector>
#include<sstream>
#include<istream>
#include<string>
#include<typeinfo>
#include<algorithm>
using namespace std;
#include"People.h"
#include"Student.h"
#include"Teacher.h"
/*
template <class T>
class SystemLog {
private:
	T people;
public:
	SystemLog();
	SystemLog(string str);
};


template<class T>//???????????????????
*/
class System {
private:
	//vector<People*>
	vector<People*>PeopleHere;
	vector<int>FaceID;
	vector<int>CardID;

public:

	bool InputID(vector<int>*ID, string str);
	bool InputFaceID(string str);
	bool InputCardID(string str);
	bool InputInfo(string str);
	//Status InputStatus(string str);

	bool AddCardID(string str);
	bool AddFaceID(string str);
	bool DeleteID(vector<int>*ID, string str);
	bool DeleteCardID(string str);
	bool DeleteFaceID(string str);
	bool CardIDClear();
	bool FaceIDCleer();

	bool Enter(string str);
	bool TeacherEnter(Teacher* teacher);
	bool StudentEnter(Student* student);

	bool Leave(string str);
	
	void ShowID(vector<int>*ID);
	void ShowCardID();
	void ShowFaceID();
	void ShowPeopleHere();
	void ShowSimulator();

	//bool FindPeople(string name);
	int FindID(vector<int>*IDs, int value);
};