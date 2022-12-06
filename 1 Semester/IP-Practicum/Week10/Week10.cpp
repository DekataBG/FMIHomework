#include <iostream>

int exponent(int a, int n)
{
    if(n == 1)
    {
        return a;
    }

    return a * exponent(a, n - 1);
}

void problem1()
{
    int a, n;

    std::cout << "Enter a: ";
    std::cin >> a;

    std::cout << "Enter n: ";
    std::cin >> n;

    std::cout << a << "^" << n << " = " << exponent(a, n);
}

int factorial(int n)
{
    if(n == 1)
    {
        return 1;
    }

    return n * factorial(n - 1);
}

void problem2()
{
    int n;

    std::cout << "Enter n: ";
    std::cin >> n;

    std::cout << n << "! = " << factorial(n);
}

int fibonacci(int n)
{
    if(n == 0)
    {
        return 0;
    }

    if(n == 1)
    {
        return 1;
    }

    return fibonacci(n - 2) + fibonacci(n - 1);
}

void problem3()
{
    int n;

    std::cout << "Enter n: ";
    std::cin >> n;

    std::cout << "F" << n << " = " << fibonacci(n);
}

int numberOfDigits(int n, int digits)
{
    if(n < 9)
    {
        return ++digits;
    }

    return numberOfDigits(n / 10, ++digits);
}

void problem4()
{
    int n;

    std::cout << "Enter n: ";
    std::cin >> n;

    std::cout << n << " has " << numberOfDigits(n, 0) << " digits";
}

void reverse(int n, int reverses)
{
    if(n == 0 && reverses != 0)
    {
        return;
    }

    std::cout << n % 10;

    reverse(n / 10, ++reverses);
}

void problem5()
{
    int n;

    std::cout << "Enter n: ";
    std::cin >> n;

    reverse(n, 0);
}

int findSum(int array[], int size, int index, int sum)
{
    if(index == size)
    {
        return sum;
    }

    return findSum(array, size, ++index, sum + array[index]);
}

void problem6()
{
    int n;
    int array[100];

    std::cout << "Enter n: ";
    std::cin >> n;

    for(int i = 0; i < n; i++)
    {
        std::cout << "Enter element: ";
        std::cin >> array[i];
    }

    std::cout << "The sum is " << findSum(array, n, 0, 0);
}

void printFigure(int n)
{
    if(n == 0)
    {
        return;
    }

    for(int i = 0; i < n; i++)
    {
        std::cout << "*";
    }

    std::cout << std::endl;

    printFigure(n - 1);

    for(int i = 0; i < n; i++)
    {
        std::cout << "#";
    }

    std::cout << std::endl;
}

void problem7()
{
    int n;
    int array[100];

    std::cout << "Enter n: ";
    std::cin >> n;

    printFigure(n);
}

void generateBoolVectors(int n, int number)
{
    int newNumber = number;

    for(int i = n; i >= 1; i--)
    {
        std::cout << newNumber / exponent(2, i);
        newNumber = newNumber % exponent(2, i);
    }
    std::cout << std::endl;

    if(number == exponent(2, n + 1) - 2)
    {
        return;
    }

    generateBoolVectors(n, number + 2);
}

void problem8()
{
    int n;
    int array[100];

    std::cout << "Enter n: ";
    std::cin >> n;

    generateBoolVectors(n, 0);
}

void generateCombinations(int numbers[], int k, int count, int index, int numbersToPrint[])
{
    if(count == k + 1)
    {
        for(int i = 0; i < k; i++)
        {
            std::cout << numbersToPrint[i];
        }
        std::cout << std::endl;

        return;
    }

    numbersToPrint[count] = numbers[index];

    generateCombinations(numbers, k, ++count, ++index, numbersToPrint);
}

void generateCombinations2(int numbers[],int n, int k, int index, int count)
{
    if(count == k)
    {
        std::cout << std::endl;
        return;
    }

    std::cout << numbers[index] << " ";
    for(int i = index + 1; i < n; i++)
    {
        generateCombinations2(numbers, n, k, i, ++count);
    }
}

void problem9()
{
    int n, k;
    int array[100], numbersToPrint[100];

    std::cout << "Enter n: ";
    std::cin >> n;

    std::cout << "Enter k: ";
    std::cin >> k;

    for(int i = 0; i < n; i++)
    {
        std::cout << "Enter element: ";
        std::cin >> array[i];
    }

    // generateCombinations(array, k, 0, 0, numbersToPrint);
    generateCombinations2(array, n, k, -1, 0);
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
    problem9();


    return 0;
}