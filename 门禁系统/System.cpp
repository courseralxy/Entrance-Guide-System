
#pragma once
#include"System.h"

int System::FindID(vector<int>*IDs, int value)//遍历查找，仍有改进空间
{
	for (size_t i = 0; i < IDs->size(); i++) {
		if ((*IDs)[i] == value)
			return i;
	}
	return -1;
}
vector<string>SplitByStr(string str, string split)
{
	vector<string>result;
	char* strch = new char[str.size() + 1];
	strcpy(strch, str.c_str());
	result.clear();
	char* temp = strtok(strch, split.c_str());
	while (temp) {
		string vs = temp;
		result.push_back(vs);
		temp = strtok(NULL, split.c_str());
	}
	return result;
}

/*
vector<string>SplitByChar(string str, char ch)//以ch为分隔符分割str 
{
	vector<string>result;
	result.clear();
	istringstream iss(str);
	string temp;
	temp.clear();
	while (getline(iss, temp, ch)) {
		
		result.push_back(temp);
		temp.clear();
	}
	return result;
}
*/
bool System::InputID(vector<int>*ID, string str) 
{
	vector<string>IDs = SplitByStr(str, ",");//为了防止用户把','写成'，'。目前仅实现了全为'，'的兼容，仍需实现同时有','和'，'
	vector<string>IDs2 = SplitByStr(str, "，");
	if (IDs2.size() > IDs.size())IDs = IDs2;
	for (size_t i = 0; i < IDs.size(); i++) {
		int temp = atoi(IDs[i].c_str());
		if (FindID(ID, temp)==-1)
			ID->push_back(temp);
	}
	return true;
}

bool System::InputFaceID(string str)
{
	return InputID(&FaceID, str);
	/*
	vector<string>FaceIDs = SplitByChar(str, ',');//为了防止用户把','写成'，'。目前仅实现了全为'，'的兼容，仍需实现同时有','和'，'
	vector<string>FaceIDs2 = SplitByChar(str, '，');
	if (FaceIDs2.size() > FaceIDs.size())FaceIDs = FaceIDs2;
	for (int i = 0; i < FaceIDs.size(); i++) {
		int temp = atoi(FaceIDs[i].c_str());
		if(!FindID(&FaceID, temp))FaceID.push_back(atoi(FaceIDs[i].c_str()));
	}
	return true;
	*/
}
bool System::InputCardID(string str)
{
	return InputID(&CardID, str);
	/*
	vector<string>CardIDs = SplitByChar(str, ',');//为了防止用户把','写成'，'。目前仅实现了全为'，'的兼容，仍需实现同时有','和'，'
	vector<string>CardIDs2 = SplitByChar(str, '，');
	if (CardIDs2.size() > CardIDs.size())CardIDs = CardIDs2;
	for (int i = 0; i < CardIDs.size(); i++) {
		int temp = atoi(CardIDs[i].c_str());
		if (!FindID(&CardID, temp))FaceID.push_back(atoi(CardIDs[i].c_str()));
	}
	return true;
	*/
}
bool System::InputInfo(string str)
{
	vector<string>InputPeople = SplitByStr(str, "，");
	vector<string>InputPeople2 = SplitByStr(str, ",");
	if (InputPeople2.size() > InputPeople.size())InputPeople = InputPeople2;
	if (InputPeople[InputPeople.size() - 1] == "进") {
		Enter(str);
	}
	else if(InputPeople[InputPeople.size() - 1] == "出") {
		Leave(str);
	}
	return true;
}

bool System::AddCardID(string str)
{
	return InputCardID(str);
}
bool System::AddFaceID(string str)
{
	return InputFaceID(str);
}
bool System::DeleteID(vector<int>*ID, string str)
{
	vector<string>IDs = SplitByStr(str, ",");//为了防止用户把','写成'，'。目前仅实现了全为'，'的兼容，仍需实现同时有','和'，'
	vector<string>IDs2 = SplitByStr(str, "，");
	if (IDs2.size() > IDs.size())IDs = IDs2;
	for (size_t i = 0; i < IDs.size(); i++) {
		int temp = atoi(IDs[i].c_str());
		int index = FindID(ID, temp);
		if (index!=-1)ID->erase(ID->begin() + i);
	}
	return true;
}
bool System::DeleteCardID(string str)
{
	return DeleteID(&CardID, str);
}
bool System::DeleteFaceID(string str)
{
	return DeleteID(&FaceID, str);
}
bool System::CardIDClear()
{
	CardID.clear();
	return true;
}
bool System::FaceIDCleer()
{
	FaceID.clear();
	return true;
}

//Status System::InputStatus(string str){	}
bool System::Enter(string str) {//输入必须用
	vector<string>EnterPeople = SplitByStr(str, ",");//为了防止用户把','写成'，'。目前仅实现了全为'，'的兼容，仍需实现同时有','和'，'
	vector<string>EnterPeople2 = SplitByStr(str, "，");
	if (EnterPeople2.size() > EnterPeople.size())EnterPeople = EnterPeople2;
	if (EnterPeople.size() == 5) {
		//Student* stu = new Student(EnterPeople[0], atoi(EnterPeople[2].substr(4).c_str()));
		Student* stu = new Student(EnterPeople[0], atoi(EnterPeople[2].substr(4).c_str()),  (int)EnterPeople[3][0] - '0', atoi(EnterPeople[3].substr(2).c_str()), EnterPeople[4] == "进" ? 进 : 出);
		PeopleHere.push_back(stu);
		return true; //StudentEnter(stu);
	}
	else if (EnterPeople.size() == 6) {
		//Teacher(string name, int CardID, int FaceID, int hour, int minute, Status status)
		Teacher* tea = new Teacher(EnterPeople[0], atoi(EnterPeople[2].substr(4).c_str()), atoi(EnterPeople[3].substr(4).c_str()), (int)EnterPeople[4][0] - '0', atoi(EnterPeople[4].substr(2).c_str()), EnterPeople[5]=="进"?进:出);
		PeopleHere.push_back(tea);
		return true;// TeacherEnter(tea);

	}
	return false;
}

bool System::TeacherEnter(Teacher* teacher)
{
	/*
	if (!FindPeople(teacher->getName())) {
		PeopleHere.push_back(teacher);
	}
	*/
	if (FindID(&FaceID, teacher->getFaceID())!=-1) {
		cout << "老师" << teacher->getName() << "，有效人脸识别，" << teacher->getActiveTime() << "，" << teacher->getStatus() << endl;
		return true;
	}
	else if (FindID(&CardID, teacher->getCardID())!=-1) {
		cout << "老师" << teacher->getName() << "，无效人脸识别，有效刷卡，" << teacher->getActiveTime() << "，" << teacher->getStatus() << endl;
		return true;
	}
	else {
		cout << "老师" << teacher->getName() << "，无效人脸识别，无效刷卡，" << teacher->getActiveTime() << "，未" << teacher->getStatus() << endl;
		return false;
	}
}
bool System::StudentEnter(Student* student)
{
	if (FindID(&CardID, student->getCardID())!=-1) {
		cout << "学生" << student->getName() << "，有效刷卡，" << student->getActiveTime() << "，" << student->getStatus()<<endl;
		return true;
	}
	else {
		cout << "学生" << student->getName() << "，无效刷卡，" << student->getActiveTime() << "，未" << student->getStatus() << endl;;
		return false;
	}
}

bool System::Leave(string str)
{
	vector<string>LeavePeople = SplitByStr(str, ",");//为了防止用户把','写成'，'。目前仅实现了全为'，'的兼容，仍需实现同时有','和'，'
	vector<string>LeavePeople2 = SplitByStr(str, "，");
	if (LeavePeople2.size() > LeavePeople.size())LeavePeople = LeavePeople2;
	if (LeavePeople.size() == 5) {
		//Student* stu = new Student(LeavePeople[0], atoi(LeavePeople[2].substr(4).c_str()));
		Student* stu = new Student(LeavePeople[0], atoi(LeavePeople[2].substr(4).c_str()), (int)LeavePeople[3][0] - '0', atoi(LeavePeople[3].substr(2).c_str()), LeavePeople[4] == "进" ? 进 : 出);
		PeopleHere.push_back(stu);
		return StudentEnter(stu);
	}
	else if (LeavePeople.size() == 6) {
		//Teacher* tea = new Teacher(LeavePeople[0], atoi(LeavePeople[2].substr(4).c_str()), atoi(LeavePeople[3].substr(4).c_str()));
		Teacher* tea = new Teacher(LeavePeople[0], atoi(LeavePeople[2].substr(4).c_str()), atoi(LeavePeople[3].substr(4).c_str()), (int)LeavePeople[4][0] - '0', atoi(LeavePeople[4].substr(2).c_str()), LeavePeople[5] == "进" ? 进 : 出);

		PeopleHere.push_back(tea);
		return TeacherEnter(tea);
	}
	return false;
}

void System::ShowID(vector<int>*ID)
{
	if (ID->size() == 0)return;
	for (int i = 0; i < ID->size() - 1; i++)
		cout << (*ID)[i] << "，";
	cout << (*ID)[ID->size() - 1] << endl;
}
void System::ShowCardID()
{
	ShowID(&CardID);
}
void System::ShowFaceID()
{
	ShowID(&FaceID);
}
void System::ShowPeopleHere()
{
	for (size_t i = 0; i < PeopleHere.size(); i++) {
		PeopleHere[i]->ShowInfo();
	}
}

bool func(People*p1, People*p2)
{
	return p1 < p2;
}

void System::ShowSimulator()
{
	sort(PeopleHere.begin(), PeopleHere.end(), func);
	for (int i = 0; i < PeopleHere.size(); i++) {
		//cout << typeid(*PeopleHere[i]).name();
		//if (typeid(*PeopleHere[i]).name() == typeid(Student).name())cout << 1111 << endl;
		if (typeid(*PeopleHere[i]).name() == typeid(Teacher).name()) {//RTTI
			//cout << "teacher" << endl;
			TeacherEnter((Teacher*)PeopleHere[i]);
		}
		else if (typeid(*PeopleHere[i]).name() == typeid(Student).name()) {
			StudentEnter((Student*)PeopleHere[i]);
		}
	}
}