#define _CRT_SECURE_NO_WARNINGS
#define start "Событий нет\n"
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
	TCalendar(char *str = "Событий нет", int n = -1, int _y = 0, int _m = 0, int _d = 0)
	{
		event = new char*[30];
		for (int i = 0; i < 30; i++)
		{
			y[i] = 0;
			m[i] = 0;
			d[i] = 0;
			event[i] = new char[strlen(start) + 1];
			strcpy(event[i], start);
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
			return *this;
		}
	}
	void setEvent(int n, int _year, int _month, int _day, char *str)
	{
		if ((n > -1) && (n < 30))
		{
			if ((_year > 0 && _year <= 2020) && (_month > 0 && _month <= 12) && (_day > 0 && _day <= 31))
			{
				y[n] = _year;
				m[n] = _month;
				d[n] = _day;
				strcpy(event[n], str);
			}
			else
				cout << "Некорректный ввод\n";
		}
		
	}
	
	void getEvent(int n)
	{
		if ((getYear(n) == 0) || (getMonth(n) == 0) || (getDay(n) == 0))
			cout << event[n];
		else
			cout << y[n] << " год " << m[n] << " месяц " << d[n] << " день " << endl;
	}
	void Difference(int n, int _day, int _month, int _year)
	{
		int r_d = abs((_year * 365 + _month * 30.4 + _day) - (y[n] * 365 + m[n] * 30.4 + d[n]));
		int r_m = abs(r_d / 30);
		int r_y = abs(r_m / 12);
		if ((r_m > 0) && (r_y) > 0)
			cout << "Разница составляет " << r_y << " лет " << (r_m % 12) - 1 << " месяцев " << (r_d % 30) -1 << " дней \n";
		else
			if (r_m > 0)
				cout << "Разница составляет " << r_m << " месяцев " << (r_d % 30) - 1 << " дней \n";
			else
				cout << "Разница составляет " << r_d << " дней\n";
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
	char str[150];
	setlocale(LC_ALL, "Russian");
	class TCalendar event;
	in:
	cout << "1. Установить событие \n2. Узнать дату события\n3. Найти разницу между датами\n0.Выход\n";
	cin >> a;
	switch (a)
		{
		case 1:
			cout << "Порядковый номер события(0-29): " << endl;
			cin >> n;
			cout << "Введите событие: " << endl;
			cin.ignore();
			cin.getline(str, 200, '\n');
			cout << "Введите дату (день(1-31) месяц(1-12) год(1-2020)): " << endl;
			cin >> d >> m >> y;
			event.setEvent(n, y, m, d, str);
			goto in;
		case 2:
			cout << "Введите номер события: \n";
			cin >> n;
			event.getEvent(n);
			goto in;
		case 3:
			cout << "Введите номер события: \n";
			cin >> n;
			cout << "Введите дату, с которой нужно найти разницу (день месяц год): \n";
			cin >> d_d >> m_d >> y_d;
			event.Difference(n, d_d, m_d, y_d);
		case 0:
			break;
		}
	system("pause");
}
