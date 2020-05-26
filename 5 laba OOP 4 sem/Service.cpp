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
	cout << "������� �������� ������: "; name = InputValue<string>::nextValue();
	cout << "������� ���� ������: "; cost = InputValue<double>::nextValue();
	cout << "������� �������������� ������ (� �������): "; duration = InputValue<>::nextValue();
}

void Service::get()
{
	cout << "�������� ������: " << name << endl;
	cout << "���� ������: " << cost << endl;
	cout << "�������������� ������ (� �������): " << duration << endl;
}

void Service::edit()
{
	int choice = 0;
	while (choice != 4)
	{
		cout << "��������, ��� �� ������ ���������������: " << endl;
		cout << "1. ��������" << endl;
		cout << "2. ����" << endl;
		cout << "3. ���������������� ������" << endl;
		cout << "4. �����" << endl;
		cout << "�������� �����: "; choice = InputValue<>::nextValue();

		system("cls");
		switch (choice)
		{
			case 1:
				cout << "��������: " << name << endl;
				cout << "������� ����� ��������: "; name = InputValue<string>::nextValue();
				system("cls");
				break;

			case 2:
				cout << "����: " << cost << endl;
				cout << "������� ����� ����: "; cost = InputValue<double>::nextValue();
				system("cls");
				break;

			case 3:
				cout << "�������������� ������: " << duration << endl;
				cout << "������� ����� ����������������� ������: "; duration = InputValue<>::nextValue();
				system("cls");
				break;

			case 4:
				break;

			default:
			cout << "�������� �����!" << endl << endl;
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
