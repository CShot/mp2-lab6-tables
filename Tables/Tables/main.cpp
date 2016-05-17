#include <stdio.h>
#include <tchar.h>
#include "ScanTable.h"
#include "HashTable.h"
#include "TreeTable.h"
#include "Math.h"
#include "stdlib.h"
#include "time.h"

using namespace std;

int main()
{
	srand((unsigned)time(NULL));
	int number = 0;
	while (number != 7)
	{

		setlocale(LC_ALL, "Russian");
	C1:
		system("cls");
		cout << "Меню:\n\n";

		cout << "1. Просматреваемая таблица\n";
		cout << "2. Хеш-таблица\n";
		cout << "3. Дерево\n";

		cout << "\n0. Выход\n" << endl;

		cin >> number;

		switch (number)
		{
		case 1:
		{
			TScanTable A(1000);
			TRecord rec;
			A.Read("Text.txt");
			system("cls");
			A.Print();
			cout << endl;
			int numer = 0;
			cout << "Таблица:" << endl << endl;
		C2:

			cout << "1. Вставить слово\n";
			cout << "2. Удалить слово\n";
			cout << "3. Поиск \n";
			cout << "4. Выход" << endl;
			cin >> numer;
			string str;

			if (numer == 1)
			{
				cout << "Вставка " << endl << "Введите слово:" << endl;
				cin >> str;
				cout << endl;
				rec.key = str;
				rec.val = 1;
				if (rec.key != "!")
				{
					A.Insert(rec);
					A.Print();
				}
				goto C2;
			}

			str = "";
			if (numer == 2)
			{
				cout << "Удаление " << endl << "Введите слово:" << endl;
				cin >> str;
				cout << endl;
				rec.key = str;
				rec.val = 1;
				A.Delete(rec.key);
				A.Print();
				goto C2;
			}

			if (numer == 3)
			{
				cout << "Поиск " << endl << "Введите слово:" << endl;
				cin >> str;
				cout << endl;
				rec.key = str;
				rec.val = 1;
				int j = 0;
				A.Findelem(rec.key);
				goto C2;

			}
			if (numer == 4)
			{
				system("cls");
				goto C1;
			}
			cout << endl;
			break;
		}

		case 2:
		{
			TScanTable C(1000);
			TRecord rec;
			C.Read("Text.txt");
			system("cls");
			cout << "Хеш-таблица:" << endl << endl;
			C.Print();
			cout << endl;
			int numer = 0;
			cout << "Таблица:" << endl << endl;
		C3:
			cout << "1. Вставить слово\n";
			cout << "2. Удалить слово\n";
			cout << "3. Поиск\n";
			cout << "4. Выход" << endl;
			cin >> numer;
			string str;

			if (numer == 1)
			{
				cout << "Вставка " << endl << "Введите слово:" << endl;
				cin >> str;
				cout << endl;
				rec.key = str;
				rec.val = 1;
				C.Insert(rec);
				C.Print();
				goto C3;
			}

			str = "";
			if (numer == 2)
			{
				cout << "Удаление " << endl << "Введите слово:" << endl;
				cin >> str;
				cout << endl;
				rec.key = str;
				rec.val = 1;
				C.Delete(rec.key);
				C.Print();
				goto C3;
			}
			if (numer == 3)
			{
				cout << "Поиск " << endl << "Введите слово:" << endl;
				cin >> str;
				cout << endl;
				rec.key = str;
				rec.val = 1;
				int j = 0;
				C.Findelem(rec.key);
				goto C3;
			}
			if (numer == 4)
			{
				system("cls");
				goto C1;
			}
			cout << endl;
			break;
		}
		case 3:
		{
			TTreeTable D;
			TScanTable TMP(1000);
			TRecord rec;
			D.Read("Text.txt");
			system("cls");
			cout << "TreeTable" << endl << endl;
			D.PrintTree();
			int numer = 0;
			cout << "Таблица:" << endl << endl;
		C4:
			cout << "1. Вставить слово\n";
			cout << "2. Удалить слово\n";
			cout << "3. Выход" << endl;
			cin >> numer;
			string str;

			if (numer == 1)
			{
				cout << "Вставка " << endl << "Введите слово:" << endl;
				cin >> str;
				cout << endl;
				rec.key = str;
				rec.val = 1;
				if (rec.key != "!")
				{
					D.Insert(rec);
					D.PrintTree();
					goto C4;
				}
			}
			str = "";
			if (numer == 2)
			{
				cout << "Удаление " << endl << "Введите слово:" << endl;
				cin >> str;
				cout << endl;
				rec.key = str;
				rec.val = 1;
				D.Delete(rec.key);
				D.PrintTree();
				goto C4;
			}
			if (numer == 3)
			{
				system("cls");
				goto C1;
			}

			cout << endl;
			break;
		}
		case 0:

			return 0;

		}

	}

	system("pause");
	return 0;
}

