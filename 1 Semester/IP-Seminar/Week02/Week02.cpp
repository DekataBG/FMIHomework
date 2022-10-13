#include <iostream>
#include <cmath>

void problem1()
{
    int n;

    std::cout << "Enter number for the month: ";
    std::cin >> n;

    switch(n)
    {
        case 1: 
            std::cout << "January";
            break;
        case 2: 
            std::cout << "February";
            break;
        case 3: 
            std::cout << "March";
            break;
        case 4: 
            std::cout << "April";
            break;
        case 5: 
            std::cout << "May";
            break;
        case 6: 
            std::cout << "June";
            break;
        case 7: 
            std::cout << "July";
            break;
        case 8: 
            std::cout << "August";
            break;
        case 9: 
            std::cout << "September";
            break;
        case 10: 
            std::cout << "October";
            break;
        case 11: 
            std::cout << "November";
            break;
        case 12: 
            std::cout << "December";
            break;
        default: 
            std::cout << "Invalid month";
            break;
    }
}

void problem2()
{
    char c;

    std::cout << "Enter a character: ";
    std::cin >> c;

    if(c >= 65 && c <= 90)
    {
        std::cout << "Upper case letter";
    }
    else if(c >= 97 && c <= 122)
    {
        std::cout << "Lower case letter";
    }
    else
    {
        std::cout << "Not a letter";
    }
}

void problem3()
{
    double a, b, c;

    std::cout << "Enter a: ";
    std::cin >> a;

    std::cout << "Enter b: ";
    std::cin >> b;
    
    std::cout << "Enter c: ";
    std::cin >> c;

    bool triangle = a + b > c && a + c > b && b + c > a;

    if(triangle)
    {
        std::cout << "A triangle with these sides can exist";
    }
    else
    {
        std::cout << "A triangle with these sides can NOT exist";
    }
}

void problem4()
{
    int n;

    std::cout << "Enter n: ";
    std::cin >> n;

    int d = n % 10;
    n /= 10;

    int c = n % 10;
    n /= 10;

    int b = n % 10;
    n /= 10;

    int a = n % 10;

    bool increasing = a <= b && b <= c && c <= d;

    if(increasing)
    {
    std::cout << "sorted";
    }
    else
    {
        std::cout << "not sorted";
    }
}

void problem5()
{
    double xa, ya, xb, yb, xc, yc;

    std::cout << "Enter Xa: ";
    std::cin >> xa;

    std::cout << "Enter Ya: ";
    std::cin >> ya;

    std::cout << "Enter Xb: ";
    std::cin >> xb;

    std::cout << "Enter Yb: ";
    std::cin >> yb;
    
    std::cout << "Enter Xc: ";
    std::cin >> xc;

    std::cout << "Enter Yc: ";
    std::cin >> yc;

    double ab = sqrt((xa - xb) * (xa - xb) + (ya - yb) * (ya - yb));
    double ac =  sqrt((xa - xc) * (xa - xc) + (ya - yc) * (ya - yc));
    double bc =  sqrt((xb - xc) * (xb - xc) + (yb - yc) * (yb - yc));

    double p = (ab + ac + bc) / 2;

    double biggest = std::max(std::max(ab, ac), bc);

    double area =  sqrt(p * (p - ab) * (p - ac) * (p - bc));

    double height = 2 * area / biggest;

    std::cout << "The height to the biggest side is " << height;
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