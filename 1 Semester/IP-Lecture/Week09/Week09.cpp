// Problems from section 4 from https://github.com/stranxter/lecture-notes/blob/master/homeworks/Problems%20in%20Programming.pdf

#include <iostream>

void swapArrayElements(int array1[], int array2[], int size)
{
    for (int i = 0; i < size; i++)
    {
        int temp = array1[i];
        array1[i] = array2[i];
        array2[i] = temp;
    }
}

void problem4_1()
{
    int size;
    int array1[100], array2[100];

    std::cout << "Enter size: ";
    std::cin >> size;

    for (int i = 0; i < size; i++)
    {
        std::cout << "Enter element for array1: ";
        std::cin >> array1[i];

        std::cout << "Enter element for array2: ";
        std::cin >> array2[i];
    }

    std::cout << "Array 1 before swap: ";
    for (int i = 0; i < size; i++)
    {
        std::cout << array1[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "Array 2 before swap: ";
    for (int i = 0; i < size; i++)
    {
        std::cout << array2[i] << " ";
    }
    std::cout << std::endl;

    swapArrayElements(array1, array2, size);

    std::cout << "Array 1 after swap: ";
    for (int i = 0; i < size; i++)
    {
        std::cout << array1[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "Array 2 after swap: ";
    for (int i = 0; i < size; i++)
    {
        std::cout << array2[i] << " ";
    }
    std::cout << std::endl;
}

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

void problem4_2()
{
    int a, b;

    std::cout << "Enter a: ";
    std::cin >> a;

    std::cout << "Enter b: ";
    std::cin >> b;

    swap(a, b);

    std::cout << "After swap: \na: " << a << "\nb: " << b << std::endl;
}

bool duplicates(long *pointers[])
{
    int ctr = 0;

    while (pointers[ctr])
    {
        int ctr2 = ctr + 1;
        while (pointers[ctr2])
        {
            if (*pointers[ctr] == *pointers[ctr2])
            {
                return true;
            }

            ctr2++;
        }

        ctr++;
    }

    return false;
}

void problem4_3()
{
    int n;
    long values[50];
    long *pointers[50];

    std::cout << "Enter n: ";
    std::cin >> n;

    for (int i = 0; i < n; i++)
    {
        std::cout << "Enter element: ";
        std::cin >> values[i];
        pointers[i] = &values[i];
    }
    pointers[n] = nullptr;

    std::cout << "Equal elements: " << std::boolalpha << duplicates(pointers) << std::endl;
}

bool containsElement(int array[], int size, int element)
{
    for (int i = 0; i < size; i++)
    {
        if (array[i] == element)
        {
            return true;
        }
    }

    return false;
}

bool arraysContainElement(int *arrays[], int npointers, int arrlenghts[], int element)
{
    for (int i = 0; i < npointers; i++)
    {
        if (!containsElement(arrays[i], arrlenghts[i], element))
        {
            return false;
        }
    }

    return true;
}

bool commonel(int *arrays[], int npointers, int arrlenghts[])
{
    for (int i = 0; i < arrlenghts[0]; i++)
    {
        if (arraysContainElement(arrays, npointers, arrlenghts, arrays[0][i]))
        {
            return true;
        }
    }

    return false;
}

void problem4_4()
{
    int matrix[50][50];
    int npointers;
    int arrlenghts[50];
    int *arrays[50];

    std::cout << "Enter n: ";
    std::cin >> npointers;

    for (int i = 0; i < npointers; i++)
    {
        int size;

        std::cout << "Enter size for array " << i + 1 << ": ";
        std::cin >> arrlenghts[i];

        for (int j = 0; j < arrlenghts[i]; j++)
        {
            std::cout << "Enter element for array " << i + 1 << ": ";
            std::cin >> matrix[i][j];
        }

        arrays[i] = matrix[i];
    }

    std::cout << "There are common elements: " << std::boolalpha
              << commonel(arrays, npointers, arrlenghts) << std::endl;
}

bool isSubArrayOfArray(int arr1[], int size1, int arr2[], int size2)
{
    if (size2 > size1)
    {
        return false;
    }

    for (int i = 0; i < size2; i++)
    {
        if (!containsElement(arr1, size1, arr2[i]))
        {
            return false;
        }
    }

    return true;
}

bool isSubArrayOfAllArrays(int *arrays[], int npointers, int arrlenghts[], int arr[], int size)
{
    for (int i = 0; i < npointers; i++)
    {
        if (!isSubArrayOfArray(arrays[i], arrlenghts[i], arr, size))
        {
            return false;
        }
    }

    return true;
}

bool subarrays(int *arrays[], int npointers, int arrlenghts[])
{
    for (int i = 0; i < npointers; i++)
    {
        if (isSubArrayOfAllArrays(arrays, npointers, arrlenghts, arrays[i], arrlenghts[i]))
        {
            return true;
        }
    }

    return false;
}

void problem4_5()
{
    int matrix[50][50];
    int npointers;
    int arrlenghts[50];
    int *arrays[50];

    std::cout << "Enter n: ";
    std::cin >> npointers;

    for (int i = 0; i < npointers; i++)
    {
        int size;

        std::cout << "Enter size for array " << i + 1 << ": ";
        std::cin >> arrlenghts[i];

        for (int j = 0; j < arrlenghts[i]; j++)
        {
            std::cout << "Enter element for array " << i + 1 << ": ";
            std::cin >> matrix[i][j];
        }

        arrays[i] = matrix[i];
    }

    for (int i = 0; i < npointers; i++)
    {
        for (int j = 0; j < arrlenghts[i]; j++)
        {
            std::cout << arrays[i][j] << " ";
        }
        std::cout << std::endl;
    }

    std::cout << "There is a common subarray: " << std::boolalpha
              << subarrays(arrays, npointers, arrlenghts) << std::endl;
}

double sum(size_t n, double currentSum)
{
    if (n == 0)
    {
        return currentSum;
    }

    double element;

    std::cout << "Enter element: ";
    std::cin >> element;

    currentSum += element;

    return sum(n - 1, currentSum);
}

void problem4_6()
{
    int n;

    std::cout << "Enter n: ";
    std::cin >> n;

    std::cout << sum(n, 0);
}

void reverse(int n)
{
    if (n == 0)
    {
        return;
    }

    int number;

    std::cout << "Enter a number: ";
    std::cin >> number;

    reverse(n - 1);

    std::cout << number << " ";
}

void problem4_7()
{
    int n;

    std::cout << "Enter n: ";
    std::cin >> n;

    reverse(n);
}

void getmax1(long *pmax, size_t n)
{
    long array[50];

    for (int i = 0; i < n; i++)
    {
        std::cout << "Enter element: ";
        std::cin >> array[i];

        if (pmax == nullptr || *pmax < array[i])
        {
            pmax = &array[i];
        }
    }

    std::cout << *pmax << std::endl;
}

void getmax2(long *pmax, size_t n)
{
    if (n == 0)
    {
        std::cout << *pmax << std::endl;
        return;
    }

    long element;

    std::cout << "Enter element: ";
    std::cin >> element;

    if (pmax == nullptr || *pmax < element)
    {
        pmax = &element;
    }

    getmax2(pmax, n - 1);
}

void problem4_8()
{
    int n;

    std::cout << "Enter n: ";
    std::cin >> n;

    getmax1(nullptr, n);
    getmax2(nullptr, n);
}

int main()
{
    // problem4_1();
    // problem4_2();
    // problem4_3();
    // problem4_4();
    // problem4_5();
    // problem4_6();
    // problem4_7();
    // problem4_8();

    return 0;
}