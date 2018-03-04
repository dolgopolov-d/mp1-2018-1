#define _CRT_SECURE_NO_WARNINGS
#define Start "������� ���\n"
#include <clocale>
#include <iostream>
#include <cstring>

using namespace std;
class TCalendar {
	int d[30];
	int	m[30];
	int y[30];
	char **event;
public:
	TCalendar(char *str = "������� ���", int n = -1, int _y = 0, int _m = 0, int _d = 0)
	{
		event = new char*[30];
		for (int i = 0; i < 30; i++)
		{
			y[i] = 0;
			m[i] = 0;
			d[i] = 0;
			event[i] = new char[strlen(Start) + 1];
			strcpy(event[i], Start);
		}
		if ((n > -1) && (n < 30))
		{
			delete[] event[n];
			event[n] = new char[strlen(str) + 1];
			strcpy(event[n], str);
		}
	}
	~TCalendar()
	{
		for (int i = 0; i < 30; i++)
			delete[] event[i];
		delete[] event;
	}
	TCalendar& operator=(const TCalendar& obj)
	{
		for (int i = 0; i < 30; i++)
		{
			d[i] = obj.d[i];
			m[i] = obj.m[i];
			y[i] = obj.y[i];
			delete[] event[i];
			event[i] = new char[strlen(obj.event[i]) + 1];
			strcpy(event[i], obj.event[i]);
		}
		return *this;
	}
	void setEvent(int n, int _year, int _month, int _day, char *str)
	{
		if ((n > -1) && (n < 30))
			if ((_year > 0 && _year <= 2020) && (_month > 0 && _month <= 12) && (_day > 0 && _day <= 31))
			{
				y[n] = _year;
				m[n] = _month;
				d[n] = _day;
				strcpy(event[n], str);
			}
	}
	
	void getEvent(int n)
	{
		if ((y[n] == 0) || (m[n] == 0) || (d[n] == 0))
			cout << Start;
		else
			cout << getYear(n) << " ��� " << getMonth(n) << " ����� " << getDay(n) << " ���� " << endl;
	}
	void Difference(int n, int _day, int _month, int _year)
	{
		int r_d = abs((_year * 365 + _month * 30.4 + _day) - (y[n] * 365 + m[n] * 30.4 + d[n]));
		int r_m = abs(r_d / 30);
		int r_y = abs(r_m / 12);
		if ((r_m > 0) && (r_y) > 0)
			cout << "������� ���������� " << r_y << " ��� " << (r_m % 12) << " ������� " << (r_d % 31) -1 << " ���� \n";
		else
			if (r_m > 0)
				cout << "������� ���������� " << r_m << " ������� " << (r_d % 30) - 1 << " ���� \n";
			else
				cout << "������� ���������� " << r_d << " ����\n";
	}
	void moveEvent(int n, int _d, int _m, int _y, int a)
	{
		switch (a)
		{
		case 1:
			if ((d[n]+_d) >31)
			{
				m[n] = m[n] + 1;
				d[n] = (d[n]+_d) - 31;
			}
			else
				d[n] = d[n] + _d;

			if ((m[n] + _m) > 12)
			{
				y[n] = y[n] + 1;
				m[n] = (m[n] + _m) - 12;
			}
			else
				m[n] = m[n] + _m;
			y[n] = y[n] + _y;

			getEvent(n);
		case 2:
			
				if ((d[n] - _d) < 1)
				{
					m[n] = m[n] - 1;
					d[n] = 31 - (_d - d[n]);
				}
				else
					d[n] = d[n] - _d;

				if ((m[n] - _m) < 1)
				{
					y[n] = y[n] - 1;
					m[n] = 12 - (_m - m[n]);
				}
				else
					m[n] = m[n] - _m;

				y[n] = y[n] - _y;

				getEvent(n);
			
		}
	}
	int getDay(int n)
	{
		return d[n];
	}
	int getMonth(int n)
	{
		return m[n];
	}
	int getYear(int n)
	{
		return y[n];
	}
};



void main()
{
	int y, m, d, n;
	int a;
	int y_d, m_d, d_d;
	int d1, m1, y1;
	int b;
	char str[150];
	setlocale(LC_ALL, "Russian");
	class TCalendar event;
	in:
	cout << "1. ���������� ������� \n2. ������ ���� �������\n3. ����� ������� ����� ������\n4. �������� �������\n0.�����\n";
	cin >> a;
	switch (a)
		{
		case 1:
			cout << "���������� ����� �������(0-29): " << endl;
			cin >> n;
			cout << "������� �������: " << endl;
			cin.ignore();
			cin.getline(str, 200, '\n');
			cout << "������� ���� (����(1-31) �����(1-12) ���(1-2020)): " << endl;
			cin >> d >> m >> y;
			event.setEvent(n, y, m, d, str);
			goto in;
		case 2:
			cout << "������� ����� �������: \n";
			cin >> n;
			event.getEvent(n);
			goto in;
		case 3:
			cout << "������� ����� �������: \n";
			cin >> n;
			cout << "������� ����, � ������� ����� ����� ������� (���� ����� ���): \n";
			cin >> d_d >> m_d >> y_d;
			event.Difference(n, d_d, m_d, y_d);
			break;
		case 4:
			cout << "������� ����� �������: \n";
			cin >> n;
			cout << "������� ���� �� ������ �������� ����: 1 - ������, 2 - �����\n";
			cin >> b;
			cout << "������� �� ������� �� ������ �������� ����: ����� ����� ���:  \n";
			cin >> d1 >> m1 >> y1;
			event.moveEvent(n, d1, m1, y1, b);
			break;
		case 0:
			break;
		}
	system("pause");
}
