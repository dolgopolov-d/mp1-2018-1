#include <vector>
#include <iostream>
#include <string>
#include <locale.h>
#include <time.h>
#include <cmath>

using namespace std;

class Bulls_n_Cows
{
private:
	vector<int> numbers;
	int bulls=0;
	int cows=0;
	int dont_forget_to_remove_later;
public:
	Bulls_n_Cows(int amount)
	{
		int st = pow(10, amount);
		srand(time(0));
		int temp = (rand()*9) % st;
		dont_forget_to_remove_later = temp;
		do
		{
			numbers.push_back(temp % 10);
			temp = temp / 10;
		} while (temp != 0);
	}

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
					for (int k = number.size() - 1; k >= 0; k--)
						if ((i != k) && (numbers[i] == number[k]))
							cows++;
			}
	}

	int GetCows_n_Bulls(int i)
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
l:cout << "Введите количество цифр в числе:\n";
	cin >> amount;
k:if (amount <= 0)
	{
		cout << "Неверный ввод\n";
		goto l;
	}
	Bulls_n_Cows ex(amount);
	if (ex.GetNumbers().size() < amount)
		goto k;
	for (int i = ex.GetNumbers().size() - 1; i >= 0; i--)
		for (int j = 0; j < i; j++)
			if (ex.GetNumbers()[i] == ex.GetNumbers()[j])
				goto k;
start:cout << "Введите число:(без одинаковых цифр)\n";
	cin >> number;
	temp = number;
	digits.clear();
	cout << "Начальное число: " << ex.Dont_Forget_To_Remove_Later() << endl;
	do
	{
		digits.push_back(temp % 10);
		temp = temp / 10;
	} while (temp != 0);
	if (digits.size() != amount)
	{
		cout << "Неверный ввод\n";
		goto start;
	}
	for (int i = 0; i < digits.size(); i++)
		for (int j = 0; j < i; j++)
			if (digits[i] == digits[j])
			{
				cout << "Неверный ввод\n";
				goto start;
			}
	ex.Amount_Of_Bulls_n_Cows(digits);
	cout << "Число быков: " << ex.GetCows_n_Bulls(1) << endl << "Число коров: " << ex.GetCows_n_Bulls(2) << endl;
	if (ex.GetCows_n_Bulls(1) != amount)
		goto start;
	system("pause");
}