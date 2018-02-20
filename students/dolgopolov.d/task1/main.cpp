#include <iostream>

using namespace std;
	class TTemperature
	{
		float tC;
		float tF;
		float tK;
	public:
		TTemperature(float tC1, float tF1, float tK1) : tC(tC1), tF(tF1), tK(tK1)
		{
			cout << "Insert temperature in Celsius\n";
			cin >> tC;
			tF = tC * 9 / 5 + 32;
			tK = tC + 273;
		}
		float get_tC()
		{
			return tC;
		}
		float get_tF()
		{
			return tF;
		}
		float get_tK()
		{
			return tK;
		}
	};
	int main()
	{
		TTemperature temp;
		cout << "Temperature in C" << temp.get_tC() << endl;
		cout << "Temperature in F" << temp.get_tF() << endl;
		cout << "Temperature in K" << temp.get_tK() << endl;
		system("pause");
		return 0;
	}