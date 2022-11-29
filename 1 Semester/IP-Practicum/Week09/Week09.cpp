#include <iostream>

void swapValues(int &a, int &b)
{   
    int temp = a;
    a = b;
    b = temp;
}

void problem1()
{
    int a, b;

    std::cout << "Enter a: ";
    std::cin >> a;

    std::cout << "Enter b: ";
    std::cin >> b;

    swapValues(a, b);

    std::cout << a << " " << b;
}

void add(int x, int y, int &z)
{
    z = x + y;
}

void problem2()
{
    int x, y, z;

    std::cout << "Enter x: ";
    std::cin >> x;

    std::cout << "Enter y: ";
    std::cin >> y;

    add(x, y, z);

    std::cout << "z: " << z << std::endl;
}

void printSequence(int array[], int *ptr)
{
    int index = 0;

    while(*(array + index) != *ptr)
    {
        std::cout << *(array + index) << " ";
        index++;
    }

    std::cout << *(array + index) << std::endl;
}

void problem3()
{
    int array[5] = {5, 2, 3, -6, 9};

    int *ptr = &array[4];

    printSequence(array, ptr);
}

int *middleElementPointer(int array[], int *ptr)
{
    int index = 0;

    while(*(array + index) != *ptr)
    {
        index++;
    }

    return array + (index / 2);
}

void problem4()
{
    int array[7] = {7, 2, -5, 12, 16, 16, 19};

    int *ptr = &array[7];

    std:: cout << *middleElementPointer(array, ptr);
}

int findAverage(int array[], int &size, int &average)
{
    for(int i = 0; i < size; i++)
    {
        average += array[i];
    }

    average /= size;
}

void problem5()
{
    int array[100];
    int size, average = 0;

    std::cout << "Enter size: ";
    std::cin >> size;

    for(int i = 0; i < size; i++)
    {
        std::cout << "Enter element for the array: ";
        std::cin >> array[i];
    }

    findAverage(array, size, average);
    std::cout << "Average: " << average;
}

void findLetters(char word, char *lastLetter)
{

}

void problem6()
{
    char word[7] = {'r', 'p', 'q', 's', 'f', 'a', 'u'};

    std::cout << "Enter a string: ";
    std::cin >> word;

    findLetters(word, &);
}


int main()
{
    // problem1();
    // problem2();
    // problem3();
    // problem4();
    // problem5();
    problem6();


    return 0;
}