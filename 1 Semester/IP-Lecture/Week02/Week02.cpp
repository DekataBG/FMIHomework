//Problems from https://github.com/stranxter/lecture-notes/blob/master/homeworks/Problems%20in%20Programming.pdf

#include <iostream>


void problem1_8()
{
    int x, k;

    std::cout << "Enter x: ";
    std::cin >> x;
    
    std::cout << "Enter k: ";
    std::cin >> k;

    for(int i = 0; i < k - 1; i++)
    {
        x /= 10;
    }

    std::cout << "X's k-th digit is " << x % 10;
}

void problem1_9()
{
    int n;

    std::cout << "Enter n: ";
    std::cin >> n;

    int sum = 0;

    for(int i = 2; i <= n; i += 3)
    {
        sum += i;
    }

    std::cout << "The sum is " << sum;
}

void problem1_10()
{
    int n;

    std::cout << "Enter n: ";
    std::cin >> n;

    int elements = 0;

    for(int i = 1; i <= n; i++)
    {
        int number = i * i * i + 13 * i * n + n * n * n;

        if(number % 5 == 0 || number % 9 == 0)
        {
            elements++;
        }
    }

    std::cout << "The number of elements divisible by 5 or 9 is " << elements;
}

void problem1_11()
{
    int n, k;

    std::cout << "Enter n: ";
    std::cin >> n;

    std::cout << "Enter k: ";
    std::cin >> k;

    int newK = k;
    int power = 1; 
    bool isPower = false;

    while(n >= newK)
    {
        if(n == newK)
        {
            std::cout << n << " = " << k << "^" << power;
            isPower = true;
        }

        newK *= k;
        power++;
    }

    if(!isPower)
    {
        std::cout << n << " is not power of " << k;
    }
}

int main()
{
    //problem1_8();
    //problem1_9();
    //problem1_10();
    //problem1_11();


    return 0;
}