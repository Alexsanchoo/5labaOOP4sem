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
	cout << "������� ���: "; name = InputValue<string>::nextValue();
	cout << "������� �������: "; lastname = InputValue<string>::nextValue();
	cout << "������� ���������: "; position = InputValue<string>::nextValue();
}

void Employee::get()
{
	cout << "���: " << name << endl;
	cout << "�������: " << lastname << endl;
	cout << "���������: " << position << endl;
	if (idService != -1)
	{
		cout << "��� ������: " << idService << endl;
	}
}

void Employee::edit()
{
	int choice = 0;
	while (choice != 4)
	{
		cout << "��������, ��� �� ������ ���������������: " << endl;
		cout << "1. ���" << endl;
		cout << "2. �������" << endl;
		cout << "3. ���������" << endl;
		cout << "4. �����" << endl;
		cout << "�������� �����: "; choice = InputValue<>::nextValue();

		system("cls");
		switch (choice)
		{
		case 1:
			cout << "���: " << name << endl;
			cout << "������� ����� ���: "; name = InputValue<string>::nextValue();
			system("cls");
			break;

		case 2:
			cout << "�������: " << lastname << endl;
			cout << "������� ����� �������: "; lastname = InputValue<string>::nextValue();
			system("cls");
			break;

		case 3:
			cout << "���������: " << position << endl;
			cout << "������� ����� ���������: "; position = InputValue<string>::nextValue();
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
