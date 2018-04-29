#include <vector>
#include <iostream>
#include <string>
#include <locale.h>
#include <time.h>
#include <cmath>

using namespace std;

class Bulls_n_Cows_Storage
{
private:
	vector<int> numbers;
	int bulls=0;
	double cows=0;
	int dont_forget_to_remove_later;
public:
	Bulls_n_Cows_Storage(int amount)
	{
		int st = pow(10, amount);
		srand(time(0));
		int temp = rand() % st + 1;
		dont_forget_to_remove_later = temp;
		do
		{
			numbers.push_back(temp % 10);
			temp = temp / 10;
		} while (temp != 0);
	}
	friend class Bulls_n_Cows;

	vector<int> GetNumbers()
	{
		return numbers;
	}

	void Amount_Of_Bulls_n_Cows(vector<int> number)
	{
		cows = 0;
		bulls = 0;
		for (int i = number.size() - 1; i >= 0; i--)
			if (numbers[i] == number[i])
				bulls++;
			else
			{
				for (int j = number.size() - 1; j >= 0; j--)
					for (int k = number.size() - 1; k >= 0; k--)
						if ((j != k) && (numbers[j] == number[k]))
							cows++;
			}
	}

	double GetCows_n_Bulls(int i)
	{
		switch (i)
		{
		case 1:
			return bulls;
		case 2:
			return cows;
		}
	}

	int Dont_Forget_To_Remove_Later()
	{
		return dont_forget_to_remove_later;
	}
};



void main()
{
	int amount;
	int number;
	int temp;
	vector<int> digits;
	setlocale(LC_ALL, "Russian");
	cout << "Введите количество цифр в числе:\n";
	cin >> amount;
	Bulls_n_Cows_Storage ex(amount);
	start:cout << "Введите число:\n";
	cin >> number;
	temp = number;
	digits.clear();
	cout << "Начальное число: " << ex.Dont_Forget_To_Remove_Later() << endl;
	do
	{
		digits.push_back(temp % 10);
		temp = temp / 10;
	} while (temp != 0);
	ex.Amount_Of_Bulls_n_Cows(digits);
	cout << "Число быков: " << ex.GetCows_n_Bulls(1) << endl << "Число коров: " << ex.GetCows_n_Bulls(2) << endl;
	if (ex.GetCows_n_Bulls(1) != amount)
		goto start;
	system("pause");
}