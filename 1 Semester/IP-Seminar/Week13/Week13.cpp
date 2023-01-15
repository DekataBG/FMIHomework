#include <iostream>
#include <cstring>

void problem1()
{
    int n;
    int *arr;

    std::cout << "Enter n: ";
    std::cin >> n;

    arr = new int[n];

    for(int i = 0; i < n; i++)
    {
        std::cout << "Enter element: ";
        std::cin >> arr[i];
    }

    for(int i = 0; i < n; i++)
    {
        std::cout << arr[i] << " ";
    }

    delete[] arr;
}

int* createArray(int size)
{
    int *arr = new int[size];

    for(int i = 0; i < size; i++)
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

    for(int i = 0; i < n; i++)
    {
        std::cout << arr[i] << " ";
    }

    delete[] arr;
}

char* concat(char* first, char* second)
{
    int firstSize = strlen(first);
    int secondSize = strlen(second);

    char *newArr = new char[firstSize + secondSize];

    for(int i = 0; i < firstSize; i++)
    {
        newArr[i] = first[i];
    }

    for(int i = 0; i < secondSize; i++)
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

bool contains(int* arr, int size, int element)
{
    for(int i = 0; i < size; i++)
    {
        if(arr[i] == element)
        {
            return true;
        }
    }

    return false;
}

int* toSet(int* arr, int size, int& setSize)
{
    int index = 0;
    int* newArr = new int[size];

    for(int i = 0; i < size; i++)
    {
        if(!contains(newArr, index, arr[i]))
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

    for(int i = 0; i < setSize; i++)
    {
        std::cout << set[i] << " ";
    }
}

void problem5()
{

}


int main()
{
    // problem1();
    // problem2();
    // problem3();
    // problem4();
    problem5();


    return 0;
}