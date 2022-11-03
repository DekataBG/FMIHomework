#include <iostream>
#include <string.h>

void problem1()
{
    int n;

    std::cout << "Enter n: ";
    std::cin >> n;

    int array[20];

    for(int i = 0; i < n; i++)
    {
        std::cout << "Enter element: ";
        std::cin >> array[i];
    }

    for(int i = 0; i < n; i++)
    {
        std::cout << array[i] << " ";
    }
}

void problem2()
{
    int n;
    long product = 1;

    std::cout << "Enter n: ";
    std::cin >> n;


    for(int i = 0; i < n; i++)
    {
        int element;

        std::cout << "Enter element: ";
        std::cin >> element;

        product *= element;
    }

    std::cout << "Product: " << product;
}

void problem3()
{
    char symbols[50];

    std::cout << "Enter a string: ";
    std::cin.getline(symbols, 50);

    if(symbols[0] >= 65 && symbols[0] <= 90)
    {
        std::cout << symbols;
    }
}

void problem4()
{
    char sentence[50];

    std::cout << "Enter a string: ";
    std::cin.getline(sentence, 50);

    switch (sentence[strlen(sentence) - 1])
    {
    case '.':
        std::cout << "Declarative sentence";
        break;
    case '?':
        std::cout << "Interrogative sentence";
        break;
    case '!':
        std::cout << "Exclamative sentence";
        break;
    default:
        std::cout << "Not a sentence";
        break;
    }
}

void problem5()
{
    int n, sum = 0;

    std::cout << "Enter n: ";
    std::cin >> n;

    for(int i = 0; i < n; i++)
    {
        int element;

        std::cout << "Enter element: ";
        std::cin >> element;

        if(element % 2 == 0)
        {
            sum += element;
        }
    }

    std::cout << "Sum of even elements: " << sum;
}

void problem6()
{
    int n, sum = 0;

    std::cout << "Enter n: ";
    std::cin >> n;

    for(int i = 0; i < n; i++)
    {
        int element;

        std::cout << "Enter element: ";
        std::cin >> element;

        if(i % 3 == 0)
        {
            sum += element;
        }
    }

    std::cout << "Sum of every third element is  " << sum;
}

void problem7()
{
    int n;

    std::cout << "Enter n: ";
    std::cin >> n;

    int array[20];

    for(int i = 0; i < n; i++)
    {
        std::cout << "Enter element: ";
        std::cin >> array[i];
    }

    for(int i = n - 1; i >= 0; i--)
    {
        std::cout << array[i] << " ";
    }
}

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

void problem8()
{
    int size, elem;

    std::cout << "Enter size: ";
    std::cin >> size;

    std::cout << "Enter element to search: ";
    std::cin >> elem;

    int array[20];

    for(int i = 0; i < size; i++)
    {
        std::cout << "Enter element: ";
        std::cin >> array[i];
    }

    std::cout << std::boolalpha << contains(array, size, elem);
}

void replace(int array[], int size, int find, int repl)
{
    for(int i = 0; i < size; i++)
    {
        if(array[i] == find)
        {
            array[i] = repl;
        }
    }

    for(int i = 0; i < size; i++)
    {
        std::cout << array[i] << " ";
    }
}

void problem9()
{
    int size, find, repl;

    std::cout << "Enter size: ";
    std::cin >> size;

    std::cout << "Enter element to find: ";
    std::cin >> find;

    std::cout << "Enter element to replace: ";
    std::cin >> repl;

    int array[20];

    for(int i = 0; i < size; i++)
    {
        std::cout << "Enter element: ";
        std::cin >> array[i];
    }

    replace(array, size, find, repl);
}

void problem10()
{
    int size;

    std::cout << "Enter array size: ";
    std::cin >> size;

    int array[20];
    int newArray[20];

    for(int i = 0; i < size; i++)
    {
        std::cout << "Enter element: ";
        std::cin >> array[i];
    }

    for(int i = 0; i < size; i++)
    {
        int element = array[i];
        int ctr = 0;

        for(int j = i + 1; j < size; j++)
        {
            if(array[j] < element)
            {
                ctr++;
            }
        }

        newArray[i] = ctr;
    }

    for(int i = 0; i < size; i++)
    {
        std::cout << newArray[i] << " ";
    }
}

void problem1HW()
{
    int size;

    std::cout << "Enter array size: ";
    std::cin >> size;

    int array[256];

    for(int i = 0; i < size; i++)
    {
        std::cout << "Enter element: ";
        std::cin >> array[i];
    }

    int maxIndex = 0, minIndex = 0;
    for(int i = 1; i < size; i++)
    {
        if(array[maxIndex] < array[i])
        {
            maxIndex = i;
        }

        if(array[minIndex] > array[i])
        {
            minIndex = i;
        }
    }

    int biggerIndex = maxIndex > minIndex ? maxIndex : minIndex;
    int smallerIndex = maxIndex + minIndex - biggerIndex;

    int sum = 0;
    for(int i = smallerIndex + 1; i < biggerIndex; i++)
    {
        sum += array[i];
    }

    std::cout << "The sum is " << sum;
}

void problem2HW()
{
    int symbols[255];

    for(int i = 0; i < 255; i++)
    {
        symbols[i] = 0;
    }

    char string[100];

    std::cout << "Enter a string: ";
    std::cin.getline(string, 100);

    int length = strlen(string);

    for(int i = 0; i < length; i++)
    {
        symbols[string[i]]++;
    }

    for(int i = 0; i < length; i++)
    {
        if(symbols[string[i]] == 1)
        {
            std::cout << string[i] << " -> " << "1\n";
        }
        else if(symbols[string[i]] > 1)
        {
            std::cout << string[i] << " -> " << symbols[string[i]] << std::endl;
            symbols[string[i]] = 0;
        }
    }
}

int getLength(int array[])
{
    for(int i = 0; i < 257; i++)
    {
        if(array[i] == '\0')
        {
            return i;
        }
    }

    return 0;
}

void problem3HW()
{
    int size1, size2;

    std::cout << "Enter array size1: ";
    std::cin >> size1;

    std::cout << "Enter array size2: ";
    std::cin >> size2;

    int array1[256];
    int array2[256];

    for(int i = 0; i < 256; i++)
    {
        array1[i] = 0;
        array2[i] = 0;
    }

    for(int i = 0; i < size1; i++)
    {
        int element;
        std::cout << "Enter element for the first array: ";
        std::cin >> element;

        if(!contains(array1, size1, element))
        {
            int length = getLength(array1);

            array1[length] = element;
        }
    }

    for(int i = 0; i < size2; i++)
    {
        int element;

        std::cout << "Enter element for the second array: ";
        std::cin >> element;

        if(!contains(array2, size2, element))
        {
            int length = getLength(array2);

            array2[length] = element;
        }
    }

    bool equal = true;

    int length1 = getLength(array1);
    int length2 = getLength(array2);

    
    if(length1 != length2)
    {
        equal = false;
    }

    for(int i = 0; i < length1 && equal; i++)
    {
        if(!contains(array2, size2, array1[i]))
        {
            equal = false;
        }
        if(!contains(array1, size1, array2[i]))
        {
            equal = false;
        }
    }

    if(equal)
    {
        std::cout << "The two sets are equal";
    }
    else
    {
        std::cout << "The two sets are NOT equal";
    }
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
    //problem1HW();
    //problem2HW();
    //problem3HW();


    return 0;
}