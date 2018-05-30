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
	on:cout << "Введите стартовую дату:(день, месяц, год) \n";
	cin >> startDay >> startMonth >> startYear;
	if ((startDay > 31) || (startMonth > 12) || (startDay <= 0) || (startMonth <= 0) || (startYear <= 0))
	{
		cout << "Неверный ввод" << endl;
		goto on;
	}
	of.SetStDate(startDay, startMonth, startYear);
	in:cout << "Введите действие:\n1.Ввести подсчет\n2.Узнать стартовую дату\n3.Узнать информацию о подсчете\n4.Среднее число шагов в выбранном месяце\n5.Найти максимальное количество шагов в выбранном месяце\n6.Узнать среднее количество шагов в выбранный день недели\n7.Сохранить данные в файл\n8.Загрузить данные из файла\n0.Выход\n";
	cin >> j;
	switch (j)
	{
	case 1:
		cout << "Введите номер подсчета: (0 - " << counts - 1 << ")\n";
		cin >> i;
		if ((i > counts - 1) || (i < 0))
		{
			cout << "Некорректный ввод" << endl;
			goto in;
		}
		cout << "Введите количество шагов: ";
		cin >> steps;
		_day: cout << "Введите день подсчета: ";
		cin >> day;
		if ((day <= 0) || (day > 31))
		{
			cout << "Неверный ввод" << endl;
			goto _day;
		}
		_month:cout << "Введите месяц подсчета: ";
		cin >> month;
		if ((month <= 0) || (month > 12))
		{
			cout << "Неверный ввод" << endl;
			goto _month;
		}
		_year:cout << "Введите год подсчета ";
		cin >> year;
		if (year <= 0)
		{
			cout << "Неверный ввод" << endl;
			goto _year;
		}
		_startHour:cout << "Введите часы начала подсчета: ";
		cin >> startHour;
		if ((startHour < 0) || (startHour > 23))
		{
			cout << "Неверный ввод" << endl;
			goto _startHour;
		}
		_startMin:cout << "Введите минуты начала подсчета: ";
		cin >> startMin;
		if ((startMin < 0) || (startMin > 59))
		{
			cout << "Неверный ввод" << endl;
			goto _startMin;
		}
		_endHour:cout << "Введите часы конца подсчета: ";
		cin >> endHour;
		if ((endHour < 0) || (endHour > 23))
		{
			cout << "Неверный ввод" << endl;
			goto _endHour;
		}
		_endMin:cout << "Введите минуты конца подсчета: ";
		cin >> endMin;
		if ((endMin < 0) || (endMin > 59))
		{
			cout << "Неверный ввод" << endl;
			goto _endMin;
		}
		of.SetCountInfo(i, steps, startHour, startMin, endHour, endMin, day, month, year);
		goto in;
		break;
	case 2:
		if ((of.GetStDate(1) == 0) && (of.GetStDate(2) == 0) && (of.GetStDate(3) == 0))
			cout << "Дата не задана" << endl << endl;
		else
			cout << "Дата: " << of.GetStDate(1) << "." << of.GetStDate(2) << "." << of.GetStDate(3) << endl << endl;
		goto in;
		break;
	case 3:
		cout << "Введите номер подсчета: (0 - " << counts - 1 << ")\n";
		cin >> i;
		if ((i > counts - 1) || (i < 0))
		{
			cout << "Некорректный ввод" << endl;
			goto in;
		}
		info:cout << "1.Количество шагов\n2.День подсчета\n3.Месяц подсчета\n4.Год подсчета\n5.Часы начала подсчета\n6.Минуты начала подсчета\n7.Часы окончания подсчета\n8.Минуты окончания подсчета\n0.Выход\n";
		cin >> k;
		switch (k)
		{
			case 1:
				cout << "Шаги: " << endl;
				break;
			case 2:
				cout << "День: " << endl;
				break;
			case 3:
				cout << "Месяц: " << endl;
				break;
			case 4:
				cout << "Год: " << endl;
				break;
			case 5:
				cout << "Час начала: " << endl;
				break;
			case 6:
				cout << "Минута начала: " << endl;
				break;
			case 7:
				cout << "Час окончания: " << endl;
				break;
			case 8:
				cout << "Минута окончания: " << endl;
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
		cout << "Введите месяц(1-12): \n";
		cin >> user_month;
		if (user_month <= 0)
			cout << "Неверный ввод\n";
		else
			if (of.AverageStepsMonth(user_month) == 0)
				cout << "Неверный ввод" << endl;
			else
				cout << "Среднее количество шагов за месяц: " << of.AverageStepsMonth(user_month) << endl << endl;
		goto in;
		break;
	case 5:
		cout << "Введите месяц(1-12): \n";
		cin >> user_month;
		if (user_month == 0)
			cout << "Неверный ввод\n";
		else
			cout << "Максимальное количество шагов в этом месяце: " << of.MaxSteps(user_month, 1) << endl << "Дата: " << of.GetCountInfo(of.MaxSteps(user_month, 2), 2) << "." << of.GetCountInfo(of.MaxSteps(user_month, 2), 3) << "." << of.GetCountInfo(of.MaxSteps(user_month, 2), 4) << endl << endl;
		goto in;
		break;
	case 6:
		cout << "Введите нужный день недели:\n1 - Понедельник\n2 - Вторник\n3 - Среда\n4 - Четверг\n5 - Пятница\n6 - Суббота\n0 - Воскресенье" << endl;
		cin >> user_dayOfWeek;
		if (user_dayOfWeek >= 7)
			cout << "Неверный ввод" << endl;
		else
			if (of.AverageStepsDay(user_dayOfWeek) == 0)
				cout << "Нет шагов" << endl;
			else 
				cout << "Среднее число шагов в выбранный день: " << of.AverageStepsDay(user_dayOfWeek) << endl << endl;
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