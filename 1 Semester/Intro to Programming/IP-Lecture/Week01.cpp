//Problems from https://github.com/stranxter/lecture-notes/blob/master/homeworks/Problems%20in%20Programming.pdf
#include <iostream>
#include <cmath>

void problem1_3()
{
    int years;

    std::cout << "Enter years: ";

    std::cin >> years;

    int days = years * 365.4;
    int hours = days * 24;
    long minutes = hours * 60;
    long seconds = minutes * 60;

    std::cout << "Days: " << days << "\nHours: " << hours << "\nMinutes: " << minutes << "\nSeconds: " << seconds;
}

void problem1_4a()
{
    double side, heigth;

    std::cout << "Enter side: ";
    std::cin >> side;

    std::cout << "Enter height: ";
    std::cin >> heigth;

    std::cout << "The area is " << side * heigth / 2;
}

void problem1_4b()
{
    double a, b, c;

    std::cout << "Enter a: ";
    std::cin >> a;

    std::cout << "Enter b: ";
    std::cin >> b;

    std::cout << "Enter c: ";
    std::cin >> c;

    double p = (a + b + c) / 2;

    std::cout << "The area is " << sqrt(p * (p - a) * (p - b) * (p - c));
}

void problem1_5()
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
        std::cout << "On the y-axis";
    }
    else if(x =! 0 && y == 0)
    {
        std::cout << "On the x-axis";
    }
    else
    {
        std::cout << "On point (0; 0)";
    }
}

void problem1_6a()
{
    int p;

    std::cout << "Enter p: ";
    std::cin >> p;

    bool isDivisible = p % 4 == 0 || p % 7 == 0;

    std::cout << std::boolalpha << isDivisible;
}

void problem1_6b()
{
    double a, b, c;

    std::cout << "Enter a: ";
    std::cin >> a;

    std::cout << "Enter b: ";
    std::cin >> b;

    std::cout << "Enter c: ";
    std::cin >> c;

    bool doesntHaveRealRoots = (b * b - 4 * a * c) < 0;

    std::cout << std::boolalpha << doesntHaveRealRoots;
}

void problem1_6c()
{
    double a, b, r;

    std::cout << "Enter a: ";
    std::cin >> a;

    std::cout << "Enter b: ";
    std::cin >> b;

    bool isInside = sqrt(a * a + (b - 1) * (b - 1)) < 5;

    std::cout << std::boolalpha << isInside;
}

void problem1_6d()
{
    double a, b;

    std::cout << "Enter a: ";
    std::cin >> a;

    std::cout << "Enter b: ";
    std::cin >> b;

    bool isInsideAndInIIIQuadrant = a < 0 && b < 0 && sqrt(a * a + (b) * (b)) <= 5;

    std::cout << std::boolalpha << isInsideAndInIIIQuadrant;
}

void problem1_6e()
{
    double a, b;

    std::cout << "Enter a: ";
    std::cin >> a;

    std::cout << "Enter b: ";
    std::cin >> b;

    bool isOnFigure = sqrt(a * a + (b) * (b)) == 5 || sqrt(a * a + (b) * (b)) == 10;

    std::cout << std::boolalpha << isOnFigure;
}

void problem1_6f()
{
    double x;

    std::cout << "Enter x: ";
    std::cin >> x;

    bool in = x >= 0 && x <= 1;

    std::cout << std::boolalpha << in;
}

void problem1_6g()
{
    double a, b, c, x;

    std::cout << "Enter a: ";
    std::cin >> a;

    std::cout << "Enter b: ";
    std::cin >> b;

    std::cout << "Enter c: ";
    std::cin >> c;
    
    std::cout << "Enter x: ";
    std::cin >> x;

    bool equal = std::max(std::max(a, b), c) == x;
    std::cout << std::boolalpha << equal;
}

void problem1_6h()
{
    double a, b, c, x;

    std::cout << "Enter a: ";
    std::cin >> a;

    std::cout << "Enter b: ";
    std::cin >> b;

    std::cout << "Enter c: ";
    std::cin >> c;
    
    std::cout << "Enter x: ";
    std::cin >> x;

    bool different = std::max(std::max(a, b), c) != x;
    std::cout << std::boolalpha << different;
}

void problem1_6i()
{
    bool x, y;

    std::cout << "Enter x: ";
    std::cin >> x;

    std::cout << "Enter y: ";
    std::cin >> y;

    std::cout << std::boolalpha << x || y;
}

void problem1_6j()
{
    bool x, y;

    std::cout << "Enter x: ";
    std::cin >> x;

    std::cout << "Enter y: ";
    std::cin >> y;

    std::cout << std::boolalpha << x && y;
}

void problem1_6k()
{
    double a, b, c;

    std::cout << "Enter a: ";
    std::cin >> a;

    std::cout << "Enter b: ";
    std::cin >> b;

    std::cout << "Enter c: ";
    std::cin >> c;

    bool allNotPositive = a <= 0 && b <= 0 && c <= 0;

    std::cout << std::boolalpha << allNotPositive;
}

void problem1_6l()
{
    int p;

    std::cout << "Enter p: ";
    std::cin >> p;

    bool contains7 = false;

    contains7 = p % 10 == 7 || contains7;
    p /= 10;

    contains7 = p % 10 == 7 || contains7;
    p /= 10;

    contains7 = p % 10 == 7 || contains7;

    std::cout << std::boolalpha << contains7;
}

void problem1_6m()
{
    int m, a, b, c;

    std::cout << "Enter m: ";
    std::cin >> m;

    a = m % 10;
    m /= 10;

    b = m % 10;
    m /= 10;

    c = m % 10;

    bool different = a != b && a != c && b != c;

    std::cout << std::boolalpha << different;
}

void problem1_6n()
{
    int m, a, b, c;

    std::cout << "Enter m: ";
    std::cin >> m;

    a = m % 10;
    m /= 10;

    b = m % 10;
    m /= 10;

    c = m % 10;

    bool twoEqualDigits = a == b || b == c || a == c;

    std::cout << std::boolalpha << twoEqualDigits;
}

void problem1_6o()
{
    int x, a, b, c;

    std::cout << "Enter x: ";
    std::cin >> x;

    a = x % 10;
    x /= 10;

    b = x % 10;
    x /= 10;

    c = x % 10;

    bool increaseOrDegrease = (a > b && b > c) || (a < b && b < c);

    std::cout << std::boolalpha << increaseOrDegrease;
}

void problem1_6p()
{
    int x, y, a1, b1, c1, a2, b2, c2;

    std::cout << "Enter x: ";
    std::cin >> x;

    std::cout << "Enter y: ";
    std::cin >> y;

    a1 = x % 10;
    x /= 10;
    b1 = x % 10;
    x /= 10;
    c1 = x % 10;

    a2 = y % 10;
    y /= 10;
    b2 = y % 10;
    y /= 10;
    c2 = y % 10;

    bool symmetric = a1 == c2 && a1 != 0 && b1 == b2 && c1 == a2 && c1 != 0;

    std::cout << std::boolalpha << symmetric;
}

void problem1_6q()
{
    int x;

    std::cout << "Enter x: ";
    std::cin >> x;

    bool prime = x != 1 && x % 2 != 0 && x % 3 != 0;

    std::cout << std::boolalpha << prime;
}

void problem1_7()
{
    int year;

    std::cout << "Enter year: ";
    std::cin >> year;

    bool isLeapYear = year % 4 == 0;

    if(isLeapYear)
    {
        std::cout << "The year is leap";
    }
    else
    {
        std::cout << "The year is NOT leap";
    }
}


int main()
{
    //problem1_3();
    //problem1_4a();
    //problem1_4b();
    //problem1_5();
    //problem1_6a();
    //problem1_6b();
    //problem1_6c();
    //problem1_6d();
    //problem1_6e();
    //problem1_6f();
    //problem1_6g();
    //problem1_6h();
    //problem1_6i();
    //problem1_6j();
    //problem1_6k();
    //problem1_6l();
    //problem1_6m();
    //problem1_6n();
    //problem1_6o();
    //problem1_6p();
    //problem1_6q();
    //problem1_7();

    return 0;
}