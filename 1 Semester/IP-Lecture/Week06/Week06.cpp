#include <iostream>
#include <cmath>
#include <cstring>

int reduceN(int n)
{
    n /= 10;
    int copyOfN = n;

    int digits = 0;
    do
    {
        copyOfN /= 10;
        digits++;
    } while(copyOfN > 0);

    n -= (n / (int)pow(10, digits - 1)) * pow(10, digits - 1);

    return n;
}

bool contains(unsigned n, unsigned k)
{
    while (k > 0)
    {
        if(n % 10 != k % 10)
        {
            return false;
        }

        n /= 10;
        k /= 10;
    }

    return true;
}

void problem1()
{
    unsigned int n, k;

    std::cout << "Enter n: ";
    std::cin >> n;

    std::cout << "Enter k: ";
    std::cin >> k;

    n = reduceN(n);

    bool in = false;
    do
    {
        in = in || contains(n, k);
        n /= 10;
    } while(n > 0);

    std::cout << std::boolalpha << in;
}

bool isNeighbor(unsigned n)
{
    while(n > 10)
    {
        int last = n % 10;
        int current = (n / 10) % 10;

        if(last == current)
        {
            return false;
        }

        n /= 10;
    } 

    return true;
}

void problem2()
{
    unsigned a, b, max = -1, min = -1;

    std::cout << "Enter a: ";
    std::cin >> a;

    std::cout << "Enter b: ";
    std::cin >> b;

    for(int i = b; i >= a; i--)
    {
        if(isNeighbor(i))
        {
            max = i;
            break;
        }
    }

    for (int i = a; i <= b; i++)
    {
        if(isNeighbor(i))
        {
            min = i;
            break;
        }
    }

    if(min == -1)
    {
        std::cout << "No adjecent numbers";
    }
    else
    {
        std::cout << max-min;
    }
    
}

void moveToFront(char array[])
{
    int size = strlen(array);
    char element = array[size - 1];

    for(int i = size - 1; i > 0; i--)
    {
        array[i] = array[i - 1];
    }

    array[0] = element;
}

void rotate(char firstArray[], char rotatedArray[], int characters)
{
    strcpy(rotatedArray, firstArray);

    for(int i = 0; i < characters; i++)
    {
        moveToFront(rotatedArray);
    }
}

bool containsRotation(char array[], char combination[])
{
    int combLength = strlen(combination);
    int arrLength = strlen(array);

    if(combLength > arrLength)
    {
        return false;
    }

    for(int i = arrLength - 1; i >= arrLength - combLength; i--)
    {
        if(array[i] != combination[i - arrLength + combLength])
        {
            return false;
        }
    }

    return true;
}

void copyArray(char destination[], char target[], int size)
{
    for(int i = 0; i < size; i++)
    {
        destination[i] = target[i];
    }

    destination[size] = '\0';
}

bool containsAllLetters(char array[], char letters[])
{
    char lettersHistogram1[26], lettersHistogram2[26];
    int length1 = strlen(array);
    int length2 = strlen(letters);

    for(int i = 0;  i < 26; i++)
    {
        lettersHistogram1[i] = 0;
        lettersHistogram2[i] = 0;
    }


    for(int i = 0; i < length1; i++)
    {
        char letter = array[i] - 'a';

        lettersHistogram1[letter]++;
    }

    for(int i = 0; i < length2; i++)
    {
        char letter = letters[i] - 'a';

        lettersHistogram2[letter]++;
    }

    for(int i = 0;  i < 26; i++)
    {
        if(lettersHistogram1[i] < lettersHistogram2[i])
        {
            return false;
        }
    }

    return true;
}

void problem3()
{
    int n, k;
    char firstArr[1024];
    char secondArr[1024];

    std::cout << "Enter size1: ";
    std::cin >> n;

    std::cout << "Enter size2: ";
    std::cin >> k;

    std::cin.ignore(2, '\n');

    std::cout << "Enter first array: ";
    std::cin.getline(firstArr, n + 1);

    std::cout << "Enter second array: ";
    std::cin.getline(secondArr, k + 1);


    bool contains = false;
    for(int i = 0; i < k; i++)
    {
        char rotatedArray[1024];
        rotate(secondArr, rotatedArray, i);

        for(int j = 0; j <= n - k; j++)
        {
            char copy[1024];

            copyArray(copy, firstArr, n - j);

            if(containsRotation(copy, rotatedArray))
            {

                std::cout << "Rotation \"" << rotatedArray << "\" found after deleting " 
                    << n - j - k << " characters from the start and " 
                    << j << " characters from the end";

                return;
            }
        }
    }
}

int main()
{
    //problem1();
    //problem2();
    //problem3();
    

    return 0;
}