
#include"Interface.h"


void Interface::ChooseSurface()
{
	switch (surface) {
	case 1:Surface1();break;
	case 2:Surface2();break;
	case 3:Surface3();break;
	case 4:Surface4();break;
	case 6:Surface6();break;
	case 7:Surface7();break;
	case 8:Surface8();break;
	case 9:Surface9();break;
	case 10:Surface10();break;
	case 11:Surface11();break;
	case 12:Surface12();break;
	case 13:Surface13();break;
	case 14:Surface14();break;
	case 15:Surface15();break;
	case 16:Surface16();break;
	case 17:Surface17();break;
	case 21:Surface21(); break;
	default:;
	}
}

void Interface::Output(vector<string>*output, int totalline)
{
	system("cls");
	for (size_t i = 0; i < output->size(); i++) {
		if (i == line) {
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_INTENSITY
				| FOREGROUND_INTENSITY | BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE);
			cout << (*output)[i] << endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY
				| FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
		}
		else
			cout << (*output)[i] << endl;
	}
	for (int i = totalline; i < 29; i++)cout << endl;
	cout << "当前目录编号" << surface << "\t按ESC键返回上一层";
}
bool Interface::SecondConfirm()
{
	system("cls");
	int totalline = 3;
	line = 0;
	vector<string>output;
	string tmp = "确认删除？";
	output.push_back(tmp);
	tmp.clear();

	tmp = "确认";
	output.push_back(tmp);
	tmp.clear();

	tmp = "取消";
	output.push_back(tmp);

	Output(&output, totalline);
	char ch;
	while (1) {
		if (_kbhit()) {
			ch = _getch();
			switch ((int)ch) {
				cout << (int)ch << endl;
			case 13://回车，进入界面
				if (line == 1)return true;
				else if (line == 2)return false;
				break;
			case 72://方向键上
				line = (line - 1 + totalline) % totalline;

				Output(&output, totalline);
				break;
			case 80://方向键下
				line = (line + 1) % totalline;

				Output(&output, totalline);
				break;
				//case 39:方向键左
				//case 40://方向键右
			default:
				break;
			}

		}
	}
}
void Interface::Surface0()
{
	int totalline = 4;
	line = 0;
	vector<string>output;
	string tmp = "录入、删除、增加、清空、打印有效刷卡id";
	output.push_back(tmp);
	tmp.clear();

	tmp = "录入、删除、增加、清空、打印有效人脸id";
	output.push_back(tmp);
	tmp.clear();

	tmp = "输入、打印进出人员信息";
	output.push_back(tmp);
	tmp.clear();

	tmp = "显示模拟结果";
	output.push_back(tmp);

	Output(&output, totalline);
	

	
	char ch;
	while (1) {
		if (_kbhit()) {
			ch = _getch();
			switch ((int)ch){
				cout << (int)ch << endl;
			case 13://回车，进入界面
				surface = line + surface * width + 1;
			
				ChooseSurface();
				line = 0;
				Output(&output, totalline);
				break;
			case 27://ESC
				//保存文件
				exit(0);
			case 72://方向键上
				line = (line - 1 + totalline) % totalline;
			
				Output(&output, totalline);
				break;
			case 80://方向键下
				line = (line + 1) % totalline;
			
				Output(&output, totalline);
				break;
			//case 39:方向键左
			//case 40://方向键右
			default:
				break;
			}

		}
	}
}

void Interface::Surface1()//录入、删除、增加、清空、打印有效刷卡id
{
	int totalline = 5;
	line = 0;
	vector<string>output;
	string tmp = "录入有效刷卡id";
	output.push_back(tmp);
	tmp.clear();

	tmp = "删除有效刷卡id";
	output.push_back(tmp);
	tmp.clear();

	tmp = "增加有效刷卡id";
	output.push_back(tmp);
	tmp.clear();

	tmp = "清空有效刷卡id";
	output.push_back(tmp);
	tmp.clear();

	tmp = "打印有效刷卡id";
	output.push_back(tmp);


	Output(&output, totalline);



	
	char ch;
	while (1) {
		if (_kbhit()) {
			ch = _getch();
			switch ((int)ch)
			{
			case 13:
				surface = line + surface * width + 1;
				ChooseSurface();
				line = 0;
				Output(&output, totalline);
				break;
			case 27://ESC
					//保存文件
				surface = surface / width;
				return;
			case 72://方向键上
				line = (line - 1 + totalline) % totalline;
				Output(&output, totalline);
				break;
			case 80://方向键下
				line = (line + 1) % totalline;
				Output(&output, totalline);
				break;

				//case 39:方向键左
				//case 40://方向键右
			default:
				break;
			}

		}
	}
}
void Interface::Surface2()//录入、删除、增加、清空、打印有效人脸id
{
	int totalline = 5;
	line = 0;
	vector<string>output;
	string tmp = "录入有效人脸id";
	output.push_back(tmp);
	tmp.clear();

	tmp = "删除有效人脸id";
	output.push_back(tmp);
	tmp.clear();

	tmp = "增加有效人脸id";
	output.push_back(tmp);
	tmp.clear();

	tmp = "清空有效人脸id";
	output.push_back(tmp);
	tmp.clear();

	tmp = "打印有效人脸id";
	output.push_back(tmp);


	Output(&output, totalline);



	char ch;
	while (1) {
		if (_kbhit()) {
			ch = _getch();
			switch ((int)ch)
			{
			case 13:
				surface = line + surface * width + 1;
				ChooseSurface();
				line = 0;
				Output(&output, totalline);
				break;
			case 27://ESC
					//保存文件
				surface = surface / width;
				return;
			case 72://方向键上
				line = (line - 1 + totalline)% totalline;
				Output(&output, totalline);
				break;
			case 80://方向键下
				line = (line + 1) % totalline;
				Output(&output, totalline);
				break;
				//case 39:方向键左
				//case 40://方向键右
			default:
				break;
			}

		}
	}
}
void Interface::Surface3()//输入、打印进出人员信息
{
	int totalline = 2;
	line = 0;
	vector<string>output;
	string tmp = "输入进出人员信息";
	output.push_back(tmp);
	tmp.clear();

	tmp = "打印进出人员信息";
	output.push_back(tmp);
	

	Output(&output, totalline);



	char ch;
	while (1) {
		if (_kbhit()) {
			ch = _getch();
			switch ((int)ch)
			{
			case 13:
				surface = line + surface * width + 1;
				ChooseSurface();
				line = 0;
				Output(&output, totalline);
				break;
			case 27://ESC
					//保存文件
				surface = surface / width;
				return;
			case 72://方向键上
				line = (line - 1 + totalline) % totalline;
				Output(&output, totalline);
				break;
			case 80://方向键下
				line = (line + 1) % totalline;
				Output(&output, totalline);
				break;
				//case 39:方向键左
				//case 40://方向键右
			default:
				break;
			}

		}
	}




}
void Interface::Surface4()//显示模拟结果
{
	int totalline = 1;

	line = 0;
	vector<string>output;
	string tmp = "显示模拟结果";
	output.push_back(tmp);


	Output(&output, totalline);



	char ch;
	while (1) {
		if (_kbhit()) {
			ch = _getch();
			switch ((int)ch)
			{
			case 13:
				surface = line + surface * width + 1;
				ChooseSurface();
				line = 0;
				Output(&output, totalline);
				break;
			case 27://ESC
					//保存文件
				surface = surface / width;
				return;
			case 72://方向键上
				line = (line - 1 + totalline) % totalline;
				Output(&output, totalline);
				break;
			case 80://方向键下
				line = (line + 1) % totalline;
				Output(&output, totalline);

				//case 39:方向键左
				//case 40://方向键右
			default:
				break;
			}

		}
	}
}


void Interface::Surface6()//录入有效刷卡id
{
	system("cls");
	string str;
	cin >> str;
	GateSystem.InputCardID(str);
	surface = surface / width;

}
void Interface::Surface7()//删除有效刷卡id
{
	system("cls");
	string str;
	cin >> str;
	if(SecondConfirm())
	GateSystem.DeleteCardID(str);
	surface = surface / width;
}
void Interface::Surface8()//增加有效刷卡id
{
	Surface6();
}
void Interface::Surface9()//清空有效刷卡id
{
	system("cls");
	if(SecondConfirm())
	GateSystem.CardIDClear();
	surface = surface / width;
}
void Interface::Surface10()//打印有效刷卡id
{
	system("cls");
	GateSystem.ShowCardID();
	surface = surface / width - 1;//注意！！在所有的SurfaceX中，这里应该使用向上取整减一，此处简化
	system("pause");
}
void Interface::Surface11()//录入有效人脸id
{
	system("cls");
	string str;
	cin >> str;
	GateSystem.InputFaceID(str);
	surface = surface / width;
}
void Interface::Surface12()//删除有效人脸id
{
	system("cls");
	string str;
	cin >> str;
	//cout << "确认删除？";
	if(SecondConfirm())
	GateSystem.DeleteFaceID(str);
	surface = surface / width;

}
void Interface::Surface13()//增加有效人脸id
{
	Surface11();
}
void Interface::Surface14()//清空有效人脸id
{
	system("cls");
	if(SecondConfirm())
	GateSystem.FaceIDCleer();
	surface = surface / width;
}
void Interface::Surface15()//打印有效人脸id
{
	system("cls");
	GateSystem.ShowFaceID();
	surface = surface / width - 1;
	system("pause");
}
void Interface::Surface16()//输入进出人员信息
{
	system("cls");
	cout << "格式例：" << endl << "A，学生，卡号1，8:00，进" << endl << "B，老师，人脸1，卡号2，9:00，进" << endl << "注意！不能中文逗号与英文逗号混用！" << endl <<"时间小时与分钟之间必须使用英文冒号！" << endl;
	string str;
	cin >> str;
	//while (cin >> str) {
		GateSystem.InputInfo(str);
	//}
		surface = surface / width;
}
void Interface::Surface17()//打印进出人员信息
{
	system("cls");
	GateSystem.ShowPeopleHere();
	surface = surface / width;
	system("pause");
}
void Surface18()//
{

}
void Surface19()//
{

}
void Surface20()//
{

}
void Interface::Surface21()//显示模拟结果
{
	system("cls");
	
	GateSystem.ShowSimulator();
	surface = surface / width;
	system("pause");
}