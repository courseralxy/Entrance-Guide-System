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
	void Surface0();//初始界面
	void Surface1();//功能1
	void Surface2();//功能2
	void Surface3();//功能3
	void Surface4();//功能4
	void Surface5();//功能5
	void Output(vector<string>*output,int totalline);
	bool SecondConfirm();
	void Surface6();//录入有效刷卡id
	void Surface7();//删除有效刷卡id
	void Surface8();//增加有效刷卡id
	void Surface9();//清空有效刷卡id
	void Surface10();//打印有效刷卡id
	void Surface11();//录入有效人脸id
	void Surface12();//删除有效人脸id
	void Surface13();//增加有效人脸id
	void Surface14();//清空有效人脸id
	void Surface15();//打印有效人脸id
	void Surface16();//输入进出人员信息
	void Surface17();//打印进出人员信息
	void Surface18();//
	void Surface19();//
	void Surface20();//
	void Surface21();//显示模拟结果
};