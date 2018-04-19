#include <iostream>
#include <vector>
#include <locale.h>
#include <fstream>
#include <string>

using namespace std;

class GorRailWay 
{
protected:
	int train_type;
	int carriage_type;
	vector <string> trainLastoch_place;
	vector <string> trainFirm_place;
	vector <string> trainScor_place;
	vector <int> trainLastoch_carriage;
	vector <int> trainFirm_carriage;
	vector <int> trainScor_carriage;
	vector <bool> occupied_trainLastoch_place;
	vector <bool> occupied_trainFirm_place;
	vector <bool> occupied_trainScor_place;
public:
	GorRailWay() :trainLastoch_place(100), trainFirm_place(108), trainScor_place(108), trainLastoch_carriage(8), trainFirm_carriage(12), trainScor_carriage(12), occupied_trainLastoch_place(100), occupied_trainFirm_place(108), occupied_trainScor_place(108) // lastoch_place - 0-99 сидячие, firm_place/scor_place - 0-26 плацкарт верхние, 27-53 плацкарт нижние, 54-71 - купе верхние, 72 - 99 - купе нижние, 100 - 117 - СВ
	{
		for (int i = 0; i < 108; i++)
		{
			occupied_trainLastoch_place[i] = false;
			occupied_trainFirm_place[i] = false;
			occupied_trainScor_place[i] = false;
		}
	}
	friend class RailWayStation;
};

class RailWayStation
{
	GorRailWay obj;
public:
	RailWayStation()
	{}

	void SetTrain(int i) // 1 - Ласточка, 2 - фирменный, 3 - скорый
	{
		obj.train_type = i;
	}

	void SetCarriage(int i)
	{
		obj.carriage_type = i;
	}

	void SetPlace(int i)
	{
		switch (obj.train_type)
		{
		case 1:
			obj.occupied_trainLastoch_place[i] = true;
			break;
		case 2:
			obj.occupied_trainFirm_place[i] = true;
			break;
		case 3:
			obj.occupied_trainScor_place[i] = true;
			break;
		}
	}
	void SetPassengersData(int i, string s)
	{
		switch (obj.train_type)
		{
		case 1:
			obj.trainLastoch_place[i] = s;
			break;
		case 2:
			obj.trainFirm_place[i] = s;
			break;
		case 3:
			obj.trainScor_place[i] = s;
			break;
		}
	}
	vector<int> Checker(int i) // метод, возвращающий вектор номеров свободных мест
	{
		vector <int> places(108);
		switch (obj.train_type)
		{
		case 1:
			for (int j = 0; j < 100; j++)
				if (obj.occupied_trainLastoch_place[j] == false)
					places.push_back(j);
			return places;
			break;
		case 2:
			for (int j = 0; j < 108; j++)
				if (obj.occupied_trainFirm_place[j] == false)
					places.push_back(j);
			return places;
			break;
		case 3:
			for (int j = 0; j < 108; j++)
				if (obj.occupied_trainScor_place[j] == false)
					places.push_back(j);
			return places;
			break;
		}
	}
	void ReservePlace(int i, int place)
	{
		switch (i)
		{
		case 1:
			obj.occupied_trainLastoch_place[place] = true;
			break;
		case 2:
			obj.occupied_trainFirm_place[place] = true;
			break;
		case 3:
			obj.occupied_trainScor_place[place] = true;
			break;
		}
	}
	void CancelOrder(int i, int place)
	{
		switch (i)
		{
		case 1:
			obj.trainLastoch_place[place] = "Свободно";
			obj.occupied_trainLastoch_place[place] = false;
			break;
		case 2:
			obj.trainFirm_place[place] = "Свободно";
			obj.occupied_trainFirm_place[place] = false;
			break;
		case 3:
			obj.trainScor_place[place] = "Свободно";
			obj.occupied_trainScor_place[place] = false;
			break;
		}
	}
};

void main()
{

}