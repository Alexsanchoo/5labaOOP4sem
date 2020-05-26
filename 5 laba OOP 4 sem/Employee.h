#pragma once
#include<iostream>
#include<string>
#include "InputValue.h"

using namespace std;

class Employee
{
public:
	Employee(string name = "", string lastname = "", string position = "", int idService = -1) : name(name), 
		lastname(lastname), position(position), idService(idService) {}
	Employee(const Employee& obj) : name(obj.name), lastname(obj.lastname), position(obj.position), 
		idService(obj.idService) {}

	void setName(string name);
	void setLastname(string lastname);
	void setPosition(string position);
	void setIdService(int id);
	int getIdService();
	string getName();
	string getLastname();
	string getPosition();
	void set();
	void get();
	void edit();
	friend istream& operator>>(istream& in, Employee& obj);
	friend ostream& operator<<(ostream& out, Employee& obj);

private:
	string name;
	string lastname;
	string position;
	int idService;
};

