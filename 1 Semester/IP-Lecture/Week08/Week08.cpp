// Problems from section 3.3, 3.4 and 3.5 from https://github.com/stranxter/lecture-notes/blob/master/homeworks/Problems%20in%20Programming.pdf

#include <iostream>

void problem3_17()
{
    int array1[50], array2[50];
    int n, ctr = 0;

    std::cout << "Enter n: ";
    std::cin >> n;

    for (int i = 0; i < n; i++)
    {
        std::cout << "Enter element for array 1: ";
        std::cin >> array1[i];

        std::cout << "Enter element for array 2: ";
        std::cin >> array2[i];

        if (array1[i] == array2[i])
        {
            ctr++;
        }
    }

    std::cout << ctr << " equal elements";
}

bool contains(int array[], int size, int element)
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

void problem3_18()
{
    int array1[50], array2[50];
    int n;

    std::cout << "Enter n: ";
    std::cin >> n;

    for (int i = 0; i < n; i++)
    {
        std::cout << "Enter element for array 1: ";
        std::cin >> array1[i];

        std::cout << "Enter element for array 2: ";
        std::cin >> array2[i];
    }

    bool similar = true;
    for (int i = 0; i < n; i++)
    {
        if (!contains(array1, n, array2[i]) || !contains(array2, n, array1[i]))
        {
            similar = false;
            break;
        }
    }

    std::cout << (similar ? "The arrays are similar" : "The arrays are not similar");
}

void problem3_19()
{
    int matrix[50][50];
    int n;

    std::cout << "Enter n: ";
    std::cin >> n;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            std::cout << "Enter matrix [" << i << "][" << j << "]: ";
            std::cin >> matrix[i][j];
        }
    }

    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (matrix[i][j] % 2 == 1)
            {
                sum += matrix[i][j];
            }
        }
    }

    std::cout << "The sum of the odd numbers below the main diagonal is " << sum;
}

void problem3_20()
{
}

void problem3_21()
{
}

void problem3_22()
{
}

int main()
{
    // problem3_17();
    // problem3_18();
    problem3_19();
    // problem3_20();
    // problem3_21();
    // problem3_22();

    return 0;
}