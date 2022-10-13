#include <iostream>
#include <cmath>

void problem1()
{
    int a, b;

    std::cout << "Enter a: ";
    std::cin >> a;

    std::cout << "Enter b: ";
    std::cin >> b;

    std::cout << "Sum: " << a + b << std::endl;
    std::cout << "Difference: " << a - b << std::endl;
    std::cout << "Product: " << a * b << std::endl;
    std::cout << "Quotient: " << a / b << std::endl;
}

void problem1_1()
{
    double a, b;

    std::cout << "Enter a: ";
    std::cin >> a;

    std::cout << "Enter b: ";
    std::cin >> b;

    std::cout << "Sum: " << a + b << std::endl;
    std::cout << "Difference: " << a - b << std::endl;
    std::cout << "Product: " << a * b << std::endl;
    std::cout << "Quotient: " << a / b << std::endl;
}

void problem2()
{
    int number;

    std::cout << "Enter 4-digit number: ";

    std::cin >> number;

    int sum = 0;

    sum += number % 10;
    number /= 10;

    sum += number % 10;
    number /= 10;
    
    sum += number % 10;
    number /= 10;
    
    sum += number % 10;
    number /= 10;

    std::cout << "The sum of the digits is " << sum;
}

void problem3()
{
    double x, y;

    std::cout << "Enter x: ";
    std::cin >> x;

    std::cout << "Enter y: ";
    std::cin >> y;

    std::cout << "The distance is: " << sqrt(x * x + y * y);
}

void problem3_1()
{
    double x, y, r;

    std::cout << "Enter x: ";
    std::cin >> x;

    std::cout << "Enter y: ";
    std::cin >> y;
    
    std::cout << "Enter r: ";
    std::cin >> r;

    double distance = sqrt(x * x + y * y);

    bool in = distance <= r;

    if(in)
    {
        std::cout << "The point is in the circle.";
    }
    else
    {
        std::cout << "The point is NOT in the circle.";
    }
}

void problem4()
{
    int n;

    std::cout << "Enter n: ";

    std::cin >> n;

    char c1 = 96 + n;
    char c2 = 64 + n;

    std::cout << c1 << " " << c2;
}


int main()
{
    //problem1();
    //problem1_1();
    //problem2();
    //problem3();
    //problem3_1();
    //problem4();

    return 0;
}