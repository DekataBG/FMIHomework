#include <iostream>
#include <cstring>

void swap(char str[], int i1, int i2)
{
    int temp = str[i1];
    str[i1] = str[i2];
    str[i2] = temp;
}

void permutations(char str[], int start, int end)
{
    if(start == end - 1)
    {
        std::cout << str << std::endl;
    }

    for(int i = start; i < end; i++)
    {
        swap(str, start, )
        permutations(str);

        addCharElement(str, i, removed);
    }
}

void problem1()
{
    char string[100];

    std::cout << "Enter a string: ";
    std::cin.getline(string, 100);

    permutations(string);
}

void problem2()
{
    int a, b, p;

    std::cout << "Enter a: ";
    std::cin >> a;

    std::cout << "Enter b: ";
    std::cin >> b;

    std::cout << "Enter p: ";
    std::cin >> p;

}

void removeIntElement(int numbers[], int size, int index)
{
    for(int i = index; i < size - 1; i++)
    {
        numbers[i] = numbers[i + 1];
    }
}

void addIntElement(int numbers[], int size, int index, int element)
{
    for(int i = size; i > index; i--)
    {
        numbers[i] = numbers[i - 1];
    }

    numbers[index] = element;
}

void printIntArray(int numbers[], int size)
{
    for(int i = 0; i < size; i++)
    {
        std::cout << numbers[i] << " ";
    }

    std::cout << std::endl;
}

void generateCombinations(int numbers[], int size, int elements[], int count, int k, int index)
{
    if(count == k)
    {
        printIntArray(elements, count);
        return;
    }

    for(int i = index; i < size; i++)
    {
        int removedElement = numbers[i];

        elements[count] = removedElement;

        removeIntElement(numbers, size, i);

        generateCombinations(numbers, size - 1, elements, count + 1, k, i);

        addIntElement(numbers, size, i, removedElement);
    }
}

void problem3()
{
    int n;
    int array[100], numbersToPrint[100];

    std::cout << "Enter n: ";
    std::cin >> n;

    for(int i = 0; i < n; i++)
    {
        std::cout << "Enter element: ";
        std::cin >> array[i];
    }

    for(int k = 0; k <= n; k++)
    {
        generateCombinations(array, n, numbersToPrint, 0, k, 0);
    }
}

void problem4()
{
    
}

void problem5()
{
    
}


int main()
{
    problem1();
    //problem2();
    //problem3();
    //problem4();
    //problem5();

    return 0;
}