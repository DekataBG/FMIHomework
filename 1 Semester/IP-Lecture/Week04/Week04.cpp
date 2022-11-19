// Problems from section 3.2 from https://github.com/stranxter/lecture-notes/blob/master/homeworks/Problems%20in%20Programming.pdf

#include <iostream>
#include <cmath>
#include <cstring>

void problem3_8()
{
    char symbols[255];
    int n;
    
    std::cout << "Enter n: ";
    std::cin >> n;

    std::cout << "Enter sequence: ";
    for(int i = 0; i < n; i++)
    {
        std::cin >> symbols[i];
    }

    int ctr = 0;
    for(int i = 0; i < n; i++)
    {
        if(symbols[i] >= '0' && symbols[i] <= '9')
        {
            std::cout << symbols[i];
        }
    }
    for(int i = 0; i < n; i++)
    {
        if(symbols[i] >= 'a' && symbols[i] <= 'z')
        {
            std::cout << symbols[i];
        }
    }
    for(int i = 0; i < n; i++)
    {
        if(!((symbols[i] >= '0' && symbols[i] <= '9') || (symbols[i] >= 'a' && symbols[i] <= 'z')))
        {
            std::cout << symbols[i] << " " << std::endl;
        }
    }
}

void problem3_9()
{
    char symbols[255];
    int n;
    
    std::cout << "Enter n: ";
    std::cin >> n;

    std::cout << "Enter sequence: ";
    for(int i = 0; i < n; i++)
    {
        std::cin >> symbols[i];
    }

    bool isSymmetric = true;
    for(int i = 0; i < n; i++)
    {
        if(symbols[i] != symbols[n - i -1])
        {
            isSymmetric = false;
            break;
        }
    }    

    std::cout << (isSymmetric ? "The sequence is symmetric" : "The sequence is not symmetric") << std::endl;
}

void problem3_10()
{
    char string1[256];
    char string2[256];
    int common = 0;

    std::cout << "Enter string1: ";
    std::cin.getline(string1, 256);

    std::cout << "Enter string2: ";
    std::cin.getline(string2, 256);

    int length1 = strlen(string1);
    int length2 = strlen(string2);
    int length = std::min(length1, length2);

    for(int i = 0; i < length; i++)
    {
        if(string1[i] != string2[i])
        {
            break;
        }

        common++;
    }

    std::cout << common << std::endl;
}

void problem3_11()
{
    char string[256];

    std::cout << "Enter a string: ";
    std::cin.getline(string, 256);

    int length = strlen(string);

    for(int i = 0; i < length; i++)
    {
        if(string[i] >= 'a' && string[i] <= 'z')
        {
            string[i] -= 'a' - 'A';
        }
    }

    std::cout << string << std::endl;
}

void reverse(char s[])
{
    char copy[256];

    strcpy(copy, s);

    int length = strlen(s);
    for(int i = 0; i < length; i++)
    {
        s[i] = copy[length - i - 1];
    }
}

void problem3_12()
{
    char string[256];

    std::cout << "Enter a string: ";
    std::cin >> string;

    reverse(string);

    std::cout << string;
}

void problem3_13()
{
    int lower = 0, upper = 0;
    char string[256];

    std::cout << "Enter a string: ";
    std::cin >> string;

    int length = strlen(string);

    for(int i = 0; i < length; i++)
    {
        if(string[i] >= 'A' && string[i] <= 'Z')
        {
            upper++;
        }
        else
        {
            lower++;
        }
    }

    if(lower > upper)
    {
        for(int i = 0; i < length; i++)
        {   
            if(string[i] >= 'A' && string[i] <= 'Z')
            {
                string[i] += 'a' - 'A';
            }
        }
    }
    else
    {
        for(int i = 0; i < length; i++)
        {   
            if(string[i] >= 'a' && string[i] <= 'z')
            {
                string[i] -= 'a' - 'A';
            }
        }
    }

    std::cout << string << std::endl;
}

void problem3_14()
{
    char string[255];
    char letters[26];

    std::cout << "Enter a string: ";
    std::cin >> string;

    for(int i = 0; i < 26; i++)
    {
        letters[i] = 0;
    }

    int length = strlen(string);
    for(int i = 0; i < length; i++)
    {
        char letter = string[i] - 'a';
        letters[letter]++;
    }

    for(int i = 0; i < 26; i++)
    {
        if(letters[i] > 0)
        {
            std::cout << char(i + 'a') << "-> " << (int)letters[i] << std::endl;
        }
    }

}

bool contains(char string[], char subString[])
{
    int strLength = strlen(string);
    int subLength = strlen(subString);

    for(int i = strLength - 1; i >= strLength - subLength; i--)
    {
        if(string[i] != subString[i - strLength + subLength])
        {
            return false;
        }
    }

    return true;
}

void reduce(char string[])
{
    int length = strlen(string);

    string[length - 1] = '\0';
}

bool isSubString(char string[], char subString[])
{
    while (strlen(string) >= strlen(subString))
    {
        if(contains(string, subString))
        {
            return true;
        }

        reduce(string);
    }
    
    return false;
}

void problem3_15()
{
    char string[255], subString[255];

    std::cout << "Enter string: ";
    std::cin >> string;

    std::cout << "Enter substring: ";
    std::cin >> subString;

    std::cout << std::boolalpha << isSubString(string, subString);
}

void problem3_16()
{
    bool exists = true;
    char string1[255];
    char string2[255];
    char letters1[26];
    char letters2[26];

    std::cout << "Enter a string1: ";
    std::cin >> string1;

    std::cout << "Enter a string2: ";
    std::cin >> string2;

    for(int i = 0; i < 26; i++)
    {
        letters1[i] = 0;
        letters2[i] = 0;
    }

    int length = strlen(string1);

    for(int i = 0; i < length; i++)
    {
        char letter1 = string1[i] - 'a';
        char letter2 = string2[i] - 'a';

        letters1[letter1]++;
        letters2[letter2]++;
    }

    for(int i = 0; i < length; i++)
    {
        char letter1 = string1[i] - 'a';
        char letter2 = string2[i] - 'a';

        if(letters1[letter1] != letters2[letter2])
        {
            exists = false;
            break;
        }
    }

    std::cout << (exists ? "A function exists" : "A function doesnt exist") << std::endl;
}


int main()
{
    //problem3_8();
    //problem3_9();
    //problem3_10();
    //problem3_11();
    //problem3_12();
    //problem3_13();
    //problem3_14();
    //problem3_15();
    //problem3_16();

    return 0;
}