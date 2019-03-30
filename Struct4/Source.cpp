#include "Shedule.h"
#include "DateTime.h"
#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <ostream>
#include <iomanip>
#include <ctime>
#include <string>
#include <fstream>
#include <cstdio>

using namespace std;
struct Goods
{
	char *Name;
	char *Producting_country;
	int Year;
	int Month;
	int Day;
	int Count;
	float Cost;
	
};

void Add_Goods(Goods *&mas, int &n)
{
	if (n == 0)
	{
		mas = new Goods[n + 1]; // выделение памяти для первой структуры
	}
	else
	{
		Goods* tmp = new Goods[n + 1];

		for (int i = 0; i < n; i++)
		{
			tmp[i] = mas[i]; // копируем во временный объект
		}
		delete[] mas;

		mas = tmp;
	}
	cout << "Введите название товара: ";
	char name[30];
	cin >> name;

	cout << "Введите страну-производителя: ";
	char prodCountry[30];
	cin >> prodCountry;

	cout << "Введите количество товара на складе: ";
	int count;
	cin >> count;

	cout << "Введите год истечения срока товара: ";
	int year;
	cin >> year;

	cout << "Введите месяц истечения срока товара: ";
	int month;
	cin >> month;

	cout << "Введите день истечения срока товара: ";
	int day;
	cin >> day;

	cout << "Введите цену товара: ";
	float cost;
	cin >> cost;

	mas[n].Name = name;
	mas[n].Producting_country = prodCountry;
	mas[n].Year = year;
	mas[n].Month = month;
	mas[n].Day = day;
	mas[n].Count = count;
	mas[n].Cost = cost;
	//return Obj;
	ofstream out;
	out.open("save.txt", ios::app);
	if (out.is_open())
	{
		out << mas[n].Name << "/" << mas[n].Producting_country << "/" << mas[n].Count << "/" << mas[n].Cost
			<< "/" << mas[n].Day << "/" << mas[n].Month << "/" << mas[n].Year << "/" << "\n";
	}
	out.close();
	n++;
}
void Show(Goods tmp)
{
	cout << "Название товара: " << tmp.Name << "\n" << "Страна-производитель: " << tmp.Producting_country << "\n" << "Истечение срока: " << tmp.Year << "." << tmp.Month << "." << tmp.Day << "\n" << "Количество товара на складе: " << tmp.Count << "\n" << "Стоимость товара: " << tmp.Cost << "\n";
}
void Print(Goods *mas, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "Товар №" << i + 1 << "\n========================================\n";
		Show(mas[i]);
		cout << "========================================\n\n";
	}
}
void Del(Goods *& mas, int &n, char *Name)
{
	int k = 0;
	for (int i = 0; i < n; i++)
	{
		while (i < n && stricmp(mas[i].Name, Name) == 0)
		{
			k = 1;
			for (int j = i; j < n - 1; j++)
			{
				mas[j] = mas[j + 1];
			}
			mas = (Goods*)realloc(mas, (n - 1) * sizeof(Goods));
			n--;
		}
	}
	if (k == 0)
	{
		cout << "Нет совпадений.\n";
	}
	else
	{
		cout << "Удаление произошло.\n";
	}
}
void FindByProductingCountry(Goods *mas, int n, char *prodCountry)
{
	bool f = 0;
	for (int i = 0; i < n; i++)
	{
		if (stricmp(mas[i].Producting_country, prodCountry) == 0)
		{
			f = 1;
			Show(mas[i]);
		}
	}
	if (f == 0)
	{
		cout << "Нет совпадений.\n";
	}
}
void FindByName(Goods *mas, int n, char *Name)
{
	bool f = 0;
	for (int i = 0; i < n; i++)
	{
		if (stricmp(mas[i].Name, Name) == 0)
		{
			f = 1;
			Show(mas[i]);
		}
	}
	if (f == 0)
	{
		cout << "Нет совпадений.\n";
	}
}
void SortByName(Goods *mas, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n - 1; j++)
		{
			if (stricmp(mas[j].Name, mas[j + 1].Name) < 0)
			{
				Goods tmp = mas[j];
				mas[j] = mas[j + 1];
				mas[j + 1] = tmp;
			}
		}
	}
}
void SortByProductingCountry(Goods *mas, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n - 1; j++)
		{
			if (stricmp(mas[j].Producting_country, mas[j + 1].Producting_country) < 0)
			{
				Goods tmp = mas[j];
				mas[j] = mas[j + 1];
				mas[j + 1] = tmp;
			}
		}
	}
}
void Explode(string delimiter, string str, Shedule<string> &arr)
{
	string tmp = "";
	size_t prev = 0;
	size_t next;
	size_t delta = delimiter.length();

	while ((next = str.find("/", prev)) != string::npos) {
		tmp = str.substr(prev, next - prev);

		if (tmp != "")
		{
			arr.push_back(tmp);
			prev = next + delta;
		}
		else
			prev = next + delta;

	}
}
void Load_Goods(Goods *&mas, int &n, Shedule<string> list)
{
	mas = new Goods[n];
	int index = 0;

	for (int i = 0; i < n; i++)
	{	
		char charName[50];
		strcpy(charName, list[index].c_str());

		mas[i].Name = charName;
		index++;

		char charProd[50];
		strcpy(charProd, list[index].c_str());

		mas[i].Producting_country = charName;
		index++;

		mas[i].Count = stoi(list[index]);
		index++;

		mas[i].Cost = stoi(list[index]);
		index++;

		mas[i].Day = stoi(list[index]);
		index++;

		mas[i].Month = stoi(list[index]);
		index++;

		mas[i].Year = stoi(list[index]);
		index++;
	}
}

void main()
{
	setlocale(LC_ALL, "rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	char ch;
	int n = 0;
	Goods *Catalog = NULL;
	string line = "";
	Shedule<string> list;

	if (ifstream("save.txt"))
	{
		try
		{
			ifstream in("save.txt");
			if (in.is_open())
			{
				string tmp_line = "";
				while (getline(in, tmp_line))
				{
					cout << tmp_line << "\n";
					line += tmp_line;
				}
			}
			in.close();
			Explode("/", line, list);
			n = list.GetLength() / 7;
			Load_Goods(Catalog, n, list);

		}
		catch (const std::exception& ex)
		{
			cout << ex.what() << "\n";
			system("pause");
		}


	}

	char str[20];
	do
	{
		system("cls");
		cout << "МЕНЮ:\n\n";
		cout << "1 - Добавить товар.\n";
		cout << "2 - Вывод товаров на экран.\n";
		cout << "3 - Поиск товара по стране-производителю.\n";
		cout << "4 - Поиск товара по названию.\n";
		cout << "5 - Сортировка товаров по названию.\n";
		cout << "6 - Сортировка товаров по стране-производителю.\n";
		
		cout << "Esc - Выход.\n\n";
		cout << "Ваш выбор: ";
		ch = getch();
		switch (ch)
		{
		case '1':
			system("cls");
			Add_Goods(Catalog, n);
			cout << "Товар добавлен.\n";
			Sleep(1000);
			break;
		case '2':
			system("cls");
			if (n != 0)
			{
				//Catalog[0].Name;
				Print(Catalog, n);
				system("pause");
			}
			else
			{
				cout << "Каталог пуст.\n";
				Sleep(1000);
			}
			break;
		case '3':
			system("cls");
			if (n != 0)
			{
				cout << "Введите фамилию автора: ";
				gets_s(str);
				FindByProductingCountry(Catalog, n, str);
			}
			else
			{
				cout << "Каталог пуст.\n";
			}
			system("pause");
			break;
		case '4':
			system("cls");
			if (n != 0)
			{
				cout << "Введите название книги: ";
				gets_s(str);
				FindByName(Catalog, n, str);
			}
			else
			{
				cout << "Каталог пуст.\n";
			}
			system("pause");
			break;
		case '5':
			system("cls");
			if (n != 0)
			{
				SortByName(Catalog, n);
				cout << "Сортировка произведена.\n";
				Print(Catalog, n);
				system("pause");
				break;
			}
			else
			{
				cout << "Каталог пуст.\n";
			}
			Sleep(1000);
			break;
		case '6':
			system("cls");
			if (n != 0)
			{
				SortByProductingCountry(Catalog, n);
				cout << "Сортировка произведена.\n";
				Print(Catalog, n);
				system("pause");
				break;
			}
			else
			{
				cout << "Каталог пуст.\n";
			}
			Sleep(1000);
			break;
		
		}
	} while (ch != 27);
}