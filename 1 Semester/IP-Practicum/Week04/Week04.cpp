//Problems from https://www.hackerrank.com/contests/week-04-functions/challenges

#include <iostream>
#include <cmath>
#include <cstring>

int absolute()
{
    int n;

    std::cin >> n;
    

    return n > 0 ? n : -n;
}

char sign()
{
    int n;

    std::cin >> n;

    if(n > 0)
    {
        return '+';
    }
    else if(n == 0)
    {
        return '0';
    }
    
    return '-';
}

bool isLeap()
{
    unsigned int year;

    std::cin >> year;

    if(year < 1582)
    {
        return false;
    }

    if(year % 400 == 0)
    {
        return true;
    }

    if(year % 100 == 0)
    {
        return false;
    }

    if(year % 4 == 0)
    {
        return true;
    }

    return false;
}

int min(int n1, int n2)
{
    return n1 > n2 ? n2 : n1;
}

int max(int n1, int n2)
{
    return n1 = n2 ? n1 : n2;
}

int findMostCommonDigit()
{
    int digits[] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
    int n;

    std::cin >> n;
    n = n > 0 ? n : -n;

    do
    {
        int index = n % 10;

        digits[index]++;

        n /= 10;
    } while (n > 0);

    int biggest = digits[0] > digits[1] ? 0 : 1;

    for(int i = 2; i < 10; i++)
    {
        biggest = digits[biggest] > digits[i] ? biggest : i;
    }    

    return biggest;
}

bool isPrime(int a)
{
    for(int i = 2; i <= sqrt(a); i++)
    {
        if(a % i == 0)
        {
            return false;
        }
    }

    return true;
}

void printAllPrimeNumbersInInterval(int start, int end)
{
    start = start > 2 ? start : 2;

    for(int i = start; i <= end; i++)
    {
        if(isPrime(i))
        {
            std::cout << i << " ";
        }
    }
}

bool isPowerOf2(int n)
{
    if(n == 1 || n == 2)
    {
        return true;
    }

    int two = 2;
    
    while(two <= n)
    {
        if(n == two)
        {
            return true;
        }

        two *= 2;
    }

    return false;
}

void calculateTime()
{
    int time[2];
    char output[5];
    int minutesToAdd, hoursToAdd;

    while(true)
    {

        std::cin >> time[0];
        std::cin >> time[1];

        if(!(time[0] >= 24 || time[0] < 0 || time[1] >= 60 || time[1] < 0))
        {
            break;
        }
    }

    std::cin >> minutesToAdd;

    hoursToAdd = minutesToAdd / 60;
    minutesToAdd = minutesToAdd % 60;

    time[0] += hoursToAdd;
    time[1] += minutesToAdd;
    time[0] += time[1] / 60;
    time[1] = time[1] % 60;
    time[0] = time[0] % 24;

    if(time[0] < 9)
    {
        std::cout << "0";
        std::cout << time[0];
    }
    else
    {
        std::cout << time[0];
    }

    std::cout << ":";

    if(time[1] < 9)
    {
        std::cout << "0";
        std::cout << time[1];
    }
    else
    {
        std::cout << time[1];
    }

}

long long factorial(int n)
{
    long long fact = 1;

    for(int i = 2; i <= n; i++)
    {
        fact *= i;
    }

    return fact;
}

long long variations(int n, int k)
{
    long long v = 1;

    for(int i = n; i > n - k; i--)
    {
        v *= i;
    }

    return v;
}

void caseP(char operations[])
{
    int number = 0;

    std::cin.getline(operations, 100);
    int length = strlen(operations);

    if(length < 2)
    {
        std::cout << "Invalid (n, k) input!" << std::endl;
        return;
    }

    for(int i = 1; i < length; i++)
    {
        if(operations[i] == ' ')
        {
            std::cout << "Invalid (n, k) input!" << std::endl;
            return;
        }

        int digit = (int)operations[i] - 48;

        if(digit < 0 || digit > 9)
        {
            std::cout << "Invalid (n, k) input!" << std::endl;
            return;
        }

        number += digit * pow(10, length - 1 - i);
    }

    long long fact = factorial(number);

    std::cout << "P(n) = " << fact << std::endl;
}

long long reverseNumber(long long n)
{
    long long newN = n;
    long long newNumber = 0;
    int ctr = 0, length = 0;

    do
    {
        newN /= 10;
        length++;
    }
    while (newN > 0);

    while (n > 0)
    {
        newNumber += (n % 10) * pow(10, length - 1 - ctr);

        n /= 10;
        ctr++;
    }
    
    return newNumber;
}

void caseV(char operations[])
{
    int n = 0, k = 0;

    std::cin.getline(operations, 100);
    int length = strlen(operations);

    if(length < 2)
    {
        std::cout << "Invalid (n, k) input!" << std::endl;
        return;
    }

    int index = 0;
    for(int i = 1; i < length; i++)
    {
        if(operations[i] == ' ')
        {
            index = i;
            break;
        }

        int digit = (int)operations[i] - 48;

        if(digit < 0 || digit > 9)
        {
            std::cout << "Invalid (n, k) input!" << std::endl;
            return;
        }

        n += digit * pow(10, i - 1);
    }
    n = reverseNumber(n);

    if(index == 0)
    {
        std::cout << "Invalid (n, k) input!" << std::endl;
        return;
    }

    for(int i = index + 1; i < length; i++)
    {
        if(operations[i] == ' ')
        {
            std::cout << "Invalid (n, k) input!" << std::endl;
            return;
        }

        int digit = (int)operations[i] - 48;

        if(digit < 0 || digit > 9)
        {
            std::cout << "Invalid (n, k) input!" << std::endl;
            return;
        }

        k += digit * pow(10, i - index - 1);
    }
    k = reverseNumber(k);

    if(n < k)
    {
        std::cout << "Invalid (n, k) input!" << std::endl;
        return;
    }

    long long variation = variations(n, k);

    std::cout << "V(n, k) = " << variation << std::endl;
}

void caseC(char operations[])
{
    int n = 0, k = 0;

    std::cin.getline(operations, 100);
    int length = strlen(operations);

    if(length < 2)
    {
        std::cout << "Invalid (n, k) input!" << std::endl;
        return;
    }

    int index = 0;
    for(int i = 1; i < length; i++)
    {
        if(operations[i] == ' ')
        {
            index = i;
            break;
        }

        int digit = (int)operations[i] - 48;

        if(digit < 0 || digit > 9)
        {
            std::cout << "Invalid (n, k) input!" << std::endl;
            return;
        }

        n += digit * pow(10, i - 1);
    }
    n = reverseNumber(n);

    if(index == 0)
    {
        std::cout << "Invalid (n, k) input!" << std::endl;
        return;
    }

    for(int i = index + 1; i < length; i++)
    {
        if(operations[i] == ' ')
        {
            std::cout << "Invalid (n, k) input!" << std::endl;
            return;
        }

        int digit = (int)operations[i] - 48;

        if(digit < 0 || digit > 9)
        {
            std::cout << "Invalid (n, k) input!" << std::endl;
            return;
        }

        k += digit * pow(10, i - index - 1);
    }
    k = reverseNumber(k);

    if(n < k)
    {
        std::cout << "Invalid (n, k) input!" << std::endl;
        return;
    }

    long long combination = variations(n, k) / factorial(k);

    std::cout << "C(n, k) = " << combination << std::endl;
}

void combinatorics()
{
    bool running = true;

    while(running)
    {
        char operations[100];

        std::cin >> operations;

        switch (operations[0])
        {
        case 'E':
            running = false;
            break;
        case 'P':
            caseP(operations);
            break;
        case 'V': 
            caseV(operations);
            break;
        case 'C': 
            caseC(operations);
            break;
        default:
            std::cout << "Invalid command input!" << std::endl;
            break;
        }
    }
}

void decimalToBinary()
{
    long binary = 0;

    int decimal;
    std::cin >> decimal;

    if(decimal < 0)
    {
        std::cout << "-";
        decimal = - decimal;
    }

    int quotient = decimal;
    int ctr = 0;
    do
    {
        int remainder = quotient % 2;

        binary += remainder * pow(10, ctr);

        ctr++;
        quotient /= 2;
    } while(quotient > 0);
    
    std::cout << binary;
}


void problem1()
{
    std::cout << absolute();
}

void problem2()
{
    std::cout << sign();
}

void problem3()
{
    if(isLeap())
    {
        std::cout << "Yes";
    }
    else
    {
        std::cout << "No";
    }
}

void problem4()
{
    int a, b, c, d;
    std::cin >> a;
    std::cin >> b;
    std::cin >> c;
    std::cin >> d;
    int bigger1 = max(a, b);
    int bigger2 = max(c, d);
    int biggest = max(bigger1, bigger2);
    int smaller1 = min(a, b);
    int smaller2 = min(c, d);
    int smallest = min(smaller1, smaller2);
    std::cout << "Min: " << smallest << std::endl;
    std::cout << "Max: " << biggest;
}

void problem5()
{
    std::cout << findMostCommonDigit();
}

void problem6()
{
    int start, end;
    std::cin >> start;
    std::cin >> end;
    printAllPrimeNumbersInInterval(start, end);
}

void problem7()
{
    int n;
    std::cin >> n;
    std::cout << std::boolalpha << isPowerOf2(n);
}

void problem8()
{
    calculateTime();
}

void problem9()
{
    combinatorics();
}

void problem10()
{
    decimalToBinary();
}


int main ()
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

    return 0;
}