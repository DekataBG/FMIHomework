#include <iostream>
#include <cmath>
#include <cstdlib>
#include <time.h>


int absolute(int x)
{
    return x > 0 ? x : -x;
}

bool isEven(int x)
{
    return x % 2 == 0;
}

char toLower(char sym)
{
    return (sym - 32);

}

void printAll(int from, int until)
{
    for(int i = from; i <= until; i++)
    {
        std::cout << i << " ";
    }

    std::cout << "\n";
}

bool equalRemainder(int a, int b, int p)
{
    return a % p == b % p;
}

int arithSequenceSum(int start, int difference, int n)
{
    return (2 * start + (n - 1) * difference) / 2;
}

bool isPrime(int n)
{
    for(int i = 2; i <= sqrt(n); i++)
    {
        if(n % i == 0)
        {
            return false;
        }
    }

    return true;
}

int primeNumbers(int n)
{
    int ctr = 0;
    for(int i = 2; i <= n; i++)
    {
        if(isPrime(i))
        {
            ctr++;
        }
    }
    return ctr;
}

bool isSubNumber(int find, int search)
{
    int findLen = 0;
    int searchLen = 0;

    int findCopy = find;
    int searchCopy = search;

    do
    {
        findLen++;
        findCopy /= 10;
    } while(findCopy > 0);

    do
    {
        searchLen++;
        searchCopy /= 10;
    } while(searchCopy > 0);

    for(int i = 0; i < searchLen - findLen + 1; i++)
    {
        int searchCopy = search;
        int newNumber = 0;

        for(int j = 0; j < findLen; j++)
        {
            newNumber += (searchCopy % 10) * pow(10, j); 
            searchCopy /= 10;
        }

        if(newNumber == find)
        {
            return true;
        }

        search /= 10;
    }

    return false;
}

void printAllSubNumbers(int n)
{
    for(int i = 0; i <= n; i++)
    {
        if(isSubNumber(i, n))
        {
            std::cout << i << " ";
        }
    }
}

int rps(char firstPlayerMove, char secondPlayerMove)
{
    if(firstPlayerMove == 'r')
    {
        if(secondPlayerMove == 'r')
        {
            return 0;
        }
        if(secondPlayerMove == 'p')
        {
            return -1;
        }

        return 1; 
    }
    if(firstPlayerMove == 'p')
    {
        if(secondPlayerMove == 'r')
        {
            return 1;
        }
        if(secondPlayerMove == 'p')
        {
            return 0;
        }

        return -1; 
    }

    
    if(secondPlayerMove == 'r')
    {
        return -1;
    }
    if(secondPlayerMove == 'p')
    {
        return 1;
    }

    return 0; 
    
}

char randomMove()
{
    srand(time(0));

    int random = rand() % 3;

    if(random == 0)
    {
        return 'r';
    }
    if(random == 1)
    {
        return 'p';
    }

    return 's';
}

void rpsGame()
{
    double rounds;

    std::cout << "Please input the maximum number of rounds: ";
    std::cin >> rounds;

    int winsNeeded = ceil(rounds / 2);

    int i = 1, winsHuman = 0, winsPC = 0;;
    while(winsHuman < winsNeeded && winsPC < winsNeeded)
    {
        char moveHuman, movePC;
        
        std::cout << "Please input move " << i << ": ";
        std::cin >> moveHuman;

        movePC = randomMove();

        if(rps(moveHuman, movePC) > 0)
        {
            winsHuman++;
        }
        else if(rps(moveHuman, movePC) < 0)
        {
            winsPC++;
        }

        std::cout << "Computer: '" << movePC << "', Player: '" << moveHuman << "' - Result " << winsPC << "-" << winsHuman << std::endl;

        i++;
    }

    std::cout << "The result is"  << winsPC << "-" << winsHuman ;

    if(winsPC > winsHuman)
    {
        std::cout << ". The PC is the winner!\n";
    }
    else
    {
        std::cout << ". You are the winner!\n";
    }
}

void printInBinary(int decimal)
{
    long binary = 0;

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
    
    std::cout << binary << std::endl;
}

void majoritySymbol(double n)
{
    int array[256];
    bool frequent = false;

    for(int i = 0; i < 256; i++)
    {
        array[i] = 0;
    }

    for(int i = 0; i < n; i++)
    {
        char symbol;

        std::cout << "Enter symbol: ";
        std::cin >> symbol;

        array[symbol]++;
    }

    for(int i = 0; i < 256; i++)
    {
        double limit = n / 2;

        if(array[i] > limit)
        {
            std::cout << (char)i << std::endl;
            frequent = true;
            break;
        }
    }

    if(!frequent)
    {
        std::cout << "No symbols with frequency more than 50%" << std::endl;
    }
}


void problem1()
{
    int x, y, c, lowerBound, upperBound;

    std::cout << "Enter x: ";
    std::cin >> x;
    std::cout << absolute(x) << std::endl;

    std::cout << "Enter y: ";
    std::cin >> y;
    std::cout << std::boolalpha << isEven(y) << std::endl;

    std::cout << "Enter uppercase symbol: ";
    std::cin >> c;
    std::cout << (char)tolower(c) << std::endl;

    std::cout << "Enter lower bound: ";
    std::cin >> lowerBound;
    std::cout << "Enter upper bound: ";
    std::cin >> upperBound;
    printAll(lowerBound, upperBound);
}

void problem2()
{
    int a, b, p;

    std::cout << "Enter a: ";
    std::cin >> a;

    std::cout << "Enter b: ";
    std::cin >> b;

    std::cout << "Enter p: ";
    std::cin >> p;

    std::cout << std::boolalpha << equalRemainder(a, b, p) << std::endl;
}

void problem3()
{
    int start, difference, n;

    std::cout << "Enter start: ";
    std::cin >> start;

    std::cout << "Enter difference: ";
    std::cin >> difference;

    std::cout << "Enter n: ";
    std::cin >> n;

    std::cout << "Sum: " << arithSequenceSum(start, difference, n);
}

void problem4()
{
    int n;

    std::cout << "Enter n: ";
    std::cin >> n;

    std::cout << "Number of primes: " << primeNumbers(n);
}

void problem5()
{
    int find, search;

    std::cout << "Enter find: ";
    std::cin >> find;

    std::cout << "Enter search: ";
    std::cin >> search;

    std::cout << std::boolalpha << isSubNumber(find, search) << std::endl;
}

void problem6()
{
    int n;

    std::cout << "Enter n: ";
    std::cin >> n;

    printAllSubNumbers(n);
}

void problem7()
{
    rpsGame();
}

void problem8()
{
    int n;

    std::cout << "Enter n: ";
    std::cin >> n;

    printInBinary(n);
}

void problem9()
{
    double n;

    std::cout << "Enter n: ";
    std::cin >> n;

    majoritySymbol(n);
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


    return 0;
}