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

void combinatorics()
{
    bool running = true;

    while(true)
    {
        char operations[100];

        std::cin.getline(operations, 100);

        switch (operations[0])
        {
        case 'E':
            running = false;
            break;
        case 'P':

            break;
        case 'V': 

            break;
        case 'C': 

            break;
        default:
            std::cout << "Invalid command input!";
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


int main ()
{

    ///Problem1
    //std::cout << absolute();

    ///Problem2
    //std::cout << sign();


    ///Problem3
    // if(isLeap())
    // {
    //     std::cout << "Yes";
    // }
    // else
    // {
    //     std::cout << "No";
    // }

    ///Problem4
    // int a, b, c, d;
    // std::cin >> a;
    // std::cin >> b;
    // std::cin >> c;
    // std::cin >> d;
    // int bigger1 = max(a, b);
    // int bigger2 = max(c, d);
    // int biggest = max(bigger1, bigger2);
    // int smaller1 = min(a, b);
    // int smaller2 = min(c, d);
    // int smallest = min(smaller1, smaller2);
    // std::cout << "Min: " << smallest << std::endl;
    // std::cout << "Max: " << biggest;

    ///Problem5
    //std::cout << findMostCommonDigit();

    ///Problem6
    // int start, end;
    // std::cin >> start;
    // std::cin >> end;
    // printAllPrimeNumbersInInterval(start, end);

    ///Problem7
    // int n;
    // std::cin >> n;
    // std::cout << std::boolalpha << isPowerOf2(n);

    ///Problem8
    // calculateTime();

    combinatorics();

    //decimalToBinary();

    return 0;
}