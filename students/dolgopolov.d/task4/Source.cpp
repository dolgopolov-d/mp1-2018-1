#include <iostream>
#include <stdio.h>
#include <locale.h>
#include <fstream>
#include <string>

using namespace std;

class StepCounter
{
	ifstream in;
	ofstream out;
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
	
	void SetSteps(int count, int _steps = 0)
	{
		Steps[count] = _steps;
	}

	int GetSteps(int count)
	{
		return Steps[count];
	}

	void SetStartDate(int count, int _day = 0, int _month = 0, int _year = 0)
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

	void SaveToFile(int _count)
	{
		int i=0;
		out.open("C:/Test/out.txt");
		do
		{
			out << Steps[i] << endl << date[i].day << endl << date[i].month << endl << date[i].year << endl << time[i].startHour << endl << time[i].startMin << endl << time[i].endHour << endl << time[i].endMin << endl;
			i++;
		} while (date[i].day && date[i].month && date[i].year != 0);
		out.close();
	}

	void GetFromFile(int _count)
	{
		int i;
		char temp[200];
		in.open("C:/Test/out.txt");
		for (i = 0; i < _count; i++)
		{
			in.getline(temp, 200, '\n');
			Steps[i] = atoi(temp);
			in.getline(temp, 200, '\n');
			date[i].day = atoi(temp);
			in.getline(temp, 200, '\n');
			date[i].month = atoi(temp);
			in.getline(temp, 200, '\n');
			date[i].year = atoi(temp);
			in.getline(temp, 200, '\n');
			time[i].startHour = atoi(temp);
			in.getline(temp, 200, '\n');
			time[i].startMin = atoi(temp);
			in.getline(temp, 200, '\n');
			time[i].endHour = atoi(temp);
			in.getline(temp, 200, '\n');
			time[i].endMin = atoi(temp);
		}
		in.close();
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
	int stepCount = 0;
	int user_month;
	ofstream out;
	ifstream in;
	cout << "������� ������� ����� ����� ���������:\n";
	cin >> temp;
	StepCounter of(temp);
	in:cout << "������� ��������:\n1.������ �������\n2.������ ���� ��������\n3.������ ���������� � ��������\n4.������� ����� ����� � ��������� ������\n5.����� ������������ ���������� ����� � ��������� ������\n6.������ ������� ���������� ����� � ��������� ���� ������\n7.��������� ������ � ����\n8.��������� ������ �� �����0.�����\n";
	cin >> j;
	switch (j)
	{
	case 1:
		cout << "������� ����� ��������: (0 - " << temp - 1 << ")\n";
		cin >> i;
		if (i >= temp)
		{
			cout << "������������ ����" << endl;
			goto in;
		}
		cout << "������� ����:(����, �����, ���)\n";
		cin >> day >> month >> year;
		if ((day > 31) || (month > 12))
		{
			cout << "������������ ����" << endl;
			goto in;
		}
		of.SetStartDate(i, day, month, year);
		cout << "������� �����: (��� ������, ������ ������, ��� �����, ������ �����)\n";
		cin >> stHour >> stMin >> enHour >> enMin;
		if ((stHour >= 24) || (stMin >= 60) || (enHour >= 24) || (enMin >= 60))
		{
			cout << "������������ ����" << endl;
			goto in;
		}
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
		cout << "������� ������ ���� ������:\n1 - �����������\n2 - �������\n3 - �����\n4 - �������\n5 - �������\n6 - �������\n0 - �����������" << endl;
		cin >> user_dayOfWeek;
		if (user_dayOfWeek >= 7)
			cout << "�������� ����" << endl;
		else
			if (of.AverageStepsDay(user_dayOfWeek) == 0)
				cout << "��� �����" << endl;
			else 
				cout << "������� ����� ����� � ��������� ����: " << of.AverageStepsDay(user_dayOfWeek) << endl;
		goto in;
		break;
	case 7:
		of.SaveToFile(temp);
		goto in;
		break;
	case 8:
		of.GetFromFile(temp);
		goto in;
		break;
	case 0:
		break;
	}
	system("pause");
}