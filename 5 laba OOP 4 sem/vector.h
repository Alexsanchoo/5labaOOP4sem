#pragma once
#include<iostream>
#include<cassert>

using namespace std;

template<class T>
class Vector
{
public:
	Vector() : size(0) { arr = new T[size]; }
	Vector(const Vector<T>& obj);

	int getSize();
	void push_back(T value);
	T& operator[](int index);
	T erase(int index);
	int find(T value);
	bool isEmpty();
	void sort();
	void show(ostream& out, bool mode = false);
	void read(istream& in);
	~Vector();
private:
	T* arr;
	int size;
};


template<class T>
inline Vector<T>::Vector(const Vector<T>& obj) : size(obj.size)
{
	delete[] arr;
	arr = new T[obj.size];

	for (int i = 0; i < obj.size; i++)
	{
		arr[i] = obj.arr[i];
	}
}

template<class T>
inline int Vector<T>::getSize()
{
	return size;
}

template<class T>
inline void Vector<T>::push_back(T value)
{
	T* arr = new T[++size];
	for (int i = 0; i < size - 1; i++)
	{
		arr[i] = this->arr[i];
	}
	arr[size - 1] = value;
	delete[] this->arr;
	this->arr = arr;
}

template<class T>
inline T& Vector<T>::operator[](int index)
{
	assert(index >= 0 && index < size);
	return arr[index];
}

template<class T>
inline T Vector<T>::erase(int index)
{
	assert(index >= 0 && index < size);
	T valueReturn = this->arr[index];
	T* arr = new T[--size];
	int j = 0;
	for (int i = 0; i < size + 1; i++)
	{
		if (index != i)
		{
			arr[j++] = this->arr[i];
		}
	}
	delete[] this->arr;
	this->arr = arr;
	return valueReturn;
}

template<class T>
inline int Vector<T>::find(T value)
{
	for (int i = 0; i < size; i++)
	{
		if (arr[i] == value)
		{
			return i;
		}
	}
	return -1;
}

template<class T>
inline bool Vector<T>::isEmpty()
{
	if (size == 0)
	{
		return true;
	}
	return false;
}

template<class T>
inline void Vector<T>::sort()
{
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = 0; j < size - i - 1; j++)
		{
			if (arr[j + 1] < arr[j])
			{
				T temp = arr[j + 1];
				arr[j + 1] = arr[j];
				arr[j] = temp;
			}
		}
	}
}

template<class T>
inline void Vector<T>::show(ostream& out, bool mode)
{
	for (int i = 0; i < size; i++)
	{
		if (!mode)
		{
		out << arr[i];
		}
		else
		{
			out << "#" << i + 1 << endl;
			arr[i].get();
			out << endl;
		}
	}
}

template<class T>
inline void Vector<T>::read(istream& in)
{
	while (true)
	{
		T value;
		in >> value;
		if (in.eof()) { break; }
		push_back(value);
	}
}

template<class T>
inline Vector<T>::~Vector()
{
	delete[] arr;
	size = 0;
	arr = nullptr;
}
