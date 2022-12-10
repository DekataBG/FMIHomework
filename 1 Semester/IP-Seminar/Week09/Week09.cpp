#include <iostream>
#include <cstring>

int *findBiggestElement(int *start, int *end)
{
    int *max = start;

    while (start != end)
    {
        if (*max < *start)
        {
            max = start;
        }

        start++;
    }

    return max;
}

void problem1()
{
    int n;
    int array[100];

    std::cout << "Enter n: ";
    std::cin >> n;

    for (int i = 0; i < n; i++)
    {
        std::cout << "Enter element: ";
        std::cin >> array[i];
    }

    std::cout << "Biggest element: " << *findBiggestElement(&array[0], &array[n - 1]);
}

void findBiggestElement2(int *start, int *end, int *&max)
{
    while (start != end)
    {
        if (max == nullptr || *max < *start)
        {
            max = start;
        }

        start++;
    }
}

void problem2()
{
    int n;
    int array[100];

    std::cout << "Enter n: ";
    std::cin >> n;

    for (int i = 0; i < n; i++)
    {
        std::cout << "Enter element: ";
        std::cin >> array[i];
    }

    int *max = nullptr;
    findBiggestElement2(&array[0], &array[n - 1], max);

    std::cout << "Biggest element: " << *max;
}

int sum(int a, int b)
{
    if (b == a)
    {
        return a;
    }

    return b + sum(a, b - 1);
}

void problem3()
{
    int a, b;

    std::cout << "Enter a: ";
    std::cin >> a;

    std::cout << "Enter b: ";
    std::cin >> b;

    std::cout << "The sum is " << sum(a, b) << std::endl;
}

int arraySum(int *start, int *end)
{
    if (start == end)
    {
        return *end;
    }

    return *start + arraySum(start + 1, end);
}

void problem4()
{
    int n;
    int array[100];

    std::cout << "Enter n: ";
    std::cin >> n;

    for (int i = 0; i < n; i++)
    {
        std::cout << "Enter element: ";
        std::cin >> array[i];
    }

    std::cout << "Sum of array elements: " << arraySum(&array[0], &array[n - 1]);
}

void print(char *str)
{
    if (*str == '\0')
    {
        return;
    }

    std::cout << *str;

    print(str + 1);
}

void printRev(char *str)
{
    if (*str == '\0')
    {
        return;
    }

    printRev(str + 1);

    std::cout << *str;
}

void problem5()
{
    char string[100];

    std::cout << "Enter a string: ";
    std::cin.getline(string, 100);

    std::cout << "Straight: ";
    print(string);

    std::cout << std::endl;

    std::cout << "Reversed: ";
    printRev(string);
}

int fibonacci(int n)
{
    if (n == 0)
    {
        return 0;
    }
    if (n == 1)
    {
        return 1;
    }

    return fibonacci(n - 2) + fibonacci(n - 1);
}

void problem6()
{
    int n;

    std::cout << "Enter n: ";
    std::cin >> n;

    std::cout << n << " Fibonacci number: " << fibonacci(n);
}

bool isPalyndrome(char string[], int length)
{
    if (length < 2)
    {
        return true;
    }

    bool equalFirstAndLast = *string == *(string + length - 1);

    return equalFirstAndLast && isPalyndrome(string + 1, length - 2);
}

void problem7()
{
    char string[50];

    std::cout << "Enter a string: ";
    std::cin.getline(string, 50);

    std::cout << "Is palyndrome: " << std::boolalpha << isPalyndrome(string, strlen(string));
}

int compare(char string1[], char string2[])
{
    if (*string1 < *string2)
    {
        return -1;
    }
    else if (*string1 > *string2)
    {
        return 1;
    }
    else if (*string1 == *string2 && *string1 == '\0')
    {
        return 0;
    }

    return compare(string1 + 1, string2 + 1);
}

void problem8()
{
    char string1[50];
    char string2[50];

    std::cout << "Enter string 1: ";
    std::cin.getline(string1, 50);

    std::cout << "Enter string 2: ";
    std::cin.getline(string2, 50);

    int n = compare(string1, string2);

    if (n < 0)
    {
        std::cout << "string 1 is before string 2" << std::endl;
    }
    else if (n == 0)
    {
        std::cout << "string 1 is equal to string 2" << std::endl;
    }
    else
    {
        std::cout << "string 1 is after string 2" << std::endl;
    }
}

bool findPath(int matrix[][100], int rows, int cols, int row, int col)
{
    if (row == 0 && col == 0)
    {
        std::cout << "(0, 0)";
        return true;
    }

    if (col > 0 && matrix[row][col - 1] == 1 && findPath(matrix, rows, cols, row, col - 1) > 0)
    {
        std::cout << ", (" << row << ", " << col << ")";
        return true;
    }
    if (row > 0 && matrix[row - 1][col] == 1 && findPath(matrix, rows, cols, row - 1, col) > 0)
    {
        std::cout << ", (" << row << ", " << col << ")";
        return true;
    }
    if (col > 0 && row > 0 && matrix[row - 1][col - 1] == 1 && findPath(matrix, rows, cols, row - 1, col - 1) > 0)
    {
        std::cout << ", (" << row << ", " << col << ")";
        return true;
    }

    return false;
}

void problem9()
{
    int n, m;
    int matrix[100][100];

    std::cout << "Enter n: ";
    std::cin >> n;

    std::cout << "Enter m: ";
    std::cin >> m;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            std::cout << "Enter matrix[" << i << "][" << j << "]: ";
            std::cin >> matrix[i][j];
        }
    }

    findPath(matrix, n, m, n - 1, m - 1);
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
    // problem9();

    return 0;
}