#include <iostream>

using namespace std;
	class TTemperature
	{
		double tC;
	public:
		TTemperature(double t) :tC(t)
		{
			
			
			
			
		}
		TTemperature &operator=(double _tC)
		{
			tC = _tC;
			return *this;
		}
		TTemperature &operator=(const TTemperature &temper)
		{
			tC = temper.tC;
			return *this;
		}
		double get_tC()
		{
			return tC;
		}
		double get_tF()
		{
			double tF;
			tF = tC * 9 / 5 + 32;
			return tF;
		}
		double get_tK()
		{
			double tK;
			tK = tC + 273;
			return tK;
		}
		double get_tRe()
		{
			double tRe;
			tRe = tC * 0.8;
			return tRe;
		}
		double get_tR()
		{
			double tR;
			tR = tC * 493.47;
			return tR;
		}
	};
	int main()
	{
		double t;
		cout << "Enter temperature in Celsius\n";
		cin >> t;
		TTemperature temp(t);
		TTemperature temp1(15);
		cout << "Temperature in Celsius " << temp.get_tC() << endl;
		cout << "Temperature in Fahrenheit " << temp.get_tF() << endl;
		cout << "Temperature in Kelvin " << temp.get_tK() << endl;
		cout << "Temperature in Remyure " << temp.get_tRe() << endl;
		cout << "Temperature in Rankin " << temp.get_tR() << endl;
		temp = 5;
		cout << endl;
		cout << "Temperature in Celsius " << temp.get_tC() << endl;
		cout << "Temperature in Fahrenheit " << temp.get_tF() << endl;
		cout << "Temperature in Kelvin " << temp.get_tK() << endl;
		cout << "Temperature in Remyure " << temp.get_tRe() << endl;
		cout << "Temperature in Rankin " << temp.get_tR() << endl;
		temp = temp1;
		cout << endl;
		cout << "Temperature in Celsius " << temp.get_tC() << endl;
		cout << "Temperature in Fahrenheit " << temp.get_tF() << endl;
		cout << "Temperature in Kelvin " << temp.get_tK() << endl;
		cout << "Temperature in Remyure " << temp.get_tRe() << endl;
		cout << "Temperature in Rankin " << temp.get_tR() << endl;
		system("pause");
		return 0;
	}