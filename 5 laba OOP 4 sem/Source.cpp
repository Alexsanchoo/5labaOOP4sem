#include<iostream>
#include<string>
#include<fstream>
#include<Windows.h>
#include "vector.h"
#include "map.h"
#include "Employee.h"
#include "Service.h"

using namespace std;

void serviceManagement(Map<int, Service>& map);
void employeeManagement(Vector<Employee>& vec, Map<int, Service>& map);

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	cin.exceptions(ios::failbit | ios::badbit);

	Map<int, Service> services;
	Vector<Employee> employees;

	fstream file;
	
	file.open("services.txt", ios::in);
	if (file.is_open())
	{
		services.read(file);
		file.close();
	}
	
	file.open("employees.txt", ios::in);
	if (file.is_open())
	{
		employees.read(file);
		file.close();
	}

	int choice = 0;
	while (choice != 3)
	{
		cout << "����" << endl;
		cout << "1. ���������� ��������" << endl;
		cout << "2. ���������� ������������" << endl;
		cout << "3. �����." << endl;
		cout << "�������� �����: ";
		choice = InputValue<>::nextValue();

		system("cls");
		switch (choice)
		{
		case 1:
			serviceManagement(services);
			system("cls");
			break;

		case 2:
			employeeManagement(employees, services);
			system("cls");
			break;

		case 3:
		{
			file.open("services.txt", ios::out | ios::trunc);
			services.print(file);
			file.close();
			file.open("employees.txt", ios::out | ios::trunc);
			employees.show(file);
			file.close();
		}
			break;

		default:
			cout << "�������� �����!" << endl << endl;
			break;
		}
	}
	return 0;
}


void serviceManagement(Map<int, Service>& map)
{
	int choice = 0;
	while (choice != 5)
	{
		cout << "����" << endl;
		cout << "1. �������� ������" << endl;
		cout << "2. ����������� ������" << endl;
		cout << "3. ��������������� ������" << endl;
		cout << "4. ������� ������" << endl;
		cout << "5. �����" << endl;
		cout << "�������� �����: ";
		choice = InputValue<>::nextValue();

		system("cls");
		switch (choice)
		{
		case 1:
		{
			Service service;
			service.set();
			int size = map.count();
			int id;
			while (size == map.count())
			{
				cout << "������� ��� ������: "; id = InputValue<>::nextValue();
				if (id < 0) { cout << "�������� ����!" << endl; continue; }
				map.insert(make_Pair(id, service));
				if (size == map.count())
				{
					cout << "����� ��� ��� ����������!" << endl;
				}
			}
		}
			system("cls");
			break;

		case 2:
			if (!map.isEmpty())
			{
				map.print(cout, true);
				system("pause");
				system("cls");
			}
			else
			{
				cout << "������ ����� ����!" << endl << endl;
			}
			break;

		case 3:
		{
			if (!map.isEmpty())
			{
				map.print(cout, true);
				bool isExists = false;
				int key;
				while (!isExists)
				{
					cout << "������� ��� ������, ������� �� ������ ���������������: "; key = InputValue<>::nextValue();
					isExists = map.isKeyExists(key);
					if (!isExists)
					{
						cout << "��� ������ ���� ������!" << endl;
					}
				}
				system("cls");
				map[key].edit();
				system("cls");
			}
			else
			{
				cout << "������ ����� ����!" << endl << endl;
			}
		}
			break;

		case 4:
			if (!map.isEmpty())
			{
				map.print(cout, true);
				bool isExists = false;
				int key;
				while (!isExists)
				{
					cout << "������� ��� ������, ������� �� ������ �������: "; key = InputValue<>::nextValue();
					isExists = map.isKeyExists(key);
					if (!isExists)
					{
						cout << "��� ������ ���� ������!" << endl;
					}
				}
				map.erase(key);
				system("cls");
			}
			else
			{
				cout << "������ ����� ����!" << endl << endl;
			}
			break;

		case 5:
			break;

		default:
			cout << "�������� �����!" << endl << endl;
			break;
		}
	}
}



void employeeManagement(Vector<Employee>& vec, Map<int, Service>& map)
{
	int choice = 0;
	while (choice != 6)
	{
		cout << "����" << endl;
		cout << "1. �������� ����������" << endl;
		cout << "2. ����������� �����������" << endl;
		cout << "3. ��������������� ����������" << endl;
		cout << "4. ������� ����������" << endl;
		cout << "5. ��������� ���������� ������" << endl;
		cout << "6. �����" << endl;
		cout << "�������� �����: ";
		choice = InputValue<>::nextValue();

		system("cls");
		switch (choice)
		{
		case 1:
		{
			Employee emp;
			emp.set();
			vec.push_back(emp);
		}
			system("cls");
			break;

		case 2:
			if (!vec.isEmpty())
			{
				vec.show(cout, true);
				system("pause");
				system("cls");
			}
			else
			{
				cout << "������ ����������� ����!" << endl << endl;
			}
			break;

		case 3:
			if (!vec.isEmpty())
			{
				vec.show(cout, true);
				int choice = InputValue<>::nextChoice(1, vec.getSize()) - 1;
				system("cls");
				if (choice != -1)
				{
					vec[choice].edit();
				}
				system("cls");
			}
			else
			{
				cout << "������ ����������� ����!" << endl << endl;
			}
			break;

		case 4:
			if (!vec.isEmpty())
			{
				vec.show(cout, true);
				int choice = InputValue<>::nextChoice(1, vec.getSize()) - 1;
				if (choice != -1)
				{
					vec.erase(choice);
				}
				system("cls");
			}
			else
			{
				cout << "������ ����������� ����!" << endl << endl;
			}
			break;

		case 5:
			if (!vec.isEmpty() && !map.isEmpty())
			{
				vec.show(cout, true);
				int choice = InputValue<>::nextChoice(1, vec.getSize()) - 1;
				if (choice == -1)
				{
					system("cls");
					break;
				}
				system("cls");
				map.print(cout, true);
				bool isExists = false;
				int key;
				while (!isExists)
				{
					cout << "�������� ��� ������, ������� �� ������ ��������� ����������: "; 
					key = InputValue<>::nextValue();
					isExists = map.isKeyExists(key);
					if (!isExists)
					{
						cout << "��� ������ ���� ������!" << endl;
					}
				}
				vec[choice].setIdService(key);
			}
			else
			{
				cout << "������ ����������� ��� ����� ����!" << endl << endl;
			}
			system("cls");
			break;

		case 6:
			break;

		default:
			cout << "�������� �����!" << endl << endl;
			break;
		}
	}
}
