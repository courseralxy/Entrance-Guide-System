#include"People.h"
ostream& operator << (ostream& out, Status status)
{
	if (status == ��)
		out << "��ϵ¥";
	else
		out << "��ϵ¥";
	return out;
}
ostream& operator << (ostream& out, const ActiveTime AT)
{
out << AT.hour << "��" << setw(2) << setfill('0')<< AT.minute;
return out;
}
const int People::getCardID()
{
	return CardID;
}
const string People::getName()
{
	return name;
}
const ActiveTime People::getActiveTime()
{
	return AT;
}
const Status People::getStatus()
{
	return status;
}
void People::ShowInfo2()
{
	cout << name << ",����" << CardID;
}