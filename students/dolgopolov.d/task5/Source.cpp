#include <iostream>
#include <vector>
#include <locale.h>
#include <fstream>
#include <string>

using namespace std;

struct ticket
{
	string date = "0";
	int train_number = 0;
	int carriage_number = 0;
	int place_number = 0;
	string user_data = "0";
	string department_station = "0";
	string arrival_station = "0";
};
struct passengers_data
{
	string date = "0";
	int train_type = 0; // 1 - Ласточка 2 - Фирменный 3 - Скорый
	int carriage_type = 0; // 4 - сидячий, 1 - плацкартный, 2 - купейный, 3 - СВ
	int place_number = 0;
	string user_data = "0";
};

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
	GorRailWay() :trainLastoch_place(101), trainFirm_place(119), trainScor_place(119), trainLastoch_carriage(8), trainFirm_carriage(12), trainScor_carriage(12), occupied_trainLastoch_place(101), occupied_trainFirm_place(119), occupied_trainScor_place(119) // lastoch_place - 1-100 сидячие, firm_place/scor_place - 1-27 плацкарт верхние, 28-54 плацкарт нижние, 55-72 - купе верхние, 73 - 100 - купе нижние, 101 - 118 - СВ
	{
		for (int i = 1; i < 101; i++)
		{
			trainLastoch_place[i] = "Свободно";
			occupied_trainLastoch_place[i] = false;
		}

		for (int i = 1; i < 119; i++)
		{
			trainFirm_place[i] = "Свободно";
			trainScor_place[i] = "Свободно";
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

	string GetPlaceStatus(int i, int place)
	{
		switch (i)
		{
		case 1:
			return obj.trainLastoch_place[place];
		case 2:
			return obj.trainFirm_place[place];
		case 3:
			return obj.trainScor_place[place];
		}
	}

	bool GetPlaceStatus1(int i, int place)
	{
		switch (i)
		{
		case 1:
			return obj.occupied_trainLastoch_place[place];
		case 2:
			return obj.occupied_trainFirm_place[place];
		case 3:
			return obj.occupied_trainScor_place[place];
		}
	}

	void SetPlace(int i)
	{
		switch (obj.train_type)
		{
		case 1:
			obj.trainLastoch_place[i] = "Занято";
			obj.occupied_trainLastoch_place[i] = true;
			break;
		case 2:
			obj.trainFirm_place[i] = "Занято";
			obj.occupied_trainFirm_place[i] = true;
			break;
		case 3:
			obj.trainScor_place[i] = "Занято";
			obj.occupied_trainScor_place[i] = true;
			break;
		}
	}
	
	vector<int> Checker(int i) 
	{
		vector <int> places;
		switch (i)
		{
		case 1:
			for (int j = 1; j < 101; j++)
				places.push_back(j);
			return places;
			break;
		case 2:
			for (int j = 1; j < 119; j++)
				places.push_back(j);
			return places;
			break;
		case 3:
			for (int j = 1; j < 119; j++)
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
			obj.trainLastoch_place[place] = "Занято";
			obj.occupied_trainLastoch_place[place] = true;
			break;
		case 2:
			obj.trainFirm_place[place] = "Занято";
			obj.occupied_trainFirm_place[place] = true;
			break;
		case 3:
			obj.trainScor_place[place] = "Занято";
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
	setlocale(LC_ALL, "Russian");
	RailWayStation ex;
	GorRailWay ex1;
	ticket t;
	passengers_data p;
	int i;
	int amount;
	int j;
	cout << "Введите дату поездки:\n";
	cin >> p.date;
	cout << "Введите нужный тип поезда:(1-Ласточка, 2-Фирменный, 3-Скорый)\n";
	cin >> p.train_type;
	switch (p.train_type)
	{
	case 1:
		cout << "Доступны только сидячие места\n";
		//p.carriage_type = 4;
		break;
	case 2:
		cout << "Доступны плацкартные вагоны, купейные и СВ\n";
		//cout << "Введите нужный тип вагона: (1 - плацкартные, 2 - купейные, 3 - СВ)\n";
		//cin >> p.carriage_type;
		break;
	case 3:
		cout << "Доступны плацкартные вагоны, купейные и СВ\n";
		//cout << "Введите нужный тип вагона: (1 - плацкартные, 2 - купейные, 3 - СВ)\n";
		//cin >> p.carriage_type;
		break;
	}
	cout << "Введите количество билетов:\n";
	cin >> amount;
	cout << "Введите ФИО:\n";
	cin >> p.user_data;
	in:cout << "1. Проверка свободных мест\n2. Создать заказ\n3. Рассчитать стоимость билетов\n4. Отменить заказ\n5. Сформировать билеты\n0. Выход\n";
	cin >> i;
	switch (i)
	{
	case 1:
		cout << "Выберите тип поезда:\n";
		cin >> j;
		for (i = 0; i < ex.Checker(j).size(); i++)
			cout << "Место " << ex.Checker(j)[i] << " - " << ex.GetPlaceStatus(j, i+1) << endl;
		goto in;
		break;
	case 2:
		cout << "Выберите тип поезда:\n";
		cin >> j;
		switch (j)
		{
		case 1:
			cout << "Введите номер места:(1-100 сидячие)\n";
			break;
		case 2:
			cout << "Введите номер места: (1-27 плацкарт верхние, 28-54 плацкарт нижние, 55-72 - купе верхние, 73 - 100 - купе нижние, 101 - 118 - СВ)\n";
			break;
		case 3:
			cout << "Введите номер места: (1-27 плацкарт верхние, 28-54 плацкарт нижние, 55-72 - купе верхние, 73 - 100 - купе нижние, 101 - 118 - СВ)\n";
			break;
		}
		cin >> p.place_number;
		if (ex.GetPlaceStatus1(j, p.place_number) == true)
		{
			cout << "Это место уже занято\n";
			goto in;
			break;
		}
		ex.ReservePlace(j, p.place_number);
		goto in;
		break;
	case 4:
		cout << "Выберите тип поезда:\n";
		cin >> j;
		cout << "Введите номер места:\n";
		cin >> p.place_number;
		ex.CancelOrder(j, p.place_number);
		goto in;
		break;
	case 0:
		break;

	}
	system("pause");
}