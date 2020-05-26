#pragma once
#include<iostream>
#include<string>
#include "InputValue.h"

using namespace std;

class Service
{
public:
	Service(string name = "", double cost = 0.0, int duration = 0) : name(name), cost(cost), duration(duration) {}
	Service(const Service& obj) : name(obj.name), cost(obj.cost), duration(obj.duration) {}

	void setName(string name);
	void setCost(double cost);
	void setDuration(int duration);

	string getName();
	double getCost();
	int getDuration();
	void set();
	void get();
	void edit();
	friend istream& operator>>(istream& in, Service& obj);
	friend ostream& operator<<(ostream& out, Service& obj);

private:
	string name;
	double cost;
	int duration;
};

