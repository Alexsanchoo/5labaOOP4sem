#pragma once
#include<iostream>

using namespace std;

template<class T1, class T2>
struct Pair {
    T1 key;
    T2 value;

    Pair() {}
    Pair(T1 key, T2 value) : key(key), value(value) {}
    Pair(const Pair& obj) : key(obj.key), value(obj.value) {}
};


template<class T1, class T2>
Pair<T1, T2> make_Pair(T1 key, T2 value)
{
    return Pair<T1, T2>(key, value);
}


template<class T1, class T2>
class Map
{
public:
    Map() : size(0) { arr = new Pair<T1, T2>[size]; }
    Map(const Map& obj);

    int count() const;
    void insert(Pair<T1, T2> value);
    T2 erase(T1 key);
    T2& operator[](T1 key);
    bool isKeyExists(T1 key);
    bool isEmpty();
    T1 find(T2 value);
    void sort();
    void print(ostream& out, bool mode = false);
    void read(istream& in);

    ~Map();

private:
    Pair<T1, T2>* arr;
    int size;
};

template<class T1, class T2>
inline Map<T1, T2>::Map(const Map& obj) : size(obj.size)
{
    delete[] arr;
    arr = new Pair<T1, T2>[size];
    for (int i = 0; i < size; i++)
    {
        arr[i] = obj.arr[i];
    }
}

template<class T1, class T2>
inline int Map<T1, T2>::count() const
{
    return size;
}

template<class T1, class T2>
inline void Map<T1, T2>::insert(Pair<T1, T2> value)
{
    bool isUnique = true;
    for (int i = 0; i < size; i++)
    {
        if (arr[i].key == value.key)
        {
            isUnique = false;
            break;
        }
    }
    if (!isUnique) { return;}

    Pair<T1, T2>* arr = new Pair<T1, T2>[++size];
    for (int i = 0; i < size -1; i++)
    {
        arr[i] = this->arr[i];
    }
    arr[size - 1] = value;
    delete[] this->arr;
    this->arr = arr;
}

template<class T1, class T2>
inline T2 Map<T1, T2>::erase(T1 key)
{
    T2 valueReturn;
    bool isExists = false;
    for (int i = 0; i < size; i++)
    {
        if (this->arr[i].key == key)
        {
            valueReturn = this->arr[i].value;
            isExists = true;
            break;
        }
    }

    if (!isExists) { abort(); }

    Pair<T1,T2>* arr = new Pair<T1,T2>[--size];
    int j = 0;
    for (int i = 0; i < size + 1; i++)
    {
        if (this->arr[i].key != key)
        {
            arr[j++] = this->arr[i];
        }
    }
    delete[] this->arr;
    this->arr = arr;
    return valueReturn;
}

template<class T1, class T2>
inline T2& Map<T1, T2>::operator[](T1 key)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i].key == key)
        {
            return arr[i].value;
        }
    }
    abort();
}

template<class T1, class T2>
inline bool Map<T1, T2>::isKeyExists(T1 key)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i].key == key)
        {
            return true;
        }
    }
    return false;
}

template<class T1, class T2>
inline bool Map<T1, T2>::isEmpty()
{
    if (size == 0)
    {
        return true;
   }
    return false;
}

template<class T1, class T2>
inline T1 Map<T1, T2>::find(T2 value)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i].value == value)
        {
            return arr[i].key;
        }
    }
    return T1();
}

template<class T1, class T2>
inline void Map<T1, T2>::sort()
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (arr[j + 1].value < arr[j].value)
            {
                Pair<T1,T2> temp = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

template<class T1, class T2>
inline void Map<T1, T2>::print(ostream& out, bool mode)
{
    for (int i = 0; i < size; i++)
    {
        if (!mode)
        {
            out << arr[i].key << " " << arr[i].value;
        }
        else
        {
            out << "Код услуги: " << arr[i].key << endl;
            arr[i].value.get();
            cout << endl;
        }
    }
}

template<class T1, class T2>
inline void Map<T1, T2>::read(istream& in)
{
    while (true)
    {
        T1 key;
        T2 value;
        in >> key >> value;
        if (in.eof()) { break; }
        insert(make_Pair(key, value));
    }
}

template<class T1, class T2>
inline Map<T1, T2>::~Map()
{
    delete[] arr;
    size = 0;
    arr = nullptr;
}
