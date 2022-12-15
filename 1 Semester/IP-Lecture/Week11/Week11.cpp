// Problems from section 5 from https://github.com/stranxter/lecture-notes/blob/master/homeworks/Problems%20in%20Programming.pdf
#include <iostream>

double hermitePolynomial(double x, int n)
{
    if(n == 0)
    {
        return 1;
    }
    if(n == 1)
    {
        return 2 * x;
    }

    return 2 * x * hermitePolynomial(x, n - 1) + 2 * (n - 1) * hermitePolynomial(x, n - 2);
}

void problem5_1()
{
    int n;
    double x;

    std::cout << "Enter n: ";
    std::cin >> n;

    std::cout << "Enter x: ";
    std::cin >> x;

    std::cout << "H_" << n << "(" << x <<  ") = " << hermitePolynomial(x, n) << std::endl;
}

double mult(double a, double b)
{
    if(b == 1)
    {
        return a;
    }

    return a + mult(a, b - 1);
}

void problem5_2()
{
    double a, b;

    std::cout << "Enter a: ";
    std::cin >> a;
    
    std::cout << "Enter b: ";
    std::cin >> b;

    std::cout << a << " * " << b << " = " << mult(a, b);
}

int gcd(int a, int b)
{
    if(a % b == 0)
    {
        return b;
    }

    return gcd(b, a % b);
}

void problem5_3()
{
    int a, b;

    std::cout << "Enter a: ";
    std::cin >> a;
    
    std::cout << "Enter b: ";
    std::cin >> b;

    std::cout << "gcd(" << a << ", " << b << ") = " << gcd(a, b) << std::endl;
}

int product(int n, int k, int current)
{
    if(current > n)
    {
        return 1;
    }

    return current * product(n, k, current + k);
}

void problem5_4()
{
    int n, k;

    std::cout << "Enter n: ";
    std::cin >> n;
    
    std::cout << "Enter k: ";
    std::cin >> k;

    std::cout << "The product is " << product(n, k, 1) << std::endl;
}

int sumOfDigits(int n, int k, int sum)
{
    if(n == 0)
    {
        return sum;
    }
    
    return sumOfDigits(n / k, k, sum + n % k);
}

void problem5_5()
{
    int n, k;

    std::cout << "Enter number: ";
    std::cin >> n;

    std::cout << "Enter base: ";
    std::cin >> k;

    std::cout << "The sum of the digits of " << n << " in base " 
        << k << " is " << sumOfDigits(n, k, 0) << std::endl;
}

bool contains(int n, int k, int digits)
{
    if(n == 0)
    {
        return digits == 1;
    }

    if(n % 10 == k)
    {
        return true;
    } 


    return contains(n / 10, k, digits + 1);
}

void problem5_6()
{
    int n, k;

    std::cout << "Enter n: ";
    std::cin >> n;

    std::cout << "Enter k: ";
    std::cin >> k;

    bool containsK = contains(n, k, 1);

    std::cout << n << (containsK ? " contains " : " doesnt contain ") << k <<  std::endl;
}

bool isFibonacci(int n, int previous, int current)
{
    if(n <= previous)
    {
        return n == previous;
    }

    return isFibonacci(n, current, previous + current);
}

void problem5_7()
{
    int n;

    std::cout << "Enter n: ";
    std::cin >> n;

    std::cout << n << (isFibonacci(n, 0, 1) ? " is " : " isnt ") 
        << "Fibonacci digit" <<  std::endl;
}

int findBiggestElement(int array[], int n)
{
    if(n == 1)
    {
        return array[n - 1];
    }

    int biggestElement = findBiggestElement(array, n - 1);

    return array[n - 1] >= biggestElement ? array[n - 1] : biggestElement;
}

void problem5_8()
{
    int n;
    int array[50];

    std::cout << "Enter n: ";
    std::cin >> n;

    for(int i = 0; i < n; i++)
    {
        std::cout << "Enter element: ";
        std::cin >> array[i];
    }

    std::cout << "The biggest element is " << findBiggestElement(array, n) << std::endl;
}

void insertSorted(int x, int array[], int n)
{
    array[n] = array[n - 1];

    if(x >= array[n - 1])
    {
        array[n] = x;
        return;
    }

    insertSorted(x, array, n - 1);
}

void problem5_9()
{
    int n, element;
    int array[50];

    std::cout << "Enter n: ";
    std::cin >> n;

    for(int i = 0; i < n; i++)
    {
        std::cout << "Enter element: ";
        std::cin >> array[i];
    }

    std::cout << "Enter element to insert: ";
    std::cin >> element;

    insertSorted(element, array, n);

    for(int i = 0; i < n + 1; i++)
    {
        std::cout << array[i] << " ";
    }
}

int compare(char string1[], char string2[])
{
    if (*string1 < *string2)
    {
        return -1;
    }
    else if (*string1 > *string2)
    {
        return 1;
    }
    else if (*string1 == *string2 && *string1 == '\0')
    {
        return 0;
    }

    return compare(string1 + 1, string2 + 1);
}

void problem5_10()
{
    char string1[50];
    char string2[50];

    std::cout << "Enter string 1: ";
    std::cin.getline(string1, 50);

    std::cout << "Enter string 2: ";
    std::cin.getline(string2, 50);

    int n = compare(string1, string2);

    if (n < 0)
    {
        std::cout << "string 1 is before string 2" << std::endl;
    }
    else if (n == 0)
    {
        std::cout << "string 1 is equal to string 2" << std::endl;
    }
    else
    {
        std::cout << "string 1 is after string 2" << std::endl;
    }
}


int main()
{
    // problem5_1();
    // problem5_2();
    // problem5_3();
    // problem5_4();
    // problem5_5();
    // problem5_6();
    // problem5_7();
    // problem5_8();
    // problem5_9();
    // problem5_10();


    return 0;
}