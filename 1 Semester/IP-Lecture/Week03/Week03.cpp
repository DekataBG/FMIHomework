//Section 3.1 from Kalin Georgiev's book - 
//https://github.com/stranxter/lecture-notes/blob/master/homeworks/Problems%20in%20Programming.pdf


#include <iostream>
#include <cmath>

void problem3_1()
{
    int n, min;

    std::cout << "Enter n: ";
    std::cin >> n;

    std::cout << "Enter number: ";
    std::cin >> min;

    for(int i = 0; i < n - 1; i++)
    {
        int m;

        std::cout << "Enter number: ";
        std::cin >> m;

        if(m < min)
        {
            min = m;
        }
    }

    std::cout << "The smallest number is " << min;
}

void problem3_2()
{
    int n, sum = 0;

    std::cout << "Enter n: ";
    std::cin >> n;

    for(int i = 0; i < n; i++)
    {
        int m;

        std::cout << "Enter number: ";
        std::cin >> m;

        if(m % 2 == 1 && m == floor(sqrt(m)) * floor(sqrt(m)))
        {
            sum += m;
        }
    }

     std::cout << "The sum is " << sum;
}

void problem3_3()
{
    int n, sum = 0, product = 1;

    std::cout << "Enter n: ";
    std::cin >> n;

    for(int i = 0; i < n; i++)
    {
        int m;

        std::cout << "Enter number: ";
        std::cin >> m;

        if(m >= 0)
        {
            sum += m;
        }
        else
        {
            product *= m;
        }
    }

     std::cout << "The sum is " << sum << std::endl << "The product is " << product;
}

void problem3_7()
{
    int n, previous;
    bool equal = false;

    std::cout << "Enter n: ";
    std::cin >> n;

    std::cout << "Enter number: ";
    std::cin >> previous;

    for(int i = 0; i < n - 1; i++)
    {
        int m;

        std::cout << "Enter number: ";
        std::cin >> m;

        if(m == previous)
        {
            equal = true;
        }

        previous = m;
    }

    if(equal)
    {
        std::cout << "There are 2 consequent equal numbers";
    }
    else
    {
        std::cout << "There are NOT 2 consequent equal numbers";
    }
}

void problem3_8()
{
    int n, previous;
    bool increasing = true;

    std::cout << "Enter n: ";
    std::cin >> n;

    std::cout << "Enter number: ";
    std::cin >> previous;

    for(int i = 0; i < n - 1; i++)
    {
        int m;

        std::cout << "Enter number: ";
        std::cin >> m;

        if(m < previous)
        {
            increasing = false;
        }

        previous = m;
    }

    if(increasing)
    {
        std::cout << "There sequence is increasing";
    }
    else
    {
        std::cout << "There sequence is NOT increasing";
    }
}

void problem3_15()
{
    int n, sum = 0;

    std::cout << "Enter n: ";
    std::cin >> n;

    for(int i = 0; i < n; i++)
    {
        int a, b;

        std::cout << "Enter a" << i << " :";
        std::cin >> a;

        std::cout << "Enter b" << i << " :";
        std::cin >> b;

        sum += a * b;
    }

    std::cout << "The scalar product is " << sum;
}

void problem3_10()
{
    int n, previous, length = 1, maxLength = 1;

    std::cout << "Enter n: ";
    std::cin >> n;

    std::cout << "Enter number: ";
    std::cin >> previous;

    for(int i = 0; i < n - 1; i++)
    {
        int m;

        std::cout << "Enter number: ";
        std::cin >> m;

        if(m >= previous)
        {
            length++;
        }
        else
        {
            if(maxLength < length)
            {
                maxLength = length;
            }

            length = 1;
        }

        previous = m;
    }

    if(maxLength < length)
    {
        maxLength = length;
    }
    
    std::cout << "The longest non-decreasing sequence has " << maxLength << " members"; 
}


int main()
{
    //problem3_1();
    //problem3_2();
    //problem3_3();
    //problem3_7();
    //problem3_8();
    //problem3_15();
    //problem3_10();


    return 0;
}