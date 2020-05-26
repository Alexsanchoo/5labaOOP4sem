#include "Service.h"

void Service::setName(string name)
{
	this->name = name;
}

void Service::setCost(double cost)
{
	this->cost = cost;
}

void Service::setDuration(int duration)
{
	this->duration = duration;
}

string Service::getName()
{
	return name;
}

double Service::getCost()
{
	return cost;
}

int Service::getDuration()
{
	return duration;
}

void Service::set()
{
	cout << "Введите название услуги: "; name = InputValue<string>::nextValue();
	cout << "Введите цену услуги: "; cost = InputValue<double>::nextValue();
	cout << "Введите продолжительно услуги (в минутах): "; duration = InputValue<>::nextValue();
}

void Service::get()
{
	cout << "Название услуги: " << name << endl;
	cout << "Цена услуги: " << cost << endl;
	cout << "Продолжительно услуги (в минутах): " << duration << endl;
}

void Service::edit()
{
	int choice = 0;
	while (choice != 4)
	{
		cout << "Выберите, что вы хотите отредактировать: " << endl;
		cout << "1. Название" << endl;
		cout << "2. Цену" << endl;
		cout << "3. Продолжительност услуги" << endl;
		cout << "4. Назад" << endl;
		cout << "Сделайте выбор: "; choice = InputValue<>::nextValue();

		system("cls");
		switch (choice)
		{
			case 1:
				cout << "Название: " << name << endl;
				cout << "Введите новое название: "; name = InputValue<string>::nextValue();
				system("cls");
				break;

			case 2:
				cout << "Цена: " << cost << endl;
				cout << "Введите новую цену: "; cost = InputValue<double>::nextValue();
				system("cls");
				break;

			case 3:
				cout << "Продолжительно услуги: " << duration << endl;
				cout << "Введите новую продолжительность услуги: "; duration = InputValue<>::nextValue();
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

istream& operator>>(istream& in, Service& obj)
{
	in >> obj.name >> obj.cost >> obj.duration;
	return in;
}

ostream& operator<<(ostream& out, Service& obj)
{
	out << obj.name << " " << obj.cost << " " << obj.duration << " ";
	return out;
}
