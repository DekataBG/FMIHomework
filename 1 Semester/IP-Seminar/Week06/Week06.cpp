#include <iostream>
#include <cmath>
#include <cstring>

bool contains(int array[], int size, int elem)
{
    for(int i = 0; i < size; i++)
    {
        if(array[i] == elem)
        {
            return true;
        }
    }

    return false;
}

void problem1()
{
    int n, elem;

    std::cout << "Enter size: ";
    std::cin >> n;

    int array[100];

    for(int i = 0; i < n; i++)
    {
        std::cout << "Enter element for the array: ";
        std::cin >> array[i];
    }

    std::cout << "Enter element to find: ";
    std::cin >> elem;

    std::cout << std::boolalpha << contains(array, n, elem);
}

void replace(int array[], int size, int find, int search)
{
    for(int i = 0; i < size; i++)
    {
        if(array[i] == find)
        {
            array[i] = search;
        }
    }

    for(int i = 0; i < size; i++)
    {
        std::cout << array[i] << " ";
    }
}

void problem2()
{
    int n, find, repl;

    std::cout << "Enter size: ";
    std::cin >> n;

    int array[100];

    for(int i = 0; i < n; i++)
    {
        std::cout << "Enter element for the array: ";
        std::cin >> array[i];
    }

    std::cout << "Enter element to find: ";
    std::cin >> find;

    std::cout << "Enter element to replace: ";
    std::cin >> repl;

    replace(array, n, find, repl);
}

bool startsWith(char start[], char str[])
{
    int length = strlen(start);
    int strLength = strlen(str);

    if(length > strLength)
    {
        return false;
    }  

    for(int i = 0; i < length; i++)
    {
        if(start[i] != str[i])
        {
            return false;
        }
    }

    return true;
}

bool endsWith(char end[], char str[])
{
    int length = strlen(end);
    int strLength = strlen(str);

    if(length > strLength)
    {
        return false;
    }   

    for(int i = strLength - length; i < strLength; i++)
    {
        if(end[i - (strLength - length)] != str[i])
        {
            return false;
        }
    }

    return true;
}

void problem3()
{
    char string[100];
    char start[100];
    char end[100];

    std::cout << "Enter a string: ";
    std::cin.getline(string, 100);

    std::cout << "Enter a start string: ";
    std::cin.getline(start, 100);

    std::cout << "Enter an end string: ";
    std::cin.getline(end, 100);

    std::cout << "Starts with: " << std::boolalpha << startsWith(start, string) << "\nEnds with: " << std::boolalpha << endsWith(end, string);
}

bool arithmeticSequence(int array[], int size)
{
    if(size < 2)
    {
        return true;
    }

    int difference = array[1] - array[0];

    for(int i = 2; i < size; i++)
    {
        if(difference != array[i] - array[i - 1])
        {
            return false;
        }
    }

    return true;
}

void problem4()
{
    int n;

    std::cout << "Enter size: ";
    std::cin >> n;

    int array[100];

    for(int i = 0; i < n; i++)
    {
        std::cout << "Enter element for the array: ";
        std::cin >> array[i];
    }

    std::cout << "Array is arithmetic sequence: " << std::boolalpha << arithmeticSequence(array, n);
}

void problem5()
{
    int n, x, sum = 0;

    std::cout << "Enter size: ";
    std::cin >> n;

    int array[100];

    for(int i = 0; i < n; i++)
    {
        std::cout << "Enter element for the array: ";
        std::cin >> array[i];
    }

    std::cout << "Enter x: ";
    std::cin >> x;

    for(int i = 0; i < n; i++)
    {
        sum += array[i] * pow(x, i);
    }

    std::cout << "f(x) = " << sum;
}

void substring(char source[], int beginIndex, int endIndex, char target[])
{
    for(int i = beginIndex; i <= endIndex; i++)
    {
        target[i - beginIndex] = source[i];
    }

    for(int i = 0; i < endIndex - beginIndex + 1; i++)
    {
        std::cout << target[i];
    }
}

void problem6()
{
    int beginIndex, endIndex;
    char source[100];
    char target[100];

    std::cout << "Enter begin index: ";
    std::cin >> beginIndex;

    std::cout << "Enter end index: ";
    std::cin >> endIndex;

    std::cin.ignore();

    std::cout << "Enter source string: ";
    std::cin.getline(source, 100);

    substring(source, beginIndex, endIndex, target);
}

void problem7()
{
    //unclear task
}

bool compareArrays(int arr1[], int size1, int arr2[], int size2)
{
    for(int i = 0; i < size1; i++)
    {
        for(int j = 0; j < size2; j++)
        {
            if(arr1[i] > arr2[j])
            {
                return false;
            }
        }
    }

    return true;
}

void problem8()
{
    int n, m;

    std::cout << "Enter size1: ";
    std::cin >> n;


    std::cout << "Enter size2: ";
    std::cin >> m;

    int array1[100];
    int array2[100];

    for(int i = 0; i < n; i++)
    {
        std::cout << "Enter element for the first array: ";
        std::cin >> array1[i];
    }

    for(int i = 0; i < m; i++)
    {
        std::cout << "Enter element for the second array: ";
        std::cin >> array2[i];
    }

    std::cout << std::boolalpha << compareArrays(array1, n, array2, m);
}

void trim(char original[], char trimmed[])
{
    int length = strlen(original);
    int startIndex, endIndex;

    for(int i = 0; i < length; i++)
    {
        if(original[i] != ' ')
        {
            startIndex = i;
            break;
        }
    }

    for(int i = length - 1; i > 0; i--)
    {
        if(original[i] != ' ')
        {
            endIndex = i;
            break;
        }
    }

    for(int i = startIndex; i <= endIndex; i++)
    {
        trimmed[i - startIndex] = original[i];
    }
}

void problem9()
{
    char original[50];
    char trimmed[50];

    std::cout << "Enter string to trim: ";
    std::cin.getline(original, 50);

    trim(original, trimmed);
    
    std::cout << trimmed;   
}

void problem10()
{
    int n;

    std::cout << "Enter size: ";
    std::cin >> n;

    int array[100];
    int newArray[100];

    for(int i = 0; i < n; i++)
    {
        std::cout << "Enter element for the array: ";
        std::cin >> array[i];
    }

    for(int i = 0; i < n; i++)
    {
        int ctr = 0;

        for(int j = i; j < n; j++)
        {
            if(array[j] < array[i])
            {
                ctr++;
            }
        }

        newArray[i] = ctr;
    }

    for(int i = 0; i < n; i++)
    {
        std::cout << newArray[i] << " ";
    }
}

void problem11()
{
    //unclear task
}

void problem12()
{
    //unclear task
}


int main()
{
    //problem1();
    //problem2();
    //problem3();
    //problem4();
    //problem5();
    //problem6();
    //problem7();
    //problem8();
    //problem9();
    //problem10();
    //problem11();
    //problem12();


    return 0;
}