#pragma once
#include<iostream>
#include<conio.h>
#include<Windows.h>
#include<vector>
#include<string>
#include<sstream>
using namespace std;
#include"System.h"
class Interface {
private:
	
	int surface;
	int line;
	const int width;
	System GateSystem;

public:
	Interface():surface(0), line(0),width(5){}
	void ChooseSurface();
	void Surface0();//��ʼ����
	void Surface1();//����1
	void Surface2();//����2
	void Surface3();//����3
	void Surface4();//����4
	void Surface5();//����5
	void Output(vector<string>*output,int totalline);
	bool SecondConfirm();
	void Surface6();//¼����Чˢ��id
	void Surface7();//ɾ����Чˢ��id
	void Surface8();//������Чˢ��id
	void Surface9();//�����Чˢ��id
	void Surface10();//��ӡ��Чˢ��id
	void Surface11();//¼����Ч����id
	void Surface12();//ɾ����Ч����id
	void Surface13();//������Ч����id
	void Surface14();//�����Ч����id
	void Surface15();//��ӡ��Ч����id
	void Surface16();//���������Ա��Ϣ
	void Surface17();//��ӡ������Ա��Ϣ
	void Surface18();//
	void Surface19();//
	void Surface20();//
	void Surface21();//��ʾģ����
};