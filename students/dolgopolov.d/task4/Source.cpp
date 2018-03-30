#include <iostream>
#include <stdio.h>
#include <locale.h>

using namespace std;

class StepCounter
{
	int *Steps; 
	int counter; 
	struct Date
	{
		int day=0;
		int month=0;
		int year=0;
	} *date; 
	struct Time
	{
		int startHour=0;
		int startMin=0;
		int endHour=0;
		int endMin=0;
	} *time; 
public:
	StepCounter(int _counter = 0)
	{
		counter = _counter;
		Steps = new int[counter];
		date = new Date[counter];
		time = new Time[counter];
	}
	~StepCounter()
	{
		delete[] Steps;
		delete[] date;
		delete[] time;
	}
	
	void SetSteps(int count,int _steps=0)
	{
		Steps[count] = _steps;
	}
	int GetSteps(int count)
	{
		return Steps[count];
	}
	void SetStartDate(int count, int _day=0, int _month=0, int _year=0)
	{
		date[count].day = _day;
		date[count].month = _month;
		date[count].year = _year;
	}
	int GetStartDay(int count)
	{
		return date[count].day;
	}
	int GetStartMonth(int count)
	{
		return date[count].month;
	}
	int GetStartYear(int count)
	{
		return date[count].year;
	}
	void SetCount(int _startHour, int _startMin, int _endHour, int _endMin, int count)
	{
		time[count].startHour = _startHour;
		time[count].startMin = _startMin;
		time[count].endHour = _endHour;
		time[count].endMin = _endMin;
	}
	int GetStartHour(int count)
	{
		return time[count].startHour;
	}
	int GetStartMin(int count)
	{
		return time[count].startMin;
	}
	int GetEndHour(int count)
	{
		return time[count].endHour;
	}
	int GetEndMin(int count)
	{
		return time[count].endMin;
	}
	int AverageStepsMonth()
	{

	}
	int AverageStepsDay()
	{

	}
	int MaxSteps()
	{

	}
	void SaveToFile()
	{

	}
	void GetFromFile()
	{

	}
};

int main()
{
	setlocale(LC_ALL, "Russian");
	int temp;
	int j;
	int i;
	int day, month, year;
	int stHour;
	int stMin;
	int enHour;
	int enMin;
	int stepCount;
	cout << "������� ������� ����� ����� ���������:\n";
	cin >> temp;
	StepCounter of(temp);
	in:cout << "������� ��������:\n1.������ �������\n2.������ ���� ��������\n3.������ ���������� � ��������\n4.������� ����� ����� � ��������� ������\n0.�����\n";
	cin >> j;
	switch (j)
	{
	case 1:
		cout << "������� ����� ��������: (1 - " << temp << ")\n";
		cin >> i;
		cout << "������� ����:(����, �����, ���)\n";
		cin >> day >> month >> year;
		of.SetStartDate(i, day, month, year);
		cout << "������� �����: (��� ������, ������ ������, ��� �����, ������ �����)\n";
		cin >> stHour >> stMin >> enHour >> enMin;
		of.SetCount(stHour, stMin, enHour, enMin, i);
		cout << "������� ���-�� �����:\n";
		cin >> stepCount;
		of.SetSteps(i, stepCount);
		goto in;
		break;
	case 2:
		cout << "������� ����� ��������: (1 - " << temp << ")\n";
		cin >> i;
		if ((of.GetStartDay(i) == 0) && (of.GetStartMonth(i) == 0) && (of.GetStartYear(i) == 0))
			cout << "���� �� ������" << endl << endl;
		else
			cout << "����: " << of.GetStartDay(i) << "." << of.GetStartMonth(i) << "." << of.GetStartYear(i) << endl << endl;
		goto in;
		break;
	case 3:
		cout << "������� ����� ��������: (1 - " << temp << ")\n";
		cin >> i;
		if ((of.GetStartHour(i) == 0) && (of.GetStartMin(i) == 0) && (of.GetEndHour(i) == 0) && (of.GetEndMin(i) == 0))
			cout << "������� �� �����" << endl << endl;
		else
		{
			cout << "�����: " << of.GetStartHour(i) << ":" << of.GetStartMin(i) << " - " << of.GetEndHour(i) << ":" << of.GetEndMin(i) << endl << endl;
			cout << "�����: " << of.GetSteps(i) << endl << endl;
		}
		goto in;
		break;
	case 0:
		break;
	}
	system("pause");
}