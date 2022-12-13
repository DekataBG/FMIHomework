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

void problem5_2()
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

void problem5_3()
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

void problem5_5()
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

void problem5_7()
{
    int n, k;

    std::cout << "Enter n: ";
    std::cin >> n;
    
    std::cout << "Enter k: ";
    std::cin >> k;

    std::cout << "The product is " << product(n, k, 1) << std::endl;
}


int main()
{
    // problem5_2();
    // problem5_3();
    // problem5_7();
    // problem5_7();


    return 0;
}