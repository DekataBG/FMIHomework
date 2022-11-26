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

bool isMinimalElementInRow(int matrix[][50], int size, int row, int element)
{
    for (int i = 0; i < size; i++)
    {
        if (element > matrix[row][i])
        {
            return false;
        }
    }

    return true;
}

bool isMinimalElementInCol(int matrix[][50], int size, int col, int element)
{
    for (int i = 0; i < size; i++)
    {
        if (element > matrix[i][col])
        {
            return false;
        }
    }

    return true;
}

void problem3_20()
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

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (isMinimalElementInRow(matrix, n, i, matrix[i][j]) && isMinimalElementInCol(matrix, n, j, matrix[i][j]))
            {
                std::cout << matrix[i][j] << std::endl;
            }
        }
    }
}

bool isPeriodic(int array[], int size, int period)
{
    for (int i = 0; i < size; i++)
    {
        if (array[i] != array[i % period])
        {
            return false;
        }
    }

    return true;
}

void problem3_21()
{
    int array[50];
    int n;

    std::cout << "Enter n: ";
    std::cin >> n;

    for (int i = 0; i < n; i++)
    {
        std::cout << "Enter element: ";
        std::cin >> array[i];
    }

    for (int i = 1; i <= n / 2; i++)
    {
        if (isPeriodic(array, n, i))
        {
            std::cout << "The array has period " << i << std::endl;
            return;
        }
    }

    std::cout << "The array is not periodic" << std::endl;
}

void problem3_22()
{
    int matrix1[50][50], matrix2[50][50], matrix3[50][50];
    int n, m;

    std::cout << "Enter n: ";
    std::cin >> n;

    std::cout << "Enter m: ";
    std::cin >> m;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            std::cout << "Enter element for matrix A[" << i << "][" << j << "]: ";
            std::cin >> matrix1[i][j];
        }
    }

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            std::cout << "Enter element for matrix B[" << i << "][" << j << "]: ";
            std::cin >> matrix2[i][j];
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int col = 0; col < m; col++)
        {
            int sum = 0;
            for (int j = 0; j < n; j++)
            {
                sum += matrix1[i][j] * matrix2[j][col];
            }
            matrix3[i][col] = sum;
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            std::cout << matrix3[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

int main()
{
    // problem3_17();
    // problem3_18();
    // problem3_19();
    // problem3_20();
    // problem3_21();
    problem3_22();

    return 0;
}