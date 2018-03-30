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
		int day;
		int month;
		int year;
	} *date; 
	struct Time
	{
		int startHour;
		int startMin;
		int endHour;
		int endMin;
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
		delete Steps;
		delete date;
		delete time;
	}
	void SetSteps(int count,int _steps)
	{
		Steps[count] = _steps;
	}
	void SetStartDate(int _day, int _month, int _year, int count)
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
		return date->month;
	}
	int GetStartYear(int count)
	{
		return date->year;
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
	int i;
	int day, month, year;
	int stHour;
	int stMin;
	int enHour;
	int enMin;
	int stepCount;
	cout << "¬ведите сколько всего будет подсчетов:\n";
	cin >> temp;
	StepCounter of(temp);
	cout << "¬ведите номер подсчета: (1 - " << temp << ")\n";
	cin >> i;
	cout << "¬ведите дату:(день, мес€ц, год)\n";
	cin >> day >> month >> year;
	of.SetStartDate(day, month, year, i);
	cout << "¬ведите врем€: (час начала, минуты начала, час конца, минуты конца)\n";
	cin >> stHour >> stMin >> enHour >> enMin;
	of.SetCount(stHour, stMin, enHour, enMin, i);
	cout << "¬ведите кол-во шагов:\n";
	cin >> stepCount;
	of.SetSteps(i, stepCount);


}