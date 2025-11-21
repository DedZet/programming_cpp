#ifndef MYTEMPLATES
#define MYTEMPLATES

#include <iostream>
#include <stdexcept>

const int MAXSIZE = 100;

class ContainerFullException : public std::exception {
public:
    const char* what() const noexcept override {
        return "Cannot add data to a full container";
    }
};

class ContainerEmptyException : public std::exception {
public:
    const char* what() const noexcept override {
        return "Cannot remove data from an empty container";
    }
};

class MaxDataException : public std::exception {
public:
    const char* what() const noexcept override {
        return "Element is too large to add";
    }
};

template <class T>
class Container
{
private:
    T data[MAXSIZE];
    int size;
public:
    Container();
    void add(T x);
    void del();
    void sort();
    T getMax() const;

    template <class U>
    friend std::ostream& operator<<(std::ostream& os, const Container<U>& cont);
};

template <class T>
Container<T>::Container()
{
    size = 0;
}

template <class T>
void Container<T>::add(T x)
{
    if (size >= MAXSIZE)
        throw ContainerFullException();

    if (size > 0)
    {
        T currentMax = getMax();
        if (x > currentMax * 2)
            throw MaxDataException();
    }

    data[size++] = x;
}

template <class T>
void Container<T>::del()
{
    if (size <= 0)
        throw ContainerEmptyException();
    size--;
}

template <class T>
void Container<T>::sort()
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - 1; j++)
        {
            if (data[j + 1] < data[j])
            {
                T element = data[j];
                data[j] = data[j + 1];
                data[j + 1] = element;
            }
        }
    }
}

template <class T>
T Container<T>::getMax() const
{
    if (size == 0)
        return T();

    T maxVal = data[0];
    for (int i = 1; i < size; i++)
    {
        if (maxVal < data[i])
            maxVal = data[i];
    }
    return maxVal;
}

template <class T>
std::ostream& operator<<(std::ostream& os, const Container<T>& cont)
{
    for (int i = 0; i < cont.size; i++)
    {
        os << cont.data[i];
        if (i < cont.size - 1)
            os << ", ";
    }
    return os;
}

#endif // MYTEMPLATES