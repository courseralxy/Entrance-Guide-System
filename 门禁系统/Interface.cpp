
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
	cout << "��ǰĿ¼���" << surface << "\t��ESC��������һ��";
}
bool Interface::SecondConfirm()
{
	system("cls");
	int totalline = 3;
	line = 0;
	vector<string>output;
	string tmp = "ȷ��ɾ����";
	output.push_back(tmp);
	tmp.clear();

	tmp = "ȷ��";
	output.push_back(tmp);
	tmp.clear();

	tmp = "ȡ��";
	output.push_back(tmp);

	Output(&output, totalline);
	char ch;
	while (1) {
		if (_kbhit()) {
			ch = _getch();
			switch ((int)ch) {
				cout << (int)ch << endl;
			case 13://�س����������
				if (line == 1)return true;
				else if (line == 2)return false;
				break;
			case 72://�������
				line = (line - 1 + totalline) % totalline;

				Output(&output, totalline);
				break;
			case 80://�������
				line = (line + 1) % totalline;

				Output(&output, totalline);
				break;
				//case 39:�������
				//case 40://�������
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
	string tmp = "¼�롢ɾ�������ӡ���ա���ӡ��Чˢ��id";
	output.push_back(tmp);
	tmp.clear();

	tmp = "¼�롢ɾ�������ӡ���ա���ӡ��Ч����id";
	output.push_back(tmp);
	tmp.clear();

	tmp = "���롢��ӡ������Ա��Ϣ";
	output.push_back(tmp);
	tmp.clear();

	tmp = "��ʾģ����";
	output.push_back(tmp);

	Output(&output, totalline);
	

	
	char ch;
	while (1) {
		if (_kbhit()) {
			ch = _getch();
			switch ((int)ch){
				cout << (int)ch << endl;
			case 13://�س����������
				surface = line + surface * width + 1;
			
				ChooseSurface();
				line = 0;
				Output(&output, totalline);
				break;
			case 27://ESC
				//�����ļ�
				exit(0);
			case 72://�������
				line = (line - 1 + totalline) % totalline;
			
				Output(&output, totalline);
				break;
			case 80://�������
				line = (line + 1) % totalline;
			
				Output(&output, totalline);
				break;
			//case 39:�������
			//case 40://�������
			default:
				break;
			}

		}
	}
}

void Interface::Surface1()//¼�롢ɾ�������ӡ���ա���ӡ��Чˢ��id
{
	int totalline = 5;
	line = 0;
	vector<string>output;
	string tmp = "¼����Чˢ��id";
	output.push_back(tmp);
	tmp.clear();

	tmp = "ɾ����Чˢ��id";
	output.push_back(tmp);
	tmp.clear();

	tmp = "������Чˢ��id";
	output.push_back(tmp);
	tmp.clear();

	tmp = "�����Чˢ��id";
	output.push_back(tmp);
	tmp.clear();

	tmp = "��ӡ��Чˢ��id";
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
					//�����ļ�
				surface = surface / width;
				return;
			case 72://�������
				line = (line - 1 + totalline) % totalline;
				Output(&output, totalline);
				break;
			case 80://�������
				line = (line + 1) % totalline;
				Output(&output, totalline);
				break;

				//case 39:�������
				//case 40://�������
			default:
				break;
			}

		}
	}
}
void Interface::Surface2()//¼�롢ɾ�������ӡ���ա���ӡ��Ч����id
{
	int totalline = 5;
	line = 0;
	vector<string>output;
	string tmp = "¼����Ч����id";
	output.push_back(tmp);
	tmp.clear();

	tmp = "ɾ����Ч����id";
	output.push_back(tmp);
	tmp.clear();

	tmp = "������Ч����id";
	output.push_back(tmp);
	tmp.clear();

	tmp = "�����Ч����id";
	output.push_back(tmp);
	tmp.clear();

	tmp = "��ӡ��Ч����id";
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
					//�����ļ�
				surface = surface / width;
				return;
			case 72://�������
				line = (line - 1 + totalline)% totalline;
				Output(&output, totalline);
				break;
			case 80://�������
				line = (line + 1) % totalline;
				Output(&output, totalline);
				break;
				//case 39:�������
				//case 40://�������
			default:
				break;
			}

		}
	}
}
void Interface::Surface3()//���롢��ӡ������Ա��Ϣ
{
	int totalline = 2;
	line = 0;
	vector<string>output;
	string tmp = "���������Ա��Ϣ";
	output.push_back(tmp);
	tmp.clear();

	tmp = "��ӡ������Ա��Ϣ";
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
					//�����ļ�
				surface = surface / width;
				return;
			case 72://�������
				line = (line - 1 + totalline) % totalline;
				Output(&output, totalline);
				break;
			case 80://�������
				line = (line + 1) % totalline;
				Output(&output, totalline);
				break;
				//case 39:�������
				//case 40://�������
			default:
				break;
			}

		}
	}




}
void Interface::Surface4()//��ʾģ����
{
	int totalline = 1;

	line = 0;
	vector<string>output;
	string tmp = "��ʾģ����";
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
					//�����ļ�
				surface = surface / width;
				return;
			case 72://�������
				line = (line - 1 + totalline) % totalline;
				Output(&output, totalline);
				break;
			case 80://�������
				line = (line + 1) % totalline;
				Output(&output, totalline);

				//case 39:�������
				//case 40://�������
			default:
				break;
			}

		}
	}
}


void Interface::Surface6()//¼����Чˢ��id
{
	system("cls");
	string str;
	cin >> str;
	GateSystem.InputCardID(str);
	surface = surface / width;

}
void Interface::Surface7()//ɾ����Чˢ��id
{
	system("cls");
	string str;
	cin >> str;
	if(SecondConfirm())
	GateSystem.DeleteCardID(str);
	surface = surface / width;
}
void Interface::Surface8()//������Чˢ��id
{
	Surface6();
}
void Interface::Surface9()//�����Чˢ��id
{
	system("cls");
	if(SecondConfirm())
	GateSystem.CardIDClear();
	surface = surface / width;
}
void Interface::Surface10()//��ӡ��Чˢ��id
{
	system("cls");
	GateSystem.ShowCardID();
	surface = surface / width - 1;//ע�⣡�������е�SurfaceX�У�����Ӧ��ʹ������ȡ����һ���˴���
	system("pause");
}
void Interface::Surface11()//¼����Ч����id
{
	system("cls");
	string str;
	cin >> str;
	GateSystem.InputFaceID(str);
	surface = surface / width;
}
void Interface::Surface12()//ɾ����Ч����id
{
	system("cls");
	string str;
	cin >> str;
	//cout << "ȷ��ɾ����";
	if(SecondConfirm())
	GateSystem.DeleteFaceID(str);
	surface = surface / width;

}
void Interface::Surface13()//������Ч����id
{
	Surface11();
}
void Interface::Surface14()//�����Ч����id
{
	system("cls");
	if(SecondConfirm())
	GateSystem.FaceIDCleer();
	surface = surface / width;
}
void Interface::Surface15()//��ӡ��Ч����id
{
	system("cls");
	GateSystem.ShowFaceID();
	surface = surface / width - 1;
	system("pause");
}
void Interface::Surface16()//���������Ա��Ϣ
{
	system("cls");
	cout << "��ʽ����" << endl << "A��ѧ��������1��8:00����" << endl << "B����ʦ������1������2��9:00����" << endl << "ע�⣡�������Ķ�����Ӣ�Ķ��Ż��ã�" << endl <<"ʱ��Сʱ�����֮�����ʹ��Ӣ��ð�ţ�" << endl;
	string str;
	cin >> str;
	//while (cin >> str) {
		GateSystem.InputInfo(str);
	//}
		surface = surface / width;
}
void Interface::Surface17()//��ӡ������Ա��Ϣ
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
void Interface::Surface21()//��ʾģ����
{
	system("cls");
	
	GateSystem.ShowSimulator();
	surface = surface / width;
	system("pause");
}