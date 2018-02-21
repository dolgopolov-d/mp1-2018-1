#include <iostream>

using namespace std;
	class TTemperature
	{
		double tC;
		double tF;
		double tK;
		double tRe;
		double tR;
	public:
		TTemperature(double t) :tC(t)
		{
			tF = tC * 9 / 5 + 32;
			tK = tC + 273;
			tRe = tC * 0.8;
			tR = tC * 493.47;
		}
		TTemperature &operator=(double _tC)
		{
			tC = _tC;
			return *this;
		}
		double get_tC()
		{
			return tC;
		}
		double get_tF()
		{
			return tF;
		}
		double get_tK()
		{
			return tK;
		}
		double get_tRe()
		{
			return tRe;
		}
		double get_tR()
		{
			return tR;
		}
	};
	int main()
	{
		double t;
		cout << "Insert temperature in Celsius\n";
		cin >> t;
		TTemperature temp(t);
		cout << "Temperature in Celsius " << temp.get_tC() << endl;
		cout << "Temperature in Fahrenheit " << temp.get_tF() << endl;
		cout << "Temperature in Kelvin " << temp.get_tK() << endl;
		cout << "Temperature in Remyure " << temp.get_tRe() << endl;
		cout << "Temperature in Rankin " << temp.get_tR() << endl;
		system("pause");
		return 0;
	}