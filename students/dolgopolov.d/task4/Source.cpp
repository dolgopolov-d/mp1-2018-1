#include <iostream>
#include <stdio.h>
#include <locale.h>
#include <fstream>
#include <string>
#define counts 20


using namespace std;

class StepCounter
{
	ifstream in;
	ofstream out;
	int *Steps;
	struct Date
	{
		int day = 0;
		int month = 0;
		int year = 0;
	} *date;
	struct Time
	{
		int startHour = 0;
		int startMin = 0;
		int endHour = 0;
		int endMin = 0;
	} *time;
	struct StDate
	{
		int stDay = 0;
		int stMonth = 0;
		int stYear = 0;
	} stDate;
public:
	StepCounter()
	{
		Steps = new int[counts];
		date = new Date[counts];
		time = new Time[counts];
	}

	~StepCounter()
	{
		delete[] Steps;
		delete[] date;
		delete[] time;
	}
	
	void SetStDate(int _day, int _month, int _year)
	{
		stDate.stDay = _day;
		stDate.stMonth = _month;
		stDate.stYear = _year;
	}

	int GetStDate(int i)
	{
		switch (i)
		{
		case 1:
			return stDate.stDay;
		case 2:
			return stDate.stMonth;
		case 3:
			return stDate.stYear;
		}
	}

	void SetCountInfo(int count, int _steps, int _startHour, int _startMin, int _endHour, int _endMin, int _day = 0, int _month = 0, int _year = 0)
	{
		int i;
		for (i = 0; i < counts; i++)
			Steps[i] = 0;
		Steps[count] = _steps;
		date[count].day = _day;
		date[count].month = _month;
		date[count].year = _year;
		time[count].startHour = _startHour;
		time[count].startMin = _startMin;
		time[count].endHour = _endHour;
		time[count].endMin = _endMin;
	}

	int GetCountInfo(int count, int i)
	{
		switch (i)
		{
		case 1:
			return Steps[count];
		case 2:
			return date[count].day;
		case 3:
			return date[count].month;
		case 4:
			return date[count].year;
		case 5:
			return time[count].startHour;
		case 6:
			return time[count].startMin;
		case 7:
			return time[count].endHour;
		case 8:
			return time[count].endMin;
		case 0:
			return 0;
		}
	}

	int AverageStepsMonth(int _month)
	{
		int count=0;
		int i;
		int tempSteps = 0;
		for (i = 0; i < counts; i++)
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
		for (i = 0; i < counts; i++)
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

	int MaxSteps(int _month, int j)
	{
		int dateOfMax = 0;
		int tempMax = 0;
		int i;
		for (i = 0; i < counts; i++)
			if (date[i].month == _month)
				if (Steps[i] > tempMax)
				{
					tempMax = Steps[i];
					dateOfMax = i;
				}
		switch (j)
		{
			case 1:
				return tempMax;
			case 2:
				return dateOfMax;
		}
	}

	void SaveToFile()
	{
		int i;
		out.open("C:/Test/out.txt");
		for (i=0; i<counts; i++)
			out << stDate.stDay << endl << stDate.stMonth << endl << stDate.stYear << endl << Steps[i] << endl << time[i].startHour << endl << time[i].startMin << endl << time[i].endHour << endl << time[i].endMin << endl << date[i].day << endl << date[i].month << endl << date[i].year << endl;
		out.close();
	}

	void GetFromFile()
	{
		int i;
		char temp[200];
		in.open("C:/Test/out.txt");
		for (i = 0; i < counts; i++)
		{
			in.getline(temp, 200, '\n');
			stDate.stDay = atoi(temp);
			in.getline(temp, 200, '\n');
			stDate.stMonth = atoi(temp);
			in.getline(temp, 200, '\n');
			stDate.stYear = atoi(temp);
			in.getline(temp, 200, '\n');
			Steps[i] = atoi(temp);
			in.getline(temp, 200, '\n');
			time[i].startHour = atoi(temp);
			in.getline(temp, 200, '\n');
			time[i].startMin = atoi(temp);
			in.getline(temp, 200, '\n');
			time[i].endHour = atoi(temp);
			in.getline(temp, 200, '\n');
			time[i].endMin = atoi(temp);
			in.getline(temp, 200, '\n');
			date[i].day = atoi(temp);
			in.getline(temp, 200, '\n');
			date[i].month = atoi(temp);
			in.getline(temp, 200, '\n');
			date[i].year = atoi(temp);
		}
		in.close();
	}
};

void main()
{
	setlocale(LC_ALL, "Russian");
	int user_dayOfWeek = -1;
	int j;
	int i;
	int k;
	int steps;
	int day;
	int month;
	int year;
	int startHour;
	int startMin;
	int endHour;
	int endMin;
	int startDay, startMonth, startYear;
	int stepCount = 0;
	int user_month;
	ofstream out;
	ifstream in;
	StepCounter of;
	on:cout << "������� ��������� ����:(����, �����, ���) \n";
	cin >> startDay >> startMonth >> startYear;
	if ((startDay > 31) || (startMonth > 12) || (startDay <= 0) || (startMonth <= 0) || (startYear <= 0))
	{
		cout << "�������� ����" << endl;
		goto on;
	}
	of.SetStDate(startDay, startMonth, startYear);
	in:cout << "������� ��������:\n1.������ �������\n2.������ ��������� ����\n3.������ ���������� � ��������\n4.������� ����� ����� � ��������� ������\n5.����� ������������ ���������� ����� � ��������� ������\n6.������ ������� ���������� ����� � ��������� ���� ������\n7.��������� ������ � ����\n8.��������� ������ �� �����\n0.�����\n";
	cin >> j;
	switch (j)
	{
	case 1:
		cout << "������� ����� ��������: (0 - " << counts - 1 << ")\n";
		cin >> i;
		if ((i > counts - 1) || (i < 0))
		{
			cout << "������������ ����" << endl;
			goto in;
		}
		cout << "������� ���������� �����: ";
		cin >> steps;
		_day: cout << "������� ���� ��������: ";
		cin >> day;
		if ((day <= 0) || (day > 31))
		{
			cout << "�������� ����" << endl;
			goto _day;
		}
		_month:cout << "������� ����� ��������: ";
		cin >> month;
		if ((month <= 0) || (month > 12))
		{
			cout << "�������� ����" << endl;
			goto _month;
		}
		_year:cout << "������� ��� �������� ";
		cin >> year;
		if (year <= 0)
		{
			cout << "�������� ����" << endl;
			goto _year;
		}
		_startHour:cout << "������� ���� ������ ��������: ";
		cin >> startHour;
		if ((startHour < 0) || (startHour > 23))
		{
			cout << "�������� ����" << endl;
			goto _startHour;
		}
		_startMin:cout << "������� ������ ������ ��������: ";
		cin >> startMin;
		if ((startMin < 0) || (startMin > 59))
		{
			cout << "�������� ����" << endl;
			goto _startMin;
		}
		_endHour:cout << "������� ���� ����� ��������: ";
		cin >> endHour;
		if ((endHour < 0) || (endHour > 23))
		{
			cout << "�������� ����" << endl;
			goto _endHour;
		}
		_endMin:cout << "������� ������ ����� ��������: ";
		cin >> endMin;
		if ((endMin < 0) || (endMin > 59))
		{
			cout << "�������� ����" << endl;
			goto _endMin;
		}
		of.SetCountInfo(i, steps, startHour, startMin, endHour, endMin, day, month, year);
		goto in;
		break;
	case 2:
		if ((of.GetStDate(1) == 0) && (of.GetStDate(2) == 0) && (of.GetStDate(3) == 0))
			cout << "���� �� ������" << endl << endl;
		else
			cout << "����: " << of.GetStDate(1) << "." << of.GetStDate(2) << "." << of.GetStDate(3) << endl << endl;
		goto in;
		break;
	case 3:
		cout << "������� ����� ��������: (0 - " << counts - 1 << ")\n";
		cin >> i;
		if ((i > counts - 1) || (i < 0))
		{
			cout << "������������ ����" << endl;
			goto in;
		}
		info:cout << "1.���������� �����\n2.���� ��������\n3.����� ��������\n4.��� ��������\n5.���� ������ ��������\n6.������ ������ ��������\n7.���� ��������� ��������\n8.������ ��������� ��������\n0.�����\n";
		cin >> k;
		switch (k)
		{
			case 1:
				cout << "����: " << endl;
				break;
			case 2:
				cout << "����: " << endl;
				break;
			case 3:
				cout << "�����: " << endl;
				break;
			case 4:
				cout << "���: " << endl;
				break;
			case 5:
				cout << "��� ������: " << endl;
				break;
			case 6:
				cout << "������ ������: " << endl;
				break;
			case 7:
				cout << "��� ���������: " << endl;
				break;
			case 8:
				cout << "������ ���������: " << endl;
				break;
			case 0:
				break;
		}
		if (k != 0)
		{
			cout << of.GetCountInfo(i, k) << endl;
			goto info;
		}
		if (k == 0)
			goto in;
		break;
	case 4:
		cout << "������� �����(1-12): \n";
		cin >> user_month;
		if (user_month <= 0)
			cout << "�������� ����\n";
		else
			if (of.AverageStepsMonth(user_month) == 0)
				cout << "�������� ����" << endl;
			else
				cout << "������� ���������� ����� �� �����: " << of.AverageStepsMonth(user_month) << endl << endl;
		goto in;
		break;
	case 5:
		cout << "������� �����(1-12): \n";
		cin >> user_month;
		if (user_month == 0)
			cout << "�������� ����\n";
		else
			cout << "������������ ���������� ����� � ���� ������: " << of.MaxSteps(user_month, 1) << endl << "����: " << of.GetCountInfo(of.MaxSteps(user_month, 2), 2) << "." << of.GetCountInfo(of.MaxSteps(user_month, 2), 3) << "." << of.GetCountInfo(of.MaxSteps(user_month, 2), 4) << endl << endl;
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
				cout << "������� ����� ����� � ��������� ����: " << of.AverageStepsDay(user_dayOfWeek) << endl << endl;
		goto in;
		break;
	case 7:
		of.SaveToFile();
		goto in;
		break;
	case 8:
		of.GetFromFile();
		goto in;
		break;
	case 0:
		break;
	}
	system("pause");
}