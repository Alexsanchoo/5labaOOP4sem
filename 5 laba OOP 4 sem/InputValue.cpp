#include "InputValue.h"


int InputValue<int>::nextChoice(int minValue, int maxValue)
{
	int choice;
	while (true)
	{
		cout << "Сделайте выбор (для выхода введите 0): ";
		choice = InputValue<>::nextValue();
		if (choice == 0) { return choice; }
		if (choice < minValue || choice > maxValue)
		{
			cout << "Ошибка! Повторите ввод." << endl;
		}
		else
		{
			return choice;
		}
	}
}
