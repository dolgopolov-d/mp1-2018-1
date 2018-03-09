#include <math.h>
#include <iostream>
#include <clocale>
#include <time.h>

using namespace std;
class TFunction
{
	int seed = time(0);
	int a;
	int b;
	int num;
	int dot;
	double y = (b - a) / dot;
public:
	TFunction()
	{}
	TFunction &operator=(int _num)
	{
		num = _num;
		return *this;
	}
	void setFunction(int _num)
	{
		num = _num;
	}
	void setDots(int _dot)
	{
		dot = _dot;
	}
	int getDots()
	{
		return dot;
	}
	void setInter(int _a, int _b)
	{
		a = _a;
		b = _b;
	}
	int getInter1()
	{
		return a;
	}
	int getInter2()
	{
		return b;
	}
	void doTab(int _dot)
	{
		int temp = a;
		int i;
		for (i = 0; i < _dot; i++)
			cout << "Значение", temp, "=", sign(temp);
		temp = temp + y;
	}
};

int sign(int a)
{
	int r;
	if (a > 0)
		r = 1;
	if (a < 0)
		r = -1;
	else
		r = 0;
	return r;
}

int main()
{
	int n;
	int d;
	setlocale(LC_ALL, "Russian");
	cout << "Выберите нужную функцию";
	cin >> n;
	cout << "Выберите число точек";
	cin >> d;

}
