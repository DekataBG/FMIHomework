#include <iostream>
#include <cstdlib>
#include <windows.h>

void problem1()
{
    int n;
    
    std::cout << "Enter n: ";
    std::cin >> n;

    for(int i = 3; i <= n; i += 3)
    {
        std::cout << i << " ";
    }
}

void problem2()
{
    int n;
    
    std::cout << "Enter n: ";
    std::cin >> n;

    int sum = n * (n + 1) * (2 * n + 1) / 6;

    std::cout << "The sum of the squares is " << sum;
}

void problem3()
{
    int n;
    double sum = 0;
    
    std::cout << "Enter n: ";
    std::cin >> n;

    for(int i = 0; i < n; i++)
    {
        double number;

        std::cout << "Enter number: ";
        std::cin >> number;

        sum += number;
    }

    std::cout << "The sum is " << sum;
}

void problem4()
{
    int n;
    
    std::cout << "Enter n: ";
    std::cin >> n;

    for(int i = 1; i <= n; i++)
    {
        if(n % i == 0)
        {
            std::cout << i << " ";
        }
    }

}

void problem5()
{
    int n, product = 1;
    
    std::cout << "Enter n: ";
    std::cin >> n;

    for(int i = n; i > 1; i -= 2)
    {
        product *= i;
    }

    std::cout << "n!! = " << product;
}

void problem6()
{
    srand(time(0));

    int number, n, ctr = 0;
    
    std::cout << "Enter number: ";
    std::cin >> number;

    n = rand() % number + 1; 
    std::cout << n << std::endl;

    while(true)
    {
        ctr++;
        int guessed;

        std::cout << "Guess the number: ";
        std::cin >>  guessed;

        if(guessed > n)
        {
            std::cout << "Your number is bigger" << std::endl;
        }
        else if(guessed < n)
        {
            std::cout << "Your number is smaller" << std::endl;
        }
        else
        {
            std::cout << "Correct!" << std::endl;
            break;
        }
    }

    std::cout << ctr << " attempts were necessary to guess the number";
}

void problem7()
{
    int n;
    bool asc = true;
    
    std::cout << "Enter n: ";
    std::cin >> n;      

    int previousNumber = n % 10;
    n /= 10;

    while(n > 0)
    {
        if(previousNumber < n % 10)
        {
            asc = false;
            break;
        }

        n /= 10;
    }

    if(asc)
    {
        std::cout << "The digits are ascending";
    }
    else
    {
        std::cout << "The digits are not ascending";
    }
    

}

void problem8()
{
    int n, m, sumN = 0, sumM = 0;
    
    std::cout << "Enter n: ";
    std::cin >> n; 

    std::cout << "Enter m: ";
    std::cin >> m; 

    while(n > 0)
    {
        sumN += n % 10;
        
        n /= 10;
    }

    while(m > 0)
    {
        sumM += m % 10;
        
        m /= 10;
    }

    if(sumM == sumN)
    {
        std::cout << "The sums are equal";
    }
    else
    {
        std::cout << "The sums are not equal";
    }
}

void problem9()
{
    int n;
    bool automorph = true;
    
    std::cout << "Enter n: ";
    std::cin >> n; 

    int squared = n * n;

    while(n > 0)
    {
        if(n % 10 != squared % 10)
        {   
            automorph = false;
            break;
        }

        n /= 10;
        squared /= 10;
    }

    if(automorph)
    {
        std::cout << "The number is automorph";
    }
    else
    {
        std::cout << "The number is not automorph";
    }
}

void problem10()
{
    std::cout << "0: The program ends\n1: C\n2: D\n3: E\n4: F\n5: G\n6: A\n7: B";
    bool running = true;

    while(running)
    {
        double frequency;
        int input;

        std::cin >> input;

        switch (input)
        {
            case 0:
                running = false;
                break;
            case 1:
                frequency = 130.81;
                break;
            case 2:
                frequency = 146.83;
                break;
            case 3:
                frequency = 164.81;
                break;
            case 4:
                frequency = 174.61;
                break;
            case 5:
                frequency = 196.00;
                break;
            case 6:
                frequency = 220.00;
                break;
            case 7:
                frequency = 246.94;
                break;
            default:
                running = false;
                break;
        }
    
        Beep(frequency, 1000);
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
    
    return 0;
}