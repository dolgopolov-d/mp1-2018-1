#include <iostream>
#include <vector>
#include <locale.h>
#include <fstream>
#include <string>
#define l_place_cost 900
#define f_place_plac_cost 1200 
#define f_place_comp_cost 1900
#define f_place_SV_cost 2700
#define s_place_plac_cost 1500 
#define s_place_comp_cost 2300
#define s_place_SV_cost 3000

using namespace std;

struct ticket
{
	string date = "0";
	int train_number = 0;
	int carriage_number = 0;
	int place_number = 0;
	string user_data = "0";
	string departure_station = "0";
	string arrival_station = "0";
}t;
struct passengers_data
{
	string date = "0";
	int train_type = 0; // 1 - Ласточка 2 - Фирменный 3 - Скорый
	int l_place_amount = 0;
	int f_plac_place_amount = 0;
	int f_comp_place_amount = 0;
	int f_SV_place_amount = 0;
	int s_plac_place_amount = 0;
	int s_comp_place_amount = 0;
	int s_SV_place_amount = 0;
	string user_data = "0";
}p;

class GorRailWay 
{
protected:
	vector <string> trainLastoch_place;
	vector <string> trainFirm_place;
	vector <string> trainScor_place;
	vector <bool> occupied_trainLastoch_place;
	vector <bool> occupied_trainFirm_place;
	vector <bool> occupied_trainScor_place;
	vector <bool> is_in_order_trainLastoch_place;
	vector <bool> is_in_order_trainFirm_place;
	vector <bool> is_in_order_trainScor_place;
public:
	GorRailWay() :trainLastoch_place(101), trainFirm_place(109), trainScor_place(109), occupied_trainLastoch_place(101), occupied_trainFirm_place(109), occupied_trainScor_place(109), is_in_order_trainLastoch_place(101), is_in_order_trainFirm_place(109), is_in_order_trainScor_place(109) // lastoch_place - 1-100 сидячие, firm_place/scor_place - 1-27 плацкарт верхние, 28-54 плацкарт нижние, 55-72 - купе верхние, 73 - 90 - купе нижние, 91 - 108 - СВ
	{
		for (int i = 1; i < 101; i++)
		{
			trainLastoch_place[i] = "Свободно";
			occupied_trainLastoch_place[i] = false;
			is_in_order_trainLastoch_place[i] = false;
		}

		for (int i = 1; i < 109; i++)
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
	void SetPassengersData(string _date, int _train_type, int l_place_amount, int f_plac_place_amount, int f_comp_place_amount, int f_SV_place_amount, int s_plac_place_amount, int s_comp_place_amount, int s_SV_place_amount, string _user_data)
	{
		p.date = _date;
		p.train_type = _train_type;
		p.l_place_amount = l_place_amount;
		p.f_plac_place_amount = f_plac_place_amount;
		p.f_comp_place_amount = f_comp_place_amount;
		p.f_SV_place_amount = f_SV_place_amount;
		p.s_plac_place_amount = s_plac_place_amount;
		p.s_comp_place_amount = s_comp_place_amount;
		p.s_SV_place_amount = s_SV_place_amount;
		p.user_data = _user_data;
	}

	void SetTicketsData(string _date, int _train_number, int _carriage_number, string _user_data)
	{
		t.date = _date;
		t.train_number = _train_number;
		t.carriage_number = _carriage_number;
		t.user_data = _user_data;
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

	bool IsInOrder(int i, int place)
	{
		switch (i)
		{
		case 1:
			return obj.is_in_order_trainLastoch_place[place];
		case 2:
			return obj.is_in_order_trainFirm_place[place];
		case 3:
			return obj.is_in_order_trainScor_place[place];
		}
	}

	void SetPlace(int i, int place)
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
	
	vector<int> Places(int i) 
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
			for (int j = 1; j < 109; j++)
				places.push_back(j);
			return places;
			break;
		case 3:
			for (int j = 1; j < 109; j++)
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
			obj.is_in_order_trainLastoch_place[place] = true;
			break;
		case 2:
			obj.trainFirm_place[place] = "Занято";
			obj.occupied_trainFirm_place[place] = true;
			obj.is_in_order_trainFirm_place[place] = true;
			break;
		case 3:
			obj.trainScor_place[place] = "Занято";
			obj.occupied_trainScor_place[place] = true;
			obj.is_in_order_trainScor_place[place] = true;
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
			obj.is_in_order_trainLastoch_place[place] = false;
			break;
		case 2:
			obj.trainFirm_place[place] = "Свободно";
			obj.occupied_trainFirm_place[place] = false;
			obj.is_in_order_trainFirm_place[place] = false;
			break;
		case 3:
			obj.trainScor_place[place] = "Свободно";
			obj.occupied_trainScor_place[place] = false;
			obj.is_in_order_trainScor_place[place] = false;
			break;
		}
	}
};

void main()
{
	setlocale(LC_ALL, "Russian");
	RailWayStation ex;
	GorRailWay ex1;
	string date, user_data;
	vector<int> k1, k2, k3;
	int i;
	int place;
	int train_type;
	int count = 0;
	int count_l = 0, count_f_plac = 0, count_f_comp = 0, count_f_SV = 0, count_s_plac = 0, count_s_comp = 0, count_s_SV = 0;
	int temp_count_l = 0, temp_count_f_plac = 0, temp_count_f_comp = 0, temp_count_f_SV = 0, temp_count_s_plac = 0, temp_count_s_comp = 0, temp_count_s_SV = 0;
	cout << "Введите дату поездки:\n";
	cin >> date;
	cout << "Введите ФИО:\n";
	cin >> user_data;
	on:cout << "Выберите тип поезда:\n";
	cin >> train_type;
	in:cout << "1. Проверка свободных мест\n2. Создать заказ(Резервирование)\n3. Рассчитать стоимость билетов\n4. Отменить заказ\n5. Сформировать билеты\n6. Выбрать другой поезд\n0. Выход\n";
	cin >> i;
	switch (i)
	{
	case 1:
		for (i = 0; i < ex.Places(train_type).size(); i++)
			cout << "Место " << ex.Places(train_type)[i] << " - " << ex.GetPlaceStatus(train_type, i+1) << endl;
		goto in;
		break;
	case 2:
		switch (train_type)
		{
		case 1:
			cout << "Введите номер места:(1-100 сидячие)\n";
			break;
		case 2:
			cout << "Введите номер места: (1-27 плацкарт верхние, 28-54 плацкарт нижние, 55-72 - купе верхние, 73 - 90 - купе нижние, 91 - 108 - СВ)\n";
			break;
		case 3:
			cout << "Введите номер места: (1-27 плацкарт верхние, 28-54 плацкарт нижние, 55-72 - купе верхние, 73 - 90 - купе нижние, 91 - 108 - СВ)\n";
			break;
		}
		cin >> place;
		if (ex.GetPlaceStatus1(train_type, place) == true)
		{
			cout << "Это место уже занято\n";
			goto in;
			break;
		}
		ex.ReservePlace(train_type, place);
		goto in;
		break;
	case 3:
		for (i = 1; i < 101; i++)
			if (ex.IsInOrder(1, i) == true)
			{
				count_l++;
				k1.push_back(i);
			}
		for (i = 1; i<109; i++)
			if (ex.IsInOrder(2, i) == true)
			{
				if ((1 <= i) && (i <= 54))
					count_f_plac++;
				else
					if ((55 <= i) && (i <= 90))
						count_f_comp++;
					else
						if ((91 <= i) && (i <= 108))
							count_f_SV++;
				k2.push_back(i);
			}
		for (i = 1; i<109; i++)
			if (ex.IsInOrder(3, i) == true)
			{
				if ((1 <= i) && (i <= 54))
					count_s_plac++;
				else
					if ((55 <= i) && (i <= 90))
						count_s_comp++;
					else
						if ((91 <= i) && (i <= 108))
							count_s_SV++;
				k3.push_back(i);
			}
		count = count_l + count_f_plac + count_f_comp + count_f_SV + count_s_plac + count_s_comp + count_s_SV;
		cout << count << " билета(-ов) в заказе \n\n";
		cout << "В Ласточке заказаны место(-а): \n";
		for (i = 0; i < k1.size(); i++)
			cout << k1[i] << "  ";
		cout << endl;
		cout << "В Фирменном заказаны место(-а): \n";
		for (i = 0; i < k2.size(); i++)
			cout << k2[i] << "  ";
		cout << endl;
		cout << "В Скором заказаны место(-а): \n";
		for (i = 0; i < k3.size(); i++)
			cout << k3[i] << "  ";
		cout << endl;
		cout << "Стоимость билетов: \n";
		cout << count_l * l_place_cost << " сидячие в Ласточке\n";
		k1.clear();
		cout << count_f_plac * f_place_plac_cost << " плацкарт в Фирменном\n";
		cout << count_f_comp * f_place_comp_cost << " купе в Фирменном\n";
		cout << count_f_SV * f_place_SV_cost << " СВ в Фирменном\n";
		k2.clear();
		cout << count_s_plac * s_place_plac_cost << " плацкарт в Скором\n";
		cout << count_s_comp * s_place_comp_cost << " купе в Скором\n";
		cout << count_s_SV * s_place_SV_cost << " СВ в Скором\n";
		k3.clear();
		cout << "Общая стоимость: \n" << count_l * l_place_cost + count_f_plac * f_place_plac_cost + count_f_comp * f_place_comp_cost + count_f_SV * f_place_SV_cost + count_s_plac * s_place_plac_cost + count_s_comp * s_place_comp_cost + count_s_SV * s_place_SV_cost << endl;
		temp_count_l = count_l;
		temp_count_f_plac = count_f_plac;
		temp_count_f_comp = count_f_comp;
		temp_count_f_SV = count_f_SV;
		temp_count_s_plac = count_s_plac;
		temp_count_s_comp = count_s_comp;
		temp_count_s_SV = count_s_SV;
		count_l = 0;
		count_f_plac = 0;
		count_f_comp = 0;
		count_f_SV = 0;
		count_s_plac = 0;
		count_s_comp = 0;
		count_s_SV = 0;
		count = 0;
		goto in;
		break;
	case 4:
		cout << "Введите номер места:\n";
		cin >> place;
		if (ex.IsInOrder(train_type, place) == false)
		{
			cout << "Это не ваш заказ\n";
			goto in;
			break;
		}
		ex.CancelOrder(train_type, place);
		goto in;
		break;
	case 5:
		switch (train_type)
		{
		case 1:
			ex.SetTicketsData(date, rand() % 100, rand() % 12, user_data);
		case 2:
			ex.SetTicketsData(date, rand() % 100, rand() % 12, user_data);
		case 3:
			ex.SetTicketsData(date, rand() % 100, rand() % 12, user_data);
		}
	case 8:
		switch (train_type)
		{
		case 1:
			ex.SetPassengersData(date, 1, temp_count_l, temp_count_f_plac, temp_count_f_comp, temp_count_f_SV, temp_count_s_plac, temp_count_s_comp, temp_count_s_SV, user_data);
		case 2:
			ex.SetPassengersData(date, 2, temp_count_l, temp_count_f_plac, temp_count_f_comp, temp_count_f_SV, temp_count_s_plac, temp_count_s_comp, temp_count_s_SV, user_data);
		case 3:
			ex.SetPassengersData(date, 3, temp_count_l, temp_count_f_plac, temp_count_f_comp, temp_count_f_SV, temp_count_s_plac, temp_count_s_comp, temp_count_s_SV, user_data);
		}
	case 6:
		goto on;
	case 0:
		break;

	}
	system("pause");
}