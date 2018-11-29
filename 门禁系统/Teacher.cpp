#include"Teacher.h"
const int Teacher::getFaceID()
{
	return FaceID;
}
void Teacher::ShowInfo()
{
	cout << "ÀÏÊ¦";
	ShowInfo2();
	cout << "£¬ÈËÁ³" << FaceID << endl;

}