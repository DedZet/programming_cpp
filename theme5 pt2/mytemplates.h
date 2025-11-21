#ifndef MYTEMPLATES_H
#define MYTEMPLATES_H

#include <iostream>

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

class DuplicateDataException : public std::exception {
public:
    const char* what() const noexcept override {
        return "Cannot add duplicate data to container";
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
    void info();
    void sort();
    bool contains(T x) const;
    int getSize() const { return size; }
    bool isEmpty() const { return size == 0; }
    bool isFull() const { return size >= MAXSIZE; }

    template <class U>
    friend std::ostream& operator<<(std::ostream& os, const Container<U>& container);
};

template <class T>
Container<T>::Container()
{
    size = 0;
}

template <class T>
bool Container<T>::contains(T x) const {
    for (int i = 0; i < size; i++) {
        if (data[i] == x) {
            return true;
        }
    }
    return false;
}

template <class T>
void Container<T>::add(T x)
{
    if (isFull()) {
        throw ContainerFullException();
    }

    if (contains(x)) {
        throw DuplicateDataException();
    }

    data[size] = x;
    size++;
}

template <class T>
void Container<T>::del()
{
    if (isEmpty()) {
        throw ContainerEmptyException();
    }
    size--;
}

template <class T>
void Container<T>::info()
{
    for (int i = 0; i < size - 1; i++)
    {
        std::cout << data[i] << ", ";
    }
    if (size > 0)
    {
        std::cout << data[size - 1];
    }
    std::cout << "\n";
}

template <class T>
void Container<T>::sort()
{
    T element;
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - 1; j++)
        {
            if (data[j + 1] < data[j])
            {
                element = data[j];
                data[j] = data[j + 1];
                data[j + 1] = element;
            }
        }
    }
}

template <class T>
std::ostream& operator<<(std::ostream& os, const Container<T>& container)
{
    for (int i = 0; i < container.size - 1; i++)
    {
        os << container.data[i] << ", ";
    }
    if (container.size > 0)
    {
        os << container.data[container.size - 1];
    }
    return os;
}

#endif
