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
	void SetStartDate(int _day, int _month, int _year)
	{
		date->day = _day;
		date->month = _month;
		date->year = _year;
	}
	int GetStartDay()
	{
		return date->day;
	}
	int GetStartMonth()
	{
		return date->month;
	}
	int GetStartYear()
	{
		return date->year;
	}
	void SetCount(int _startHour, int _startMin, int _endHour, int _endMin)
	{
		time->startHour = _startHour;
		time->startMin = _startMin;
		time->endHour = _endHour;
		time->endMin = _endMin;
	}
	int GetStartHour()
	{
		return time->startHour;
	}
	int GetStartMin()
	{
		return time->startMin;
	}
	int GetEndHour()
	{
		return time->endHour;
	}
	int GetEndMin()
	{
		return time->endMin;
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
	int NOF;
	StepCounter of;
	cout << "¬ведите номер подсчета шагов:\n";
	cin >> temp;
	NOF++;


}