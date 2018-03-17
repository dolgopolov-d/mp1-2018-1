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
	int getFunc()
	{
		return num;
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

	void doSign()
	{
		double temp = getInter1();
		int i;
		for (i = 0; i < getDots(); i++)
		{
			dotvalue[i] = temp;
			funcvalue[i] = sign(temp);
			temp = temp + ((getInter2() - getInter1()) / getDots());
		}
	}

	void doQuad()
	{
		double temp = getInter1();
		int i;
		for (i = 0; i < getDots(); i++)
		{
			dotvalue[i] = temp;
			funcvalue[i] = quad(temp);
			temp = temp + ((getInter2() - getInter1()) / getDots());
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
	cout << "�������� ������ �������:\n1. ������\n2. �������\n3. C�������� ������ � ����\n4. ��������� ������� � ����\n";
	cin >> n;
	func.setFunction(n);
	cout << "�������� ����� �����\n";
	cin >> d;
	func.setDots(d);
	cout << "����� �����: " << func.getDots() << endl;
	cout << "�������� �������, ������� ������� ������� �������, ����� ������\n";
	cin >> a;
	cin >> b;
	func.setInter(a, b);
	cout << "��������: �� " << func.getInter1() << " �� " << func.getInter2() << endl;
	switch (func.getFunc())
	{
		case 1:
			func.doSign();
			for (i = 0; i < d; i++)
				cout << "�������� � ����� " << func.getDot_value(i) << " = " << func.getFunc_value(i) << endl;
			break;
		case 2:
			func.doQuad();
			for (i = 0; i < d; i++)
				cout << "�������� � ����� " << func.getDot_value(i) << " = " << func.getFunc_value(i) << endl;
			break;
		case 3:
			func.doSign();
			out.open("out.txt");
			for (i = 0; i < d; i++)
				out << "�������� � ����� " << func.getDot_value(i) << " = " << func.getFunc_value(i) << endl;
			break;
		case 4:
			func.doQuad();
			out.open("out.txt");
			for (i = 0; i < d; i++)
				out << "�������� � ����� " << func.getDot_value(i) << " = " << func.getFunc_value(i) << endl;
			break;
	}
	system("pause");
	return 0;
}
