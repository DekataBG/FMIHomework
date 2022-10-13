#include <iostream>

void problem1() 
{
    double a, b;

    std::cout << "Enter weight: ";
    std::cin >> a;

    std::cout << "Enter height: ";
    std::cin >> b;

    double bmi = a / (b * b);

    std::cout << "BMI: " << bmi << std::endl;
}

void problem2()
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

void problem3()
{
    double a, b, x;

    std::cout << "Enter a: ";
    std::cin >> a;

    std::cout << "Enter b: ";
    std::cin >> b;

    std::cout << "Enter x: ";
    std::cin >> x;


    bool in = x >= a && x <= b;

    if(in)
    {
        std::cout << "In";
    }
    else
    {
        std::cout << "Out";
    }
}

void problem4()
{
    double a, b, c, first, second, third, bigger, smaller;

    std::cout << "Enter a: ";
    std::cin >> a;

    std::cout << "Enter b: ";
    std::cin >> b;

    std::cout << "Enter c: ";
    std::cin >> c;

    if(a >= b){
        bigger = a;
        smaller = b;
    } else {
        bigger = b;
        smaller = a;
    }

    if(bigger >= c) {
        first = bigger;
        
        if(c >= smaller) {
            second = c;
            third = smaller;
        } else {
            second = smaller;
            third = c;
        }
    } else {
        first = c;
        second = bigger;
        third = smaller;
    }

    std::cout << third << " " << second << " " << first;
}

void problem5()
{
    double a, b;

    std::cout << "Enter a: ";
    std::cin >> a;

    std::cout << "Enter b: ";
    std::cin >> b;

    a = a + b;
    b = a - b;
    a = a - b;

    std::cout << "a: " << a << "\nb: " << b << std::endl;
}


int main() 
{
    //problem1();
    //problem2();
    //problem3();
    //problem4();
    //problem5();

    return 0;
}