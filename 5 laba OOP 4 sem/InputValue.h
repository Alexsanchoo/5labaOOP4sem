#pragma once
#include<iostream>
#include<string>
#include<regex>
#include<conio.h>

using namespace std;

template<class T = int>
class InputValue
{
public:
	static T nextValue();
	static int nextChoice(int minValue, int maxValue);
};

template<class T>
inline T InputValue<T>::nextValue()
{
	T value;
	while (true)
	{
		try
		{
			cin >> value;
			cin.ignore(1000, '\n');
			if (cin.gcount() > 1) throw runtime_error("extra characters");
			return value;
		}
		catch (ios_base::failure ex)
		{
			cout << "ќшибка! ¬ведите ещЄ раз: ";
			cin.clear();
			while (cin.get() != '\n');
		}
		catch (runtime_error ex)
		{
			cout << "ќшибка! ¬ведите ещЄ раз: ";
		}
	}
}