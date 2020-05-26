#include "Employee.h"

void Employee::setName(string name)
{
	this->name = name;
}

void Employee::setLastname(string lastname)
{
	this->lastname = lastname;
}

void Employee::setPosition(string position)
{
	this->position = position;
}

void Employee::setIdService(int id)
{
	this->idService = id;
}

int Employee::getIdService()
{
	return idService;
}

string Employee::getName()
{
	return name;
}

string Employee::getLastname()
{
	return lastname;
}

string Employee::getPosition()
{
	return position;
}

void Employee::set()
{
	cout << "Введите имя: "; name = InputValue<string>::nextValue();
	cout << "Введите фамилию: "; lastname = InputValue<string>::nextValue();
	cout << "Введите должность: "; position = InputValue<string>::nextValue();
}

void Employee::get()
{
	cout << "Имя: " << name << endl;
	cout << "Фамилия: " << lastname << endl;
	cout << "Должность: " << position << endl;
	if (idService != -1)
	{
		cout << "Код услуги: " << idService << endl;
	}
}

void Employee::edit()
{
	int choice = 0;
	while (choice != 4)
	{
		cout << "Выберите, что вы хотите отредактировать: " << endl;
		cout << "1. Имя" << endl;
		cout << "2. Фамилия" << endl;
		cout << "3. Должность" << endl;
		cout << "4. Назад" << endl;
		cout << "Сделайте выбор: "; choice = InputValue<>::nextValue();

		system("cls");
		switch (choice)
		{
		case 1:
			cout << "Имя: " << name << endl;
			cout << "Введите новое имя: "; name = InputValue<string>::nextValue();
			system("cls");
			break;

		case 2:
			cout << "Фамилия: " << lastname << endl;
			cout << "Введите новую фамилию: "; lastname = InputValue<string>::nextValue();
			system("cls");
			break;

		case 3:
			cout << "Должность: " << position << endl;
			cout << "Введите новую должность: "; position = InputValue<string>::nextValue();
			system("cls");
			break;

		case 4:
			break;

		default:
			cout << "Неверный выбор!" << endl << endl;
			break;
		}
	}
}

istream& operator>>(istream& in, Employee& obj)
{
	in >> obj.name >> obj.lastname >> obj.position >> obj.idService;
	return in;
}

ostream& operator<<(ostream& out, Employee& obj)
{
	out << obj.name << " " << obj.lastname << " " << obj.position << " " << obj.idService << " ";
	return out;
}
