#include <math.h>
#include <iostream>
#include <clocale>
#include <fstream>

double sign(double a)
{
	double r;
	if (a > 0)
		r = 1;
	if (a < 0)
		r = -1;
	if (a == 0)
		r = 0;
	return r;
} 

double quad(double a)
{
	double r;
	r = a;
	return r * r;
}
using namespace std;
class TFunction
{
	double a;
	double b;
	int num;
	double dot;
	double dotvalue[300];
	double funcvalue[300];
public:
	TFunction()
	{}
	void setFunction(int _num)
	{
		num = _num;
	}

	void setDots(int _dot)
	{
		dot = _dot;
	}

	double getDots()
	{
		return dot;
	}

	void setInter(double _a, double _b)
	{
		a = _a;
		b = _b;
	}

	double getInter1()
	{
		return a;
	}

	double getInter2()
	{
		return b;
	}

	void doSign(int _dot, double a, double b)
	{
		double temp = a;
		int i;
		for (i = 0; i < _dot; i++)
		{
			dotvalue[i] = temp;
			funcvalue[i] = sign(temp);
			temp = temp + ((b - a) / _dot);
		}
	}

	void doQuad(int _dot, double a, double b)
	{
		double temp = a;
		int i;
		for (i = 0; i < _dot; i++)
		{
			dotvalue[i] = temp;
			funcvalue[i] = quad(temp);
			temp = temp + ((b - a) / _dot);
		}
	}
	
	double getDot_value(int i)
	{
		return dotvalue[i];
	}
	double getFunc_value(int i)
	{
		return funcvalue[i];
	}
};


int main()
{
	TFunction func;
	ofstream out;
	double a, b;
	int n;
	int d;
	int i;
	setlocale(LC_ALL, "Russian");
	cout << "Выберите нужную функцию:\n1. Сигнум\n2. Квадрат\n3. Cохранить Сигнум в файл\n4. Сохранить Квадрат в файл\n";
	cin >> n;
	func.setFunction(n);
	cout << "Выберите число точек\n";
	cin >> d;
	func.setDots(d);
	cout << "Всего точек: " << func.getDots() << endl;
	cout << "Выберите отрезок, сначала введите верхнюю границу, потом нижнюю\n";
	cin >> a;
	cin >> b;
	func.setInter(a, b);
	cout << "Интервал: от " << func.getInter1() << " до " << func.getInter2() << endl;
	switch (n)
	{
		case 1:
			func.doSign(d, a, b);
			for (i = 0; i < d; i++)
				cout << "Значение в точке " << func.getDot_value(i) << " = " << func.getFunc_value(i) << endl;
			break;
		case 2:
			func.doQuad(d, a, b);
			for (i = 0; i < d; i++)
				cout << "Значение в точке " << func.getDot_value(i) << " = " << func.getFunc_value(i) << endl;
			break;
		case 3:
			func.doSign(d, a, b);
			out.open("out.txt");
			for (i = 0; i < d; i++)
				out << "Значение в точке " << func.getDot_value(i) << " = " << func.getFunc_value(i) << endl;
			break;
		case 4:
			func.doQuad(d, a, b);
			out.open("out.txt");
			for (i = 0; i < d; i++)
				out << "Значение в точке " << func.getDot_value(i) << " = " << func.getFunc_value(i) << endl;
			break;
	}
	system("pause");
	return 0;
}
