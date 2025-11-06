#ifndef MYTEMPLATES
#define MYTEMPLATES

template <class T>
void sortUp(T* arr, int n)
{
    T element;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1; j++)
        {
            if (arr[j + 1] < arr[j])
            {
                element = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = element;
            }
        }
    }
}

template <class T>
void sortDown(T* arr, int n)
{
    T element;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1; j++)
        {
            if (arr[j] < arr[j + 1])
            {
                element = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = element;
            }
        }
    }
}

template <class T>
T sum(T* arr, int size)
{
    T result = 0;

    for (int i = 0; i < size; i++)
    {
        result += arr[i];
    }
    return result;
}

template <class T>
T medium(T* arr, int size)
{
    T result = 0;

    for (int i = 0; i < size; i++)
    {
        result += arr[i];
    }
    return result / size;
}

template <class T>
int amountMore(T* arr, int size, T value) {
    int result = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] > value) {
            result++;
        }
    }
    return result;
}

template <class T>
int amountLess(T* arr, int size, T value) {
    int result = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] < value) {
            result++;
        }
    }
    return result;
}

#endif
