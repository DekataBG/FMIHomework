#include <iostream>

void problem1()
{
    int a = 5;
    int *b = &a;

    *b = 6;

    std::cout << a;
}

void changeNumber(int* number)
{
    if(*number % 2 == 0)
    {
        *number = 0;
    }
}

void problem2()
{
    int number;

    std::cout << "Enter a number: ";
    std::cin >> number;

    int *ptr = &number;

    changeNumber(ptr);

    std::cout << "New value: " << number << std::endl;
}

void swap(int &a , int &b)
{
    int temp = a;

    a = b;
    b = temp;
}

void problem3()
{
    int a, b;

    std::cout << "Enter a: ";
    std::cin >> a;
    
    std::cout << "Enter b: ";
    std::cin >> b;

    swap(a, b);

    std::cout << "a: " << a << "\nb: " << b;
}

void populateArr(int* start, int size)
{
    for(int i = 0; i < size; i++)
    {
        std::cout << "Enter element: ";
        std::cin >> *(start + i);
    }
}

void printArr(int* start, int size)
{
    for(int i = 0; i < size; i++)
    {
        std::cout << *(start + i) << " ";
    }
}

void problem4()
{
    int arr[100];
    int size;

    std::cout << "Enter size: ";
    std::cin >> size;

    populateArr(arr, size);
    printArr(arr, size);
}

void capitalizeChars (char* word)
{
    while (*word != '\0')
    {
        if(*word >= 'a' && *word <= 'z')
        {
            *word -= 'a' - 'A';
        }

        word++;
    }
    
}

void problem5()
{
    char word[50];

    std::cout << "Enter a word: ";
    std::cin >> word;

    capitalizeChars(word);

    std::cout << word << std::endl;
}

void count(int* arr, int size, int &find, int &occurences)
{
    for(int i = 0; i < size; i++)
    {
        if(*(arr + i) == find)
        {
            occurences++;
        }
    }
}

void problem6()
{
    int size, find, occurance = 0;
    int array[50];

    std::cout << "Enter size: ";
    std::cin >> size;

    populateArr(array, size);

    std::cout << "Enter element to find: ";
    std::cin >> find;

    count(array, size, find, occurance);

    std::cout << "Count: " << occurance << std::endl;
}

char* nextSentence(char* text)
{ 
    while(*text && *text != '.')
    {
        text++;
    }

    if(text)
    {
        return text + 1;
    }

    return nullptr;
}

void problem7()
{
    char sentence[50];

    std::cin.getline(sentence, 50);   

    std::cout << *nextSentence(sentence) << std::endl;
}

void findTheGreaterValue(int x, int y, int *&ptr)
{
    ptr = x > y ? &x : &y;
}

void problem8()
{
    int x, y;
    int *ptr;

    std::cout << "Enter x: ";
    std::cin >> x;
    
    std::cout << "Enter y: ";
    std::cin >> y;

    findTheGreaterValue(x, y, ptr);

    std::cout << "The bigger number is " << *ptr << std::endl;
}

void deleteElement(int *arr, int &size, int index)
{
    for(int i = index; i < size - 1; i++)
    {
        *arr = *(arr + i);
    }

    size--;
}

void problem9()
{
    int size, index;
    int array[50];

    std::cout << "Enter size: ";
    std::cin >> size;

    populateArr(array, size);

    std::cout << "Enter index: ";
    std::cin >> index;

    deleteElement(array, size, index);

    std::cout << "Size: " << size << std::endl; 
    printArr(array, size);
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