#include <iostream>
#include <cstring>
#include <cmath>

void problem1()
{
    char input[50];

    std::cout << "Enter a string: ";
    std::cin >> input;

    std::cout << input << std::endl;
}

void problem2()
{
    char input[50];

    std::cout << "Enter a message: ";
    std::cin.getline(input, 50);

    std::cout << input << std::endl;
}

void problem3()
{
    char input[50];

    std::cout << "Enter a string: ";
    std::cin >> input;

    std::cout << input << std::endl;

    for(int i = 0; input[i] != '\0'; i++)
    {
        char letter = input[i];

        if(letter >= 'a' && letter <= 'z')
        {
            input[i] = letter - 32;
        }
        else if(letter >= 'A' && letter <= 'Z')
        {
            input[i] = letter + 32;
        }
    }

    std::cout << input << std::endl;
}

void problem4()
{
    char input1[50];
    char input2[50];

    std::cout << "Enter a string: ";
    std::cin >> input1;

    std::cout << "Enter a string: ";
    std::cin >> input2;

    strcpy(input1, input2);

    std::cout << "First String: \"" << input1 << "\"" << std::endl;
    std::cout << "Second String: \"" << input2 << "\"" << std::endl;
}

void problem5()
{
    char input1[50];
    char input2[50];
    char input3[50];

    std::cout << "Enter a string: ";
    std::cin >> input1;

    std::cout << "Enter a string: ";
    std::cin >> input2;

    std::cout << "Enter a string: ";
    std::cin >> input3;

    std::cout << input1 << input2 << input3 << std::endl;
}

void problem6()
{
    char input[50];
    char output[50];

    std::cout << "Enter a string: ";
    std::cin >> input;

    int length = strlen(input);

    for(int i = 0; i < length; i++)
    {
        output[i] = input[length - 1 - i];
    }
    output[length] = '\0';

    std::cout << output << std::endl;
}

void problem7()
{
    int vowels = 0;
    char input[50];

    std::cout << "Enter a string: ";
    std::cin >> input;

    int length = strlen(input);

    for(int i = 0; i < length; i++)
    {
        char letter = input[i];

        if(letter == 'A' || letter == 'a' || letter == 'E' || letter == 'e' 
            || letter == 'I' || letter == 'i' || letter == 'O' || letter == 'o' || 
            letter == 'U' || letter == 'u' || letter == 'Y' || letter == 'y')
        {
            vowels++;
        }
    }

    std::cout << vowels << " vowels" << std::endl;
}

void problem8()
{
    char input[256];

    std::cout << "Enter a message: ";
    std::cin.getline(input, 256);

    int length = strlen(input);

    int max = 0;
    int ctr = 0;
    int index = 0;
    for(int i = 0; i < length; i++)
    {
        char letter = input[i];
        
        if(letter == ' ')
        {
            if(max < ctr)
            {
                max = ctr;
                index = i - 1;
            }

            ctr = 0;
        }
        
        ctr++;
    }

    for(int i = index - max + 2; i <= index; i++)
    {
        std::cout << input[i];
    }
}

void problem9()
{
    char input[50];

    std::cout << "Enter a string: ";
    std::cin >> input;

    int length = strlen(input);

    for(int i = 0; i < length - 1; i++)
    {
        char current = input[i];
        char next = input[i + 1];

        std::cout << current;

        if(current % 2 == 1 && next % 2 == 1)
        {
            std::cout << "-";
        }
    }
}

void problem10()
{
    char input[256];

    std::cout << "Enter a message: ";
    std::cin.getline(input, 256);

    int length = strlen(input);

    int ctr = 0;
    int sum = 0;
    int subSum = 0;
    for(int i = 0; i < length; i++)
    {
        char letter = input[i];
        
        if(letter >= '0' && letter <= '9')
        {
            int number = ((int)letter - 48);

            if(i > ctr && input[i - ctr - 1] == '-')
            {
                number *= -1;
            }

            subSum = subSum * 10 + number;
            ctr++;
        }
        else
        {
            sum += subSum;
            subSum = 0;
            ctr = 0;
        }
    }
    sum += subSum;

    std::cout << "The sum is " << sum << std::endl;
}

bool contains(char input1[], int length1, char input2[], int length2)
{
    if(length2 > length1)
    {
        return false;
    }

    bool isContained = false;
    for(int i = length1 - 1; i - length2 + 1 >= 0; i--)
    {
        bool isSubSequence = true;
        for(int j = 0; length2 - 1 - j >= 0; j++)
        {
            if(input1[i - j] != input2[length2 - 1 - j])
            {
                isSubSequence = false;
                break;
            }
        }

        isContained = isContained || isSubSequence;

        if(isContained)
        {
            break;
        }
    }

    return isContained;
}

void problem11()
{
    char input1[256];
    char input2[256];

    std::cout << "Enter a message: ";
    std::cin.getline(input1, 256);

    std::cout << "Enter a message: ";
    std::cin.getline(input2, 256);

    int length1 = strlen(input1);
    int length2 = strlen(input2);

    for(int i = 0; i < length1; i++)
    {
        char letter = input1[i];
        if(letter >= 'A' && letter <= 'Z')
        {
            input1[i] = letter + 32;
        }
    }

    for(int i = 0; i < length2; i++)
    {
        char letter = input2[i];
        if(letter >= 'A' && letter <= 'Z')
        {
            input2[i] = letter + 32;
        }
    }

    std::cout << std::boolalpha << contains(input1, length1, input2, length2);
}

void problem12()
{
    int n; 
    int digits[100];

    std::cout << "Enter n: ";
    std::cin >> n;

    if(n < 0)
    {
        std::cout << "-";
        n *= -1;
    }

    int ctr = 0;
    do
    {
        digits[ctr] = n % 10;
        n /= 10;

        ctr++;
    } while (n > 0);
    
    for(int i = ctr - 1; i >= 0; i--)
    {
        std::cout << digits[i];
        if(i != 0 && i % 3 == 0)
        {
            std::cout << ",";
        }
        
    }
}

void problem13()
{
    bool correct = true;
    int left = 0, right = 0;
    char input[50];

    std::cout << "Enter a string: ";
    std::cin >> input;

    int length = strlen(input);
    for(int i = 0; i < length; i++)
    {
        char letter = input[i];

        if(letter == '(')
        {
            left++;
        }
        else if(letter == ')')
        {
            right++;
            if(right > left)
            {
                correct = false;
            }
        }
    }

    if(left != right)
    {
        correct = false;
    }

    std::cout << std::boolalpha << correct;
}

void problem14()
{
    char string[50];
    char letter1, letter2;

    std::cout << "Enter a string: ";
    std::cin >> string;

    std::cout << "Enter a letter to be replaced: ";
    std::cin >> letter1;

    std::cout << "Enter a letter to replace: ";
    std::cin >> letter2;

    int length = strlen(string);

    for(int i = 0; i < length; i++)
    {   
        if(string[i] == letter1)
        {
            string[i] = letter2;
        }
    }

    std::cout << string << std::endl;

}

bool isPascalCase(char array[])
{
    if((array[0] >= 'A' && array[0] <= 'z') && (array[0] < 'A' || array[0] > 'Z'))
    {
        array[0] -= 32;
        return false;
    }

    int length = strlen(array);
    for(int i = 2; i < length; i++)
    {
        if(array[i - 1] == ' ' && array[i] >= 'A' && array[i] <= 'z')
        {
            if(array[i] < 'A' || array[i] > 'Z')
            {
                array[i] -= 32;
                return false;
            }
        }
        else
        {
            if(array[i] >= 'A' && array[i] <= 'Z')
            {
                array[i] += 32;
                return false;
            }
        }
    }

    return true;
}

void problem15()
{
    char input[256];

    std::cout << "Enter a message: ";
    std::cin.getline(input, 256);

    bool isPascal = isPascalCase(input);

    std::cout << std::boolalpha << isPascal << std::endl;

    if(!isPascal)
    {
        while(!isPascalCase(input))
        {

        }

        std::cout << input << std::endl;
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
    //problem11();
    //problem12();
    //problem13();
    //problem14();
    //problem15();


    return 0;
}