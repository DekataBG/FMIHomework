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

void removeElement(int numbers[], int size, int index)
{
    for(int i = index; i < size - 1; i++)
    {
        numbers[i] = numbers[i + 1];
    }
}

void addElement(int numbers[], int size, int index, int element)
{
    for(int i = size; i > index; i--)
    {
        numbers[i] = numbers[i - 1];
    }

    numbers[index] = element;
}

void printArray(int numbers[], int size)
{
    for(int i = 0; i < size; i++)
    {
        std::cout << numbers[i] << " ";
    }

    std::cout << std::endl;
}

void generateCombinations(int numbers[], int size, int index, int elements[], int count, int k)
{
    if(count == k)
    {
        printArray(elements, count);
        return;
    }

    for(int i = index; i < size; i++)
    {
        int removedElement = numbers[i];

        elements[count] = removedElement;

        removeElement(numbers, size, i);

        generateCombinations(numbers, size - 1, i, elements, count + 1, k);

        addElement(numbers, size, i, removedElement);
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

    generateCombinations(array, n, 0, numbersToPrint, 0, k);
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