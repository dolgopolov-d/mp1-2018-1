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

	int AverageStepsMonth(int _month)
	{
		int count=0;
		int i;
		int tempSteps = 0;
		for (i = 0; i < counter; i++)
			if (date[i].month == _month)
			{
				count++;
				tempSteps += Steps[i];
			}
		if (count == 0)
			return 0;
		else
			return (tempSteps / count);
	}

	int GetDayFromDate(int D, int M, int Y)
	{
		int a, y, m, R;
		a = (14 - M) / 12;
		y = Y - a;
		m = M + 12 * a - 2;
		R = 7000 + (D + y + y / 4 - y / 100 + y / 400 + (31 * m) / 12);
		return R % 7;
	}

	int AverageStepsDay(int _day)
	{	
		int count = 0;
		int temp = 0;
		int i;
		for (i = 0; i < counter; i++)
			if (GetDayFromDate(date[i].day, date[i].month, date[i].year) == _day)
			{
				count++;
				temp += Steps[i];
			}
		if (count == 0)
			return 0;
		else
			return (temp / count);
	}

	int MaxSteps(int _month)
	{
		int tempMax = 0;
		int i;
		for (i = 0; i < counter; i++)
			if (date[i].month == _month)
				if (Steps[i] > tempMax)
					tempMax = Steps[i];
		return tempMax;
	}

	int MaxStepsDate(int _month)
	{
		int dateOfMax = 0;
		int tempMax = 0;
		int i;
		for (i = 0; i < counter; i++)
			if (date[i].month == _month)
				if (Steps[i] > tempMax)
				{
					tempMax = Steps[i];
					dateOfMax = i;
				}
		return dateOfMax;
	}
	void SaveToFile()
	{

	}

	void GetFromFile()
	{

	}
};

void main()
{
	setlocale(LC_ALL, "Russian");
	int user_dayOfWeek = -1;
	int temp;
	int j;
	int i;
	int day, month, year;
	int stHour;
	int stMin;
	int enHour;
	int enMin;
	int stepCount;
	int user_month;
	cout << "������� ������� ����� ����� ���������:\n";
	cin >> temp;
	StepCounter of(temp);
	in:cout << "������� ��������:\n1.������ �������\n2.������ ���� ��������\n3.������ ���������� � ��������\n4.������� ����� ����� � ��������� ������\n5.����� ������������ ���������� ����� � ��������� ������\n6.������ ������� ���������� ����� � ��������� ���� ������\n0.�����\n";
	cin >> j;
	switch (j)
	{
	case 1:
		cout << "������� ����� ��������: (0 - " << temp - 1 << ")\n";
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
		cout << "������� ����� ��������: (0 - " << temp - 1 << ")\n";
		cin >> i;
		if ((of.GetStartDay(i) == 0) && (of.GetStartMonth(i) == 0) && (of.GetStartYear(i) == 0))
			cout << "���� �� ������" << endl << endl;
		else
			cout << "����: " << of.GetStartDay(i) << "." << of.GetStartMonth(i) << "." << of.GetStartYear(i) << endl << endl;
		goto in;
		break;
	case 3:
		cout << "������� ����� ��������: (0 - " << temp - 1 << ")\n";
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
	case 4:
		cout << "������� �����(1-12): \n";
		cin >> user_month;
		if (user_month == 0)
			cout << "�������� ����\n";
		else
			if (of.AverageStepsMonth(user_month) == 0)
				cout << "�������� ����" << endl;
			else
				cout << "������� ���������� ����� �� �����: " << of.AverageStepsMonth(user_month) << endl;
		goto in;
		break;
	case 5:
		cout << "������� �����(1-12): \n";
		cin >> user_month;
		if (user_month == 0)
			cout << "�������� ����\n";
		else
			cout << "������������ ���������� ����� � ���� ������: " << of.MaxSteps(user_month) << endl << "����: " << of.GetStartDay(of.MaxStepsDate(user_month)) << "." << of.GetStartMonth(of.MaxStepsDate(user_month)) << "." << of.GetStartYear(of.MaxStepsDate(user_month)) << endl;
		goto in;
		break;
	case 6:
		cout << "������� ������ ���� ������:(1 - �����������, 2 - �������, 3 - �����, 4 - �������, 5 - �������, 6 - �������, 0 - �����������" << endl;
		cin >> user_dayOfWeek;
		if (user_dayOfWeek >= 7)
			cout << "�������� ����" << endl;
		else
			if (of.AverageStepsDay(user_dayOfWeek) == 0)
				cout << "�������� ����" << endl;
			else 
				cout << "������� ����� ����� � ��������� ����: " << of.AverageStepsDay(user_dayOfWeek) << endl;
		goto in;
		break;
	case 0:
		break;
	}
	system("pause");
}