#include <iostream>
#include <iomanip>
#include <cmath>

void problem1()
{
    double x, y;

    std::cout << "Enter x: ";
    std::cin >> x;

    std::cout << "Enter y: ";
    std::cin >> y;

    if(x > 0 && y > 0)
    {
        std::cout << "I quadrant";
    }
    else if(x > 0 && y < 0)
    {
        std::cout << "IV quadrant";
    }
    else if(x < 0 && y > 0)
    {
        std::cout << "II quadrant";
    }
    else if(x < 0 && y < 0)
    {
        std::cout << "III quadrant";
    }
    else if(x == 0 && y != 0)
    {
        std::cout << "y-axis";
    }
    else if(x =! 0 && y == 0)
    {
        std::cout << "x-axis";
    }
    else
    {
        std::cout << "(0; 0)";
    }
}


void problem2()
{
    double x1, y1, x2, y2;

    std::cout << "Enter x1: ";
    std::cin >> x1;
    
    std::cout << "Enter y1: ";
    std::cin >> y1;
    
    std::cout << "Enter x2: ";
    std::cin >> x2;
    
    std::cout << "Enter y2: ";
    std::cin >> y2;

    bool colinear = x1 * y2 == y1 * x2;

    if(colinear)
    {
        std::cout << "The vector are colinear";
    }
    else
    {
        std::cout << "The vector NOT are colinear";
    }

}

void problem3()
{
    int n;

    std::cout << "Enter n: ";
    std::cin >> n;

    for(int i = 1; i <= n; i++)
    {
        std::cout << i << " ";
    }
}

void problem4()
{
    for(int c = 'a'; c <= 'z'; c++)
    {
        std::cout << (char)c << " " << (char)std::toupper(c) << std::endl;
    }
}

void problem5()
{
    int a, b;

    std::cout << "Enter a: ";
    std::cin >> a;

    std::cout << "Enter b: ";
    std::cin >> b;

    int result = (a + b) * (b - a + 1) / 2;

    std::cout << result; 
}

void problem6()
{
    double n;
    double max, min, sum = 0;

    std::cout << "Enter n: ";
    std::cin >> n;

    for(int i = 0; i < n; i++) 
    {
        double number;

        std::cout << "Enter number: ";
        std::cin >> number;

        if(i == 0) 
        {
            min = number;
            max = number;
        }
        else
        {
            min = min < number ? min : number;
            max = max > number ? max : number;
        }

        sum += number;
    }

    double average = sum / n;

    std::cout << "Min = " << min << std::endl;
    std::cout << "Max = " << max << std::endl;
    std::cout << std::setprecision(2) << "Average = " << average;
}

void problem7()
{
    int a, b;

    std::cout << "Enter a: ";
    std::cin >> a;

    std::cout << "Enter b: ";
    std::cin >> b;

    while(b != 0)
    {
        int temp = a % b;
        a = b;
        b = temp;
    }

    std::cout << a;
}

void problem8()
{
    int n, divisorsSum = 0;
    bool prime = true, perfect;

    std::cout << "Enter n: ";
    std::cin >> n;

    for(int i = 1; i < n; i++)
    {
        if(n % i == 0)
        {
            if(i != 1)
            {
                prime = false;
            }
            std::cout << i;
            divisorsSum += i;
        }
    }

    perfect = divisorsSum == n;

    std::cout << "Prime: " << std::boolalpha << prime << std::endl;
    std::cout << "Perfect: " << std::boolalpha << perfect;
}

void problem9()
{
    int n, sum = 0;

    std::cout << "Enter n: ";
    std::cin >> n;

    if(n > 0)
    {
        std::cout << "Reversed = ";
    }
    else if(n == 0)
    {
        std::cout << "Reversed = 0";
    }
    else
    {
        std::cout << "Reversed = -";
        n = std::abs(n);
    }

    while(n != 0)
    {
        int lastDigit = n % 10;

        std::cout << lastDigit;

        n /= 10;
        sum += lastDigit;
    }

    std::cout << "\nSum of digits = " << sum;
}

void problem10()
{
    int n, digits = 0, sum = 0;

    std::cout << "Enter n: ";
    std::cin >> n;

    int copyOfN = n;
    int anotherCopyOfN = n;

    do
    {
        copyOfN /= 10;
        digits++;
    } while(copyOfN > 0);
    
    for(int i = 0; i < digits; i++)
    {
        sum += pow(n % 10, digits);

        n /= 10;
    }

    bool narcissistic = sum == anotherCopyOfN;
    std::cout << std::boolalpha << narcissistic;
}

void problem11()
{
    int n, digits = 0, newNumber = 0;

    std::cout << "Enter n: ";
    std::cin >> n;

    int copyOfN = n;

    do
    {
        copyOfN /= 10;
        digits++;
    } while(copyOfN > 0);

    int anotherCopyOfN = n;

    for(int i = digits - 1; i >= 0; i--)
    {
        newNumber += (anotherCopyOfN % 10) * pow(10, i);

        anotherCopyOfN /= 10;
    }

    bool palyndrome = newNumber == n;
    
    std::cout << std::boolalpha << palyndrome;
    
}

void problem12()
{
    int n, zeroes = 0;

    std::cout << "Enter n: ";
    std::cin >> n;

    while(n % 10 == 0)
    {
        n /= 10;
        zeroes++;
    }

    std::cout << zeroes << " zero(es)";
}

void problem13()
{
    int n, product = 1;

    std::cout << "Enter n: ";
    std::cin >> n;

    while(n > 1)
    {
        product *= n;
        n--;
    }

    std::cout << "n! = " << product;
}

void problem14()
{
    int n;

    std::cout << "Enter n: ";
    std::cin >> n;

    int a = 1, b = 1;

    for(int i = 0; i < n - 1; i++)
    {
        int temp = a;
        a += b;
        b = temp;
    }

    std::cout << "The n-th Fibonacci number is " << b;
}

void problem15()
{
    int n;

    std::cout << "Enter n: ";
    std::cin >> n;

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= i; j++)
        {
            std::cout << "*";
        }
        std::cout << std::endl;
    }
}

void problem16()
{
    int n;

    std::cout << "Enter n: ";
    std::cin >> n;

    for(int i = 0; i < n; i++)
    {
        std::cout << "#";
    }
    std::cout << std::endl;

    for(int i = 0; i < n - 2; i++)
    {
        std::cout << "#";
        for(int j = 0; j < n - 2; j++)
        {
            std::cout << " ";
        }
        std::cout << "#";
        std::cout << std::endl;
    }

    if(n > 1)
    {
        for(int i = 0; i < n; i++)
        {
            std::cout << "#";
        }
    }
}

void problem17()
{
    int n;

    std::cout << "Enter n: ";
    std::cin >> n;

    for(int i = 1; i <= n; i++)
    {
        for(int j = 0; j < n - i; j++)
        {
            std::cout << " ";
        }
        for(int j = 0; j < 2 * (i - 1) + 1; j++)
        {
            std::cout << "*";
        }
        std::cout << std::endl;
    }
}

void problem18()
{
    int n;

    std::cout << "Enter n: ";
    std::cin >> n;

    for(int i = 1; i <= n; i++)
    {
        for(int j = 0; j < n - i; j++)
        {
            std::cout << " ";
        }

        for(int j = 0; j < 2 * (i - 1) + 1; j++)
        {
            std::cout << "*";
        }
        std::cout << std::endl;
    }

    for(int i = n; i > 0; i--)
    {
        for(int j = 0; j < n - i; j++)
        {
            std::cout << " ";
        }

        for(int j = 0; j < 2 * (i - 1) + 1; j++)
        {
            std::cout << "*";
        }
        std::cout << std::endl;
    }
}

void problem19()
{
    int n;

    std::cout << "Enter n: ";
    std::cin >> n;

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j <= i; j++)
        {
            int number = tgamma(i + 1) / (tgamma(j + 1) * tgamma(i - j + 1));

            std::cout << number << " ";
        }
        std::cout << std::endl;
    }
}

void problem19_1()
{
    int n;

    std::cout << "Enter n: ";
    std::cin >> n;

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < 2 * (n - i); j++)
        {
            std::cout << " ";
        }

        for(int j = 0; j <= i; j++)
        {
            int number = tgamma(i + 1) / (tgamma(j + 1) * tgamma(i - j + 1));

            std::cout << number << "   ";
        }
        std::cout << std::endl;
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
    //problem16();
    //problem17();
    //problem18();
    //problem19();
    problem19_1();



    return 0;
}