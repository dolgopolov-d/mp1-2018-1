#include <iostream>
#include <stdio.h>
#include <locale.h>
#include <fstream>
#include <string>
#include <windows.h>
#define counts 20


using namespace std;

class StepCounter
{
	ifstream in;
	ofstream out;
	int *Steps;
	int counter;
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

	int GetStDay()
	{
		return stDate.stDay;
	}

	int GetStMonth()
	{
		return stDate.stMonth;
	}

	int GetStYear()
	{
		return stDate.stYear;
	}

	void SetSteps(int count, int _steps)
	{
		int i;
		for (i = 0; i < counts; i++)
			Steps[i] = 0;
		Steps[count] = _steps;
	}

	int GetSteps(int count)
	{
		return Steps[count];
	}

	void SetDate(int count, int _day = 0, int _month = 0, int _year = 0)
	{
		date[count].day = _day;
		date[count].month = _month;
		date[count].year = _year;
	}

	int GetDay(int count)
	{
		return date[count].day;
	}

	int GetMonth(int count)
	{
		return date[count].month;
	}

	int GetYear(int count)
	{
		return date[count].year;
	}

	void SetStTime(int _startHour, int _startMin, int count)
	{
		time[count].startHour = _startHour;
		time[count].startMin = _startMin;
	}

	void SetEndTime(int _endHour, int _endMin, int count)
	{
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

	int MaxSteps(int _month)
	{
		int tempMax = 0;
		int i;
		for (i = 0; i < counts; i++)
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
		for (i = 0; i < counts; i++)
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
		int i;
		out.open("C:/Test/out.txt");
		for (i=0; i<counts; i++)
			out << stDate.stDay << endl << stDate.stMonth << endl << stDate.stYear << endl <<Steps[i] << endl << date[i].day << endl << date[i].month << endl << date[i].year << endl << time[i].startHour << endl << time[i].startMin << endl << time[i].endHour << endl << time[i].endMin << endl;
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
	int j;
	int i;
	int k;
	SYSTEMTIME date_start, date_end;
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
		op:cout << "Введите нужное дейтвие:\n1.Начать подсчет\n2.Закончить подсчет\n";
		cin >> k;
		switch (k)
		{
		case 1:
			GetLocalTime(&date_start);
			of.SetDate(i, date_start.wDay, date_start.wMonth, date_start.wYear);
			of.SetStTime(date_start.wHour, date_start.wMinute, i);
			cout << "Начало движения: " << date_start.wDay << "." << date_start.wMonth << "." << date_start.wYear << endl << date_start.wHour << ":" << date_start.wMinute << endl;
			goto op;
			break;
		case 2:
			GetLocalTime(&date_end);
			of.SetEndTime(date_end.wHour, date_end.wMinute, i);
			cout << "Конец движения: " << date_end.wDay << "." << date_end.wMonth << "." << date_end.wYear << endl << date_end.wHour << ":" << date_end.wMinute << endl;
			break;
		}
		cout << "Введите кол-во шагов:\n";
		cin >> stepCount;
		of.SetSteps(i, stepCount);
		system("cls");
		goto in;
		break;
	case 2:
		if ((of.GetStDay() == 0) && (of.GetStMonth() == 0) && (of.GetStYear() == 0))
			cout << "Дата не задана" << endl << endl;
		else
			cout << "Дата: " << of.GetStDay() << "." << of.GetStMonth() << "." << of.GetStYear() << endl << endl;
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
		if ((of.GetStartHour(i) == 0) && (of.GetStartMin(i) == 0) && (of.GetEndHour(i) == 0) && (of.GetEndMin(i) == 0))
			cout << "Подсчет не задан" << endl << endl;
		else
			if ((of.GetDay(i) == 0) && (of.GetMonth(i) == 0) && (of.GetYear(i) == 0))
				cout << "Дата не задана" << endl << endl;
			else
			{
				cout << "Дата: " << of.GetDay(i) << "." << of.GetMonth(i) << "." << of.GetYear(i) << endl;
				cout << "Время: " << of.GetStartHour(i) << ":" << of.GetStartMin(i) << " - " << of.GetEndHour(i) << ":" << of.GetEndMin(i) << endl;
				cout << "Шагов: " << of.GetSteps(i) << endl << endl;
			}
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
			cout << "Максимальное количество шагов в этом месяце: " << of.MaxSteps(user_month) << endl << "Дата: " << of.GetDay(of.MaxStepsDate(user_month)) << "." << of.GetMonth(of.MaxStepsDate(user_month)) << "." << of.GetYear(of.MaxStepsDate(user_month)) << endl << endl;
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