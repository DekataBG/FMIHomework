#include <iostream>
#include <cstring>

void problem1()
{
    int n;
    int *arr;

    std::cout << "Enter n: ";
    std::cin >> n;

    arr = new int[n];

    for (int i = 0; i < n; i++)
    {
        std::cout << "Enter element: ";
        std::cin >> arr[i];
    }

    for (int i = 0; i < n; i++)
    {
        std::cout << arr[i] << " ";
    }

    delete[] arr;
}

int *createArray(int size)
{
    int *arr = new int[size];

    for (int i = 0; i < size; i++)
    {
        std::cout << "Enter element: ";
        std::cin >> arr[i];
    }

    return arr;
}

void problem2()
{
    int n;
    int *arr;

    std::cout << "Enter n: ";
    std::cin >> n;

    arr = createArray(n);

    for (int i = 0; i < n; i++)
    {
        std::cout << arr[i] << " ";
    }

    delete[] arr;
}

char *concat(char *first, char *second)
{
    int firstSize = strlen(first);
    int secondSize = strlen(second);

    char *newArr = new char[firstSize + secondSize];

    for (int i = 0; i < firstSize; i++)
    {
        newArr[i] = first[i];
    }

    for (int i = 0; i < secondSize; i++)
    {
        newArr[i + firstSize] = second[i];
    }

    return newArr;
}

void problem3()
{
    char arr1[50], arr2[50];

    std::cout << "Enter string 1: ";
    std::cin.getline(arr1, 50);

    std::cout << "Enter string 2: ";
    std::cin.getline(arr2, 50);

    char *arr3 = concat(arr1, arr2);

    std::cout << arr3;

    delete[] arr3;
}

bool contains(int *arr, int size, int element)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == element)
        {
            return true;
        }
    }

    return false;
}

int *toSet(int *arr, int size, int &setSize)
{
    int index = 0;
    int *newArr = new int[size];

    for (int i = 0; i < size; i++)
    {
        if (!contains(newArr, index, arr[i]))
        {
            newArr[index] = arr[i];
            index++;
        }
    }

    setSize = index;
    return newArr;
}

void problem4()
{
    int n;
    int *arr;

    std::cout << "Enter n: ";
    std::cin >> n;

    arr = createArray(n);

    int setSize;
    int *set = toSet(arr, n, setSize);

    for (int i = 0; i < setSize; i++)
    {
        std::cout << set[i] << " ";
    }
}

void add(int *&arr, int &size, int newElement)
{
    int *newArr = new int[size + 1];

    for (int i = 0; i < size; i++)
    {
        newArr[i] = arr[i];
    }

    newArr[size] = newElement;
    size++;

    delete[] arr;

    arr = newArr;
}

void problem5()
{
    int n;
    int *arr;

    std::cout << "Enter n: ";
    std::cin >> n;

    arr = createArray(n);

    int newElement;

    std::cout << "Enter new element: ";
    std::cin >> newElement;

    add(arr, n, newElement);

    for (int i = 0; i < n; i++)
    {
        std::cout << arr[i] << " ";
    }

    delete[] arr;
}

void insertAt(int *&arr, int &size, int newElement, int index)
{
    int *newArr = new int[size + 1];

    for (int i = 0; i < index; i++)
    {
        newArr[i] = arr[i];
    }

    newArr[index] = newElement;

    for (int i = index; i < size; i++)
    {
        newArr[i + 1] = arr[i];
    }

    size++;

    delete[] arr;

    arr = newArr;
}

void problem6()
{
    int n;
    int *arr;

    std::cout << "Enter n: ";
    std::cin >> n;

    arr = createArray(n);

    int newElement, index;

    std::cout << "Enter new element: ";
    std::cin >> newElement;

    std::cout << "Enter index: ";
    std::cin >> index;

    insertAt(arr, n, newElement, index);

    for (int i = 0; i < n; i++)
    {
        std::cout << arr[i] << " ";
    }

    delete[] arr;
}

void resize(int *&arr, int &size, int newSize)
{
    int *newArr = new int[newSize];

    for (int i = 0; i < size; i++)
    {
        newArr[i] = arr[i];
    }

    if (newSize > size)
    {
        for (int i = size; i < newSize; i++)
        {
            newArr[i] = 0;
        }
    }

    size = newSize;

    delete[] arr;

    arr = newArr;
}

void problem7()
{
    int n;
    int *arr;

    std::cout << "Enter n: ";
    std::cin >> n;

    arr = createArray(n);

    int size;

    std::cout << "Enter size: ";
    std::cin >> size;

    resize(arr, n, size);

    for (int i = 0; i < size; i++)
    {
        std::cout << arr[i] << " ";
    }

    delete[] arr;
}

void copy(int *arrayFrom, int sizeFrom, int *&arrayTo, int &sizeTo)
{
    for (int i = 0; i < sizeFrom; i++)
    {
        arrayTo[i] = arrayFrom[i];
    }

    sizeTo = sizeFrom;

    delete[] arrayFrom;
}

void problem8()
{
    int n, newSize = 0;
    int *arr1;
    int *arr2;

    std::cout << "Enter n: ";
    std::cin >> n;

    arr1 = createArray(n);
    arr2 = new int[n];

    copy(arr1, n, arr2, newSize);

    std::cout << "Copied array: ";
    for (int i = 0; i < newSize; i++)
    {
        std::cout << arr2[i] << " ";
    }

    delete[] arr2;
}

int main()
{
    // problem1();
    // problem2();
    // problem3();
    // problem4();
    // problem5();
    // problem6();
    // problem7();
    // problem8();

    return 0;
}