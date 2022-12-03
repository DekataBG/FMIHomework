#include <iostream>
#include <cstring>

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

    while((array + index) != ptr)
    {
        std::cout << *(array + index) << " ";
        index++;
    }

    std::cout << *(array + index) << std::endl;
}

void problem3()
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

    printSequence(array, &array[n - 1]);
}

int *middleElementPointer(int array[], int *ptr)
{
    int index = 0;

    while((array + index) != ptr)
    {
        index++;
    }

    return array + (index / 2);
}

void problem4()
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

    std:: cout << *middleElementPointer(array, &array[n - 1]);
}

void findAverage(int array[], int &size, int &average)
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

void findLetters(char word[], char *lastLetter)
{
    int vowels = 0, consonants = 0;

    while(lastLetter != &word[0])
    {
        if(*lastLetter <= 'z' && *lastLetter >= 'A')
        {
            if(*lastLetter == 'a' || *lastLetter == 'y' || *lastLetter == 'o' 
                || *lastLetter == 'u' || *lastLetter == 'e' || *lastLetter == 'i')
            {
                vowels++;
            }
            else
            {
                consonants++;
            }
        }

        *lastLetter--;
    }

    if(*lastLetter <= 'z' && *lastLetter >= 'A')
    {
        if(*lastLetter == 'a' || *lastLetter == 'y' || *lastLetter == 'o' 
            || *lastLetter == 'u' || *lastLetter == 'e' || *lastLetter == 'i')
        {
            vowels++;
        }
        else
        {
            consonants++;
        }
    }

    std::cout << "Vowels: " << vowels << std::endl 
        << "Consonants: " << consonants << std::endl;
}

void problem6()
{
    char word[50];

    std::cout << "Enter a string: ";
    std::cin >> word;

    findLetters(word, &word[strlen(word)]);
}

void sort(int array[], int *ptr)
{
    int *ptrCpy = ptr;

    bool sorted = false;
    while(!sorted)
    {
        ptr = ptrCpy;
        sorted = true;

        while(ptr != &array[0])
        {
            if(*ptr < *(ptr - 1))
            {
                swapValues(*ptr, *(ptr - 1));
                sorted = false;
            }

            ptr--;
        }
    }
}

void problem7()
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

    sort(array, &array[n]);

    printSequence(array, &array[n - 1]);
}

void game(int array[], int size, int *ptr)
{
    bool found = false;

    int ctr = 0;
    while (!found)
    {
        if(array + ctr == ptr)
        {
            std::cout << "Misho found the element" << std::endl;
            found = true;
        }
        if(array + size - 1 - ctr == ptr)
        {
            std::cout << "Ani found the element" << std::endl;
            found = true;
        }

        ctr++;
    }
    
}

void problem8()
{
    int n, index;
    int array[100];

    std::cout << "Enter n: ";
    std::cin >> n;

    for(int i = 0; i < n; i++)
    {
        std::cout << "Enter element: ";
        std::cin >> array[i];
    }

    std::cout << "Enter index of element: ";
    std::cin >> index;

    game(array, n, &array[index]);
}

void problem9()
{
    int n;

    std::cout << "Enter n: ";
    std::cin >> n;

    char *ptr = (char*) &n;

    int newVar = *ptr;

    std::cout << newVar << std::endl;
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